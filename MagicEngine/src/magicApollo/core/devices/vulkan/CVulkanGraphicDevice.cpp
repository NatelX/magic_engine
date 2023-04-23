#include "mepch.h"

#include "CVulkanGraphicDevice.h"
#include <magicEngine/core/logging/CLog.h>
#include <magicEngine/core/collections/CArray.h>

using namespace MagicEngine;

namespace MagicApollo {

	CVulkanGraphicDevice::CVulkanGraphicDevice() {
		initVulkanContext();
	}

	void CVulkanGraphicDevice::initVulkanContext() {
		const char* applicationName = "MagicEngine Vulkan App";

		uint32_t version = 0;
		version &= ~(0xFFFU);
		version = VK_MAKE_API_VERSION(0, 1, 3, 0);

		vk::ApplicationInfo appInfo = vk::ApplicationInfo(
			applicationName,
			version,
			"Doing it the hard way",
			version,
			version);

		CArray<const char*> extensions = getVulkanExtensions();
		CArray<const char*> layers = getVulkanLayers();

		vk::InstanceCreateInfo createInfo = vk::InstanceCreateInfo(
			vk::InstanceCreateFlags(),
			&appInfo,
			static_cast<uint32_t>(layers.size()), 
			layers.data(),
			static_cast<uint32_t>(extensions.size()),
			extensions.data());

		try {
			m_vkInstance = vk::createInstance(createInfo);
		}
		catch (vk::SystemError err) {
#ifdef MAGICENGINE_DEBUG
			MAGICENGINE_CORE_CRITICAL("Cannot initialize Vulkan core instance: {}", err.what());
#endif
			EXIT_APP_ERROR
		}

#ifdef MAGICENGINE_DEBUG
		MAGICENGINE_CORE_INFO("Vulkan has been initialized successfully");
#endif
	}

	CArray<const char*> CVulkanGraphicDevice::getVulkanExtensions() const {
		CArray<const char*> extensions;

#ifdef MAGICENGINE_PLATFORM_WINDOWS
		extensions.push_back("VK_KHR_surface");
		extensions.push_back("VK_KHR_win32_surface");
#endif

		std::vector<vk::ExtensionProperties> supportedExtensions = vk::enumerateInstanceExtensionProperties();

#ifdef MAGICENGINE_DEBUG
			MAGICENGINE_CORE_INFO("Device can support the following extensions: ");
			for (vk::ExtensionProperties supportedExtension : supportedExtensions) {
				MAGICENGINE_CORE_INFO("\t {}", supportedExtension.extensionName);
			}
#endif

		bool found;
		for (const char* extension : extensions) {
			found = false;
			for (vk::ExtensionProperties supportedExtension : supportedExtensions) {
				if (strcmp(extension, supportedExtension.extensionName) == 0) {
					found = true;
					break;
				}
			}
			if (!found) {
#ifdef MAGICENGINE_DEBUG
				MAGICENGINE_CORE_CRITICAL("Extension \"{}\" is not supported", extension);
#endif
				EXIT_APP_ERROR
			}
		}

		return extensions;
	}

	CArray<const char*> CVulkanGraphicDevice::getVulkanLayers() const {
		CArray<const char*> layers;
#ifdef MAGICENGINE_DEBUG
			layers.push_back("VK_LAYER_KHRONOS_validation");
#endif

		std::vector<vk::LayerProperties> supportedLayers = vk::enumerateInstanceLayerProperties();

#ifdef MAGICENGINE_DEBUG
		MAGICENGINE_CORE_INFO("Device can support the following layers: ");
			for (vk::LayerProperties supportedLayer : supportedLayers) {
				MAGICENGINE_CORE_INFO("\t{}", supportedLayer.layerName);
			}
#endif

		bool found;
		for (const char* layer : layers) {
			found = false;
			for (vk::LayerProperties supportedLayer : supportedLayers) {
				if (strcmp(layer, supportedLayer.layerName) == 0) {
					found = true;
					break;
				}
			}
			if (!found) {
#ifdef MAGICENGINE_DEBUG
				MAGICENGINE_CORE_CRITICAL("Layer \"{}\" is not supported", layer);
				EXIT_APP_ERROR
#endif
			}
		}
		return layers;
	}

}

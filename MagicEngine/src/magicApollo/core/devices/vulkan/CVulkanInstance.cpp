#include "mepch.h"

#include "CVulkanInstance.h"
#include <magicApollo/core/devices/CMagicApolloGraphicDevice.h>
#include <magicEngine/core/logging/CLog.h>

using namespace MagicEngine;

namespace MagicApollo {

	CVulkanInstance::CVulkanInstance(
		CRendererDebugger rendererDebugger) {

		const char* applicationName = "MagicEngine Vulkan App";

		uint32_t version = 0;
		version &= ~(0xFFFU);
		version = VK_MAKE_API_VERSION(0, 1, 3, 0);

		vk::ApplicationInfo appInfo = vk::ApplicationInfo(
			applicationName,
			version,
			"MagicApollo Vulkan",
			version,
			version);

		CArray<const char*> extensions = getVulkanExtensions(rendererDebugger);
		CArray<const char*> layers = getVulkanLayers(rendererDebugger);

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
			if (rendererDebugger == CRendererDebugger::ENABLED) {
				MAGICENGINE_CORE_CRITICAL("Cannot initialize Vulkan core instance: {}", err.what());
			}
			EXIT_APP_ERROR
		}

		if (rendererDebugger == CRendererDebugger::ENABLED) {
			MAGICENGINE_CORE_INFO("Vulkan has been initialized successfully");
		}
	}

	void CVulkanInstance::destroy() const {
		m_vkInstance.destroy();
	}

	vk::Instance CVulkanInstance::getInstance() const {
		return m_vkInstance;
	}

	CArray<const char*> CVulkanInstance::getVulkanExtensions(
		CRendererDebugger rendererDebugger) const {

		CArray<const char*> extensions;

#ifdef MAGICENGINE_PLATFORM_WINDOWS
		extensions.push_back("VK_KHR_surface");
		extensions.push_back("VK_KHR_win32_surface");
#endif

		if (rendererDebugger == CRendererDebugger::ENABLED) {
			extensions.push_back("VK_EXT_debug_utils");
		}

		CArray<vk::ExtensionProperties> supportedExtensions = vk::enumerateInstanceExtensionProperties();

		if (rendererDebugger == CRendererDebugger::ENABLED) {
			MAGICENGINE_CORE_INFO("Device can support the following extensions: ");
			for (vk::ExtensionProperties supportedExtension : supportedExtensions) {
				MAGICENGINE_CORE_INFO("\t {}", supportedExtension.extensionName);
			}
		}

		std::for_each(
			extensions.begin(),
			extensions.end(),
			[supportedExtensions, rendererDebugger](const char* extension) {
				auto foundIt = std::find_if(
					supportedExtensions.begin(),
					supportedExtensions.end(),
					[extension](const vk::ExtensionProperties& supportedExtension) {
						return strcmp(extension, supportedExtension.extensionName) == 0;
					}
				);
				if (foundIt == supportedExtensions.end()) {
					if (rendererDebugger == CRendererDebugger::ENABLED) {
						MAGICENGINE_CORE_CRITICAL("Extension \"{}\" is not supported", extension);
					}
					EXIT_APP_ERROR
				}
			});

		return extensions;
	}

	CArray<const char*> CVulkanInstance::getVulkanLayers(
		CRendererDebugger rendererDebugger) const {

		CArray<const char*> layers;
		if (rendererDebugger == CRendererDebugger::ENABLED) {
			layers.push_back("VK_LAYER_KHRONOS_validation");
		}

		CArray<vk::LayerProperties> supportedLayers = vk::enumerateInstanceLayerProperties();

		if (rendererDebugger == CRendererDebugger::ENABLED) {
			MAGICENGINE_CORE_INFO("Device can support the following layers: ");
			for (vk::LayerProperties supportedLayer : supportedLayers) {
				MAGICENGINE_CORE_INFO("\t{}", supportedLayer.layerName);
			}
		}

		std::for_each(
			layers.begin(),
			layers.end(),
			[supportedLayers, rendererDebugger](const char* layer) {
				auto foundIt = std::find_if(
					supportedLayers.begin(),
					supportedLayers.end(),
					[layer](const vk::LayerProperties& supportedLayer) {
						return strcmp(layer, supportedLayer.layerName) == 0;
					}
				);
				if (foundIt == supportedLayers.end()) {
					if (rendererDebugger == CRendererDebugger::ENABLED) {
						MAGICENGINE_CORE_CRITICAL("Extension \"{}\" is not supported", layer);
					}
					EXIT_APP_ERROR
				}
			});

		return layers;
	}

}

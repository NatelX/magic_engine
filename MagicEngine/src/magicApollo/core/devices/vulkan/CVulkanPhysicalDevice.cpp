#include "mepch.h"

#include "CVulkanPhysicalDevice.h"
#include <magicEngine/core/logging/CLog.h>

namespace MagicApollo {

	CVulkanPhysicalDevice::CVulkanPhysicalDevice(
		vk::Instance vkInstance,
		CRendererDebugger rendererDebugger)
	{
		MAGICENGINE_CORE_INFO("Choosing GPU");

		std::vector<vk::PhysicalDevice> availableDevices = vkInstance.enumeratePhysicalDevices();

		if (rendererDebugger == CRendererDebugger::ENABLED) {
			MAGICENGINE_CORE_INFO("Number of available GPUs: {}", availableDevices.size());
		}

		for (vk::PhysicalDevice device : availableDevices) {
			if (rendererDebugger == CRendererDebugger::ENABLED) {
				logGPUProperties(device);
			}
			if (checkIfGPUIsSuitable(device, rendererDebugger)) {
				m_physicalDevice = device;
				break;
			}
		}

		if (!m_physicalDevice) {
			if (rendererDebugger == CRendererDebugger::ENABLED) {
				MAGICENGINE_CORE_CRITICAL("Cannot find any proper GPU");
				EXIT_APP_ERROR
			}
		}
	}

	void CVulkanPhysicalDevice::logGPUProperties(
		const vk::PhysicalDevice& device
	) {
		vk::PhysicalDeviceProperties properties = device.getProperties();

		MAGICENGINE_CORE_INFO("Device name: {}", properties.deviceName);

		CString deviceType("");
		switch (properties.deviceType) {
			case (vk::PhysicalDeviceType::eCpu):
				deviceType = "CPU";
				break;

			case (vk::PhysicalDeviceType::eDiscreteGpu):
				deviceType = "Discrete GPU";
				break;

			case (vk::PhysicalDeviceType::eIntegratedGpu):
				deviceType = "Integrated GPU";
				break;

			case (vk::PhysicalDeviceType::eVirtualGpu):
				deviceType = "Virtual GPU";
				break;

			default:
				deviceType = "Other";
		}

		MAGICENGINE_CORE_INFO("Device type: {}", deviceType);
	}

	bool CVulkanPhysicalDevice::checkIfGPUIsSuitable(
		const vk::PhysicalDevice& device, 
		CRendererDebugger rendererDebugger
	) {
		if (rendererDebugger == CRendererDebugger::ENABLED) {
			MAGICENGINE_CORE_INFO("Checking if device support requested extensions");
		}

		const CArray<const char*> requestedExtensions = {
			VK_KHR_SWAPCHAIN_EXTENSION_NAME
		};

		if (checkDeviceExtensionSupport(device, requestedExtensions, rendererDebugger)) {

			if (rendererDebugger == CRendererDebugger::ENABLED) {
				MAGICENGINE_CORE_INFO("Device can support the requested extensions");
			}
			return true;
		}
		else {

			if (rendererDebugger == CRendererDebugger::ENABLED) {
				MAGICENGINE_CORE_INFO("Device can't support the requested extensions");
			}

			return false;
		}
	}

	bool CVulkanPhysicalDevice::checkDeviceExtensionSupport(
		const vk::PhysicalDevice& device, 
		const CArray<const char*>& requestedExtensions, 
		CRendererDebugger rendererDebugger
	) {
		CSet<CString> requiredExtensions(requestedExtensions.begin(), requestedExtensions.end());

		if (rendererDebugger == CRendererDebugger::ENABLED) {
			MAGICENGINE_CORE_INFO("Device can support extensions:");
		}

		for (vk::ExtensionProperties& extension : device.enumerateDeviceExtensionProperties()) {

			if (rendererDebugger == CRendererDebugger::ENABLED) {
				MAGICENGINE_CORE_INFO("\t\"{}\"", extension.extensionName);
			}

			requiredExtensions.erase(extension.extensionName);
		}

		return requiredExtensions.empty();
	}
}

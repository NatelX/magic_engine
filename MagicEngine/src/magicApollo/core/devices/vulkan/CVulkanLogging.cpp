#include "mepch.h"

#include "CVulkanLogging.h"
#include <magicEngine/core/logging/CLog.h>

namespace MagicApollo {

	VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData
	) {
		MAGICENGINE_CORE_ERROR("vulkan validation layer: {}", pCallbackData->pMessage);
		return VK_FALSE;
	}

	CVulkanLogging::CVulkanLogging(vk::Instance vkInstance) {

		m_dynamicDispatchLoader = vk::DispatchLoaderDynamic(vkInstance, vkGetInstanceProcAddr);

		vk::DebugUtilsMessengerCreateInfoEXT createInfo = vk::DebugUtilsMessengerCreateInfoEXT(
			vk::DebugUtilsMessengerCreateFlagsEXT(),
			vk::DebugUtilsMessageSeverityFlagBitsEXT::eVerbose | vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning | vk::DebugUtilsMessageSeverityFlagBitsEXT::eError,
			vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral | vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation | vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance,
			debugCallback,
			nullptr
		);

		m_debugMessenger = vkInstance.createDebugUtilsMessengerEXT(createInfo, nullptr, m_dynamicDispatchLoader);
	}

	void CVulkanLogging::destroy(vk::Instance vkInstance) {
		vkInstance.destroyDebugUtilsMessengerEXT(m_debugMessenger, nullptr, m_dynamicDispatchLoader);
	}

}

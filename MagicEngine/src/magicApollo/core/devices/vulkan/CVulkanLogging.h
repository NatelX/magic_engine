#ifndef CVULKANLOGGIN_H
#define CVULKANLOGGIN_H

#include <magicEngine/core/Core.h>
#include <vulkan/vulkan.hpp>

namespace MagicApollo {

	VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData);

	class MAGICENGINE_API CVulkanLogging {
	protected:
		vk::DispatchLoaderDynamic m_dynamicDispatchLoader;
		vk::DebugUtilsMessengerEXT m_debugMessenger;

	public:
		CVulkanLogging(vk::Instance vkInstance);

		void destroy(vk::Instance vkInstance);
	};
}

#endif
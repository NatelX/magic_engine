#ifndef CVULKANPHYSICALDEVICE_H
#define CVULKANPHYSICALDEVICE_H

#include <magicEngine/core/Core.h>
#include "CVulkan.h"
#include <magicApollo/core/devices/CMagicApolloGraphicDevice.h>
#include <magicEngine/core/collections/CArray.h>

using namespace MagicEngine;

namespace MagicApollo {

	class MAGICENGINE_API CVulkanPhysicalDevice {
	protected:
		vk::PhysicalDevice m_physicalDevice;

	public:
		CVulkanPhysicalDevice(
			vk::Instance vkInstance,
			CRendererDebugger rendererDebugger);

	private:
		void logGPUProperties(const vk::PhysicalDevice& device);

		bool checkIfGPUIsSuitable(
			const vk::PhysicalDevice& device,
			CRendererDebugger rendererDebugger);

		bool checkDeviceExtensionSupport(
			const vk::PhysicalDevice& device,
			const CArray<const char*>& requestedExtensions,
			CRendererDebugger rendererDebugger);
	};

}

#endif

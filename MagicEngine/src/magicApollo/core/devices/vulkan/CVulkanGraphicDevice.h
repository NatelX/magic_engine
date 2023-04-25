#ifndef CVULKANGRAPHICDEVICE_H
#define CVULKANGRAPHICDEVICE_H

#include "../CMagicApolloGraphicDevice.h"
#include <vulkan/vulkan.hpp>
#include <magicEngine/core/collections/CArray.h>
#include "CVulkanInstance.h"
#include "CVulkanLogging.h"

using namespace MagicEngine;

namespace MagicApollo {

	class MAGICENGINE_API CVulkanGraphicDevice : public CMagicApolloGraphicDevice {
	protected:
		CUniquePtr<CVulkanInstance> m_vulkanInstance;
		CUniquePtr<CVulkanLogging> m_debugLogging;

	public:
		CVulkanGraphicDevice(
			CRendererDebugger rendererDebugger);
		~CVulkanGraphicDevice();
	};

}

#endif
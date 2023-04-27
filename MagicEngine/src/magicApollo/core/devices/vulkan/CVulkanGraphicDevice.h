#ifndef CVULKANGRAPHICDEVICE_H
#define CVULKANGRAPHICDEVICE_H

#include "../CMagicApolloGraphicDevice.h"
#include "CVulkanInstance.h"
#include "CVulkanLogging.h"
#include "CVulkanPhysicalDevice.h"

using namespace MagicEngine;

namespace MagicApollo {

	class MAGICENGINE_API CVulkanGraphicDevice : public CMagicApolloGraphicDevice {
	protected:
		CUniquePtr<CVulkanInstance> m_vulkanInstance;
		CUniquePtr<CVulkanLogging> m_debugLogging;
		CUniquePtr<CVulkanPhysicalDevice> m_physicalDevice;

	public:
		CVulkanGraphicDevice(
			CRendererDebugger rendererDebugger);
		~CVulkanGraphicDevice();
	};

}

#endif
#include "mepch.h"

#include "CVulkanGraphicDevice.h"
#include <magicEngine/core/logging/CLog.h>

using namespace MagicEngine;

namespace MagicApollo {

	CVulkanGraphicDevice::CVulkanGraphicDevice(
		CRendererDebugger rendererDebugger) :
		CMagicApolloGraphicDevice(rendererDebugger)
	{
		m_vulkanInstance = createUniquePtr<CVulkanInstance>(rendererDebugger);

		if (m_rendererDebugger == CRendererDebugger::ENABLED) {
			m_debugLogging = createUniquePtr<CVulkanLogging>(m_vulkanInstance->getInstance());
		}

		m_physicalDevice = createUniquePtr<CVulkanPhysicalDevice>(
			m_vulkanInstance->getInstance(), 
			rendererDebugger);
	}

	CVulkanGraphicDevice::~CVulkanGraphicDevice() {
		if (m_debugLogging != nullptr) {
			m_debugLogging->destroy(m_vulkanInstance->getInstance());
		}

		m_vulkanInstance->destroy();
	}

}

#include "mepch.h"

#include "CVulkanGraphicDevice.h"
#include <magicEngine/core/logging/CLog.h>
#include <magicEngine/core/collections/CArray.h>

using namespace MagicEngine;

namespace MagicApollo {

	CVulkanGraphicDevice::CVulkanGraphicDevice(
		CRendererDebugger rendererDebugger) :
		CMagicApolloGraphicDevice(rendererDebugger),
		m_vulkanInstance(createUniquePtr<CVulkanInstance>(rendererDebugger))
	{

		if (m_rendererDebugger == CRendererDebugger::ENABLED) {
			m_debugLogging = createUniquePtr<CVulkanLogging>(m_vulkanInstance->getInstance());
		}
	}

	CVulkanGraphicDevice::~CVulkanGraphicDevice() {
		if (m_debugLogging != nullptr) {
			m_debugLogging->destroy(m_vulkanInstance->getInstance());
		}

		m_vulkanInstance->destroy();
	}

}

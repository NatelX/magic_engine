#include "mepch.h"

#include "CApplication.h"
#include <magicApollo/core/devices/vulkan/CVulkanGraphicDevice.h>

namespace MagicEngine {

	CApplication::CApplication(
		CRendererType rendererType, 
		CRendererDebugger rendererDebugger) :
		m_rendererType(rendererType) 
	{
		if (m_rendererType == CRendererType::VULKAN) {
			m_graphicDevice = createUniquePtr<CVulkanGraphicDevice>(rendererDebugger);
		} else {
			EXIT_APP_ERROR
		}
	}

	CRendererType CApplication::getRendererType() const {
		return m_rendererType;
	}

}

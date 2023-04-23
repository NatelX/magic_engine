#include "mepch.h"

#include "CApplication.h"
#include <magicApollo/core/devices/vulkan/CVulkanGraphicDevice.h>

namespace MagicEngine {

	CApplication::CApplication(CMagicEditorRendererType rendererType) : 
	m_rendererType(rendererType) {
		if (m_rendererType == CMagicEditorRendererType::VULKAN) {
			m_graphicDevice = createUniquePtr<CVulkanGraphicDevice>();
		} else {
			EXIT_APP_ERROR
		}
	}

	CMagicEditorRendererType CApplication::getRendererType() const {
		return m_rendererType;
	}

}

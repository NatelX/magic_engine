#ifndef CAPPLICATION_H
#define CAPPLICATION_H

#include <magicEngine/core/Core.h>
#include <magicApollo/core/devices/CMagicApolloGraphicDevice.h>

using namespace MagicApollo;

namespace MagicEngine {

	class MAGICENGINE_API CApplication {
	protected:
		CUniquePtr<CMagicApolloGraphicDevice> m_graphicDevice;
		CMagicEditorRendererType m_rendererType;

	public:
		CApplication(CMagicEditorRendererType rendererType);

		CMagicEditorRendererType getRendererType() const;
	};

}

#endif
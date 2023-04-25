#ifndef CAPPLICATION_H
#define CAPPLICATION_H

#include <magicEngine/core/Core.h>
#include <magicApollo/core/devices/CMagicApolloGraphicDevice.h>

using namespace MagicApollo;

namespace MagicEngine {

	class MAGICENGINE_API CApplication {
	protected:
		CUniquePtr<CMagicApolloGraphicDevice> m_graphicDevice;
		CRendererType m_rendererType;

	public:
		CApplication(
			CRendererType rendererType,
			CRendererDebugger rendererDebugger);

		CRendererType getRendererType() const;
	};

}

#endif
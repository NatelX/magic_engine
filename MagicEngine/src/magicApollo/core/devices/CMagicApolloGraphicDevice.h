#ifndef CMAGICAPOLLOGRAPHICDEVICE_H
#define CMAGICAPOLLOGRAPHICDEVICE_H

#include <magicEngine/core/Core.h>

namespace MagicApollo {

	enum MAGICENGINE_API CRendererType {
		VULKAN,
		DIRECTX_12,
		OPENGL_45
	};

	enum MAGICENGINE_API CRendererDebugger {
		ENABLED,
		DISABLED
	};

	class MAGICENGINE_API CMagicApolloGraphicDevice {
	protected:
		CRendererDebugger m_rendererDebugger;

	public:
		CMagicApolloGraphicDevice(
			CRendererDebugger rendererDebugger);
	};

}

#endif
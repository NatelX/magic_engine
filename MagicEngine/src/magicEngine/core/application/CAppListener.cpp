#include "mepch.h"

#include "CAppListener.h"
#include "CAppHandler.h"

namespace MagicEngine {

	CAppListener::CAppListener() {}

	CAppHandler* CAppListener::getAppHandler() const {
		return m_appHandler;
	}

	void CAppListener::setAppHandler(CAppHandler* appHandler) {
		m_appHandler = appHandler;
	}

	void CAppListener::onCreated() {}

	void CAppListener::onRender() {}

	void CAppListener::onResized(u_int32 width, u_int32 height) {}

	void CAppListener::onDestroyed() {}

}

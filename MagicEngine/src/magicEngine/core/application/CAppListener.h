#ifndef CAPPLISTENER_H
#define CAPPLISTENER_H

#include <magicEngine/core/Core.h>

namespace MagicEngine {

	class CAppHandler;

	class MAGICENGINE_API CAppListener {
		friend class CAppHandler;
	protected:
		CAppHandler* m_appHandler;

	public:
		CAppListener();

		CAppHandler* getAppHandler() const;

	private:
		void setAppHandler(CAppHandler* appHandler);

	protected:
		virtual void onCreated();
		virtual void onRender();
		virtual void onResized(u_int32 width, u_int32 height);
		virtual void onDestroyed();
	};

}

#endif
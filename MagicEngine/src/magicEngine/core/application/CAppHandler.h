#ifndef CAPPHANDLER_H
#define CAPPHANDLER_H

#include <magicEngine/core/Core.h>

namespace MagicEngine {

	class CAppListener;

	class MAGICENGINE_API CAppHandler {
	protected:
		CSharedPtr<CAppListener> m_appListener;

		int128 m_frameId, m_frameStart;
		float32 m_deltaTime;
		bool m_resetDeltaTime;
		u_int32 m_frames, m_fps;
		int128 m_lastTime;

	public:
		CAppHandler(CSharedPtr<CAppListener> appListener);
		~CAppHandler();

		u_int32 getFPS() const;
		float32 getDeltaTime() const;
		CSharedPtr<CAppListener> getAppListener() const;

		void create();
		void renderLoop();
		void resize(u_int32 width, u_int32 height);

	private:
		void updateTime();
	};

}

#endif
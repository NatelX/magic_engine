#include "mepch.h"

#include "CAppHandler.h"
#include "CAppListener.h"
#include <magicEngine/core/utils/CTime.h>

namespace MagicEngine {

	CAppHandler::CAppHandler(CSharedPtr<CAppListener> appListener) :
		m_frameId(-1), 
		m_frameStart(0), 
		m_deltaTime(0), 
		m_resetDeltaTime(false), 
		m_frames(0), 
		m_fps(0), 
		m_lastTime(CTime::currentTimeNano()),
		m_appListener(appListener)
	{
		m_appListener->setAppHandler(this);
	}

	CAppHandler::~CAppHandler() {
	}

	u_int32 CAppHandler::getFPS() const {
		return m_fps;
	}

	float32 CAppHandler::getDeltaTime() const {
		return m_deltaTime;
	}

	CSharedPtr<CAppListener> CAppHandler::getAppListener() const {
		return m_appListener;
	}

	void CAppHandler::create() {
		m_appListener->onCreated();
	}

	void CAppHandler::renderLoop() {
		updateTime();
		m_appListener->onRender();
	}

	void CAppHandler::resize(u_int32 width, u_int32 height) {
		m_appListener->onResized(width, height);
	}

	void CAppHandler::updateTime() {
		int128 time;
		if (m_resetDeltaTime) {
			m_resetDeltaTime = false;
			time = m_lastTime;
		}
		else
			time = CTime::currentTimeNano();
		m_deltaTime = (time - m_lastTime) / 1000000000.0f;
		m_lastTime = time;

		if (time - m_frameStart >= 1000000000) {
			m_fps = m_frames;
			m_frames = 0;
			m_frameStart = time;
		}
		m_frames++;
	}

}
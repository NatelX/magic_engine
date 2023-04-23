#ifndef MAGICEDITOR_APP_H
#define MAGICEDITOR_APP_H

#include <wx/app.h>
#include <wx/image.h>
#include <magicEngine/core/application/CApplication.h>

class MagicEditorApp : public wxApp
{
protected:
	CUniquePtr<MagicEngine::CApplication> m_app;

public:
	virtual bool OnInit();

private:
	void initWxWidgets();
};

#endif
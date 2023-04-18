#include <wx/app.h>
#include <wx/image.h> 
#include <magicEditor/editors/clientEditors/materialEditor/CMaterialEditor.h>
#include "magicEditor/CEditorCore.h"

using namespace MagicEditor;

class MagicEditorApp : public wxApp
{
public:
	virtual bool OnInit();

private:
	void initWxWidgets();
};

wxIMPLEMENT_APP(MagicEditorApp);

bool MagicEditorApp::OnInit() {
	initWxWidgets();

	//Only one editor for now
	CMaterialEditor* frame = new CMaterialEditor();
	frame->Show(true);

	return true;
}

void MagicEditorApp::initWxWidgets() {
	wxInitAllImageHandlers();
}
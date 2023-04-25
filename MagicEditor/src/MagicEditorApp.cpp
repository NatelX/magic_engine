#include "MagicEditorApp.h"
#include <magicEditor/editors/clientEditors/materialEditor/CMaterialEditor.h>

using namespace MagicEditor;

wxIMPLEMENT_APP(MagicEditorApp);

bool MagicEditorApp::OnInit() {

	m_app = createUniquePtr<MagicEngine::CApplication>(
		MagicApollo::CRendererType::VULKAN, 
		MagicApollo::CRendererDebugger::ENABLED);

	initWxWidgets();

	//Only one editor for now
	CMaterialEditor* frame = new CMaterialEditor();
	frame->Show(true);

	return true;
}

void MagicEditorApp::initWxWidgets() {
	wxInitAllImageHandlers();
}
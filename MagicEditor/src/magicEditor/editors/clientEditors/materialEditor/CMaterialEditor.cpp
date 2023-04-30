#include "CMaterialEditor.h"

#include "panels/CMaterialEditorPanel.h"

namespace MagicEditor
{
	CMaterialEditor::CMaterialEditor() :
		CEditor("Material editor") {
		CMaterialEditorPanel* panel = new CMaterialEditorPanel(this);
	}

	void CMaterialEditor::loadDocument() {
	}
}
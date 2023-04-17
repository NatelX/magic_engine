#include "CEditor.h"

namespace MagicEditor {

	BEGIN_EVENT_TABLE(CEditor, wxFrame)
		EVT_CLOSE(CEditor::onEditorClosing)
	END_EVENT_TABLE()

	CEditor::CEditor(const wxString& editorName) :
		wxFrame(NULL, wxID_ANY, ""), 
		m_modified(false), 
		m_editorName(editorName), 
		m_currentFileName("") {
		this->Maximize(true);
		this->SetMinClientSize(wxSize(800, 600));
		this->CenterOnScreen();
		this->SetTitle(editorName);
	}

	void CEditor::showEditor(const wxFileName& fileName) {
		m_currentFileName = fileName;
		this->Maximize(true);
		this->CenterOnScreen();
		this->Show(true);

		onEditorShow();
	}

	void CEditor::exitEditor() {
	}

	void CEditor::saveDocument() {
	}

	void CEditor::onChange() {
		setModified(true);
	}

	bool CEditor::isModified() const {
		return m_modified;
	}

	void CEditor::setModified(bool modified) {
		m_modified = modified;
		if (m_currentFileName.IsOk()) {
			wxString star = modified ? "*" : "";
			this->SetTitle(m_editorName + " - " + m_currentFileName.GetPath() + star);
		} else {
			this->SetTitle(m_editorName);
		}
	}

	void CEditor::onEditorClosing(wxCloseEvent& event) {
		if (onEditorClose()) {
			exitEditor();
			event.Skip();
			return;
		}

		event.Veto();
	}

	bool CEditor::onEditorClose() const {
		return true;
	}

	void CEditor::onEditorShow() {
	}

	wxFileName CEditor::getFileName() const {
		return m_currentFileName;
	}

	void CEditor::setFileName(const wxFileName& fileName) {
		m_currentFileName = fileName;
	}
}
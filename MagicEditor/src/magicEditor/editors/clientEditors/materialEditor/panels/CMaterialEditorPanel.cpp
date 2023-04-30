#include "CMaterialEditorPanel.h"

namespace MagicEditor {

	CMaterialEditorPanel::CMaterialEditorPanel(
		wxWindow* parentWindow
	) : wxPanel(parentWindow),
		m_auiManager(createUniquePtr<wxAuiManager>()) 
	{
		m_auiManager->SetManagedWindow(this);

		m_graphPanel = createSharedPtr<CMaterialGraphPanel>(this);
		m_graphPanel->SetBackgroundColour(wxColor(0, 255, 255));

		m_auiManager->AddPane(m_graphPanel.get(), wxAuiPaneInfo().Name("graph_panel").Caption("Graph panel").Center().CloseButton(false));

		m_defaultPerspective = m_auiManager->SavePerspective();
		m_auiManager->Update();
	}

}

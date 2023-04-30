#include "CMaterialGraphPanel.h"

namespace MagicEditor {

	wxBEGIN_EVENT_TABLE(CMaterialGraphPanel, wxPanel)
	wxEND_EVENT_TABLE()

	CMaterialGraphPanel::CMaterialGraphPanel(
		wxWindow* parentWindow
	) : ExternalWidgets::CMagicEnginePanel(parentWindow) {
	}

}

#ifndef CMATERIALEDITORPANEL_H
#define CMATERIALEDITORPANEL_H

#include <wx/panel.h>
#include <wx/aui/aui.h>

#include "graphPanel/CMaterialGraphPanel.h"

namespace MagicEditor {

    class CMaterialEditorPanel : public wxPanel {
    protected:
        CUniquePtr<wxAuiManager> m_auiManager;

        CSharedPtr<CMaterialGraphPanel> m_graphPanel;

        wxString m_defaultPerspective;

    public:
        CMaterialEditorPanel(wxWindow* parentWindow);
    };

}

#endif
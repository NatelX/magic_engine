#include "CMagicEnginePanel.h"

#include <wx/sizer.h>
#include "vulkanCanvas/CVulkanCanvas.h"

namespace MagicEditor {
    namespace ExternalWidgets {

        CMagicEnginePanel::CMagicEnginePanel(wxWindow* parentWindow) :
            wxPanel(parentWindow)
        {
            wxBoxSizer* verticalBoxSizer = new wxBoxSizer(wxVERTICAL);
            wxWindow* renderPanel = new CVulkanCanvas(this);
            verticalBoxSizer->Add(renderPanel, 1, wxEXPAND);
            SetSizer(verticalBoxSizer);
            SetAutoLayout(true);
        }
    }
}

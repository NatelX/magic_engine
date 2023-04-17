#include "CMagicEnginePanel.h"

#include <wx/sizer.h>

#include "vulkanCanvas/CVulkanCanvas.h"

namespace WxWidgetsMagicEngine {
    namespace ExternalWidgets {

        CMagicEnginePanel::CMagicEnginePanel(
            wxWindow* parentWindow,
            CMagicEditorRendererType renderType) :
            wxPanel(parentWindow) {

            wxBoxSizer* verticalBoxSizer = new wxBoxSizer(wxVERTICAL);
            wxWindow* renderPanel = obtainRenderPanelByType(parentWindow, renderType);
            verticalBoxSizer->Add(renderPanel, 1, wxEXPAND);
            SetSizer(verticalBoxSizer);
            SetAutoLayout(true);
        }

        wxWindow* CMagicEnginePanel::obtainRenderPanelByType(
            wxWindow* parentWindow,
            CMagicEditorRendererType renderType
        ) {
            if (renderType == VULKAN) {
                return new CVulkanCanvas(parentWindow);
            }
            return nullptr;
        }
    }
}

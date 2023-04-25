#include "CMagicEnginePanel.h"

#include <wx/sizer.h>
#include <magicEngine/core/application/CAppListener.h>
#include "vulkanCanvas/CVulkanCanvas.h"

namespace WxWidgetsMagicEngine {
    namespace ExternalWidgets {

        CMagicEnginePanel::CMagicEnginePanel(
            wxWindow* parentWindow,
            CRendererType renderType,
            CSharedPtr<CAppListener> appListener) :
            wxPanel(parentWindow),
            m_appListener(appListener)
        {
            wxBoxSizer* verticalBoxSizer = new wxBoxSizer(wxVERTICAL);
            wxWindow* renderPanel = obtainRenderPanelByType(parentWindow, renderType, appListener);
            verticalBoxSizer->Add(renderPanel, 1, wxEXPAND);
            SetSizer(verticalBoxSizer);
            SetAutoLayout(true);
        }

        CSharedPtr<CAppListener> CMagicEnginePanel::getAppListener() const {
            return m_appListener;
        }

        wxWindow* CMagicEnginePanel::obtainRenderPanelByType(
            wxWindow* parentWindow,
            CRendererType renderType,
            CSharedPtr<CAppListener> appListener
        ) {
            if (renderType == VULKAN) {
                return new CVulkanCanvas(parentWindow, appListener);
            }
            return nullptr;
        }
    }
}

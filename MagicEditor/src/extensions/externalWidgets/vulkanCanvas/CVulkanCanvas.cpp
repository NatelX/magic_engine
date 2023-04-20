#include "CVulkanCanvas.h"

#include <wx/dcclient.h>
#include <magicEngine/core/application/CAppHandler.h>
#include <magicEngine/core/application/CAppListener.h>

namespace WxWidgetsMagicEngine {
    namespace ExternalWidgets {

        wxBEGIN_EVENT_TABLE(CVulkanCanvas, wxGLCanvas)
            EVT_SIZE(CVulkanCanvas::onResized)
            EVT_IDLE(CVulkanCanvas::onIdle)
        wxEND_EVENT_TABLE()
            
        CVulkanCanvas::CVulkanCanvas(
            wxWindow* parent,
            CSharedPtr<CAppListener> appListener) :
            wxGLCanvas(parent, wxID_ANY, NULL, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE),
            m_appHandler(createSharedPtr<CAppHandler>(appListener))
        {
        }

        CVulkanCanvas::~CVulkanCanvas() {
        }

        void CVulkanCanvas::onPaint() {
            wxClientDC dc(this);
            const wxSize clientSize = GetClientSize() * GetContentScaleFactor();

            m_appHandler->renderLoop();
        }

        void CVulkanCanvas::onResized(wxSizeEvent& event) {
            m_appHandler->resize(event.GetSize().x, event.GetSize().y);
            Refresh(false);
        }

        void CVulkanCanvas::onIdle(wxIdleEvent& event) {
            onPaint();
            event.RequestMore();
        }
    }
}

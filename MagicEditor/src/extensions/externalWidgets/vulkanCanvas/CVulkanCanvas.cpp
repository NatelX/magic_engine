#include "CVulkanCanvas.h"

#include <wx/dcclient.h>

namespace WxWidgetsMagicEngine {
    namespace ExternalWidgets {

        wxBEGIN_EVENT_TABLE(CVulkanCanvas, wxGLCanvas)
            EVT_SIZE(CVulkanCanvas::onResized)
            EVT_IDLE(CVulkanCanvas::onIdle)
        wxEND_EVENT_TABLE()
            
        CVulkanCanvas::CVulkanCanvas(wxWindow* parent) :
            wxGLCanvas(parent, wxID_ANY, NULL, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE) {
        }

        CVulkanCanvas::~CVulkanCanvas() {
        }

        void CVulkanCanvas::onPaint() {
            wxClientDC dc(this);
            const wxSize clientSize = GetClientSize() * GetContentScaleFactor();
        }

        void CVulkanCanvas::onResized(wxSizeEvent& event) {
            Refresh(false);
        }

        void CVulkanCanvas::onIdle(wxIdleEvent& event) {
            onPaint();
            event.RequestMore();
        }
    }
}

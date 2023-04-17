#ifndef CVULKANCANVAS_H
#define CVULKANCANVAS_H

#include <wx/glcanvas.h>

namespace WxWidgetsMagicEngine {
    namespace ExternalWidgets {
        class CVulkanCanvas : public wxGLCanvas {
        protected:

        public:
            CVulkanCanvas(wxWindow* parent);
            ~CVulkanCanvas();

        private:
            void onPaint();
            void onResized(wxSizeEvent& event);
            void onIdle(wxIdleEvent& event);

            wxDECLARE_EVENT_TABLE();
        };
    }
}

#endif
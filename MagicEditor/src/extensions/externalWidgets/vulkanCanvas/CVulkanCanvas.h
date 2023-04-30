#ifndef CVULKANCANVAS_H
#define CVULKANCANVAS_H

#include <wx/window.h>
#include <magicEngine/core/Core.h>

namespace MagicEditor {
    namespace ExternalWidgets {

        class CVulkanCanvas : public wxWindow {
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
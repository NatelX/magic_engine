#ifndef CVULKANCANVAS_H
#define CVULKANCANVAS_H

#include <wx/glcanvas.h>
#include <magicEngine/core/Core.h>

namespace MagicEngine {
    class CAppHandler;
    class CAppListener;
}

using namespace MagicEngine;

namespace WxWidgetsMagicEngine {
    namespace ExternalWidgets {

        class CVulkanCanvas : public wxGLCanvas {
        protected:
            CSharedPtr<CAppHandler> m_appHandler;

        public:
            CVulkanCanvas(wxWindow* parent, CSharedPtr<CAppListener> appListener);
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
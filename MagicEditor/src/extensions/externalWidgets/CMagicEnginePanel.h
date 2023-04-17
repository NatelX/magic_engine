#ifndef CMAGICENGINEPANEL_H
#define CMAGICENGINEPANEL_H

#include <wx/panel.h>

namespace WxWidgetsMagicEngine {
    namespace ExternalWidgets {

        enum CMagicEditorRendererType {
            VULKAN,
            DIRECTX_12,
            OPENGL
        };

        class CMagicEnginePanel : public wxPanel {
        protected:

        public:
            CMagicEnginePanel(
                wxWindow* parentWindow, 
                CMagicEditorRendererType renderType);

        private:
            wxWindow* obtainRenderPanelByType(
                wxWindow* parentWindow, 
                CMagicEditorRendererType renderType);
        };
    }
}

#endif

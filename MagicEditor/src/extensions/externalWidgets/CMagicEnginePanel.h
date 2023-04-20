#ifndef CMAGICENGINEPANEL_H
#define CMAGICENGINEPANEL_H

#include <wx/panel.h>
#include <magicEngine/core/Core.h>

namespace MagicEngine {
    class CAppListener;
}

using namespace MagicEngine;

namespace WxWidgetsMagicEngine {
    namespace ExternalWidgets {

        enum CMagicEditorRendererType {
            VULKAN,
            DIRECTX_12,
            OPENGL_45
        };

        class CMagicEnginePanel : public wxPanel {
        protected:
            CSharedPtr<CAppListener> m_appListener;

        public:
            CMagicEnginePanel(
                wxWindow* parentWindow, 
                CMagicEditorRendererType renderType,
                CSharedPtr<CAppListener> appListener);

            CSharedPtr<CAppListener> getAppListener() const;

        private:
            wxWindow* obtainRenderPanelByType(
                wxWindow* parentWindow, 
                CMagicEditorRendererType renderType,
                CSharedPtr<CAppListener> appListener);
        };
    }
}

#endif

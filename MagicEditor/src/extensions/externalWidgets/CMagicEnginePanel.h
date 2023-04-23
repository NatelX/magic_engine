#ifndef CMAGICENGINEPANEL_H
#define CMAGICENGINEPANEL_H

#include <wx/panel.h>
#include <magicEngine/core/Core.h>
#include <magicApollo/core/devices/CMagicApolloGraphicDevice.h>

namespace MagicEngine {
    class CAppListener;
}

using namespace MagicEngine;
using namespace MagicApollo;

namespace WxWidgetsMagicEngine {
    namespace ExternalWidgets {

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

#ifndef CMAGICENGINEPANEL_H
#define CMAGICENGINEPANEL_H

#include <wx/panel.h>
#include <magicEngine/core/Core.h>

namespace MagicEditor {
    namespace ExternalWidgets {

        class CMagicEnginePanel : public wxPanel {
        public:
            CMagicEnginePanel(wxWindow* parentWindow);
        };

    }
}

#endif

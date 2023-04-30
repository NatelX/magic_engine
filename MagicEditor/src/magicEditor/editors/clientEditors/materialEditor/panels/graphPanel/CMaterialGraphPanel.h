#ifndef CMATERIALGRAPHPANEL_H
#define CMATERIALGRAPHPANEL_H

#include <MagicEngine/core/Core.h>
#include <extensions/externalWidgets/CMagicEnginePanel.h>

namespace MagicEditor {

    class CMaterialGraphPanel : public ExternalWidgets::CMagicEnginePanel {
    public:
        CMaterialGraphPanel(wxWindow* parentWindow);

    private:
        wxDECLARE_EVENT_TABLE();
    };

}

#endif
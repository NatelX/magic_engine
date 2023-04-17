#ifndef CMATERIALEDITOR_H
#define CMATERIALEDITOR_H

#include <magicEditor/editors/CEditor.h>

namespace MagicEditor {
    class CMaterialEditor : public CEditor {
    public:
        CMaterialEditor();

        void loadDocument() override;
    };
}

#endif
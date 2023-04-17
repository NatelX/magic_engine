#ifndef CEDITOR_H
#define CEDITOR_H

#include <wx/frame.h>
#include <wx/filename.h>

namespace MagicEditor {

    class CEditor : public wxFrame {
    protected:
        bool m_modified;
        wxString m_editorName;
        wxFileName m_currentFileName;

    public:
        CEditor(const wxString& editorName);

        void showEditor(const wxFileName& fileName);
        void exitEditor();

        virtual void loadDocument() = 0;
        virtual void saveDocument();

        void onChange();
        bool isModified() const;
        void setModified(bool modified);

        wxFileName getFileName() const;
        void setFileName(const wxFileName& fileName);

    private:
        void onEditorClosing(wxCloseEvent& event);

        DECLARE_EVENT_TABLE()

    protected:
        virtual bool onEditorClose() const;
        virtual void onEditorShow();
    };
}

#endif
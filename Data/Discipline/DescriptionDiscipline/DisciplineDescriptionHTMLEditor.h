#ifndef DISCIPLINEDESCRIPTIONHTMLEDITOR_H
#define DISCIPLINEDESCRIPTIONHTMLEDITOR_H

#include <QString>


////ОДНОЗНАЧНО НЕОБХОДИМ ОБОБЩЕННЫЙ HTML РЕДАКТОР

class DisciplineDescriptionHTMLEditor {

protected:
    QString m_HTML;

    QString m_OldTitle;
    quint32 m_PosTitle;

    QString m_OldDescription;
    quint32 m_PosDescription;

    void refreshPosDescription();

public:
    DisciplineDescriptionHTMLEditor();

    void setTitle( QString title );
    void setDescription( QString description );
    QString &getHTML();
};

#endif // DISCIPLINEDESCRIPTIONHTMLEDITOR_H

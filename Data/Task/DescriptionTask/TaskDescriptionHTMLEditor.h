#ifndef TASKDESCRIPTIONHTMLEDITOR_H
#define TASKDESCRIPTIONHTMLEDITOR_H

#include <Data/Discipline/DescriptionDiscipline/DisciplineDescriptionHTMLEditor.h>

class TaskDescriptionHTMLEditor : public DisciplineDescriptionHTMLEditor {

    quint32 m_PosExplorerButton;
public:
    TaskDescriptionHTMLEditor();

    void addExplorerButton();
};

#endif // TASKDESCRIPTIONHTMLEDITOR_H

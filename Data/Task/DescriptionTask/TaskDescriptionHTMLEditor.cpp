#include "TaskDescriptionHTMLEditor.h"

TaskDescriptionHTMLEditor::TaskDescriptionHTMLEditor()
{
}

void TaskDescriptionHTMLEditor::addExplorerButton() {


    m_HTML.append( "<form><button>Прикрепить файл/проект с решением...</button><input type = \"readonly\"></form>");
}

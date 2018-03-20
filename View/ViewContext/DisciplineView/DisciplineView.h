#ifndef DISCIPLINEVIEW_H
#define DISCIPLINEVIEW_H

#include <View/ViewContext/TreeView.h>
#include <View/DockWidget.h>
#include <View/ViewContext/DynamicSwitchViewContext.h>


class DisciplineView : public TreeView {

public:
    DisciplineView();

    void setModelForView( Model *pModel );
};

#endif // DISCIPLINEVIEW_H

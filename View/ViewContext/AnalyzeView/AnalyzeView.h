#ifndef ANALYZEVIEW_H
#define ANALYZEVIEW_H

#include <View/ViewContext/TreeView.h>
#include <View/DockWidget.h>
#include <View/ViewContext/DynamicSwitchViewContext.h>


class AnalyzeView : public TreeView {

public:
    AnalyzeView();

    void setModelForView( Model *pModel );
};

#endif // ANALYZEVIEW_H

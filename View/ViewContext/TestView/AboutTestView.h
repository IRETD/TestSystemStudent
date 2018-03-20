#ifndef ABOUTTESTVIEW_H
#define ABOUTTESTVIEW_H

#include <View/ViewContext/TreeView.h>
#include <View/ViewContext/DynamicSwitchViewContext.h>

class AboutTestView : public TreeView  {

    QSharedPointer < DynamicSwitchViewContext > m_pDynamicSwitchViewContext;

public:
    AboutTestView( QSharedPointer < DynamicSwitchViewContext > pDynamicSwitchViewContext );
    void setModelForView( Model *pModel );
};

#endif // ABOUTTESTVIEW_H

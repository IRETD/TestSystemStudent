#ifndef SIDE_MENU_VIEW_H
#define SIDE_MENU_VIEW_H

#include <View/ViewContext/ViewContext.h>
#include <QToolBar>
#include <QObject>
#include <View/ViewContext/DynamicSwitchViewContext.h>
#include <View/DockWidget.h>

class SideMenuView : public QToolBar,
                     public ViewContext {

    Q_OBJECT

    QSharedPointer < DynamicSwitchViewContext > m_pDynamicSwitchViewContext;
    QSharedPointer < DockWidget > m_pSideDockWidget;

private slots:
    void menuItemAdded( QAction &action );

public:
    SideMenuView( QSharedPointer < DockWidget > pSideDockWidget,
                  QSharedPointer < DynamicSwitchViewContext > pDynamicSwitchViewContext );
    void setModelForView( Model *pModel );
    QWidget *getViewWidget();

};

#endif

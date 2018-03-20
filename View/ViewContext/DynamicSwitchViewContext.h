#ifndef DYNAMIC_SWITCH_VIEW_CONTEXT_H
#define DYNAMIC_SWITCH_VIEW_CONTEXT_H

#include <QStackedWidget>
#include <Enum/View/ViewContext/ViewContextType.h>
#include <View/ViewContext/ViewContext.h>
#include <QHash>
#include <View/DockWidget.h>

class ViewContext;

class DynamicSwitchViewContext : public QStackedWidget {

    Q_OBJECT

    QHash < ViewContextType,
            ViewContext* > m_ViewTable;

    QSharedPointer < QWidget > m_DefaultWidget;

    //ссылка на док виджет, на который повешен данны сменщик контекста!
    QSharedPointer < DockWidget > m_pDockWidget;
public:
    DynamicSwitchViewContext( QSharedPointer < DockWidget > pDockWidget );

    void addView( const ViewContextType &viewContextType,
                  ViewContext *pView );

public slots:
    void setCurrentView( const ViewContextType &viewContexType );
};

#endif

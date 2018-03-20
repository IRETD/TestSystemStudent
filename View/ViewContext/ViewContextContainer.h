#ifndef VIEW_CONTEXT_CONTAINER_H
#define VIEW_CONTEXT_CONTAINER_H


/*
 * Класс контейнер (хранилище) виджетов имеющихся в расположении у текущего окна.
 * Класс несет в себе задачу укомплектовать описание и инициализацию всех виджетов.
 * Тем сама в разу сокращается конечный код описания окна, а все виджет сконцентрированы в одном объекте.
 * Окно в праве обратиться к нужному виджету по соотв. методу, с указанием имени нужно виджета.
 * ViewContext - это концепция отображения внутри другого отображения, где исходным отображение
 * явялется окно, а его контекст это все виджеты которые имеются в расположении этого окна.
 *
*/


#include <Enum/View/ViewContext/ViewContextType.h>
#include <QHash>
#include <View/ViewContext/ViewContext.h>
#include "ViewContextFactory.h"
#include <View/ViewContext/DynamicSwitchViewContext.h>
#include <View/DockWidget.h>

class DynamicSwitchViewContext;

class ViewContextContainer : public QObject {

    Q_OBJECT

    QHash < ViewContextType,
            ViewContext* > m_ViewContextTable;
    ViewContextFactory m_FactoryViewContext;

    Model *m_pModel;
    QSharedPointer < DynamicSwitchViewContext > m_pSideViewContextSwitch;
    QSharedPointer < DockWidget > m_pCentralDockWidget;
    QSharedPointer < DynamicSwitchViewContext > m_pCentralViewContextSwitch;

    ViewContext *createViewContext( ViewContextType viewContextType );

signals:
    void viewContextIsReadyForShow( ViewContextType &viewContextType );

public:
    ViewContextContainer( Model *pModel,
                          QSharedPointer < DynamicSwitchViewContext > pSideViewContextSwitch,
                          QSharedPointer < DockWidget > pCentralDockWidget,
                          QSharedPointer < DynamicSwitchViewContext > pCentralViewContextSwitch );

    void createView( const ViewContextType &viewContextType );
    ViewContext* getView( const ViewContextType &viewContextType );
    void createConnectionsForAllViewContext();
    void setModelForAllViewContext();
};

#endif

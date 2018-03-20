#include "SideMenuView.h"
#include <Enum/View/ViewContext/SideMenuView/SideMenuIconParameters.h>
#include <Model/BaseModel/PureBaseModel/ModelByQActionItem.h>

/*
 * СЛОТ
 * срабатывает при поступлении сигнала от модели MenuModel
 * сигнал передает ссылку на элемент меню (в данном случае это QAction)
 *
*/
void SideMenuView::menuItemAdded( QAction &action ) {

    addAction( &action );
}


SideMenuView::SideMenuView( QSharedPointer < DockWidget > pSideDockWidget,
                            QSharedPointer < DynamicSwitchViewContext > pDynamicSwitchViewContext ) : ViewContext( ViewContextType::SIDE_MENU_VIEW_CONTEXT ) {

    setIconSize( QSize( SideMenuIconParametes::WIDTH,
                        SideMenuIconParametes::HEIGHT ) );
    setToolButtonStyle( Qt::ToolButtonTextUnderIcon );

    m_pSideDockWidget = pSideDockWidget;
    m_pDynamicSwitchViewContext = pDynamicSwitchViewContext;
}


/*
 * Основная задача соединения с моделью
 * это соединиться с сигналом menuItemIsAdded у модели MenuModel
 * чтобы в последующем получать все изменения в модели через этот сигнал
 * и отображать эти изменения на отображении
 *
*/
void SideMenuView::setModelForView( Model *pModel ) {

//соединяемся с моделью, будем ждать сигнала о добавлении элемента меню
    QSharedPointer < ModelByQActionItem > pMenuModel = pModel -> getMenuModel();
    connect( pMenuModel.data(),
             &ModelByQActionItem::sendMenuItem,
             this,
             &SideMenuView::menuItemAdded );
    //вызываем пока что просто, как метод :)
    pMenuModel -> sendAllDataBySignal();

    connect( this,
             &SideMenuView::actionTriggered,
             pMenuModel.data(),
             &ModelByQActionItem::modelItemSelected );

    connect( pMenuModel.data(),
             &ModelByQActionItem::showViewContextType,
             m_pDynamicSwitchViewContext.data(),
             &DynamicSwitchViewContext::setCurrentView );

    connect( m_pSideDockWidget.data(),
             &DockWidget::dockWidgetIsClosed,
             pMenuModel.data(),
             &ModelByQActionItem::currentModelItemIsInActive );
}


QWidget *SideMenuView::getViewWidget() {

    return this;
}

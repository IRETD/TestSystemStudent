#include "MenuModule.h"
#include <Model/BaseModel/PureBaseModel/ModelByQActionItem.h>

QSharedPointer < DataItemModelForModelByQActionItem > MenuModule::initializeNewData( int idMenu,
                                                                                     QString title,
                                                                                     ViewContextType viewContextType ) {

    QSharedPointer < DataItemModelForModelByQActionItem > pData ( new DataItemModelForModelByQActionItem( idMenu,
                                                                                                          title,
                                                                                                          viewContextType) );

    return pData;
}


void MenuModule::updateTitle( int idMenu,
                              QString title,
                              ViewContextType viewContext ) {

    QSharedPointer < DataItemModelForModelByQActionItem > pData = initializeNewData( idMenu,
                                                                                     title,
                                                                                     viewContext );
    m_pMenuModel.data() -> updateItemInModel( pData );
}


void MenuModule::addMenu( Menu &menu ) {

    int idMenu = menu.getId();
    QSharedPointer < DataItemModelForModelByQActionItem > pData = initializeNewData( idMenu,
                                                                                     menu.getTitle(),
                                                                                     menu.getViewContextType() );
    addNewItem( m_pMenuModel,
                pData );
}


MenuModule::MenuModule( QSharedPointer < IconItemManager > pIconItemManager,
                        QSharedPointer < NotificationManager > pNotificationManager ) : BaseModule( pIconItemManager,
                                                                                                    pNotificationManager ) {

    //иницилизируем меню по умолчанию

    m_pMenuModel = QSharedPointer < ModelByQActionItem > ( new ModelByQActionItem ( TypeModel::MENU_TYPE_MODEL ) );

    Menu menu;
    QString title;

    title = "Дисциплины";
    menu.setTitle( title );
    menu.setId( TypeMenu::DISCIPLINE_MENU_ITEM );
    menu.setViewContextType( ViewContextType::DISCIPLINE_VIEW_CONTEXT );
    addMenu( menu );

    title = "Тесты";
    menu.setTitle( title );
    menu.setId( TypeMenu::TEST_MENU_ITEM );
    menu.setViewContextType( ViewContextType::TEST_VIEW_CONTEXT );
    addMenu( menu );

    title = "Анализ";
    menu.setTitle( title );
    menu.setId( TypeMenu::ANALYZE_MENU_ITEM );
    menu.setViewContextType( ViewContextType::ANALYZE_VIEW_CONTEXT );
    addMenu( menu );

    title = "Прикрепить...";
    menu.setTitle( title );
    menu.setId( TypeMenu::ATTACH_PROJECT_MENU_ITEM );
    menu.setViewContextType( ViewContextType::ATTACH_PROJECT_VIEW_CONTEXT );
    addMenu( menu );

    title = "Отправить";
    menu.setTitle( title );
    menu.setId( TypeMenu::RUN_PROJECT_MENU_ITEM );
    menu.setViewContextType( ViewContextType::RUN_PROJECT_VIEW_CONTEXT );
    addMenu( menu );
}


void MenuModule::addData( QSharedPointer < DataForMenuModule > pData ) {


}

QSharedPointer < ModelByQActionItem > MenuModule::getMenuModel() {

    return m_pMenuModel;
}

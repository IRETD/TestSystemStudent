#include "ModelByQActionItem.h"
#include <MacroDefinitons/MyMacroDefinitions.h>
#include <Model/BaseModel/DataItemModel/PureBaseModel/DataItemModelForModelByQActionItem.h>
#include <Enum/Model/MenuModel/MenuModelConstants.h>


void ModelByQActionItem::checkForSpecificSignals( TypeMenu typeMenu ) {

    //извещаем модель прикрепления проекта
    if ( typeMenu == TypeMenu::ATTACH_PROJECT_MENU_ITEM ) {

        emit attachProjectSelected();
    }

    if ( typeMenu == TypeMenu::RUN_PROJECT_MENU_ITEM ) {

        emit runProjectSelected();
    }

    if ( typeMenu == TypeMenu::TEST_MENU_ITEM ) {

        emit testSelected();
    }
}

ModelByQActionItem::ModelByQActionItem ( TypeModel typeModel ) : BaseModel( typeModel,
                                                                            ModelItemDescriptorType::MODEL_BY_QACTION_ITEM_DESCRIPTOR ) {

     m_IdLastActiveItem = NO_ITEM_AS_LAST_ACTIVED;
}


void ModelByQActionItem::addItemInModel( QSharedPointer < AbstractDataItemModel > pItemData ) {


    QSharedPointer < DataItemModelForModelByQActionItem > pItemDataForModelByQActionItem =
            pItemData.staticCast < DataItemModelForModelByQActionItem >();
    assert( !pItemDataForModelByQActionItem.isNull() );

    QSharedPointer < QAction > pAction ( nullptr );
    int idItem = pItemDataForModelByQActionItem.data() -> getIdItem();
    ViewContextType viewContextType = pItemDataForModelByQActionItem.data() -> getViewContextType();
    if ( m_IdMenuContainer.isContain( idItem ) ) {

        pAction = m_IdMenuContainer.getValue( idItem );
    }
    else {
        pAction = QSharedPointer < QAction > ( new QAction( nullptr ) );
        m_IdMenuContainer.addValue( idItem,
                                    pAction );
        m_MenuIdContainer.addValue( pAction.data(),
                                    idItem );
        m_IdViewContextType.addValue( idItem,
                                      viewContextType );
    }

    QString text = pItemDataForModelByQActionItem.data() -> getTitle();
    pAction.data() -> setText( text );

    /*QIcon *pIcon = itemDataForModelByQActionItem -> getIcon();
    if ( pIcon != nullptr ) {

        pAction -> setIcon( READ_POINTER pIcon );
    }*/

    emit sendMenuItem( READ_POINTER pAction.data() );
}


void ModelByQActionItem::updateItemInModel( QSharedPointer < AbstractDataItemModel > pItemData) {

    ///реализовать обновление!!!
}


void ModelByQActionItem::changeIconIntoItem( int idItem,
                                             QIcon *pIcon ) {

    if ( m_IdMenuContainer.isContain( idItem ) ) {

        QSharedPointer < QAction > pAction = m_IdMenuContainer.getValue( idItem );
        pAction.data() -> setIcon( READ_POINTER pIcon );
    }
}


void ModelByQActionItem::clearItemsInModel() {

    //потом реализую удаление :)
}


void ModelByQActionItem::sendAllDataBySignal() {


    QList < int > listDataItem = m_IdMenuContainer.getKeys();
    for ( int i = 0; i < listDataItem.size(); i++ ) {

        emit sendMenuItem( READ_POINTER m_IdMenuContainer.getValue( listDataItem.at( i ) ).data() );
    }
}


void ModelByQActionItem::setEnableStatus( int idItem,
                                          bool status ) {

    m_IdMenuContainer.getValue( idItem ).data() -> setEnabled( status );
}


void ModelByQActionItem::modelItemSelected( QAction *action ) {

    //обрабатываем нажатие пункта меню

    QSharedPointer < ModelByQActionItemDescriptor > descriptor( nullptr );
    if ( m_IdLastActiveItem != NO_ITEM_AS_LAST_ACTIVED ) {

         descriptor = m_ModelItemDescriptorContainer.getModelByQActionItemDescriptor( m_IdLastActiveItem );
         //говорим о том, что прошлый активный элемент больше неактивен
         if ( !descriptor.isNull() ) {
            descriptor.data() -> setActiveStatus( false );
         }
    }

    //QSharedPointer < QAction > pAction( action );
    int idItem = m_MenuIdContainer.getValue( action );
    //pAction = m_IdMenuContainer.getValue( idItem );
    descriptor = m_ModelItemDescriptorContainer.getModelByQActionItemDescriptor( idItem );

    if ( !descriptor.isNull() ) {

        descriptor.data() -> setActiveStatus( true );
    }

    m_IdLastActiveItem = idItem;

    //устанавливаем активным ТЕКУЩИЙ дескриптор
    setActiveModelItemDescriptor( descriptor );

    //просим отобразить соотв. контекст представления
    ViewContextType viewContextType = m_IdViewContextType.getValue( idItem );
    emit showViewContextType( viewContextType );

    //отправка другим моделям, если кто знать хочет
    TypeMenu typeMenu = static_cast < TypeMenu > ( idItem );

    checkForSpecificSignals( typeMenu );
}


void ModelByQActionItem::currentModelItemIsInActive() {

    QSharedPointer < ModelByQActionItemDescriptor > pDescriptor = getActiveModelItemDescriptor().
                                                                  staticCast < ModelByQActionItemDescriptor > ();
    if ( !pDescriptor.isNull() ) {

        pDescriptor.data() -> setActiveStatus( false );
    }
}

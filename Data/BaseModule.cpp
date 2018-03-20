#include "BaseModule.h"


BaseModule::BaseModule( QSharedPointer < IconItemManager > pIconItemManager,
                        QSharedPointer < NotificationManager > pNotificationManager ) {

    m_pIconItemManager = pIconItemManager;
    m_pNotificationManager = pNotificationManager;
}


void BaseModule::addNewItem( QSharedPointer < BaseModel > pBaseModel,
                             QSharedPointer < AbstractDataItemModel > pData,
                             QSharedPointer < ModelItemDescriptor > pParent ) {

    //Добавление элемента во всех моделях - схожий процесс
    //Добавляем сам элемент в модель
    pBaseModel.data() -> addItemInModel( pData );
    int idItem = pData.data() -> getIdItem();
    //инициализируем дескриптор
    pBaseModel.data() -> addModelItemDescritor( idItem,
                                                pParent );
    //инициализируем иконку
    QSharedPointer < ModelItemDescriptor > pDescriptor = pBaseModel.data() -> getModelItemDescriptor( idItem );
    m_pIconItemManager.data() -> setItemIcon( pDescriptor,
                                              IconStatus::DEFAULT_ICON_STATUS,
                                              IconSetReason::FOREVER_SET_REASON );

    //т.о. задача наследованных классов попросту подготовить данные
    // и передать указатель на модель
}


void BaseModule::addNewItemWithoutIconManager( QSharedPointer < BaseModel > pBaseModel,
                                               QSharedPointer < AbstractDataItemModel > pData,
                                               QSharedPointer < ModelItemDescriptor > pParent ) {

    //Добавление элемента во всех моделях - схожий процесс
    //Добавляем сам элемент в модель
    pBaseModel.data() -> addItemInModel( pData );
    int idItem = pData.data() -> getIdItem();
    //инициализируем дескриптор
    pBaseModel.data() -> addModelItemDescritor( idItem,
                                                pParent );
    //инициализируем иконку
}

void BaseModule::clear( QSharedPointer < BaseModel > pBaseModel ) {

}



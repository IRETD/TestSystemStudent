#include "NotificationAlgorithm.h"


NotificationAlgorithm::NotificationAlgorithm( QSharedPointer < IconItemManager > pIconItemManager ) {

    m_pIconItemManager = pIconItemManager;
}


void NotificationAlgorithm::addNotification( NotificationType notificationType,
                                             QSharedPointer < ModelItemDescriptor > pModelItemDescriptor ) {

    m_NotificationTypeQueue.addDescriptorToNotification( notificationType,
                                                         pModelItemDescriptor );
    //устанавливаем флаг в FALSE - т.о., убеждаемся, что флаг будет установлен уже в КОНКРЕТНО момент оповещения
    //и никак иначе

    connect( pModelItemDescriptor.data(),
             &ModelItemDescriptor::sendModelItemDescriptorEvent,
             this,
             &NotificationAlgorithm::getModelItemDescriptorEvent,
             Qt::UniqueConnection
           );
}


//Возвращаем истину, если есть что оповещать
bool NotificationAlgorithm::isThereSomethingForUpdate() {

    return !m_NotificationTypeQueue.isEmpty();
}


void NotificationAlgorithm::getModelItemDescriptorEvent( ModelItemDescriptorEvent event,
                                                         ModelItemDescriptor *const pDescriptor ) {

    m_NotificationTypeQueue.removeDescriptorFromNotification( event,
                                                              pDescriptor );
}

#include "NotificationTypeQueue.h"

QList < NotificationType > NotificationTypeQueue::getNotificationsByEvent( ModelItemDescriptorEvent descriptorEvent ) {

    QList < NotificationType > result;

    if ( descriptorEvent == ModelItemDescriptorEvent::STOP_NOTIFICATION_ITEM_AS_PARENT ) {

        result = { NotificationType::CHILD_ITEM_IS_UPDATED };
    }
    else {

        if ( descriptorEvent == ModelItemDescriptorEvent::STOP_NOTIFICATION_ITEM_AS_PERSONAL ) {

            result = { NotificationType::ITEM_IS_NEW,
                       NotificationType::ITEM_IS_UPDATED };
        }
    }

    return result;
}


ModelItemDescriptorEvent NotificationTypeQueue::getEventByNotificationType( NotificationType notificationType ) {

    return ( notificationType == NotificationType::ITEM_IS_UPDATED ||
             notificationType == NotificationType::ITEM_IS_NEW ) ? ModelItemDescriptorEvent::STOP_NOTIFICATION_ITEM_AS_PERSONAL :
                                                                   ModelItemDescriptorEvent::STOP_NOTIFICATION_ITEM_AS_PARENT;
}


void NotificationTypeQueue::removeFromNotificationList( QList < QSharedPointer < ModelItemDescriptor > > &notificationList,
                                                        ModelItemDescriptor *const pDescriptor) {

    foreach( auto elem, notificationList ) {

        if ( elem == pDescriptor ) {

            notificationList.removeOne( elem );
            break;
        }
    }
}

NotificationTypeQueue::NotificationTypeQueue() {

    m_CurrentNotificationType = NotificationType::NONE;
    m_IndexCurrentNotificationType = 0;
    m_NotificationTypeQueue.push_back( m_CurrentNotificationType );
}


void NotificationTypeQueue::addDescriptorToNotification( NotificationType notificationType,
                                                         QSharedPointer < ModelItemDescriptor > &pDescriptor ) {

    ////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    ///
    if ( !m_NotificationQueue[ notificationType ].contains( pDescriptor ) ) {

        m_NotificationQueue[ notificationType ].push_back( pDescriptor );

        ModelItemDescriptorEvent descriptorEvent = getEventByNotificationType( notificationType );
        if ( descriptorEvent == ModelItemDescriptorEvent::STOP_NOTIFICATION_ITEM_AS_PARENT ) {

            pDescriptor.data() -> setStopNotificationAsForParent( false );
        }
        else {

            if ( descriptorEvent == ModelItemDescriptorEvent::STOP_NOTIFICATION_ITEM_AS_PERSONAL ) {

                pDescriptor.data() -> setStopNotificationAsForPersonal( false );
            }
        }
        if ( m_CurrentNotificationType == NotificationType::NONE ) {

            //устанавливаем добавленное оповещение как текущее,
            //т.к. до сего оповещения - другого не было
            m_CurrentNotificationType = notificationType;
        }

        //если такого оповещения еще не было - добавляем его в список существующих
        if ( !m_NotificationTypeQueue.contains( notificationType ) ) {

            m_NotificationTypeQueue.push_back( notificationType );
        }
    }
}


NotificationType NotificationTypeQueue::getCurrentNotificationType() {

    return m_CurrentNotificationType;
}


NotificationType NotificationTypeQueue::getNextNotificationType() {

    //увеличиваем текущий индекс
    m_IndexCurrentNotificationType++;
    //если дошли до размера типа оповещения - возвращаемся назад
    if ( m_NotificationTypeQueue.size() <= m_IndexCurrentNotificationType ) {

        m_IndexCurrentNotificationType = 0;
    }

    m_CurrentNotificationType = m_NotificationTypeQueue[ m_IndexCurrentNotificationType ];

    return m_CurrentNotificationType;
}


QList < QSharedPointer < ModelItemDescriptor > > NotificationTypeQueue::getDescriptorsByNotificationType( NotificationType notificationType ) {

    QList < QSharedPointer < ModelItemDescriptor > > result;

    if ( m_NotificationQueue.contains( notificationType ) ) {

        result = m_NotificationQueue[ notificationType ];
    }

    return result;
}


void NotificationTypeQueue::removeDescriptorFromNotification( NotificationType notificationType,
                                                              ModelItemDescriptor * const pDescriptor ) {


    if ( m_NotificationQueue.contains( notificationType ) ) {

        QList < QSharedPointer < ModelItemDescriptor > > &pDescriptorList = m_NotificationQueue[ notificationType ];
        removeFromNotificationList( pDescriptorList,
                                    pDescriptor );
        //если после удаления список стал пустым
        if ( pDescriptorList.isEmpty() ) {
            //удаляем сам список элементов для оповещения и привязанный к ним тип самого оповещения
            m_NotificationQueue.remove( notificationType );
            int notificationIdex = m_NotificationTypeQueue.indexOf( notificationType );
            //удаляем тип оповещения из списка оповещений
            m_NotificationTypeQueue.remove( notificationIdex );
            //если удалили элемент из списка оповещений, то индекс также необходим уменьшить
            //чтобы мы не проскочили следующий за удаленным тип оповещения после удаления
            if ( m_IndexCurrentNotificationType > 0 ) {

                m_IndexCurrentNotificationType--;
            }
        }
    }
}


void NotificationTypeQueue::removeDescriptorFromNotification( ModelItemDescriptorEvent descriptorEvent,
                                                              ModelItemDescriptor *const pDescriptor ) {

    QList < NotificationType > notificationList = getNotificationsByEvent( descriptorEvent );
    foreach( auto &notificationType, notificationList ) {

        removeDescriptorFromNotification( notificationType,
                                          pDescriptor );
    }
}


bool NotificationTypeQueue::isEmpty() {

    return m_NotificationTypeQueue.isEmpty();
}

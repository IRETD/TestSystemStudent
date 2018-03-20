#ifndef NOTIFICATIONTYPEQUEUE_H
#define NOTIFICATIONTYPEQUEUE_H

#include <Enum/Model/Notification/NotificationType.h>
#include <QList>
#include <MyStorageType/SingleKeyContainer.h>
#include <Model/ModelItemDescriptor/ModelItemDescriptor.h>
#include <QVector>

class NotificationTypeQueue {

    //список СУЩЕСТВУЮЩИХ В ДАННЫЙ МОМЕНТ ТИПОВ ОПОВЕЩЕНИЙ
    QVector < NotificationType > m_NotificationTypeQueue;
    //ТЕКУЩИЙ ИНДЕКС ВЕКТОРА ОПОВЕЩЕНИЙ.
    //А ПО СВОЕЙ СУТИ, ПОСЛЕДНИЙ ЗАПРОШЕННЫЙ ПО МЕТОДУ getNext ТИП ОПОВЕЩЕНИЯ
    quint32 m_IndexCurrentNotificationType;

    QHash < NotificationType,
            QList < QSharedPointer < ModelItemDescriptor > > > m_NotificationQueue;

    NotificationType m_CurrentNotificationType;


    //является ли заданный тип оповещения ПЕРСОНАЛЬНЫМ для элемента
    QList < NotificationType > getNotificationsByEvent( ModelItemDescriptorEvent descriptorEvent );
    ModelItemDescriptorEvent getEventByNotificationType( NotificationType notificationType );

    void removeFromNotificationList( QList<QSharedPointer<ModelItemDescriptor> > &notificationList,
                                     ModelItemDescriptor *const pDescriptor );

public:
    NotificationTypeQueue();
    void addDescriptorToNotification( NotificationType notificationType,
                                      QSharedPointer < ModelItemDescriptor > &pDescriptor );
    NotificationType getCurrentNotificationType();
    NotificationType getNextNotificationType();
    QList < QSharedPointer < ModelItemDescriptor > > getDescriptorsByNotificationType( NotificationType notificationType );
    void removeDescriptorFromNotification( NotificationType notificationType,
                                           ModelItemDescriptor *const pDescriptor );
    void removeDescriptorFromNotification( ModelItemDescriptorEvent descriptorEvent,
                                           ModelItemDescriptor *const pDescriptor );

    bool isEmpty();
};

#endif // NOTIFICATIONTYPEQUEUE_H

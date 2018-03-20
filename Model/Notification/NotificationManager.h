#ifndef NOTIFICATIONQUEUE_H
#define NOTIFICATIONQUEUE_H

#include <Data/Icon/IconBuffer.h>
#include <QPersistentModelIndex>
#include <Model/BaseModel/BaseModel.h>
#include <Model/ModelItemDescriptor/ModelItemDescriptor.h>
#include <Model/Notification/NotificationTypeQueue.h>
#include <QTimer>
#include <MyStorageType/SingleKeyContainer.h>
#include <Model/Notification/NotificationAlgorithm/NotificationAlgorithm.h>

//ЗАДАЕТ АЛГОРИТМ ОПОВЕЩЕНИЯ
// И АКТИВИРУЕТ ЕГО В МОМЕНТ НАСТУПЛЕНИЯ ОПОВЕЩЕНИЯ ПО СВОЕМУ ВНУТРЕННЕМУ ТАЙМЕРУ

class NotificationManager : public QObject {

    Q_OBJECT

    QTimer m_Timer;
    int m_IntervalTimer;
    QSharedPointer < NotificationAlgorithm > m_pNotificationAlgorithm;
    // id элемента и модель в которой он находится
    // id элементов из разных моделей могут совпадать!!!
    //QMultiHash < int, BaseModel* > m_NotificationManager;
    //тип этого элемента, так как модель может быть более чем одноуровневая

private slots:
    void timerIsUp();

public:

    NotificationManager( QSharedPointer < IconItemManager > pIconItemManager );

    //добавляем элемент модели в список оповещения
    void addNotification( NotificationType notificationType,
                          QSharedPointer < ModelItemDescriptor > pModelItemDescriptor );

};

#endif

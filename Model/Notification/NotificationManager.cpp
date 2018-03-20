#include "NotificationManager.h"
#include <assert.h>
#include <Model/Notification/NotificationAlgorithm/NotificationStepByStep.h>
///ЗДЕСЬ ОСТАНОВИЛСЯ
/// 22.10.2015 01:42
void NotificationManager::timerIsUp() {

    if ( m_pNotificationAlgorithm -> isThereSomethingForUpdate() ) {
        //если еще есть что обновлять - ДЕЛАЕМ
        //перед каждой итерацией оповещения подготовливаем работу алгоритма
        m_pNotificationAlgorithm -> prepareAlgortihm();
        m_pNotificationAlgorithm -> doNextStepOfNotification();
    }
    else {
        //закончились элементы для ОПОВЕЩЕНИЯ
        //ПРИОСТАНАВЛИВАЕМ ТАЙМЕР
        m_Timer.stop();
    }
}


NotificationManager::NotificationManager( QSharedPointer < IconItemManager > pIconItemManager ) {

    connect( &m_Timer,
             &QTimer::timeout,
             this,
             &NotificationManager::timerIsUp );

    m_IntervalTimer = 1000;

    //m_ListOfNotificationType.clear();
    //m_ItOfLastNotification = nullptr;

    /// 22.10.2015 01:42
    //иницаилизируем нашу очередь изначальную
    /*m_NotificationQueue.resize( COUNT_OF_NOTIFICATION_TYPE );

    m_NotificationQueue[ NotificationType::NONE ] = QList < NotificationItem* >();
    m_NotificationQueue[ NotificationType::CHILD_ITEM_IS_UPDATED ] = QList < NotificationItem* >();
    m_NotificationQueue[ NotificationType::ITEM_IS_UPDATED ] = QList < NotificationItem* >();
    m_NotificationQueue[ NotificationType::ITEM_IS_NEW ] = QList < NotificationItem* >();

*/
   m_pNotificationAlgorithm = QSharedPointer < NotificationStepByStep > ( new NotificationStepByStep( pIconItemManager ) );
}


void NotificationManager::addNotification( NotificationType notificationType,
                                           QSharedPointer < ModelItemDescriptor > pModelItemDescriptor ) {

    assert( m_pNotificationAlgorithm != nullptr );
/*
    m_pNotificationAlgorithm -> addNotification( notificationType,
                                                 pModelItemDescriptor );

    if ( !m_Timer.isActive() ) {

        m_Timer.start( m_IntervalTimer );
    }
    */
}



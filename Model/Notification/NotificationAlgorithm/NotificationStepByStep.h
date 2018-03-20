#ifndef NOTIFICATIONSTEPBYSTEP_H
#define NOTIFICATIONSTEPBYSTEP_H

#include <Model/Notification/NotificationAlgorithm/NotificationAlgorithm.h>

/*
 *
 * Описывает алгоритм оповещения шаг за шагом.
 * Каждый ТИП оповещения проходит последовательно!
 * Т.е. например, сперва пойдут оповещения только о новых элементах
 * затем об обновившихся
 * после обновившиеся дети и т.п.
 */

class NotificationStepByStep : public NotificationAlgorithm {

    NotificationType m_CurrentNotificationStep;
    QList < QSharedPointer < ModelItemDescriptor > > m_CurrentNotificationList;


public:
    NotificationStepByStep( QSharedPointer < IconItemManager > pIconItemManager );

    virtual void doNextStepOfNotification();
    virtual void prepareAlgortihm();
};

#endif // NOTIFICATIONSTEPBYSTEP_H

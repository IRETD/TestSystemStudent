#ifndef NOTIFICATIONMODULE_H
#define NOTIFICATIONMODULE_H

#include <Model/Notification/NotificationManager.h>

class NotificationModule {

    QSharedPointer < NotificationManager > m_pNotificationManager;
public:
    NotificationModule( QSharedPointer < IconItemManager > pIconItemManager );

    QSharedPointer < NotificationManager > getNotificationManager();
};

#endif // NOTIFICATIONMODULE_H

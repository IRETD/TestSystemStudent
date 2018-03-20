#include "NotificationModule.h"


NotificationModule::NotificationModule( QSharedPointer < IconItemManager > pIconItemManager ) {

    m_pNotificationManager = QSharedPointer < NotificationManager >( new NotificationManager( pIconItemManager ) );
}


QSharedPointer < NotificationManager > NotificationModule::getNotificationManager() {

    return m_pNotificationManager;
}

#include "NotificationTimer.h"

void NotificationTimer::setLightOnStatus() {

    emit notificationSignal( m_LightOn );
    m_LightOn = ( m_LightOn == true ) ? false : true;
}

NotificationTimer::NotificationTimer() {

    //магическое число!!!!
    //убрать!!!!
    m_Interval = 1000;
    m_LightOn = true;
    connect( &m_Timer, &QTimer::timeout, this, &NotificationTimer::setLightOnStatus );
}

void NotificationTimer::startNotifications() {


    m_Timer.start( m_Interval );
}

void NotificationTimer::stopNotifications() {

    m_Timer.stop();
    m_LightOn = false;
    emit notificationSignal( m_LightOn );
}

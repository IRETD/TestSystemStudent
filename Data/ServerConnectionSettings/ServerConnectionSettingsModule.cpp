#include "ServerConnectionSettingsModule.h"


ServerConnectionSettingsModule::ServerConnectionSettingsModule() {

    //TEST INITIALIZED DATA
    m_ServerConnectionSettings.setHostAddress( "localhost" );
    m_ServerConnectionSettings.setHostPort( 1500 );
    m_ServerConnectionSettings.setLogin( "stud" );
    m_ServerConnectionSettings.setPassword( "123" );
}


void ServerConnectionSettingsModule::addData( QSharedPointer < ServerConnectionSettings > pServerConnectionSettings) {

    m_ServerConnectionSettings = *pServerConnectionSettings.data();
}


ServerConnectionSettings ServerConnectionSettingsModule::getServerConnectionSetting() {

    return m_ServerConnectionSettings;
}


void ServerConnectionSettingsModule::setServerConnectionSettings( ServerConnectionSettings serverConnectionSettings ) {

    m_ServerConnectionSettings = serverConnectionSettings;
}

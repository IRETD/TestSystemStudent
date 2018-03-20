#include "ServerConnectionSettings.h"

ServerConnectionSettings::ServerConnectionSettings() {

    m_ConnectionStatus = false;
    m_AuthorizedStatus = AuthResult::AUTHORIZATION_FAULT;
}


void ServerConnectionSettings::setLogin(QString login) {

    m_Login = login;
}


void ServerConnectionSettings::setPassword(QString password) {

    m_Password = password;
}


void ServerConnectionSettings::setHostAddress(QString hostAddress) {

    m_HostAddress = hostAddress;
}


void ServerConnectionSettings::setHostPort(quint32 hostPort) {

    m_HostPort = hostPort;
}


QString ServerConnectionSettings::getLogin() {

    return m_Login;
}


QString ServerConnectionSettings::getPassword() {

    return m_Password;
}


QString ServerConnectionSettings::getHostAddress() {

    return m_HostAddress;
}


quint32 ServerConnectionSettings::getHostPort() {

    return m_HostPort;
}


void ServerConnectionSettings::setConnectionStatus( bool connectionStatus ) {

    m_ConnectionStatus = connectionStatus;
}

void ServerConnectionSettings::setAuthorizedStatus( AuthResult authorizedStatus ) {

    m_AuthorizedStatus = authorizedStatus;
}


bool ServerConnectionSettings::getConnectionStatus() {

    return m_ConnectionStatus;
}


AuthResult ServerConnectionSettings::getAuthorizedStatus() {

    return m_AuthorizedStatus;
}


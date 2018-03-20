#ifndef SERVERCONNECTIONSETTINGS_H
#define SERVERCONNECTIONSETTINGS_H

#include <QString>
#include "../../../../Diplom/TestSystem/TestSystem/MacroDefinitions/Request/Client/AuthResult.h"

class ServerConnectionSettings {

    QString m_Login;
    QString m_Password;
    QString m_HostAddress;
    quint32 m_HostPort;
    bool m_ConnectionStatus;
    AuthResult m_AuthorizedStatus;

public:
    ServerConnectionSettings();

    void setLogin( QString login );
    void setPassword( QString password );
    void setHostAddress( QString hostAddress );
    void setHostPort( quint32 hostPort );
    void setConnectionStatus( bool connectionStatus );
    void setAuthorizedStatus( AuthResult authorizedStatus );

    QString getLogin();
    QString getPassword();
    QString getHostAddress();
    quint32 getHostPort();
    bool getConnectionStatus();
    AuthResult getAuthorizedStatus();
};

#endif

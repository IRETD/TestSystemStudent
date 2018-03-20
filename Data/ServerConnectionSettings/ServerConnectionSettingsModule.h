#ifndef SERVERCONNECTIONSETTINGSMODULE_H
#define SERVERCONNECTIONSETTINGSMODULE_H

/*
 * Хранит необходимые данные для поддержания текущего сеанса с сервером
 * Включая данные об авторизации
 *
*/

#include <Data/ServerConnectionSettings/ServerConnectionSettings.h>
#include <QSharedPointer>
class ServerConnectionSettingsModule {

    ServerConnectionSettings m_ServerConnectionSettings;

public:
    ServerConnectionSettingsModule();

    void addData( QSharedPointer < ServerConnectionSettings > pServerConnectionSettings );
    ServerConnectionSettings getServerConnectionSetting();
    void setServerConnectionSettings( ServerConnectionSettings serverConnectionSettings );
};

#endif // SERVERCONNECTIONSETTINGSMODULE_H

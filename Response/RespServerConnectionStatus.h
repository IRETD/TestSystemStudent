#ifndef RESPSERVERCONNECTIONSTATUS_H
#define RESPSERVERCONNECTIONSTATUS_H

#include <Response/Response.h>

class RespServerConnectionStatus : public Response {

    bool m_ConnectionStatus;

public:
    RespServerConnectionStatus();

    void doResponse();

    void setConnectionStatus( bool connectionStatus );
    bool getConnectionStatus();
};

#endif // RESPSERVERCONNECTIONSTATUS_H

#include "RespServerConnectionStatus.h"

RespServerConnectionStatus::RespServerConnectionStatus(){


}

void RespServerConnectionStatus::doResponse() {

    m_pDataSource.data() -> prepareConnectionStatusData( this );
}


void RespServerConnectionStatus::setConnectionStatus( bool connectionStatus ) {

    m_ConnectionStatus = connectionStatus;
}


bool RespServerConnectionStatus::getConnectionStatus() {

    return m_ConnectionStatus;
}

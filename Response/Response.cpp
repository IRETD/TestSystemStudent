#include "Response.h"

Response::Response() {
}


void Response::setType( const ResponseType &type ) {

    m_Type = type;
}

void Response::readStream( QDataStream &stream ) {


}

ResponseType Response::getType() {

    return m_Type;
}


ResponseHandlerType Response::getHandlerType() {

    return m_HandlerType;
}


void Response::setHandlerType( const ResponseHandlerType &handlerType ) {

    m_HandlerType = handlerType;
}


void Response::setDataSource( QSharedPointer < DataSource > pDataSource ) {

    m_pDataSource = pDataSource;
}


void Response::setRequestHandler( QSharedPointer< RequestHandler > pRequestHandler ) {

    m_pRequestHandler = pRequestHandler;
}

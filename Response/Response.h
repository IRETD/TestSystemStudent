#ifndef RESPONSE_H
#define RESPONSE_H

#include <QDataStream>
#include <Data/DataSource/DataSource.h>
#include "../../../Diplom/TestSystem/TestSystem/MacroDefinitions/IdentifierMessage.h"

enum ResponseHandlerType {

    WINDOW_RESPONSE = 0,
    DATA_SOURCE_RESPONSE = 1
};

typedef IdentifierMessage ResponseType;

class RequestHandler;
class DataSource;

class Response {

protected:

    ResponseType m_Type;
    ResponseHandlerType m_HandlerType;

    //для того чтобы внутри замого ответа доставлять пришедшие данные
    QSharedPointer < DataSource > m_pDataSource;

    //дабы иметь возможность отправить запрос по приходу ответа
    QSharedPointer < RequestHandler > m_pRequestHandler;


public:
    Response();

    virtual void doResponse() = 0;

    virtual void readStream( QDataStream &stream );
    void setType( const ResponseType &type );
    ResponseType getType();
    ResponseHandlerType getHandlerType();
    void setHandlerType( const ResponseHandlerType &handlerType );
    void setDataSource( QSharedPointer < DataSource > pDataSource );
    void setRequestHandler( QSharedPointer < RequestHandler > pRequestHandler );
};

#endif

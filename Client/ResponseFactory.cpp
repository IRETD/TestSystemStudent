#include "ResponseFactory.h"
#include <response/RespAuth.h>
#include <response/RespDisciplineTask.h>
#include <response/RespHistory.h>
#include <Response/RespAnalyzer.h>


ResponseFactory::ResponseFactory() {
}


QSharedPointer < Response > ResponseFactory::createResponse( const ResponseType &type ) {

    QSharedPointer < Response > pResponse ( nullptr );

    if ( type == ResponseType::AUTHORIZATION ) {
        pResponse = QSharedPointer < Response > ( new RespAuth );
        pResponse.data() -> setType( ResponseType::AUTHORIZATION );
    }

    if ( type == ResponseType::DISCIPLINE_TASK ) {
        pResponse = QSharedPointer < Response > ( new RespDisciplineTask );
        pResponse.data() -> setType( ResponseType::DISCIPLINE_TASK );
    }

    if ( type == ResponseType::HISTORY ) {
        pResponse = QSharedPointer < Response > ( new RespHistory );
        pResponse.data() -> setType( ResponseType::HISTORY );
    }

    if ( type == ResponseType::ANALYZE ) {

        pResponse = QSharedPointer < Response > ( new RespAnalyzer );
        pResponse.data() -> setType( ResponseType::ANALYZE );
    }

    return pResponse;
}

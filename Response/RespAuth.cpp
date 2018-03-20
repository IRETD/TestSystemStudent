#include "RespAuth.h"
#include <Request/RequestHandler.h>

RespAuth::RespAuth() {
}


void RespAuth::readStream( QDataStream &stream ) {

    stream >> m_Result  >>
              m_Message;
}


void RespAuth::doResponse() {

    //оповещаем наше хранилище о результатах авторизации
    m_pDataSource.data() -> prepareAuthData( this );

    //если все ок, запрашиваем все наши персональные первоначальные данные
    if ( m_Result == AuthResult::AUTHORIZATION_SUCCESS ) {

        m_pRequestHandler.data() -> doPersonalInitialData();
    }
}


AuthResult RespAuth::getResult() {

    return m_Result;
}


QString RespAuth::getMessage() {

    return m_Message;
}

#include "ReqAuth.h"
#include <MacroDefinitons/Request/RequestSenderInitialization.h>

ReqAuth::ReqAuth() : REQUEST_SENDER_INITIALIZATION {
}


void ReqAuth::writeInStream() {

    clearStream();
    m_Stream << static_cast < int > ( RequestType::AUTHORIZATION ) <<
                m_Login <<
                m_Password;
    prepareStream();
}


void ReqAuth::setLogin( const QString &login ) {

    m_Login = login;
}


void ReqAuth::setPassword( const QString &password ) {

    m_Password = password;
}

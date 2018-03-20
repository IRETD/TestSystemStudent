#include "Request.h"

Request::Request( RequestSender requestSender ) : m_Stream( &m_Buffer,
                                                            QIODevice::ReadWrite ),
                                                  m_RequestSender( requestSender ) {
}


QByteArray &Request::getBuffer() {

    return m_Buffer;
}


///ОБЯЗАТЕЛЬНО ВЫЗЫВАТЬ!
void Request::clearStream() {

    m_Buffer.clear();
    m_Stream.device() -> seek( START_POS_IN_STREAM );

    //резервируем место под РАЗМЕР буфера и тип отправителя
    m_Stream << quint32( 0 ) <<
                quint32( 0 );

}


///ОБЯЗАТЕЛЬНО ВЫЗЫВАТЬ
void Request::prepareStream() {

    //устанавливаем позицию на запись информации о типе отправителя
    m_Stream.device() -> seek( REQUEST_SENDER_POS_IN_STREAM );
    m_Stream << m_RequestSender;
    m_Stream.device() -> seek( START_POS_IN_STREAM );
    m_Stream << quint32( m_Buffer.size() - sizeof( quint32 ) );
}

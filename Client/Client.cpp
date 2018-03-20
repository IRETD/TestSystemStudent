#include "Client.h"
#include <client/StreamReader.h>
#include <client/ResponseReadInfo.h>
#include <Response/RespServerConnectionStatus.h>



void Client::createResponseAboutConnectionStatus( bool connectionStatus ) {

    QSharedPointer < RespServerConnectionStatus > pRespServerConnectionStatus = QSharedPointer < RespServerConnectionStatus > ( new RespServerConnectionStatus );
    pRespServerConnectionStatus.data() -> setConnectionStatus( connectionStatus );
    emit sendResponse( pRespServerConnectionStatus );
}


void Client::readyRead() {


    m_ClientBuffer.append( m_pClientSocket -> readAll() );

    bool clientBufferIsNotEmpty = ! m_ClientBuffer.isEmpty();

    do {
        StreamReader reader;
        ResponseReadInfo readInfo;
        QSharedPointer < Response > pResponse = reader.readStream( m_ClientBuffer, m_RecievedRequestSize, readInfo );

        if ( readInfo.getReadStatus() == ReadStatus::INPUT_DATA_ARE_INCOMPLETE ) {
            break;
        }

        if ( readInfo.getReadStatus() == ReadStatus::INPUT_DATA_ARE_UNEXPECTED ) {
            m_ClientBuffer.clear();
            break;
        }

        if ( readInfo.getReadStatus() == ReadStatus::INPUT_DATA_ARE_COMPLETE ) {
            m_RecievedRequestSize = REQUEST_SIZE_IS_NOT_READ;
            emit sendResponse( pResponse );
        }

        clientBufferIsNotEmpty = ! m_ClientBuffer.isEmpty();
    }

    while ( clientBufferIsNotEmpty );
}


Client::Client() {

    m_pClientSocket =  new QTcpSocket();
    m_RecievedRequestSize = REQUEST_SIZE_IS_NOT_READ;
}


bool Client::connectionStatus() {

    return ( m_pClientSocket -> state() == QAbstractSocket::ConnectedState );
}


bool Client::connectToServer( const QString &address, const int &port ) {

    if ( m_pClientSocket -> state() != QAbstractSocket::ConnectedState ) {
            m_pClientSocket -> connectToHost( address,
                                              port );
            if ( m_pClientSocket -> waitForConnected() ) {

                //ОТСОЕДИНЯТЬ СЛОТЫ ПРИ РАЗЪЕДИНЕНИИ!!!
                connect( m_pClientSocket, &QTcpSocket::disconnected, this, &Client::connectionIsLost );
                connect( m_pClientSocket, &QTcpSocket::readyRead, this, &Client::readyRead );
            }
            else {

                QString error = m_pClientSocket -> errorString();
                qDebug() << error;
            }
    }

    return connectionStatus();
}


bool Client::sendToServer( QByteArray &byteArray ) {

    int result = m_pClientSocket -> write( byteArray );

    return ( result != -1 );
}

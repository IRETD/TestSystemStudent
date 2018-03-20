#ifndef CLIENT_H
#define CLIENT_H

#include <QtNetwork/QTcpSocket>
#include <QString>
#include <QObject>
#include <Response/Response.h>

enum {

    REQUEST_SIZE_IS_NOT_READ = 0
};

class Response;

class Client : public QObject {

    Q_OBJECT

    QTcpSocket *m_pClientSocket;
    quint32 m_RecievedRequestSize;
    QByteArray m_ClientBuffer;

    void createResponseAboutConnectionStatus( bool connectionStatus );

private slots:
    void readyRead();

public:
    Client();

    bool connectionStatus();
    bool connectToServer( const QString &address,
                          const int &port );
    bool sendToServer( QByteArray &byteArray );

signals:
    void connectionIsLost();
    void sendResponse( QSharedPointer < Response > pResponse );
};

#endif // CLIENT_H

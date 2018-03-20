#ifndef REQAUTH_H
#define REQAUTH_H

#include <request/Request.h>
#include <QString>

class ReqAuth : public Request {

    QString m_Login;
    QString m_Password;
public:
    ReqAuth();

    void writeInStream();

    void setLogin( const QString &login );
    void setPassword( const QString &password );
};

#endif // REQAUTH_H

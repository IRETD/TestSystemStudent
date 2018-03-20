#ifndef RESPAUTH_H
#define RESPAUTH_H

#include <response/Response.h>
#include "../../../Diplom/TestSystem/TestSystem/MacroDefinitions/Request/Client/AuthResult.h"

class RespAuth : public Response {

    AuthResult m_Result;
    QString m_Message;

public:
    RespAuth();

     void readStream( QDataStream &stream );
     void doResponse();

     AuthResult getResult();
     QString getMessage();
};

#endif // RESPAUTH_H

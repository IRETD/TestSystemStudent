#ifndef REQUEST_H
#define REQUEST_H

#include <QByteArray>
#include <QDataStream>

#include "../../../Diplom/TestSystem/TestSystem/MacroDefinitions/IdentifierMessage.h"
#include "../../../Diplom/TestSystem/TestSystem/MacroDefinitions/Request/Client/RequestSender.h"

typedef IdentifierMessage RequestType;

class Request {

#define REQUEST_SENDER_POS_IN_STREAM 4
#define START_POS_IN_STREAM 0

protected:
    QByteArray m_Buffer;
    QDataStream m_Stream;
    RequestSender m_RequestSender;

public:
    Request( RequestSender requestSender );

    virtual void writeInStream() = 0;
    QByteArray &getBuffer();

    void clearStream();
    void prepareStream();

};

#endif // REQUEST_H

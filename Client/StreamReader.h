#ifndef STREAMREADER_H
#define STREAMREADER_H
#include <response/Response.h>
#include <client/ResponseReadInfo.h>
#include <QByteArray>

class StreamReader {

public:
    StreamReader();
    QSharedPointer < Response > readStream( QByteArray &buffer,
                                            quint32 &recievedRequestSize,
                                            ResponseReadInfo &info );
};

#endif // STREAMREADER_H

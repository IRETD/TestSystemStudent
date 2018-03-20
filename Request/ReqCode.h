#ifndef REQCODE_H
#define REQCODE_H

#include <request/Request.h>

class ReqCode : public Request {

    int m_IdUserLab;
    QByteArray m_FileZipBuffer;
    QString m_FilePath;

public:
    ReqCode();

    void setIdUserLab( const int &idUserLab );
    void setFilePath( QString path );
    bool prepareFileProject();
   // void setFileZipBuffer( const QByteArray &byteArray );

    void writeInStream();
};

#endif // REQCODE_H

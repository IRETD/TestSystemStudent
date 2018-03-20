#ifndef RESPHISTORY_H
#define RESPHISTORY_H

#include <response/Response.h>
#include <Data/Test/History.h>
#include <Data/Test/AboutHistory.h>

class RespHistory : public Response {

    QList < History > m_HistoryList;
    QList < AboutHistory > m_AboutHistoryList;

public:
    RespHistory();

    void readStream( QDataStream &stream );

    void doResponse();
    QList < History > getHistoryList();
    QList < AboutHistory > getAboutHistoryList();
};

#endif // RESPHISTORY_H

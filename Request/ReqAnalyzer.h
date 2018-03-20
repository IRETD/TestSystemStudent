#ifndef REQANALYZER_H
#define REQANALYZER_H

#include <request/Request.h>

class ReqAnalyzer : public Request {

    quint32 m_IdHistory;
    quint32 m_IdAboutHistory;

public:
    ReqAnalyzer();
    void setIdHistory( quint32 idHistory );
    void setIdAboutHistory( quint32 idAboutHistory );
    void writeInStream();
};

#endif

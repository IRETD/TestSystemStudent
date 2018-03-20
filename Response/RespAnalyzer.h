#ifndef RESPANALYZER_H
#define RESPANALYZER_H

#include <response/Response.h>
#include <Data/StaticAnalyzer/StaticAnalyzer.h>
#include <MyStorageType/SingleKeyContainer.h>

class RespAnalyzer : public Response {

    quint32 m_IdHistory;
    quint32 m_IdAboutHistory;

    QList < StaticAnalyzer > m_StaticAnalyzerList;
    SingleKeyContainer < quint32,
                         QString > m_IdCodeContainer;

public:
    RespAnalyzer();

    void readStream( QDataStream &stream );
    void doResponse();

    quint32 getIdHistory();
    quint32 getIdAboutHistory();
    QList < StaticAnalyzer > getStaticAnalyzerList();
    SingleKeyContainer < quint32,
                         QString > getIdCodeContainer();
};

#endif

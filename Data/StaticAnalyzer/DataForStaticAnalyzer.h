#ifndef DATAFORSTATICANALYZER_H
#define DATAFORSTATICANALYZER_H


#include <MyStorageType/SingleKeyContainer.h>
#include <Data/StaticAnalyzer/StaticAnalyzer.h>
#include <Data/AbstractData.h>


class DataForStaticAnalyzer : public AbstractData {

    SingleKeyContainer < quint32,
                         QString > m_IdCodeContainer;

    QList < StaticAnalyzer > m_StaticAnalyzer;

    quint32 m_IdHistory;
    quint32 m_IdAboutHistory;

public:
    DataForStaticAnalyzer();

    void setStaticAnalyzer( QList < StaticAnalyzer > staticAnalyzer );
    void setIdCodeContainer( SingleKeyContainer < quint32,
                                                  QString > idCodeContainer );
    void setIdHistory( quint32 idHistory );
    void setIdAboutHistory( quint32 idAboutHistory );

    QList < StaticAnalyzer > getStaticAnalyzer();
    SingleKeyContainer < quint32,
                         QString > getIdCodeContainer();
    quint32 getIdHistory();
    quint32 getIdAboutHistory();

};

#endif // DATAFORSTATICANALYZER_H

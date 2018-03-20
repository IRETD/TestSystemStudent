#include "DataForStaticAnalyzer.h"


DataForStaticAnalyzer::DataForStaticAnalyzer() : AbstractData( TypeData::ANALYZE_TYPE_DATA ) {

}


void DataForStaticAnalyzer::setStaticAnalyzer( QList < StaticAnalyzer > staticAnalyzer ) {

    m_StaticAnalyzer = staticAnalyzer;
}


void DataForStaticAnalyzer::setIdCodeContainer( SingleKeyContainer < quint32,
                                                                     QString > idCodeContainer ) {

    m_IdCodeContainer = idCodeContainer;
}


void DataForStaticAnalyzer::setIdHistory( quint32 idHistory ) {

    m_IdHistory = idHistory;
}


void DataForStaticAnalyzer::setIdAboutHistory( quint32 idAboutHistory ) {

    m_IdAboutHistory = idAboutHistory;
}


QList < StaticAnalyzer > DataForStaticAnalyzer::getStaticAnalyzer() {

    return m_StaticAnalyzer;
}


SingleKeyContainer < quint32,
                     QString> DataForStaticAnalyzer::getIdCodeContainer() {

    return m_IdCodeContainer;
}


quint32 DataForStaticAnalyzer::getIdHistory() {

    return m_IdHistory;
}


quint32 DataForStaticAnalyzer::getIdAboutHistory() {

    return m_IdAboutHistory;
}

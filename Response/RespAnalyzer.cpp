#include "RespAnalyzer.h"


void RespAnalyzer::readStream( QDataStream &stream ) {

    //Читаем исходный код
    int sourceCodeSize;
    stream >> sourceCodeSize;
    for ( int i = 0; i < sourceCodeSize; i++ ) {

        quint32 idSourceCode;
        stream >> idSourceCode;
        QString sourceCode;
        stream >> sourceCode;
        m_IdCodeContainer.addValue( idSourceCode,
                                    sourceCode );
    }

    stream >> m_IdHistory;
    stream >> m_IdAboutHistory;

    int staticAnalyzeSize;
    stream >> staticAnalyzeSize;
    for ( int i = 0; i < staticAnalyzeSize; i++ ) {

        StaticAnalyzer staticAnalyzer;
        quint32 idAboutStaticAnalyzer;
        stream >> idAboutStaticAnalyzer;
        staticAnalyzer.setIdAboutStaticAnalyzer( idAboutStaticAnalyzer );

        int typeStaticAnalyzer;
        stream >> typeStaticAnalyzer;
        staticAnalyzer.setTypeStaticAnalyzer( static_cast < TypeStaticAnalyzer > ( typeStaticAnalyzer ) );

        QString description;
        stream >> description;
        staticAnalyzer.setDescription( description );

        quint32 idLocationFile;
        stream >> idLocationFile;
        staticAnalyzer.setIdLocationFile( idLocationFile );

        quint32 line;
        stream >> line;
        staticAnalyzer.setLine( line );

        QString locationFile;
        stream >> locationFile;
        staticAnalyzer.setLocationFile( locationFile );

        m_StaticAnalyzerList.push_back( staticAnalyzer );
    }
}


void RespAnalyzer::doResponse() {

    m_pDataSource.data() -> prepareAnalyzeData( this );
}


quint32 RespAnalyzer::getIdHistory() {

    return m_IdHistory;
}


quint32 RespAnalyzer::getIdAboutHistory() {

    return m_IdAboutHistory;
}


QList < StaticAnalyzer > RespAnalyzer::getStaticAnalyzerList() {

    return m_StaticAnalyzerList;
}


SingleKeyContainer<quint32, QString> RespAnalyzer::getIdCodeContainer() {

    return m_IdCodeContainer;
}


RespAnalyzer::RespAnalyzer() {
}

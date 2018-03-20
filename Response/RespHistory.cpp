#include "RespHistory.h"


RespHistory::RespHistory() {
}


void RespHistory::readStream( QDataStream &stream ) {

    int historyCount;
    stream >> historyCount;
    for ( int i = 0; i < historyCount; i++ ) {
        History history;

        int idUserLab;
        stream >> idUserLab;
        history.setIdUserLab( idUserLab );

        int idHistory;
        stream >> idHistory;
        history.setIdHistory( idHistory );

        int result;
        stream >> result;
        history.setResult( static_cast < TestResult > ( result ) );

        QString textResult;
        stream >> textResult;
        history.setTextResult( textResult );

        QDateTime dateTime;
        stream >> dateTime;
        history.setDateHistory( dateTime );

        m_HistoryList.append( history );
    }

    int aboutHistoryCount;
    stream >> aboutHistoryCount;
    for ( int i = 0; i < aboutHistoryCount; i++ ) {
        AboutHistory aboutHistory;

        int idHistory;
        stream >> idHistory;
        aboutHistory.setIdHistory( idHistory );

        int idAboutHistory;
        stream >> idAboutHistory;
        aboutHistory.setIdAboutHistory( idAboutHistory );

        int result;
        stream >> result;
        aboutHistory.setResult( static_cast < TestResult > ( result ) );

        int stepType;
        stream >> stepType;
        aboutHistory.setStepType( static_cast < StepType > ( stepType ) );

        QString description;
        stream >> description;
        aboutHistory.setDescription( description );

        QString textResult;
        stream >> textResult;
        aboutHistory.setTextResult( textResult );

        QString memory;
        stream >> memory;
        aboutHistory.setMemory( memory );

        QString time;
        stream >> time;
        aboutHistory.setTime( time );

        QString additionalColumn;
        stream >> additionalColumn;
        aboutHistory.setAdditionalColumn( additionalColumn );

        m_AboutHistoryList.append( aboutHistory );
    }

}


void RespHistory::doResponse() {

    m_pDataSource.data() -> prepareHistoryData( this );
}


QList < History > RespHistory::getHistoryList() {

    return m_HistoryList;
}


QList < AboutHistory > RespHistory::getAboutHistoryList() {

    return m_AboutHistoryList;
}


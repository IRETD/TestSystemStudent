#include "DataSource.h"
#include <Response/RespDiscipline.h>
#include <Response/RespAuth.h>
#include <Response/RespServerConnectionStatus.h>
#include <Response/RespDisciplineTask.h>
#include <MacroDefinitons/MyMacroDefinitions.h>
#include <Response/RespHistory.h>
#include <Response/RespAnalyzer.h>


//ШАБЛОН
void DataSource::prepareDisciplineData( QList < Discipline > disciplineData ) {

    foreach ( Discipline discipline, disciplineData ) {

        QSharedPointer < DataForDisciplineModule > pDataDiscipline( new DataForDisciplineModule );
        pDataDiscipline.data() -> setDiscipline( discipline );
        addNewDataInDataModule( pDataDiscipline );
    }
}


//ШАБЛОН
void DataSource::prepareTaskData( QList < Task > taskData ) {

    foreach ( Task task, taskData ) {

        QSharedPointer < DataForTaskModule > pDataTask( new DataForTaskModule );
        pDataTask.data() -> setTask( task );
        addNewDataInDataModule( pDataTask );
    }
}


//ШАБЛОН
void DataSource::prepareHistoryData( QList< History > historyData ) {

    foreach ( History history, historyData ) {

        QSharedPointer < DataForTestModule > pData( new DataForTestModule );
        pData.data() -> setHistory( history );
        addNewDataInDataModule( pData );
    }
}


//ШАБЛОН
void DataSource::prepareAboutHistoryData( QList < AboutHistory > aboutHistoryData ) {


    foreach( AboutHistory aboutHistory, aboutHistoryData ) {

        QSharedPointer < DataForAboutTestModule > pData( new DataForAboutTestModule );
        pData.data() -> setAboutHistory( aboutHistory );
        addNewDataInDataModule( pData );
    }
}


void DataSource::addNewDataInDataModule( QSharedPointer < AbstractData > pData ) {

    m_pDataModule.data() -> addData( pData );
}


DataSource::DataSource( QSharedPointer < DataModule > pDataModule ) {

    m_pDataModule = pDataModule;
}


void DataSource::prepareDisciplineTaskData( RespDisciplineTask *pRespDisciplineTask ) {

    QList < Discipline > disciplineList = pRespDisciplineTask -> getDisciplineList();
    prepareDisciplineData( disciplineList );
    QList < Task > taskList = pRespDisciplineTask -> getTaskList();
    prepareTaskData( taskList );
}


void DataSource::prepareHistoryData( RespHistory *pRespHistory ) {


    prepareHistoryData( pRespHistory -> getHistoryList() );
    prepareAboutHistoryData( pRespHistory -> getAboutHistoryList() );
}


void DataSource::prepareAnalyzeData( RespAnalyzer *pRespAnalyzer ) {

    quint32 idAboutHistory = pRespAnalyzer -> getIdAboutHistory();
    quint32 idHistory = pRespAnalyzer -> getIdHistory();
    QSharedPointer < DataForStaticAnalyzer > pData( new DataForStaticAnalyzer );
    pData.data() -> setIdHistory( idHistory );
    pData.data() -> setIdAboutHistory( idAboutHistory );
    pData.data() -> setIdCodeContainer( pRespAnalyzer -> getIdCodeContainer() );
    pData.data() -> setStaticAnalyzer( pRespAnalyzer -> getStaticAnalyzerList() );
    addNewDataInDataModule( pData );
}


void DataSource::prepareDisciplineData( RespDiscipline *pResponse ) {

    //получаем список дисциплин
    QList < Discipline > disciplineList = pResponse -> getDisciplineList();
    prepareDisciplineData( disciplineList );
}


void DataSource::prepareAuthData( RespAuth *pResponse ) {

    ServerConnectionSettings connectionSettings = getServerConnectionSettings;

    connectionSettings.setAuthorizedStatus( pResponse -> getResult() );

    getServerConnectionSettingsModule -> setServerConnectionSettings( connectionSettings );
}


void DataSource::prepareConnectionStatusData( RespServerConnectionStatus *pRespServerConnectionStatus ) {

    ServerConnectionSettings connectionSettings = getServerConnectionSettings;
    connectionSettings.setConnectionStatus( pRespServerConnectionStatus -> getConnectionStatus() );
    getServerConnectionSettingsModule -> setServerConnectionSettings( connectionSettings );
}

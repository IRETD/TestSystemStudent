#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <Data/DataModule.h>
#include <Data/AbstractData.h>
#include<Data/Test/AboutHistory.h>

class RespDiscipline;
class RespAuth;
class RespServerConnectionStatus;
class RespDisciplineTask;
class RespHistory;
class DataModule;
class RespAnalyzer;

class DataSource {

protected:
    QSharedPointer < DataModule > m_pDataModule;

    void prepareDisciplineData( QList < Discipline > disciplineData );
    void prepareTaskData( QList < Task > taskData );
    void prepareHistoryData( QList < History > historyData );
    void prepareAboutHistoryData( QList < AboutHistory > aboutHistoryData );

    void addNewDataInDataModule( QSharedPointer < AbstractData > pData );

public:
    DataSource( QSharedPointer < DataModule > pDataModule );

    void prepareDisciplineData( RespDiscipline *pResponse );
    void prepareAuthData( RespAuth *pResponse );
    void prepareConnectionStatusData( RespServerConnectionStatus *pRespServerConnectionStatus );
    void prepareDisciplineTaskData( RespDisciplineTask *pRespDisciplineTask );
    void prepareHistoryData( RespHistory *pRespHistory );
    void prepareAnalyzeData( RespAnalyzer *pRespAnalyzer );
};

#endif

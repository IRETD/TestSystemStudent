#include "TestDataSource.h"
#include <Data/Discipline/DataForDisciplineModule.h>
#include <Data/Task/DataForTaskModule.h>

TestDataSource::TestDataSource( QSharedPointer < DataModule > pDataModule ) : DataSource( pDataModule ) {

    generateDisciplineData();
    generateTaskData();
}


void TestDataSource::generateDisciplineData() {

    QSharedPointer < DataForDisciplineModule > pDataDiscipline( new DataForDisciplineModule );
    int idDiscipline = 1;
    pDataDiscipline.data() -> setIdDiscipline( idDiscipline );
    QString nameDiscipline = "Алгоритмы и структурки";
    pDataDiscipline.data() -> setName( nameDiscipline );
    QString descriptionDiscipline = "Hello world!";
    pDataDiscipline.data() -> setDescription( descriptionDiscipline );
    addNewDataInDataModule( pDataDiscipline );
}


void TestDataSource::generateTaskData() {

    QSharedPointer < DataForTaskModule > pDataTask( new DataForTaskModule );
    pDataTask.data() -> setIdTask( 1 );
    pDataTask.data()->setIdDiscipline( 1 );
    pDataTask.data() -> setName( "Массивы" );
    pDataTask.data() -> setPurpose( "Hello world!" );
    pDataTask.data()->setDesiredDate( QDateTime::currentDateTime() );
    pDataTask.data()->setCriticalDate( QDateTime::currentDateTime() );
    addNewDataInDataModule( pDataTask );
}

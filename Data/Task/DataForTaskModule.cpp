#include "DataForTaskModule.h"
#include <Enum/Data/Task/TaskFieldName.h>


DataForTaskModule::DataForTaskModule() : AbstractData( TypeData::TASK_DATA_TYPE ) {
}


void DataForTaskModule::setIdTask( const int &idTask ) {


    m_Task.setIdTask( idTask );
    addChangedField( TaskFieldName::ID_TASK_FIELD );
}


void DataForTaskModule::setIdDiscipline( int const &idDiscipline ) {

    m_Task.setIdDiscipline( idDiscipline );
    addChangedField( TaskFieldName::ID_DISCIPLINE_TASK_FIELD );
}


void DataForTaskModule::setName( QString const &name ) {

    m_Task.setName( name );
    addChangedField( TaskFieldName::NAME_TASK_FIELD );
}


void DataForTaskModule::setPurpose( QString const &purpose ) {

    m_Task.setPurpose( purpose );
    addChangedField( TaskFieldName::PURPOSE_TASK_FIELD );
}


void DataForTaskModule::setDesiredDate( QDateTime const &desiredDate ) {

    m_Task.setDesiredDate( desiredDate );
    addChangedField( TaskFieldName::DESIRED_DATE_TASK_FIELD );
}


void DataForTaskModule::setCriticalDate( QDateTime const &criticalDate) {

    m_Task.setCriticalDate( criticalDate );
    addChangedField( TaskFieldName::CRITICAL_DATE_TASK_FIELD );
}


void DataForTaskModule::setTask( Task task ) {

    m_Task = task;
}


Task &DataForTaskModule::getTask() {

    return m_Task;
}

#include "RespDisciplineTask.h"


RespDisciplineTask::RespDisciplineTask() {
}


void RespDisciplineTask::readStream( QDataStream &stream ) {

    int disciplineCount;
    stream >> disciplineCount;

    for ( int i = 0;
          i < disciplineCount;
          i++ ) {
        Discipline discipline;

        stream >> discipline;

        m_DisciplineList.push_back( discipline );
    }

    int labCount;
    stream >> labCount;

    for ( int i = 0;
          i < labCount;
          i++ ) {
        Task task;

        stream >> task;

        m_TaskList.push_back( task );
    }
}


QList < Discipline > RespDisciplineTask::getDisciplineList() {

    return m_DisciplineList;
}


QList < Task > RespDisciplineTask::getTaskList() {

    return m_TaskList;
}



void RespDisciplineTask::doResponse() {

    m_pDataSource.data() -> prepareDisciplineTaskData( this );
}

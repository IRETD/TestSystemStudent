#ifndef RESPLABLIST_H
#define RESPLABLIST_H

#include <response/Response.h>
#include "../SharedModules/Discipline.h"
#include "../SharedModules/Task.h"


class RespDisciplineTask : public Response {

    QList < Discipline > m_DisciplineList;
    QList < Task > m_TaskList;

public:
    RespDisciplineTask();
    void readStream( QDataStream &stream );
    void doResponse();

    QList < Discipline > getDisciplineList();
    QList < Task > getTaskList();
};

#endif // RESPLABLIST_H

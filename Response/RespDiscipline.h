#ifndef RESPDISCIPLINE_H
#define RESPDISCIPLINE_H


#include "../SharedModules/Discipline.h"

#include <QDataStream>
#include <Response/Response.h>

class RespDiscipline : public Response {

    QList < Discipline > m_DisciplineList;

public:
    RespDiscipline();

    void readStream( QDataStream &stream );
    void doResponse();

    QList < Discipline > getDisciplineList();
};

#endif

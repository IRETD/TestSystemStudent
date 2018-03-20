#include "RespDiscipline.h"


RespDiscipline::RespDiscipline() {
}


void RespDiscipline::readStream( QDataStream &stream ) {

}

void RespDiscipline::doResponse() {

    m_pDataSource.data() -> prepareDisciplineData( this );
}


QList < Discipline > RespDiscipline::getDisciplineList() {

}

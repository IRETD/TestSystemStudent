#include "DataForDisciplineModule.h"
#include <Enum/Data/Discipline/DisciplineFieldName.h>


DataForDisciplineModule::DataForDisciplineModule() : AbstractData( TypeData::DISCIPLINE_DATA_TYPE ) {
}


void DataForDisciplineModule::setIdDiscipline( int &idDiscipline ) {

    m_Discipline.setIdDiscipline( idDiscipline );
    addChangedField( DisciplineFieldName::ID_DISCIPLINE_FIELD );
}


void DataForDisciplineModule::setOldId( int &oldId ) {

    m_OldId = oldId;
}


int DataForDisciplineModule::getOldId() {

    return m_OldId;
}


void DataForDisciplineModule::setName( QString &name ) {


    m_Discipline.setName( name );
    addChangedField( DisciplineFieldName::NAME_DISCIPLINE_FIELD );
}


void DataForDisciplineModule::setDescription( QString &description ) {

    m_Discipline.setDescription( description );
    addChangedField( DisciplineFieldName::DESCRIPTION_DISCIPLINE_FIELD );
}


void DataForDisciplineModule::setDiscipline( Discipline &discipline ) {

    m_Discipline = discipline;
}


Discipline &DataForDisciplineModule::getDiscipline() {

    return m_Discipline;
}

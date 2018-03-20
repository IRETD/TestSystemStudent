#include "DisciplineTextDescriptionModule.h"
#include <Model/BaseModel/DataItemModel/PureBaseModel/DataItemForModelTextDescription.h>

DisciplineTextDescriptionModule::DisciplineTextDescriptionModule() {

    m_pModelTextDescription = QSharedPointer < ModelTextDisciplineDescription > (
                              new ModelTextDisciplineDescription( TypeModel::DISCIPLINE_DESCRIPTION_TYPE_MODEL) );
}


void DisciplineTextDescriptionModule::updateTitle( int idDiscipline,
                                                   QString &title ) {

    m_pModelTextDescription.data() -> getDisciplineDescription( idDiscipline ).setTitle( title );
}


void DisciplineTextDescriptionModule::addData( const Discipline &discipline ) {

    m_pModelTextDescription.data() -> addItemInModel( discipline );

}


QSharedPointer < ModelTextDisciplineDescription > DisciplineTextDescriptionModule::getDisciplineTextDescriptionModel() {

    return m_pModelTextDescription;
}

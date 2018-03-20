#include "ModelTextDisciplineDescription.h"


ModelTextDisciplineDescription::ModelTextDisciplineDescription( TypeModel typeModel ) {

    m_TypeModel = typeModel;
}


void ModelTextDisciplineDescription::addItemInModel( Discipline const &discipline ) {

    DisciplineDescriptionHTMLEditor disciplineDescription;
    disciplineDescription.setTitle( discipline.getName() );
    disciplineDescription.setDescription( discipline.getDescription() );
    m_IdTextContainer.addValue( discipline.getIdDiscipline(),
                                disciplineDescription );
}


TypeModel ModelTextDisciplineDescription::getTypeModel() {

    return m_TypeModel;
}

DisciplineDescriptionHTMLEditor &ModelTextDisciplineDescription::getDisciplineDescription( int idItem ) {

    return m_IdTextContainer.getValue( idItem );
}


void ModelTextDisciplineDescription::disciplineItemSelected( int idItem ) {

    emit sendTextDescription( idItem,
                              m_IdTextContainer.getValue( idItem ).getHTML() );

    emit showViewContext( ViewContextType::DISCIPLINE_DESCRIPTION_VIEW_CONTEXT );
}



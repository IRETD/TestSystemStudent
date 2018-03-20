#include "ModelTextTaskDescription.h"


ModelTextTaskDescription::ModelTextTaskDescription( TypeModel typeModel ) {

    m_TypeModel = typeModel;
}


void ModelTextTaskDescription::addItemInModel( Task &task ) {

    TaskDescriptionHTMLEditor taskDescription;
    taskDescription.setTitle( task.getName() );
    taskDescription.setDescription( task.getPurpose() );
    //taskDescription.addExplorerButton();
    m_IdTextContainer.addValue( task.getIdTask(),
                                taskDescription );
}


TypeModel ModelTextTaskDescription::getTypeModel() {

    return m_TypeModel;
}

TaskDescriptionHTMLEditor &ModelTextTaskDescription::getTaskDescription( int idItem ) {

    return m_IdTextContainer.getValue( idItem );
}


void ModelTextTaskDescription::taskItemSelected( int idItem ) {

    emit sendTextDescription( idItem,
                              m_IdTextContainer.getValue( idItem ).getHTML() );

    emit showViewContext( ViewContextType::TASK_DESCRIPTION_VIEW_CONTEXT );
}



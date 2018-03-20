#include "TaskTextDescriptionModule.h"


TaskTextDescriptionModule::TaskTextDescriptionModule() {

    m_pModelTextDescription = QSharedPointer < ModelTextTaskDescription > ( new ModelTextTaskDescription( TypeModel::TASK_DESCRIPTION_TYPE_MODEL ) );
}

void TaskTextDescriptionModule::updateTitle( int idTask,
                                             QString &title ) {

    m_pModelTextDescription.data() -> getTaskDescription( idTask ).setTitle( title );
}


void TaskTextDescriptionModule::addData( Task task ) {

    m_pModelTextDescription.data() -> addItemInModel( task );

}


QSharedPointer < ModelTextTaskDescription > TaskTextDescriptionModule::getTaskTextDescriptionModel() {

    return m_pModelTextDescription;
}

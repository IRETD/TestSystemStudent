#ifndef TASKTEXTDESCRIPTIONMODULE_H
#define TASKTEXTDESCRIPTIONMODULE_H

#include <Model/BaseModel/PureBaseModel/ModelTextDescription/ModelTextTaskDescription.h>

class TaskTextDescriptionModule {

    QSharedPointer < ModelTextTaskDescription > m_pModelTextDescription;

public:
    TaskTextDescriptionModule();

    void updateTitle( int idTask,
                      QString &title );
    void addData( Task task );

    QSharedPointer < ModelTextTaskDescription > getTaskTextDescriptionModel();
};

#endif

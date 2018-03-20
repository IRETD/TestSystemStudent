#ifndef DATAFORGROUPMODULE_H
#define DATAFORGROUPMODULE_H

#include "Data/Group/Group.h"

class DataForGroupModule {

    #define ID_TASK_IS_NOT_INITIALIZED -1
    quint32 m_IdTask;
    quint32 m_IdTaskGroup;
    Group m_Group;

public:
    DataForGroupModule();

    void setIdTaskGroup( quint32 idTaskGroup );
    quint32 getIdTaskGroup();
    void setIdTask( quint32 idTask );
    quint32 getIdTask();
    void setGroup( Group group );
    Group getGroup();
};

#endif

#include "DataForGroupModule.h"
#include <assert.h>


DataForGroupModule::DataForGroupModule() {

    m_IdTask = ID_TASK_IS_NOT_INITIALIZED;
}


void DataForGroupModule::setIdTaskGroup( quint32 idTaskGroup ) {

    m_IdTaskGroup = idTaskGroup;
}


quint32 DataForGroupModule::getIdTaskGroup() {

    return m_IdTaskGroup;
}


void DataForGroupModule::setIdTask( quint32 idTask ) {

    m_IdTask = idTask;
}


quint32 DataForGroupModule::getIdTask() {

    assert( m_IdTask != ID_TASK_IS_NOT_INITIALIZED );
    return m_IdTask;
}


void DataForGroupModule::setGroup( Group group ) {

    m_Group = group;
}


Group DataForGroupModule::getGroup() {

    return m_Group;
}

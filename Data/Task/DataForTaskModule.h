#ifndef DATAFORTASKMODULE_H
#define DATAFORTASKMODULE_H

#include <Data/AbstractData.h>
#include "../SharedModules/Task.h"


class DataForTaskModule : public AbstractData {

    Task m_Task;

public:
    DataForTaskModule();

    void setIdTask( const int &idTask );
    //void setIdUserLab( const int &idUserLab );
    void setIdDiscipline( const int &idDiscipline );
    void setName( const QString &name );
    void setPurpose( const QString &purpose );
    //void setState( const LabState &state );
    void setDesiredDate( const QDateTime &desiredDate );
    void setCriticalDate( const QDateTime &criticalDate );
    void setTask( Task task );

    Task &getTask();
};

#endif // DATAFORTASKMODULE_H

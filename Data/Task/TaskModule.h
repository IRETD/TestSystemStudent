#ifndef TASKMODULE_H
#define TASKMODULE_H

#include <MyStorageType/SingleKeyContainer.h>
#include <Model/BaseModel/StandardItemBaseModel/SubClasses/TreeStandartItemBaseModel.h>
#include <Data/Icon/IconItemManager.h>

#include "../SharedModules/Task.h"

#include <Data/BaseModule.h>
#include <Data/SubBaseModuleForTreeStandartItemBaseModel.h>
#include <Data/Task/DataForTaskModule.h>
#include <Data/Task/DescriptionTask/TaskTextDescriptionModule.h>

class TaskModule : public BaseModule,
                   public SubBaseModuleForTreeStandartItemBaseModel {


    SingleKeyContainer < int,
                         Task > m_TaskTable;

    QSharedPointer < TreeStandartItemBaseModel > m_pDisciplineModel;
    QSharedPointer < TreeStandartItemBaseModel > m_pTaskModel;
    QSharedPointer < TaskTextDescriptionModule > m_pTaskTextDescriptionModule;

    //добавить остальные поля
    void updateTitle( int const &idTask,
                      QString const &title );

    void addTask( Task const &task );


public:
    TaskModule( QSharedPointer < TreeStandartItemBaseModel > pDisciplineModel,
                QSharedPointer < TaskTextDescriptionModule > pTaskTextDescriptionModule,
                QSharedPointer < IconItemManager > pIconItemManager,

                QSharedPointer < NotificationManager > pNotificationManager );

    void addData( QSharedPointer < DataForTaskModule > pData );
    QSharedPointer < TreeStandartItemBaseModel > getTaskModel();

    Task getTask( int idTask );
    Task getCurrentTask();
    int getCurrentTaskId();
    bool isThereAnyCurrenTask();
};

#endif // TASKMODULE_H

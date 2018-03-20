#ifndef GROUPMODULE_H
#define GROUPMODULE_H

#include "Data/Group/DataForGroupModule.h"
#include <Data/BaseModule.h>
#include <Data/SubBaseModuleForTreeStandartItemBaseModel.h>
#include "Group.h"
#include <MyStorageType/SingleKeyContainer.h>

class GroupModule : public BaseModule,
                    public SubBaseModuleForTreeStandartItemBaseModel {


    //по idTaskGroup определяем группу
    SingleKeyContainer < quint32, //IdTaskGroup
                         Group > m_IdTaskGroupGroupContainer;

    //связка idTaskGroup c idTask
    SingleKeyContainer < quint32,
                         quint32 > m_IdTaskGroupIdTaskContainer;

    QSharedPointer < TreeStandartItemBaseModel > m_pTaskModel;
    QSharedPointer < TreeStandartItemBaseModel > m_pGroupModule;

    void addGroup( quint32 idTaskGroup,
                   quint32 idTask,
                   Group group );

public:

    GroupModule( QSharedPointer < TreeStandartItemBaseModel > pTaskModel,
                 QSharedPointer < IconItemManager > pIconItemManager,
                 QSharedPointer < NotificationManager > pNotificationManager );
    void addData( QSharedPointer < DataForGroupModule > pData );
    QSharedPointer < TreeStandartItemBaseModel > getGroupModel();
};

#endif // GROUPMODULE_H

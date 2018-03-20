#include "GroupModule.h"


void GroupModule::addGroup( quint32 idTaskGroup,
                            quint32 idTask,
                            Group group ) {

    //пока что буду привязываться в idTask

    //int idGroup = group.getIdGroup();

    //указываем родителя - дисциплину
    QPersistentModelIndex parent = m_pTaskModel.data() -> getModelIndexById( idTask );

    //Привязываемся группой к заданию!
    QSharedPointer < DataItemModelForStandartItemBaseModel > pData = initializeNewDataForStandartItemBaseModel( idTaskGroup,
                                                                                                                group.getName(),
                                                                                                                parent );
    addNewItem( m_pGroupModule,
                pData,
                m_pTaskModel.data() -> getModelItemDescriptor( idTask ) );

    m_pNotificationManager.data() -> addNotification( NotificationType::ITEM_IS_NEW,
                                                      m_pGroupModule.data() -> getModelItemDescriptor( idTaskGroup ) );

}


GroupModule::GroupModule( QSharedPointer < TreeStandartItemBaseModel > pTaskModel ,
                          QSharedPointer < IconItemManager > pIconItemManager,
                          QSharedPointer < NotificationManager > pNotificationManager ) : BaseModule( pIconItemManager,
                                                                                                      pNotificationManager ) {

    m_pTaskModel = pTaskModel;
}



void GroupModule::addData( QSharedPointer < DataForGroupModule > pData ) {

    quint32 idTaskGroup = pData.data() -> getIdTaskGroup();
    quint32 idTask = pData.data() -> getIdTask();
    Group group = pData.data() -> getGroup();
    m_IdTaskGroupIdTaskContainer.addValue( idTaskGroup,
                                           idTask );
    m_IdTaskGroupGroupContainer.addValue( idTaskGroup,
                                          group );
    addGroup( idTaskGroup,
              idTask,
              group );
}

#include "TaskModule.h"


void TaskModule::updateTitle( int const &idTask,
                              QString const &title ) {

    QSharedPointer < DataItemModelForStandartItemBaseModel > pData = initializeNewDataForStandartItemBaseModel( idTask,
                                                                                                                title );
    m_pTaskModel.data() -> updateItemInModel( pData );
}


void TaskModule::addTask( Task const &task ){

    int idTask = task.getIdTask();
    int idDiscipline = task.getIdDiscipline();
    //указываем родителя - дисциплину
    QPersistentModelIndex parent = m_pDisciplineModel.data() -> getModelIndexById( idDiscipline );

    QSharedPointer < DataItemModelForStandartItemBaseModel > pData = initializeNewDataForStandartItemBaseModel( idTask,
                                                                                                                task.getName(),
                                                                                                                parent );
    addNewItem( m_pTaskModel,
                pData,
                m_pDisciplineModel.data() -> getModelItemDescriptor( idDiscipline ) );

    m_pNotificationManager.data() -> addNotification( NotificationType::ITEM_IS_NEW,
                                                      m_pTaskModel.data() -> getModelItemDescriptor( idTask) );

    m_pTaskTextDescriptionModule.data() -> addData( task );
}


TaskModule::TaskModule( QSharedPointer < TreeStandartItemBaseModel > pDisciplineModel,
                        QSharedPointer < TaskTextDescriptionModule > pTaskTextDescriptionModule,
                        QSharedPointer < IconItemManager > pIconItemManager,
                        QSharedPointer < NotificationManager > pNotificationManager ) : BaseModule( pIconItemManager,
                                                                                                    pNotificationManager ) {

    m_pDisciplineModel = pDisciplineModel;
    //Не забываем, что Task у нас все-таки входит в модель дисциплин,
    //а иначе как нам еще ссылаться на элементы другой модели? :)
    //поэтому забираем QStandartItemModel у модели дисциплин
    m_pTaskModel = initializeNewStandartItemBaseModel( m_pDisciplineModel.data() -> getMyStandardItemModel(),
                                                       TypeModel::TASK_TYPE_MODEL );
    m_pTaskTextDescriptionModule = pTaskTextDescriptionModule;

    QObject::connect( m_pTaskModel.data(),
                      &TreeStandartItemBaseModel::sendIdItemSelected,
                      m_pTaskTextDescriptionModule.data( )-> getTaskTextDescriptionModel().data(),
                      &ModelTextTaskDescription::taskItemSelected );
}


void TaskModule::addData( QSharedPointer < DataForTaskModule > pData ) {

    //пока что обрабатывает НОВОЕ добавление лабораторной
    Task task = pData.data() -> getTask();
    int idTask = task.getIdTask();
    if ( pData.data() -> getDataInfo() == DataInfo::THIS_IS_NEW_DATA ) {

        m_TaskTable.addValue( idTask,
                              task );
        addTask( task );
    }
}


QSharedPointer < TreeStandartItemBaseModel > TaskModule::getTaskModel() {

    return m_pTaskModel;
}


Task TaskModule::getTask( int idTask ) {

    return m_TaskTable.getValue( idTask );
}


Task TaskModule::getCurrentTask() {

    //получение описание лабы, которой соотв. текущий путь
    //поэтому полагаем, что TASK СУЩЕСТВУЕТ!
    int idTask = getCurrentTaskId();
    return getTask( idTask );
}


int TaskModule::getCurrentTaskId() {

    assert( m_pTaskModel.data() -> getActiveModelItemDescriptor().data() != nullptr );
    return m_pTaskModel.data() -> getActiveModelItemDescriptor().data() -> getIdItem();
}


bool TaskModule::isThereAnyCurrenTask() {

    return m_pTaskModel.data() -> getActiveModelItemDescriptor().data() != nullptr;
}


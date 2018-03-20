#include "AttachProjectModule.h"


void AttachProjectModule::setAttachMenuButtonEnableStatus( bool status ) {

    m_pMenuModel.data() -> setEnableStatus( TypeMenu::ATTACH_PROJECT_MENU_ITEM,
                                            status );
}


void AttachProjectModule::setRunProjectMenuButtonEnableStatus( bool status ) {

    m_pRunProjectModule.data() -> setRunProjectMenuButtonEnableStatus( status );
}


void AttachProjectModule::taskMenuItemSelected() {

    //обрабатываем нажатие на лабу
    //нужно сделать активной Run кнопку если путь уже назначен
    setAttachMenuButtonEnableStatus( true );
    int idActiveTask = m_pTaskModule.data() -> getCurrentTaskId();
    //если путь уже имеется - устанавливаем видимость, в противном случае - НЕТ
    m_IdTaskAttachProjectPathContainer.isContain( idActiveTask ) ? setRunProjectMenuButtonEnableStatus( true ):
                                                                   setRunProjectMenuButtonEnableStatus( false );
}


void AttachProjectModule::isntTaskMenuSelected() {

    setAttachMenuButtonEnableStatus( false );
    //также делаем недоступной кнопку отправки!
    setRunProjectMenuButtonEnableStatus( false );
}


//Раз уж получаю TaskModule, быть может имеет смысл не передавать TaskModel через конктруктор :)
AttachProjectModule::AttachProjectModule( QSharedPointer < ModelByQActionItem > pMenuModel,
                                          QSharedPointer < TreeStandartItemBaseModel > pTaskModel ,
                                          QSharedPointer < TreeStandartItemBaseModel > pDisciplineModel,
                                          QSharedPointer < RunProjectModule > pRunProjectModule ,
                                          QSharedPointer < TaskModule > pTaskModule ) {

    m_pMenuModel = pMenuModel;
    m_pTaskModel = pTaskModel;
    m_pDisciplineModel = pDisciplineModel;
    m_pRunProjectModule = pRunProjectModule;
    m_pTaskModule = pTaskModule;

    connect( pMenuModel.data(),
             &ModelByQActionItem::attachProjectSelected,
             this,
             &AttachProjectModule::attachProjectSelectedSlot );

    //Ничего страшного, что сигнал sendIdItemSelected посылает idItem - самое главное, что мы в курсе о том,
    //что элемент был все-таки кликнут
    connect( m_pTaskModel.data(),
             &TreeStandartItemBaseModel::sendIdItemSelected,
             this,
             &AttachProjectModule::taskMenuItemSelected );

    connect( m_pDisciplineModel.data(),
             &TreeStandartItemBaseModel::sendIdItemSelected,
             this,
             &AttachProjectModule::isntTaskMenuSelected );

    m_IdTaskForLastAttach = THERE_IS_NO_LAST_ATTACH;

    setAttachMenuButtonEnableStatus( false );

    m_IdTaskForLastAttach = 0;
}


Task AttachProjectModule::getTaskForCurrentPath() {

    //выдает конкретно ТУ задачу, на которую был выдан в последний раз путь!
    assert( m_IdTaskForLastAttach != 0 );
    return m_pTaskModule.data() -> getTask( m_IdTaskForLastAttach );
}


QString AttachProjectModule::getPathForCurrentTask() {

    QString path;
    int idTask = m_pTaskModule.data() -> getCurrentTaskId();
    if ( m_IdTaskAttachProjectPathContainer.isContain( idTask ) ) {

        path = m_IdTaskAttachProjectPathContainer.getValue( idTask );
        //запоминаем id той задачи, на которую выдали путь
        m_IdTaskForLastAttach = idTask;
    }

    return path;
}

void AttachProjectModule::attachProjectSelectedSlot() {


    //пока что просто испускаем сигнал - но в скором времени
    //понадобится предварительная обработка нажатия
    //прежде чем выводит диалоговое окно

    //проверяем, выбрана ли какая работа
    ///НЕ НРАВИТСЯ ПРОВЕКА ЕСЛИ ЧЕСТНО :(
    if ( m_pTaskModel.data() -> getActiveModelItemDescriptor().data() ) {

        m_IdTaskForLastAttach = m_pTaskModule.data() -> getCurrentTaskId();
        emit attachProjectSelectedSignal();
    }
}


//СЮДА приходит строка с путем от AttachProjectView
//В принципе, можно быть уверенным - что путь пришел именно от окна.
//и что пользователь ВЫБРАЛ путь.
//Иначе сигнал от AttachProjectView так и не дойдет
void AttachProjectModule::attachProjectPathSlot( QString attachProjectPath ) {

    assert( m_IdTaskForLastAttach != THERE_IS_NO_LAST_ATTACH );
    m_IdTaskAttachProjectPathContainer.addValue( m_IdTaskForLastAttach,
                                                 attachProjectPath );
    setRunProjectMenuButtonEnableStatus( true );
}

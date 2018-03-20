#include "RunProjectModule.h"


void RunProjectModule::setRunProjectMenuButtonEnableStatus( bool status ) {

    m_pMenuModel.data() -> setEnableStatus( TypeMenu::RUN_PROJECT_MENU_ITEM,
                                            status );
}


void RunProjectModule::setAttachProjectModule( QSharedPointer < AttachProjectModule > pAttachProjectModule ) {

    m_pAttachProjectModule = pAttachProjectModule;
}


void RunProjectModule::runProjectViewSlot() {

    //НАЧИНАЕМ обработку нажатия на кнопку отправки кода
    //Так как RunProjectView сделал все свои дела!
    //Сюда попадаем тогда, когда НУЖНО начинать формировать запрос на отправку
    //Повторюсь, на сегодняшнем варианте архитектуры, сюда я попадаю
    // от RunProjectView - от его сигнала :)
    QString path = m_pAttachProjectModule.data() -> getPathForCurrentTask();

    //если путь действительно существует!
    if ( !path.isEmpty() ) {
        //получаем описание текущей лабораторной и забираем у нее idUserlab
        ///ВНИМАНИЕ
        /// ЗДЕСЬ НАДЕЕМСЯ НА ТО, ЧТО ЗАДАЧА ДЕЙСТВИТЕЛЬНО УЖЕ СУЩЕСТВУЕТ
        int idUserLab = m_pAttachProjectModule.data() -> getTaskForCurrentPath().getIdUserLab();
        m_pRequestHandler.data() -> doRunModule( idUserLab,
                                                 path );
    }
}


RunProjectModule::RunProjectModule( QSharedPointer < ModelByQActionItem > pMenuModel,
                                    QSharedPointer < RequestHandler > pRequestHandler ) {

    m_pMenuModel = pMenuModel;
    m_pRequestHandler = pRequestHandler;
    setRunProjectMenuButtonEnableStatus( false );

    //перенаправляем на СВОЙ сигнал
    //который будет доставлен RunProjectView
    connect( pMenuModel.data(),
             &ModelByQActionItem::runProjectSelected,
             this,
             &RunProjectModule::runProjectItemSelected );
}

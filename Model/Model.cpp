#include "Model.h"
#include <MacroDefinitons/DestroyPointerMacro.h>
#include <QFile>
#include <Data/DisciplineDescriptionData.h>
#include <Model/BaseModel/StandardItemBaseModel/StandartItemBaseModell.h>
#include <Model/BaseModel/BaseModel.h>
#include <Data/Discipline/DataForDisciplineModule.h>

Model::Model() {

    m_pClient = QSharedPointer < Client > ( new Client() );

    m_pRequestHandler = QSharedPointer < RequestHandler >( new RequestHandler( m_pClient ) );
    m_pDataModule = QSharedPointer < DataModule >( new DataModule( m_pRequestHandler ) );
    m_pRequestHandler.data() -> setDataModule( m_pDataModule );

    m_pResponseHandler = QSharedPointer < ResponseHandler > ( new ResponseHandler ( m_pDataModule,
                                                                                    m_pRequestHandler ) );

    //модуль клиента отсылает респонсы (response) обработчику респонсов
    // по сигналу
    connect( m_pClient.data(),
             &Client::sendResponse,
             m_pResponseHandler.data(),
             &ResponseHandler::getResponse );

    m_pRequestHandler.data() -> doConnectionToServerAndDoAuth();

   /* QString str = QString( "Дисциплины" );

    DataItemModelForModelByQActionItem *pDisciplineMenuDataItem = new DataItemModelForModelByQActionItem( TypeMenu::DISCIPLINE_MENU_ITEM,
                                                                                                          str );
    m_ModelContainer.addDataInModel( TypeModel::MENU_TYPE_MODEL,
                                     pDisciplineMenuDataItem );
    m_ModelContainer.addDescriptor( TypeModel::MENU_TYPE_MODEL,
                                    TypeMenu::DISCIPLINE_MENU_ITEM );
    m_pIconItemManager -> setItemIcon( m_ModelContainer.getDescriptor( TypeModel::MENU_TYPE_MODEL,
                                                                       TypeMenu::DISCIPLINE_MENU_ITEM ),
                                       IconStatus::DEFAULT_ICON_STATUS,
                                       IconSetReason::FOREVER_SET_REASON );

                                       */
    //m_NotificationManager -> addNotification( NotificationType::ITEM_IS_NEW,
                                             // m_ModelContainer.getDescriptor( TypeModel::MENU_TYPE_MODEL,
                                               //                                                                    TypeMenu::DISCIPLINE_MENU_ITEM ));

    /*DataItemModelForStandartItemBaseModel *pData = new DataItemModelForStandartItemBaseModel();
    pData->setId( 1 );
    pData->setTitle( "HELLO VASYA!");
    ///НАДО УБРАТЬ ИНИЦИАЛИЗАЦИЮ ИКОНОК ЧЕРЕЗ DataItemModel
    /// У меня же этим занимается строго IconItemmanager!!!!!!!
    /// ВСЕ ЧТО СВЯЗАНО С ИКОНКАМИ СТРОГО ЧЕРЕЗ ICONITEMMANAGER
    addDataInModel( TypeModel::DISCIPLINE_TYPE_MODEL,
                    pData );
    m_ModelContainer.getValue( TypeModel::DISCIPLINE_TYPE_MODEL ) -> addModelItemDescritor( 1 );
    m_pIconItemManager->setItemIcon( m_ModelContainer.getValue( TypeModel::DISCIPLINE_TYPE_MODEL )->getModelItemDescriptor(1),
                                     IconStatus::DEFAULT_ICON_STATUS,
                                     IconSetReason::FOREVER_SET_REASON );
*/




    /*
    m_p_MenuModel -> setMenuItem( TypeMenu::DISCIPLINE_MENU_ITEM,
>>>>>>> ARCHITECTURE_TEMPLATE_VERSION_OF_MODEL
                                str,
                                m_p_IconBuffer -> getIcon( TypeModel::MENU_TYPE_MODEL,
                                                           TypeModelItem::MENU_DISCIPLINE_MODEL_ITEM,
                                                           IconStatus::DEFAULT_STATUS ) );


    m_p_DisciplineDescriptionModel = new DisciplineDescriptionModel();
    //m_p_TaskModel = new TaskModel();
    m_p_TaskDescriptionModel = new TaskDescriptionModel();

    connect( m_p_DisciplineModel,
             &DisciplineModel::sendIdDisciplineItemSelected,
             m_p_DisciplineDescriptionModel,
             &DisciplineDescriptionModel::callSendDisciplineDescriptionForcibly );

    connect( m_p_DisciplineModel,
             &DisciplineModel::sendIdTaskItemSelected,
             m_p_TaskDescriptionModel,
             &TaskDescriptionModel::callSendTaskDescriptionForcibly );

    ////!!!!!!!!!!!!!!

    connect( &m_NotificationTimer,
             &NotificationTimer::notificationSignal,
             &m_NotificationQueue,
             &NotificationQueue::doNotification );

    Task task1;
    Discipline discipline_1;
    discipline_1.setIdDiscipline( 1 );
    DisciplineDescriptionData descriptionData_1;
    descriptionData_1.setTitle( "Алгоритмы и структуры данных (1 семестр)");
    descriptionData_1.addDescription( "Изучение основ алгоритмов обработки данных" );
    descriptionData_1.addFileLink( ":/Resources/images/Model/DisciplineModel/WordLogo.png",
                    "Скачать методические указания" );
    descriptionData_1.addFileLink( ":/Resources/images/Model/DisciplineModel/Notepad.png",
                    "Скачать пример тестовых данных" );

    discipline_1.setDescription( descriptionData_1.getHTMLText() );
    discipline_1.setName( "Алгоритмы и структуры данных" );

    NotificationItem *parentForDiscipline = m_p_MenuModel->getNotificationItem( TypeModel::MENU_TYPE_MODEL,
                                                                                TypeModelItem::MENU_DISCIPLINE_MODEL_ITEM );
    m_p_DisciplineModel -> addDiscipline( discipline_1,
                                          m_p_IconBuffer -> getIcon( TypeModel::DISCIPLINE_TYPE_MODEL,
                                                                     TypeModelItem::DISCIPLINE_MODEL_ITEM,
                                                                     IconStatus::DEFAULT_STATUS ),
                                          parentForDiscipline );
    /*
    Discipline d2;
    d2.setIdDiscipline( 2 );
    d2.setDescription( "Дисциплина №2" );
    d2.setName( "Дисциплина №2" );
    m_p_DisciplineModel -> addDiscipline( d2,
                                          m_p_IconBuffer -> getIcon( TypeModel::DISCIPLINE_TYPE_MODEL,
                                                                     TypeModelItem::DISCIPLINE_MODEL_ITEM,
                                                                     IconStatus::DEFAULT_STATUS ) );

                                                                     */
    /*
    m_p_DisciplineDescriptionModel -> setDescriptionData( discipline_1.getIdDiscipline(),
                                                          descriptionData_1 );

    QFile f("1.txt");
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QString txt;
    txt =  QString( f.readAll() );

    Task t;
    QString textlab1;
    t.setIdDiscipline( 1 );
    t.setIdTask( 1 );
    t.setName( "Лабораторная работа №1. Динамический массив." );

    textlab1 += "<BODY BACKGROUND="":/Resources/images/Model/DisciplineModel/7554.jpg"">";

    textlab1 += "<h2><p align=""center""><font color=""black""><b>";
    textlab1 += t.getName();
    textlab1 += "</b></p></h2></font><br>";
    textlab1 += "<h3><font color=""black"">Языки программирования:</h3></font><br>";

    textlab1 += "<img src =':/Resources/images/Model/Language/c.png'>\
            <img src =':/Resources/images/Model/Language/cpp.png'>\
            <img src =':/Resources/images/Model/Language/pas.png'>\
            <br>";

    textlab1 += "<font color=""black""><br><h3><i>Описание:</i>";
    textlab1 += "<br> Здесь краткое описание постановки задачи в лабораторной работе. </h3><br></font>";
    textlab1 += "<h3><font color=""black"">Пример тестовых данных:<br>";
    textlab1 += " <table cellspacing=""2"" border=""2"" cellpadding=""5"" width=""600"">\
    <tr><td width=30>№</td><td>INPUT.TXT</td><td>OUTPUT.TXT</td></tr>\
    <tr><td align=center>1</td><td>5</td><td>15</td></tr>\
    </table></font><br><br>";
    textlab1 += "<h3><font color=""black"">Желательный срок сдачи: 20.10.2015<br>\
            Крайний срок сдачи: 12.12.2015</font></h3><br><br>";
    textlab1 += "<img src =':/Resources/images/Model/DisciplineModel/WordLogo.png'> <a href=""hello"">Скачать методические указания</a>";

    t.setPurpose( textlab1 );
    NotificationItem *pParentNotificationItem = m_p_DisciplineModel-> getNotificationItem( TypeModel::DISCIPLINE_TYPE_MODEL,
                                                                                          TypeModelItem::DISCIPLINE_MODEL_ITEM,
                                                                                          t.getIdDiscipline() );
    m_p_DisciplineModel->addTask( t,
                                  m_p_IconBuffer -> getIcon( TypeModel::DISCIPLINE_TYPE_MODEL,
                                                             TypeModelItem::TASK_MODEL_ITEM,
                                                             IconStatus::DEFAULT_STATUS ),
                                  pParentNotificationItem );

    m_p_TaskDescriptionModel->addTask( t.getIdTask(), t );
    */
//////ПРИ ДОБАВЛЕНИИ БОЛЬШИХ ЗАДАЧ НЕ РАБОТАЕТ ОПОВЩЕНЕНИ!!!!
/*
    Task t2;
    t2.setIdDiscipline( 2 );
    t2.setIdTask( 2 );
    t2.setName( "Обработка массива данных2" );
    t2.setPurpose( txt );
    m_p_DisciplineModel -> addTask( t2, m_p_IconBuffer -> getIcon( IconName::TASK_MODEL_ICON,
                                                                   IconStatus::DEFAULT_STATUS) );
*/
////РАЗОБРСЯТЬ, ПОЧЕМУ ПЕРЕСТАЕТ РАБОТАТЬ ОПОВЕЩЕНИЕ!!!!!!!!!
///
///
/*
    Task t4;
    t.setIdDiscipline( 1 );
    t.setIdTask( 4 );
    t.setName( "Обработка массива данных4444" );
    t.setPurpose( txt );
    m_p_DisciplineModel -> addTask( t4, m_p_IconBuffer -> getIcon( IconName::TASK_MODEL_DEFAULT_ICON ) );
*/
/*    m_NotificationQueue.addElementInQueue( m_p_DisciplineModel,
                                           t.getIdTask(),
                                           TypeModelItem::TASK );

    m_NotificationQueue.addElementInQueue( m_p_MenuModel,
                                           TypeMenu::DISCIPLINE_MENU_ITEM,
                                           TypeModelItem::MENU );

*/
/*
    m_NotificationQueue.addElementInQueue( m_p_DisciplineModel -> getTaskModelIndexByTaskId( t3.getIdTask() ),
                                           m_p_DisciplineModel );
    m_NotificationQueue.addElementInQueue( m_p_DisciplineModel -> getTaskModelIndexByTaskId( t2.getIdTask() ),
                                           m_p_DisciplineModel );


    m_NotificationTimer.startNotifications();
*/

}

Model::~Model() {

    //DestroyPointer( m_pIconBuffer )
}


QSharedPointer < AttachProjectModule > Model::getAttachProjectModule() {

    return m_pDataModule.data()-> getAttachProjectModule();
}


QSharedPointer < RunProjectModule > Model::getRunProjectModule() {

    return m_pDataModule.data() -> getRunProjectModule();
}


QSharedPointer < TreeStandartItemBaseModel > Model::getDisciplineModel() {

    return m_pDataModule.data() -> getDisciplineModule().data() -> getDisciplineModel();
}


QSharedPointer < TreeStandartItemBaseModel > Model::getTaskModel() {

    return m_pDataModule.data() -> getTaskModule().data() -> getTaskModel();
}


QSharedPointer < TreeStandartItemBaseModel > Model::getTestModel() {

    return m_pDataModule.data()->getTestModule().data()->getTestModel();
}


QSharedPointer<TreeStandartItemBaseModel> Model::getAboutTestModel() {

    return m_pDataModule.data() -> getAboutTestModule().data() -> getAboutTestModel();
}



QSharedPointer < ModelByQActionItem > Model::getMenuModel() {

    return m_pDataModule.data() -> getMenuModule().data() -> getMenuModel();
}


QSharedPointer<ModelTextDisciplineDescription> Model::getDisciplineTextDescriptionModel() {

    return m_pDataModule.data() -> getDisciplineTextDescriptionModule().data() -> getDisciplineTextDescriptionModel();
}


QSharedPointer<ModelTextTaskDescription> Model::getTaskTextDescriptionModel() {

    return m_pDataModule.data() -> getTaskTextDescriptionModule().data() -> getTaskTextDescriptionModel();
}


QSharedPointer < TreeStandartItemBaseModel > Model::getAnalyzeModel() {

    return m_pDataModule.data() -> getStaticAnalyzerModule().data() -> getStaticAnalyzerModel();
}


QSharedPointer<TreeStandartItemBaseModel> Model::getSubAnalyzeModel() {

    return m_pDataModule.data() -> getSubStaticAnalyzerModule().data() -> getSubStaticAnalyzerModel();
}

QSharedPointer<SubStaticAnalyzerModule> Model::getSubStaticAnalyzerModule() {

    return m_pDataModule.data()->getSubStaticAnalyzerModule();
}



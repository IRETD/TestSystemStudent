#include "TestModule.h"


void TestModule::addTest( History history ) {

    int idUserLab = history.getIdUserLab();
    m_TestContainer.addValue( idUserLab,
                              history );
}

void TestModule::showHistoryIntoModel( int idUserLab ) {


    //СОРТИРОВКА!!!
    //НЕЛЬЗЯ БЫТЬ УВЕРЕННЫМ, ЧТО ПОСТУПИВШИЕ ДАННЫЕ В КОНТЕЙНЕР РАСПОЛОЖЕНЫ В НУЖНОМ ДЛЯ ВЫВОДА ПОРЯДКЕ
    QList < History > historyList = m_TestContainer.getContainerValue( idUserLab );
    quint32 historyNumber = 0;
    foreach( History history, historyList ) {

        //увеличиваем текущий номер истории
        historyNumber++;
        int idHistory = history.getIdHistory();
        QString historyTitle = "Попытка сдачи № " +
                               QString::number( historyNumber ) +
                               " " +
                                history.getDateHistory().toString();
        QSharedPointer < DataItemModelForStandartItemBaseModel > pData = initializeNewDataForStandartItemBaseModel( idHistory,
                                                                                                                    historyTitle );
        addNewItem( m_pTestModel,
                    pData );

        m_pNotificationManager.data() -> addNotification( NotificationType::ITEM_IS_NEW,
                                                          m_pTestModel.data() -> getModelItemDescriptor( idHistory ) );
    }
}

void TestModule::clearHistoryIntoModel() {


    //пока что вот так вот просто подчищаем
    m_pTestModel.data() -> clearItemsInModel();
}


void TestModule::testSelectedSlot() {

    //был выбран пункт меню по отображению тестов текущей лабы

    //убеждаемся что была выбрана хоть какая-нибудь лабораторная (там указатель на ModelItemDescriptor)!!!
    if ( m_pTaskModule.data() -> isThereAnyCurrenTask() ) {
        Task currentTask = m_pTaskModule.data() -> getCurrentTask();
        int idUserLab = currentTask.getIdUserLab();
        //если какая-либо история для такой лабы есть
        if ( m_TestContainer.isContain( idUserLab ) ) {

           showHistoryIntoModel( idUserLab );
        }
        else {

            //пока что просто делаем clear :)
            clearHistoryIntoModel();
        }
    }

    //НЕ ЗАБЫВАЕМ ОЧИЩАТЬ!!!
}


void TestModule::testItemSelected( int idHistory ) {


    m_pAboutTestModule.data() -> setCurrentAboutHistoryInModel( idHistory );
    m_pStaticAnalyzerModule.data() -> setCurrentAboutHistory( idHistory );
}


TestModule::TestModule( QSharedPointer < ModelByQActionItem > pMenuModel,
                        QSharedPointer < IconItemManager > pIconItemManager,
                        QSharedPointer < NotificationManager > pNotificationManager ,
                        QSharedPointer < TaskModule > pTaskModule ,
                        QSharedPointer < AboutTestModule > pAboutTestModule ) : BaseModule( pIconItemManager,
                                                                                            pNotificationManager ) {

    m_pStaticAnalyzerModule = QSharedPointer < StaticAnalyzerModule > ( new StaticAnalyzerModule( pMenuModel,
                                                                                                  pIconItemManager,
                                                                                                  pNotificationManager ) );
    m_pMenuModel = pMenuModel;
    m_pTaskModule = pTaskModule;
    m_pAboutTestModule = pAboutTestModule;
    m_pTestModel = initializeNewStandartItemBaseModel( TypeModel::TEST_TYPE_MODEL );

    connect( m_pMenuModel.data(),
             &ModelByQActionItem::testSelected,
             this,
             &TestModule::testSelectedSlot );

    //Ловим нажатие на конкретный пункт ИСТОРИИ
    connect( m_pTestModel.data(),
             &TreeStandartItemBaseModel::sendIdItemSelected,
             this,
             &TestModule::testItemSelected );
}


QSharedPointer < TreeStandartItemBaseModel > TestModule::getTestModel() {

    return m_pTestModel;
}

void TestModule::addData( QSharedPointer < DataForTestModule > pData ) {

    History history = pData.data() -> getHistory();
    if ( pData.data() -> getDataInfo() == DataInfo::THIS_IS_NEW_DATA ) {

        addTest( history );
    }
}


QSharedPointer < StaticAnalyzerModule > TestModule::getStaticAnalyzerModule() {

    return m_pStaticAnalyzerModule;
}


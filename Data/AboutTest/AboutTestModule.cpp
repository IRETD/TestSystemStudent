#include "AboutTestModule.h"
#include <QtAlgorithms>
#include <Data/Test/AboutHistory.h>

void AboutTestModule::addAboutHistory( QSharedPointer < DataForAboutTestModule > pData ) {

    AboutHistory aboutHistory = pData.data() -> getAboutHistory();

    //запрашиваем данные по АНАЛИЗУ
    ///ПОКА ЧТО ВОТ ТАК КРИВО, ПОТОМ ЕСТЕСТВЕННО ИСПРАВИТЬ!!!!
    if ( aboutHistory.getStepType() == StepType::ANALYZE &&
         aboutHistory.getResult() == TestResult::FAIL_TEST ) {

        m_pRequestHandler.data() -> doAnalyzeData( aboutHistory.getIdHistory(),
                                                   aboutHistory.getIdAboutHistory() );
    }

    addColumnInContainer( aboutHistory.getDescription(),
                          aboutHistory,
                          IdColumnAboutHistory::STEP );

    addColumnInContainer( aboutHistory.getTextResult(),
                          aboutHistory,
                          IdColumnAboutHistory::RESULT );

    addColumnInContainer( aboutHistory.getMemory(),
                          aboutHistory,
                          IdColumnAboutHistory::MEMORY );

    addColumnInContainer( aboutHistory.getTime(),
                          aboutHistory,
                          IdColumnAboutHistory::TIME );

    addColumnInContainer( aboutHistory.getAdditionalColumn(),
                          aboutHistory,
                          IdColumnAboutHistory::ADDITIONAL_COLUMN );
}


void AboutTestModule::addColumnInContainer( QString text,
                                            AboutHistory &aboutHistory,
                                            IdColumnAboutHistory idColumn ) {

    ////БЫЛ ВАРИАНТ ПРОВЕРКУ НА ПУСТОТЫ СТРОКИ
    /// И В ТАКОМ СЛУЧАЕ НЕ ДОБАВЛЯТЬ СТОЛБЕЦ
    /// НО НЕ РАБОТАЕТ!!! (информация сдвигается, если возникает ПРОМЕЖУТОК
    /// по информации между столбцами
    //if ( !text.isEmpty() ) {

        int idHistory = aboutHistory.getIdHistory();
        int idAboutHistory = aboutHistory.getIdAboutHistory();

        ValueAboutHistory valueAboutHistory;
        valueAboutHistory.value = text;
        valueAboutHistory.testResult = aboutHistory.getResult();

        m_AboutHistoryContainer.addValue( idHistory,
                                          idAboutHistory,
                                          static_cast < int > ( idColumn ),
                                          valueAboutHistory );
        // }
}


void AboutTestModule::clearAboutHistoryInModel() {

    m_pAboutTestModel.data() -> clearItemsInModel();
}


AboutTestModule::AboutTestModule( QSharedPointer < IconItemManager > pIconItemManager,
                                  QSharedPointer < NotificationManager > pNotificationManager ,
                                  QSharedPointer < RequestHandler > pRequestHandler ) : BaseModule( pIconItemManager,
                                                                                                    pNotificationManager ) {
    ///УКАЗЫАЕМ, ЧТО НАША МОДЕЛЬ - ТАБЛИЦА
    m_pRequestHandler = pRequestHandler;
    m_pAboutTestModel = initializeNewStandartItemBaseModel( TypeModel::ABOUT_TEST_TYPE_MODEL,
                                                            TypeStandartItemModel::TABLE_TYPE );

}


void AboutTestModule::addData( QSharedPointer < DataForAboutTestModule > pData ) {

     if ( pData.data() -> getDataInfo() == DataInfo::THIS_IS_NEW_DATA ) {

         addAboutHistory( pData );
     }
}


QSharedPointer < TreeStandartItemBaseModel > AboutTestModule::getAboutTestModel() {

    return m_pAboutTestModel;
}


void AboutTestModule::setCurrentAboutHistoryInModel( int idHistory ) {

    //ПОКА ЧТО ПРОСТО ОЧИЩАЕМ ИСТОРИЮ ВОТ ТАК ВОТ :)
    ///ИСПРАВИТЬ ЭТО БЕЗОБРАЗИЕ!!!
    //m_pAboutTestModel.data() -> clearItemsInModel();
    //если есть какая-либо информация по этой истории

    ///НЕ ПОМЕШАЛО БЫ ДЕЛАТЬ ПРОВЕРКУ НА ТЕКУЩУЮ ОТОБРАЖАЕМУЮ ИСТОРИЮ
    /// ЧТОБЫ ЛИШНИЙ РАЗ НЕ ПЕРЕОТОБРАЖАТЬ ОДНО И ТОЖЕ
    clearAboutHistoryInModel();
    if ( m_AboutHistoryContainer.isContainsKey1( idHistory ) ) {

        QList < int > idAboutHistoryList = m_AboutHistoryContainer.getKey2List( idHistory );
        //Сортируем, дабы вывести в правильном порядке!
        qSort( idAboutHistoryList.begin(),
               idAboutHistoryList.end() );
        foreach( int idAboutHistory, idAboutHistoryList ) {

            QList < int > cloumnIdList = m_AboutHistoryContainer.getKey3List( idHistory,
                                                                              idAboutHistory );
            qSort( cloumnIdList.begin(),
                   cloumnIdList.end() );
            foreach( int columnId, cloumnIdList ) {

                ValueAboutHistory valueAboutHistory = m_AboutHistoryContainer.getValue( idHistory,
                                                                                        idAboutHistory,
                                                                                        columnId );
                QString value = valueAboutHistory.value;
                QSharedPointer < DataItemModelForStandartItemBaseModel > pData = initializeNewDataForStandartItemBaseModel( idAboutHistory,
                                                                                                                            columnId,
                                                                                                                            value );
                addNewItemWithoutIconManager( m_pAboutTestModel,
                                              pData );

                //УБИРАЕМ ПОКА ЧТО ОПОВЕЩЕНИЯ
                /*
                m_pNotificationManager.data() -> addNotification( NotificationType::ITEM_IS_NEW,
                                                                  m_pAboutTestModel.data() -> getModelItemDescriptor( idHistory ) );
                                                                  */
            }
        }

        //отпавляем сигнал на показ окна с моделью!
        ///ЕСЛИ ДАННЫХ НИКАКИХ ДЛЯ ИСТОРИИ НЕТ, ОКНО НЕ БУДЕТ ПОКАЗАНО!!!!
        emit m_pAboutTestModel.data() -> showViewContext( ViewContextType::ABOUT_TEST_VIEW_CONTEXT );
    }
}

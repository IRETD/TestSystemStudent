#ifndef TESTMODULE_H
#define TESTMODULE_H

#include <Data/BaseModule.h>
#include <Data/SubBaseModuleForTreeStandartItemBaseModel.h>
#include <Model/BaseModel/PureBaseModel/ModelByQActionItem.h>
#include <Data/Test/DataForTestModule.h>
#include <MyStorageType/SingleKeyWithContainerValueContainer.h>

//Берем структуру History (она же по сути Test) из Сервер
#include "../../../../Diplom/TestSystem/TestSystem/data/history/History.h"
#include <Data/Test/DataForTestModule.h>
#include <Data/Task/TaskModule.h>
#include <Data/AboutTest/AboutTestModule.h>
#include <Data/StaticAnalyzer/StaticAnalyzerModule.h>

class AboutTestModule;

class TestModule : public QObject,
                   public BaseModule,
                   public SubBaseModuleForTreeStandartItemBaseModel {

    Q_OBJECT

    SingleKeyWithContainerValueContainer < int, //idUserLab
                                           History > //List
                                         m_TestContainer;



    QSharedPointer < ModelByQActionItem > m_pMenuModel;
    QSharedPointer < TreeStandartItemBaseModel > m_pTestModel;
    QSharedPointer < TaskModule > m_pTaskModule;
    QSharedPointer < AboutTestModule > m_pAboutTestModule;
    QSharedPointer < StaticAnalyzerModule > m_pStaticAnalyzerModule;

    void addTest( History history );
    void showHistoryIntoModel( int idUserLab );
    void clearHistoryIntoModel();

public slots:
    //ПО ПУНКТУ МЕНЮ ЩЕЛКНУЛИ
    void testSelectedSlot();

    //ВЫБРАЛИ КОНКРЕТНЫЙ ПУНКТ МЕНЮ!
    void testItemSelected( int idHistory );


public:
    TestModule( QSharedPointer < ModelByQActionItem > pMenuModel,
                QSharedPointer < IconItemManager > pIconItemManager,
                QSharedPointer < NotificationManager > pNotificationManager,
                QSharedPointer < TaskModule > pTaskModule,
                QSharedPointer < AboutTestModule > pAboutTestModule );

    QSharedPointer < TreeStandartItemBaseModel > getTestModel();
    void addData( QSharedPointer < DataForTestModule > pData );
    QSharedPointer < StaticAnalyzerModule > getStaticAnalyzerModule();
};

#endif // TESTMODULE_H

#ifndef ABOUTTEST_H
#define ABOUTTEST_H

#include <QObject>
#include <Data/BaseModule.h>
#include <Data/SubBaseModuleForTreeStandartItemBaseModel.h>
#include <Data/AboutTest/DataForAboutTestModule.h>
#include <MyStorageType/SingleKeyWithContainerValueContainer.h>
#include "../../../../Diplom/TestSystem/TestSystem/MacroDefinitions/Data/Test/IdColumnAboutHistory.h"
#include <Request/RequestHandler.h>

class RequestHandler;

class AboutTestModule : public QObject,
                        public BaseModule,
                        public SubBaseModuleForTreeStandartItemBaseModel {

    QSharedPointer < TreeStandartItemBaseModel > m_pAboutTestModel;
    void addAboutHistory( QSharedPointer < DataForAboutTestModule > pData );
    QSharedPointer < RequestHandler > m_pRequestHandler;

    struct ValueAboutHistory {

        QString value;
        TestResult testResult;
    };

    TripleKeyContainer < int, //idHistory
                         int, //idAboutHistory - row
                         int, //idColumn,
                         ValueAboutHistory //value
    > m_AboutHistoryContainer;

    /*
    SingleKeyWithContainerValueContainer < int, //idHistory
                                           AboutHistory > m_IdHistoryAboutHistoryContainer;
    */

    void addColumnInContainer( QString text,
                               AboutHistory &aboutHistory,
                               IdColumnAboutHistory idColumn );\

    void clearAboutHistoryInModel();
public:

    AboutTestModule( QSharedPointer < IconItemManager > pIconItemManager,
                     QSharedPointer < NotificationManager > pNotificationManager,
                     QSharedPointer < RequestHandler > pRequestHandler );

    void addData( QSharedPointer < DataForAboutTestModule > pData );
    QSharedPointer < TreeStandartItemBaseModel > getAboutTestModel();

    //установить ТЕКУЩЕЕ описание в моделе
    void setCurrentAboutHistoryInModel( int idHistory );
};

#endif // ABOUTTEST_H

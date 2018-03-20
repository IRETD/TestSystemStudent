#ifndef STATICANALYZERMODULE_H
#define STATICANALYZERMODULE_H

#include <MyStorageType/SingleKeyWithContainerValueContainer.h>
#include <MyStorageType/DoubleKeyWithContainerValueContainer.h>
#include <MyStorageType/DoubleKeyContainer.h>
#include <Data/StaticAnalyzer/StaticAnalyzer.h>
#include <QSharedPointer>
#include <Model/BaseModel/PureBaseModel/ModelByQActionItem.h>
#include <Data/BaseModule.h>
#include <Data/SubBaseModuleForTreeStandartItemBaseModel.h>
#include <Data/StaticAnalyzer/DataForStaticAnalyzer.h>
#include <Data/StaticAnalyzer/SubStaticAnalyzerModule.h>


class StaticAnalyzerModule : public QObject,
                             public BaseModule,
                             public SubBaseModuleForTreeStandartItemBaseModel {

    Q_OBJECT


    DoubleKeyWithContainerValueContainer < quint32, //idHistory - пока что инициализируем строго по ИСТОРИИ
                                           quint32, //тип ошибки, анализа TypeStaticAnalyzer
                                           StaticAnalyzer > m_IdAboutHistoryStaticAnalyzer;

    SingleKeyContainer < quint32, //TypeStaticAnalyzer
                         QString > m_TypeStaticAnalyzerTextContainer;
    DoubleKeyContainer < quint32, //idAboutHistory
                         quint32, //idCode
                         QString > m_IdAboutHistoryIdCode;

    QSharedPointer < ModelByQActionItem > m_pMenuModel;
    QSharedPointer < TreeStandartItemBaseModel > m_pStaticAnalyzerModel;
    QSharedPointer < SubStaticAnalyzerModule > m_pSubStaticAnalyzeModule;

    void addStaticAnalyzer( quint32 idHistory,
                            quint32 idAboutHistory,
                            QList < StaticAnalyzer > staticAnalyzerList,
                            SingleKeyContainer < quint32,
                                                 QString > idSourceCode );

public:
    StaticAnalyzerModule( QSharedPointer < ModelByQActionItem > pMenuModel,
                          QSharedPointer < IconItemManager > pIconItemManager ,
                          QSharedPointer < NotificationManager > pNotificationManager );
    void addData( QSharedPointer < DataForStaticAnalyzer > pData );

    QSharedPointer < TreeStandartItemBaseModel > getStaticAnalyzerModel();
    void setCurrentAboutHistory( quint32 idHistory );
    QSharedPointer < SubStaticAnalyzerModule > getSubStaticAnalyzerModule();
};

#endif

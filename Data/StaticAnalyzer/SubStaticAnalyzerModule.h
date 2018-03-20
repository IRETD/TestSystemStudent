#ifndef SUBSTATICANALYZERMODULE_H
#define SUBSTATICANALYZERMODULE_H

#include <MyStorageType/SingleKeyWithContainerValueContainer.h>
#include <MyStorageType/DoubleKeyWithContainerValueContainer.h>
#include <MyStorageType/DoubleKeyContainer.h>
#include <Data/StaticAnalyzer/StaticAnalyzer.h>
#include <QSharedPointer>
#include <Model/BaseModel/PureBaseModel/ModelByQActionItem.h>
#include <Data/BaseModule.h>
#include <Data/SubBaseModuleForTreeStandartItemBaseModel.h>
#include <Data/StaticAnalyzer/DataForStaticAnalyzer.h>


class SubStaticAnalyzerModule : public QObject,
                                public BaseModule,
                                public SubBaseModuleForTreeStandartItemBaseModel {
    Q_OBJECT

    QSharedPointer < TreeStandartItemBaseModel > m_pSubStaticAnalyzerModel;

    SingleKeyContainer < quint32, //idAboutStaticAnalyzer
                         StaticAnalyzer > m_IdStaticAnalyzer;
    SingleKeyContainer < quint32,
                         QString > m_IdCode;

    QString prepareCode( QString sourceCode,
                         QString comment,
                         quint32 line );

public:
    SubStaticAnalyzerModule( QSharedPointer < TreeStandartItemBaseModel > pStaticAnalyzerModel,
                             QSharedPointer < IconItemManager > pIconItemManager,
                             QSharedPointer < NotificationManager > pNotificationManager );
    void addIdStaticAnalyzer( quint32 idAboutStaticAnalyzer,
                              StaticAnalyzer &staticAnalyzer );
    void setIdCode( SingleKeyContainer < quint32,
                                         QString > idCode );
    void addSubStaticAnalyzeInModel( StaticAnalyzer &staticAnalyzer,
                                     QSharedPointer < ModelItemDescriptor > pParentModelItemDescriptor,
                                     QPersistentModelIndex &pParent );
    QSharedPointer < TreeStandartItemBaseModel > getSubStaticAnalyzerModel();

public slots:
    void itemSubStaticAnalyzerSelected( int idItem );


signals:
    void showViewContext( ViewContextType viewContextType );
    void sendCodeText( QString &codeText );
};

#endif


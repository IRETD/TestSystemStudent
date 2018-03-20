#ifndef MODEL_H
#define MODEL_H

#include <Client/Client.h>
#include <Data/Icon/IconItemManager.h>
#include <Model/Notification/NotificationManager.h>
#include <MyStorageType/SingleKeyContainer.h>
#include <Model/BaseModel/StandardItemBaseModel/SubClasses/TreeStandartItemBaseModel.h>
#include <Model/BaseModel/PureBaseModel/ModelByQActionItem.h>
#include <Data/DataModule.h>
#include <Data/DataSource/TestDataSource.h>
#include <Data/DataModule.h>

#include <Data/AttachProjectModule/AttachProjectModule.h>

#include <Response/ResponseHandler.h>
#include <Request/RequestHandler.h>

class DisciplineModel;

class Model : public QObject {

    Q_OBJECT

    QSharedPointer < Client > m_pClient;
    //QSharedPointer < IconItemManager > m_pIconItemManager;
    //QSharedPointer < NotificationManager > m_NotificationManager;
    //ModelContainer m_ModelContainer;
    //QSharedPointer < DataModule > m_pDataModule;
    QSharedPointer < DataModule > m_pDataModule;
    QSharedPointer < TestDataSource > m_pTestDataSource;
    QSharedPointer < ResponseHandler > m_pResponseHandler;
    QSharedPointer < RequestHandler > m_pRequestHandler;

public:
    Model();
    ~Model();

    //QSharedPointer < PureBaseComposition > getPureBaseComposition( TypeModel typeModel );
    //QSharedPointer < MyStandartItemModel > getMyStandartItemModel( TypeModel typeModel );
    QSharedPointer < AttachProjectModule > getAttachProjectModule();
    QSharedPointer < RunProjectModule > getRunProjectModule();
    QSharedPointer < TreeStandartItemBaseModel > getDisciplineModel();
    QSharedPointer < TreeStandartItemBaseModel > getTaskModel();
    QSharedPointer < TreeStandartItemBaseModel > getTestModel();
    QSharedPointer < TreeStandartItemBaseModel > getAboutTestModel();
    QSharedPointer < ModelByQActionItem > getMenuModel();
    QSharedPointer < ModelTextDisciplineDescription > getDisciplineTextDescriptionModel();
    QSharedPointer < ModelTextTaskDescription > getTaskTextDescriptionModel();
    QSharedPointer < TreeStandartItemBaseModel > getAnalyzeModel();
    QSharedPointer < TreeStandartItemBaseModel > getSubAnalyzeModel();
    QSharedPointer < SubStaticAnalyzerModule > getSubStaticAnalyzerModule();
};

#endif

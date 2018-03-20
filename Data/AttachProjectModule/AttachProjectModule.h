#ifndef CODEMODULE_H
#define CODEMODULE_H

#include <QString>
#include <Model/BaseModel/PureBaseModel/ModelByQActionItem.h>
#include <Data/RunProject/RunProjectModule.h>
#include <Model/BaseModel/StandardItemBaseModel/SubClasses/TreeStandartItemBaseModel.h>

#include "../SharedModules/Task.h"

class RunProjectModule;
class TaskModule;

class AttachProjectModule : public QObject {

    Q_OBJECT

    #define THERE_IS_NO_LAST_ATTACH -1

    QString m_AttachProjectPath;
    quint32 m_IdTaskForLastAttach;
    SingleKeyContainer < quint32,
                         QString > m_IdTaskAttachProjectPathContainer;

    //будем лоавить клик по кнопке
    QSharedPointer < ModelByQActionItem > m_pMenuModel;
    QSharedPointer < TreeStandartItemBaseModel > m_pTaskModel;
    QSharedPointer < TaskModule > m_pTaskModule;
    QSharedPointer < TreeStandartItemBaseModel > m_pDisciplineModel;
    QSharedPointer < RunProjectModule > m_pRunProjectModule;

    void setAttachMenuButtonEnableStatus( bool status );
    void setRunProjectMenuButtonEnableStatus( bool status );

private slots:
    void taskMenuItemSelected();
    void isntTaskMenuSelected();

public:
    AttachProjectModule( QSharedPointer < ModelByQActionItem > pMenuModel,
                         QSharedPointer < TreeStandartItemBaseModel > pTaskModel,
                         QSharedPointer < TreeStandartItemBaseModel > pDisciplineModel,
                         QSharedPointer < RunProjectModule > pRunProjectModule,
                         QSharedPointer < TaskModule > pTaskModule );

    Task getTaskForCurrentPath();
    QString getPathForCurrentTask();

signals:
    void attachProjectSelectedSignal();

public slots:
    void attachProjectSelectedSlot();

    //известен путь проекта
    void attachProjectPathSlot( QString attachProjectPath );
};

#endif

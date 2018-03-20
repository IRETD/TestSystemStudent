#ifndef RUNPROJECTMODULE_H
#define RUNPROJECTMODULE_H

#include <Model/BaseModel/PureBaseModel/ModelByQActionItem.h>
#include <Data/AttachProjectModule/AttachProjectModule.h>
#include <Request/RequestHandler.h>

class AttachProjectModule;
class RequestHandler;

class RunProjectModule : public QObject {

    Q_OBJECT

    QSharedPointer < ModelByQActionItem > m_pMenuModel;
    QSharedPointer < AttachProjectModule > m_pAttachProjectModule;
    QSharedPointer < RequestHandler > m_pRequestHandler;

signals:
    void runProjectItemSelected();

public slots:
    void runProjectViewSlot();

public:
    RunProjectModule( QSharedPointer < ModelByQActionItem > pMenuModel,
                      QSharedPointer < RequestHandler > pRequestHandler );

    void setPathSelectedStatus( bool status );
    //делаем открытой, чтобы AttachProjectModule мог управлять
    void setRunProjectMenuButtonEnableStatus( bool status );
    void setAttachProjectModule( QSharedPointer < AttachProjectModule > pAttachProjectModule );


};

#endif

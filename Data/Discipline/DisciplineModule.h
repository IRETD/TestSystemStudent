#ifndef DISCIPLINECONTAINER_H
#define DISCIPLINECONTAINER_H

#include <MyStorageType/SingleKeyContainer.h>
#include "DataForDisciplineModule.h"
#include <Enum/Data/Discipline/DisciplineFieldName.h>

#include <Model/BaseModel/StandardItemBaseModel/SubClasses/TreeStandartItemBaseModel.h>
#include <QSharedPointer>
#include <Data/Icon/IconItemManager.h>
#include <Model/BaseModel/PureBaseModel/ModelByQActionItem.h>
#include <Data/BaseModule.h>
#include <Data/SubBaseModuleForTreeStandartItemBaseModel.h>
#include <Data/Discipline/DescriptionDiscipline/DisciplineTextDescriptionModule.h>

class DisciplineModule : public BaseModule,
                         public SubBaseModuleForTreeStandartItemBaseModel {

    SingleKeyContainer < int,
                         Discipline > m_DisciplineContainer;


    QSharedPointer < ModelByQActionItem > m_pMenuModel;
    QSharedPointer < TreeStandartItemBaseModel > m_pDisciplineModel;
    QSharedPointer < DisciplineTextDescriptionModule > m_pDisciplineTextDescriptionModule;

    void updateIdDiscipline( int const &oldId,
                             int const &newId );
    void updateDescription( int const &idDiscipline,
                            QString const &textDescription );
    void updateTitle( int const &idDiscipline,
                      QString const &title );

    void addDiscipline( Discipline const &discipline );

public:
    DisciplineModule( QSharedPointer < ModelByQActionItem > pMenuModel,
                      QSharedPointer < DisciplineTextDescriptionModule > pDisciplineTextDescriptionModule,
                      QSharedPointer < IconItemManager > pIconItemManager,
                      QSharedPointer < NotificationManager > pNotificationManager );

    void addData( QSharedPointer < DataForDisciplineModule > pData );
    QSharedPointer < TreeStandartItemBaseModel > getDisciplineModel();
};

#endif // DISCIPLINECONTAINER_H

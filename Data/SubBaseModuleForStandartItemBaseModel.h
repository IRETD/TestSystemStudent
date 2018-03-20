#ifndef SUBBASEMODULEFORSTANDARTITEMBASEMODEL_H
#define SUBBASEMODULEFORSTANDARTITEMBASEMODEL_H

#include <Model/BaseModel/StandardItemBaseModel/StandartItemBaseModell.h>

class SubBaseModuleForStandartItemBaseModel {


public:
    SubBaseModuleForStandartItemBaseModel();

    QSharedPointer < StandartItemBaseModel > initializeNewStandartItemBaseModel( QSharedPointer < MyStandartItemModel > standartItemModel,
                                                                                 TypeModel typeModel );
    QSharedPointer < StandartItemBaseModel > initializeNewStandartItemBaseModel( TypeModel typeModel );
    QSharedPointer < DataItemModelForStandartItemBaseModel > initializeNewDataForStandartItemBaseModel( int idItem,
                                                                                                        QString title,
                                                                                                        QPersistentModelIndex parent = QPersistentModelIndex() );


};

#endif // SUBBASEMODULEFORSTANDARTITEMBASEMODEL_H

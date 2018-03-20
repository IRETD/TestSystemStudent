#ifndef SUBBASEMODULEFORTREESTANDARTITEMBASEMODEL_H
#define SUBBASEMODULEFORTREESTANDARTITEMBASEMODEL_H

#include <Model/BaseModel/StandardItemBaseModel/SubClasses/TreeStandartItemBaseModel.h>

class SubBaseModuleForTreeStandartItemBaseModel {
public:
    SubBaseModuleForTreeStandartItemBaseModel();

    QSharedPointer < TreeStandartItemBaseModel > initializeNewStandartItemBaseModel( QSharedPointer < MyStandartItemModel > standartItemModel,
                                                                                     TypeModel typeModel );
    QSharedPointer < TreeStandartItemBaseModel > initializeNewStandartItemBaseModel( TypeModel typeModel,
                                                                                     TypeStandartItemModel typeStandartItemModel = TypeStandartItemModel::TREE_TYPE );
    QSharedPointer < DataItemModelForStandartItemBaseModel > initializeNewDataForStandartItemBaseModel( int idItem,
                                                                                                        QString title,
                                                                                                        QPersistentModelIndex parent = QPersistentModelIndex() );
    //ИНИЦИАЛИЗАЦИЯ ЭЛЕМЕНТА ДЛЯ ТАБЛИЦЫ
    QSharedPointer < DataItemModelForStandartItemBaseModel > initializeNewDataForStandartItemBaseModel( int idRow,
                                                                                                        int idColumn,
                                                                                                        QString title,
                                                                                                        QPersistentModelIndex parent = QPersistentModelIndex() );
};

#endif // SUBBASEMODULEFORTREESTANDARTITEMBASEMODEL_H

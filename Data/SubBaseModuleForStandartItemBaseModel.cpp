#include "SubBaseModuleForStandartItemBaseModel.h"

SubBaseModuleForStandartItemBaseModel::SubBaseModuleForStandartItemBaseModel() {
}

QSharedPointer < StandartItemBaseModel > SubBaseModuleForStandartItemBaseModel::initializeNewStandartItemBaseModel( QSharedPointer < MyStandartItemModel > standartItemModel,
                                                                                                                 TypeModel typeModel ) {

    QSharedPointer < StandartItemBaseModel > newModel = QSharedPointer < StandartItemBaseModel >( new StandartItemBaseModel ( standartItemModel,
                                                                                                                              typeModel ) );
    return newModel;
}


QSharedPointer < StandartItemBaseModel > SubBaseModuleForStandartItemBaseModel::initializeNewStandartItemBaseModel( TypeModel typeModel ) {

    QSharedPointer < MyStandartItemModel > standartItemModel( new MyStandartItemModel );
    QSharedPointer < StandartItemBaseModel > newModel = QSharedPointer < StandartItemBaseModel >( new StandartItemBaseModel ( standartItemModel,
                                                                                                                              typeModel ) );
    return newModel;
}

QSharedPointer < DataItemModelForStandartItemBaseModel > SubBaseModuleForStandartItemBaseModel::
                                                         initializeNewDataForStandartItemBaseModel( int idItem,
                                                                                                    QString title,
                                                                                                    QPersistentModelIndex parent) {

    QSharedPointer < DataItemModelForStandartItemBaseModel > pData( new DataItemModelForStandartItemBaseModel );
    pData.data() -> setIdItem( idItem );
    pData.data() -> setTitle( title );
    pData.data() -> setParent( parent );

    return pData;

}

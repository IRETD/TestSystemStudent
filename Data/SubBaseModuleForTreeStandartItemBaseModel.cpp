#include "SubBaseModuleForTreeStandartItemBaseModel.h"

SubBaseModuleForTreeStandartItemBaseModel::SubBaseModuleForTreeStandartItemBaseModel()
{
}

QSharedPointer < TreeStandartItemBaseModel > SubBaseModuleForTreeStandartItemBaseModel::
                                             initializeNewStandartItemBaseModel( QSharedPointer < MyStandartItemModel > standartItemModel,
                                                                                 TypeModel typeModel ) {

    QSharedPointer < TreeStandartItemBaseModel > newModel = QSharedPointer < TreeStandartItemBaseModel > ( new TreeStandartItemBaseModel ( standartItemModel,
                                                                                                                                           typeModel ) );
    return newModel;
}


QSharedPointer < TreeStandartItemBaseModel > SubBaseModuleForTreeStandartItemBaseModel::
                                             initializeNewStandartItemBaseModel( TypeModel typeModel,
                                                                                 TypeStandartItemModel typeStandartItemModel  ) {

    QSharedPointer < MyStandartItemModel > standartItemModel( new MyStandartItemModel( typeStandartItemModel ) );
    QSharedPointer < TreeStandartItemBaseModel > newModel = QSharedPointer < TreeStandartItemBaseModel > ( new TreeStandartItemBaseModel ( standartItemModel,
                                                                                                                                           typeModel ) );
    return newModel;
}


QSharedPointer < DataItemModelForStandartItemBaseModel > SubBaseModuleForTreeStandartItemBaseModel::
                                                         initializeNewDataForStandartItemBaseModel( int idItem,
                                                                                                    QString title,
                                                                                                    QPersistentModelIndex parent) {

    QSharedPointer < DataItemModelForStandartItemBaseModel > pData( new DataItemModelForStandartItemBaseModel );
    pData.data() -> setIdItem( idItem );
    pData.data() -> setTitle( title );
    pData.data() -> setParent( parent );

    return pData;

}

//ИНИЦИАЛИЗАЦИЯ ЭЛЕМЕНТА ДЛЯ ТАБЛИЦЫ
QSharedPointer < DataItemModelForStandartItemBaseModel > SubBaseModuleForTreeStandartItemBaseModel::
                                                         initializeNewDataForStandartItemBaseModel( int idRow,
                                                                                                    int idColumn,
                                                                                                    QString title,
                                                                                                    QPersistentModelIndex parent ) {

    QSharedPointer < DataItemModelForStandartItemBaseModel > pData( new DataItemModelForStandartItemBaseModel );
    pData.data() -> setIdItem( idRow );
    pData.data() -> setTitle( title );
    pData.data() -> setIdColumn( idColumn );
    pData.data() -> setParent( parent );

    return pData;
}

#ifndef STANDARTITEMBASEMODELL_H
#define STANDARTITEMBASEMODELL_H

#include <QStandardItem>
#include <Model/BaseModel/StandardItemBaseModel/MyStandartItemModel.h>
#include <Model/BaseModel/BaseModel.h>
#include <Model/BaseModel/DataItemModel/StandartItemBaseModel/DataItemModelForStandartItemBaseModel.h>
#include <MyStorageType/DoubleKeyContainer.h>

class StandartItemBaseModel : public BaseModel {

    Q_OBJECT

    QSharedPointer < MyStandartItemModel > m_pModel;

protected:
    //Таблица содержит связку ID и объектом с данными для конкретной модели
    SingleKeyContainer < QPersistentModelIndex, int > m_ModelIndexIdContainer;
    SingleKeyContainer < int, QPersistentModelIndex > m_IdModelIndexContainer;

    //Таблицы для поддержания табличного вида модели
    DoubleKeyContainer < int, //idRow
                         int, //idColumn
                         QPersistentModelIndex > m_IdColumnNameModelIndexContainer;
    struct RecordID {

        int idRow;
        int idColumn;
    };

    SingleKeyContainer < QPersistentModelIndex,
                         RecordID > m_ModelIndexRecordIDContainer;

    void addItemInModelByRowAndColumn( int idRow,
                                       int idColumn,
                                       QSharedPointer < DataItemModelForStandartItemBaseModel > pItemData );
    void addItemInModelByNewRow( QSharedPointer < DataItemModelForStandartItemBaseModel > pItemData );

public:
    StandartItemBaseModel( QSharedPointer < MyStandartItemModel > pModel,
                           TypeModel typeModel );
    StandartItemBaseModel( QSharedPointer < MyStandartItemModel > pModel,
                           TypeModel typeModel,
                           ModelItemDescriptorType modelItemDescriptorType );
    QPersistentModelIndex getModelIndexById( int id );
    void setStandartItemModel( QSharedPointer < MyStandartItemModel > pModel );
    void addItemInModel( QSharedPointer < AbstractDataItemModel > pItemData );
    void updateItemInModel( QSharedPointer < AbstractDataItemModel > pItemData );
    void clearItemsInModel();

    void changeIconIntoItem( int idItem,
                             QIcon *pIcon );
    QSharedPointer <  MyStandartItemModel > getMyStandardItemModel();

public slots:
    void modelItemSelected( QModelIndex const &itemIndex );
};

#endif // STANDARTITEMBASEMODELL_H

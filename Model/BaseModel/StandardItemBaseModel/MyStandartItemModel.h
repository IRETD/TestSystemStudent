#ifndef MYSTANDARTITEMMODEL_H
#define MYSTANDARTITEMMODEL_H

#include <QStandardItemModel>
#include <QVariant>
#include <MyStorageType/SingleKeyContainer.h>
#include <MacroDefinitons/Model/BaseModel/StandartItemBaseModel/TypeStandartItemModel.h>

class MyStandartItemModel : public QStandardItemModel {


    #define THERE_IS_NO_COLUMN_YET 0

    void setDataInModelByIndex( QModelIndex &index,
                                QString name );

    //для поддержания табличного представления
    //Храним номер столбца по его имени
    SingleKeyContainer < int, //idRow
                         int > m_ColumnNameColumnNumContainer;
    //Заопминам строки :)
    SingleKeyContainer < int, //rowId
                         int > m_RowIdRowNumContainer;

    SingleKeyContainer < int, //idColumn
                         QString > m_ColumnTitleContainer;

    int addNewColumn( int idColumn );
    int addNewRow( int idRow );

public:
    MyStandartItemModel( TypeStandartItemModel type = TypeStandartItemModel::TREE_TYPE );

    QPersistentModelIndex addItemInModelByRowAndColumn( int idRow,
                                                        int idColumn,
                                                        QString value );
    QPersistentModelIndex addItemInModel ( const QString &name );
    QPersistentModelIndex addItemIntoItemInModel( QPersistentModelIndex &parentPersistentIndex,
                                                  const QString &name );
                                                 // QIcon *icon );
    QPersistentModelIndex updateItemInModel( QPersistentModelIndex &itemIndex,
                                             QString title );
    void setColumnTitle( QPersistentModelIndex &itemIndex,
                         QString title );
    void setColumnTitle( int columnNum,
                         QString title );
    void clearItemsInModel();
};

#endif // MYSTANDARTITEMMODEL_H

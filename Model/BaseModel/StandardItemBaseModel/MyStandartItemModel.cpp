#include "MyStandartItemModel.h"
#include <MacroDefinitons/MyMacroDefinitions.h>
#include <assert.h>
#include "../../Diplom/TestSystem/TestSystem/MacroDefinitions/Data/Test/IdColumnAboutHistory.h"

MyStandartItemModel::MyStandartItemModel( TypeStandartItemModel type ) {

    //устанавливаем только один столбец по умолчанию
    /// Необходимо иметь хотя бы 1 столбец для отображения каких-либо строк
    /// В конструкторе организовывать вставку не вариант,
    /// так как этот же класс используется для табличной модели,
    /// в которой бесконтрольное появление столбца недопустимо!
    if ( type == TypeStandartItemModel::TREE_TYPE ) {
        insertColumns( columnCount(),
                       1 );
    }

    ///ТАБЛИЦА. ИНИЦИАЛИЗИРУЕМ НАИМЕНОВАНИЯ СТОЛБЦОВ
    if ( type == TypeStandartItemModel::TABLE_TYPE ) {

        m_ColumnTitleContainer.addValue( static_cast < int > ( IdColumnAboutHistory::STEP ),
                                         STEP_COLUMN_TITLE );
        m_ColumnTitleContainer.addValue( static_cast < int > ( IdColumnAboutHistory::RESULT ),
                                         RESULT_COLUMN_TITLE );
        m_ColumnTitleContainer.addValue( static_cast < int > ( IdColumnAboutHistory::MEMORY ),
                                         MEMORY_COLUMN_TITLE );
        m_ColumnTitleContainer.addValue( static_cast < int > ( IdColumnAboutHistory::TIME ),
                                         TIME_COLUMN_TITLE );
        m_ColumnTitleContainer.addValue( static_cast < int > ( IdColumnAboutHistory::ADDITIONAL_COLUMN ),
                                         ADDITIONAL_COLUMN_TITLE );
    }
    //m_ColumnNameColumnNumContainer.addValue( 1, 0 );
}

QPersistentModelIndex MyStandartItemModel::addItemInModelByRowAndColumn( int idRow,
                                                                         int idColumn,
                                                                         QString value ) {

    bool columnExists = m_ColumnNameColumnNumContainer.isContain( idColumn );

    int columnNum = ( columnExists ) ? m_ColumnNameColumnNumContainer.getValue( idColumn ):
                                       addNewColumn( idColumn );


    bool rowExists = m_RowIdRowNumContainer.isContain( idRow );
    int rowNum = ( rowExists ) ? m_RowIdRowNumContainer.getValue( idRow ):
                                 addNewRow( idRow );

    QModelIndex itemIndex = index( rowNum,
                                   columnNum );

    setDataInModelByIndex( itemIndex,
                           value );
    QPersistentModelIndex persistentIndex( itemIndex );

    return persistentIndex;
}



QPersistentModelIndex MyStandartItemModel::addItemInModel( const QString &name
                                                           //QIcon *p_Icon
                                                         ) {


    insertRows( rowCount(),
                1 );
    QModelIndex itemIndex = index( rowCount() - 1,
                                   0 );
    setDataInModelByIndex( itemIndex,
                           name );
                         //  p_Icon );
    QPersistentModelIndex persistentIndex( itemIndex );

    return persistentIndex;
}



QPersistentModelIndex MyStandartItemModel::addItemIntoItemInModel( QPersistentModelIndex &parentPersistentIndex,
                                                                   const QString &name
                                                                 //  QIcon *p_Icon
                                                                 ) {

    QModelIndex itemIndex = index( parentPersistentIndex.row(),
                                   parentPersistentIndex.column() );

    QPersistentModelIndex persistentTaskIndex;
    if ( itemIndex.isValid() ) {
        //подэлементов нет - то создаем самый первый
        if ( !hasChildren( itemIndex ) ) {
            insertColumns( 0,
                           1,
                           itemIndex );
        }

        insertRows( rowCount( itemIndex ),
                    1,
                    itemIndex );
        QModelIndex taskIndex = index( rowCount( itemIndex ) - 1,
                                       0,
                                       itemIndex );
        if ( taskIndex.isValid() ) {
            setDataInModelByIndex( taskIndex,
                                   name);
                                  // p_Icon );

            persistentTaskIndex = taskIndex ;
        }
    }

    return persistentTaskIndex;
}


QPersistentModelIndex MyStandartItemModel::updateItemInModel( QPersistentModelIndex &itemIndex,
                                                              QString title ) {

    QModelIndex item = index( itemIndex.row(),
                              itemIndex.column() );

    if ( item.isValid() ) {

        setDataInModelByIndex( item,
                               title );
    }

}


void MyStandartItemModel::setColumnTitle( int columnNum,
                                          QString title ) {

    //QStandardItem *item = item( 0, columnNum );
    setHeaderData( columnNum,
                   Qt::Horizontal,
                   title,
                   Qt::DisplayRole );
}

void MyStandartItemModel::clearItemsInModel() {

    removeRows( 0,
                rowCount() );
    removeColumns( 0,
                   columnCount() );
    //clear();
    m_ColumnNameColumnNumContainer.clear();
    m_RowIdRowNumContainer.clear();

    //m_ColumnTitleContainer.clear();

}



void MyStandartItemModel::setDataInModelByIndex( QModelIndex &index,
                                                 QString name
                                                 //QIcon *p_Icon
                                               ) {
    assert( index.isValid() );
    setData( index,
             name,
             Qt::DisplayRole );




  /*  setData( index,
             READ_POINTER p_Icon,
             Qt::DecorationRole );*/

    itemFromIndex( index ) -> setFlags( Qt::ItemIsEnabled );
}


int MyStandartItemModel::addNewColumn( int idColumn ) {


    ///УСТАНОВКА ИМЕНИ ДЛЯ СТОЛБЦА!!!!!!!!!!!!!!!!!!!!!!!!!!
    int newIndex = columnCount();
    m_ColumnNameColumnNumContainer.addValue( idColumn,
                                             newIndex );
    insertColumns( newIndex,
                   1 );
    setColumnTitle( newIndex,
                    m_ColumnTitleContainer.getValue( newIndex ) );

    return newIndex;
}


int MyStandartItemModel::addNewRow( int idRow ) {

    int newIndex = rowCount();
    m_RowIdRowNumContainer.addValue( idRow,
                                     newIndex );
    insertRows( newIndex,
                1 );

    return newIndex;
}

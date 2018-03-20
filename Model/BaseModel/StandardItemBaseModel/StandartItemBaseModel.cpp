#include "StandartItemBaseModell.h"
#include <assert.h>
#include <MacroDefinitons/MyMacroDefinitions.h>
#include <Model/BaseModel/DataItemModel/StandartItemBaseModel/DataItemModelForStandartItemBaseModel.h>


void StandartItemBaseModel::addItemInModelByRowAndColumn( int idRow,
                                                          int idColumn,
                                                          QSharedPointer < DataItemModelForStandartItemBaseModel > pItemData ) {

    //если еще не вставляли элемент на пересение idRow и columnName
    //если уже вставляли, то что-то здесь не так!
    //для обновления используется ОТДЕЛЬНЫЙ МЕТОД
    if ( !m_IdColumnNameModelIndexContainer.isContainsKey1( idRow ) ||
         !m_IdColumnNameModelIndexContainer.isContainsKey1Key2( idRow,
                                                                idColumn ) ) {

        QPersistentModelIndex persistentModelIndex;
        //опускаем пока что родителя. будем считать что родителей нет
        //QPersistentModelIndex parentItem = pData.data() -> getParent();
        QString title = pItemData.data() -> getTitle();
        persistentModelIndex = m_pModel.data() -> addItemInModelByRowAndColumn( idRow,
                                                                                idColumn,
                                                                                title );
        m_IdColumnNameModelIndexContainer.addValue( idRow,
                                                    idColumn,
                                                    persistentModelIndex );
        RecordID recordID;
        recordID.idRow = idRow;
        recordID.idColumn = idColumn;
        m_ModelIndexRecordIDContainer.addValue( persistentModelIndex,
                                                recordID );

    }
}


void StandartItemBaseModel::addItemInModelByNewRow( QSharedPointer < DataItemModelForStandartItemBaseModel > pItemData ) {

    int idItem = pItemData.data() -> getIdItem();
    if ( !m_IdModelIndexContainer.isContain( idItem ) ) {

        QPersistentModelIndex persistentModelIndex;

        QPersistentModelIndex parentItem = pItemData.data() -> getParent();
        QString title = pItemData.data() -> getTitle();
        //QIcon *pIcon = pItemData -> getIcon();

       // if ( parentItem != nullptr ) {

            //QPersistentModelIndex parentItem = READ_POINTER pParent.data();

        if ( parentItem.isValid() ) {

            persistentModelIndex = m_pModel.data() -> addItemIntoItemInModel( parentItem,
                                                                              title );
                                                                      // pIcon );
        }
        else {

            persistentModelIndex = m_pModel.data() -> addItemInModel( title );
        }
                                                              // pIcon );
       // }

        if ( persistentModelIndex.isValid() ) {

            m_ModelIndexIdContainer.addValue( persistentModelIndex,
                                              idItem );
            m_IdModelIndexContainer.addValue( idItem,
                                              persistentModelIndex );

        }
    }

}


StandartItemBaseModel::StandartItemBaseModel( QSharedPointer < MyStandartItemModel > pModel,
                                              TypeModel typeModel ) : BaseModel( typeModel,
                                                                                 ModelItemDescriptorType::BASED_MODEL_ITEM_DESCRIPTOR ) {

    m_pModel = pModel;
}


StandartItemBaseModel::StandartItemBaseModel( QSharedPointer < MyStandartItemModel > pModel,
                                              TypeModel typeModel,
                                              ModelItemDescriptorType modelItemDescriptorType) : BaseModel( typeModel,
                                                                                                            modelItemDescriptorType ) {
    m_pModel = pModel;
}


void StandartItemBaseModel::addItemInModel( QSharedPointer < AbstractDataItemModel > pItemData ) {

    QSharedPointer < DataItemModelForStandartItemBaseModel > pData = pItemData.staticCast < DataItemModelForStandartItemBaseModel >();
    //QScopedPointer < DataItemModelForStandartItemBaseModel > pData = static_cast < QScopedPointer < DataItemModelForStandartItemBaseModel > > pItemData;
    //DataItemModelForStandartItemBaseModel *pItemData = static_cast < DataItemModelForStandartItemBaseModel* > ( pItemData );

    //Если НЕ табличные данные
    if ( pData.data() -> isItColumnData() ) {

        int idRow = pData.data() -> getIdItem();
        int idColumn = pData.data() -> getIdColumn();
        addItemInModelByRowAndColumn( idRow,
                                      idColumn,
                                      pData );
    }
    else {

        addItemInModelByNewRow( pData );
    }

}


void StandartItemBaseModel::updateItemInModel( QSharedPointer < AbstractDataItemModel > pItemData ) {

    //QScopedPointer < DataItemModelForStandartItemBaseModel > pData = static_cast < QScopedPointer < DataItemModelForStandartItemBaseModel > > pItemData;
    QSharedPointer < DataItemModelForStandartItemBaseModel > pData =
            pItemData.staticCast < DataItemModelForStandartItemBaseModel >();
    int idItem = pData.data() -> getIdItem();
    QString title = pData.data() -> getTitle();
    QPersistentModelIndex &itemIndex = m_IdModelIndexContainer.getValue( idItem );
    m_pModel.data() -> updateItemInModel( itemIndex,
                                          title );
}


void StandartItemBaseModel::clearItemsInModel() {


    m_ModelIndexIdContainer.clear();
    m_IdModelIndexContainer.clear();
    m_IdColumnNameModelIndexContainer.clear();
    m_ModelIndexRecordIDContainer.clear();

    m_pModel.data() -> clearItemsInModel();
}


QPersistentModelIndex StandartItemBaseModel::getModelIndexById( int id ) {

    assert( m_IdModelIndexContainer.isContain( id ) == true );
    return m_IdModelIndexContainer.getValue( id );
}


void StandartItemBaseModel::setStandartItemModel( QSharedPointer < MyStandartItemModel > pModel ) {

    m_pModel = pModel;
}




//Вставляет элемент в другой элемент
// Например, вставка лабораторной к дисциплине
// ОЖИДАЕТСЯ КОРРЕКТНОЕ ЗНАЧЕНИЕ persistentIndex
// ВОЗВРАТ НУЛЕВОГО УКАЗАТЕЛЯ!!!!



void StandartItemBaseModel::changeIconIntoItem( int idItem,
                                                QIcon *pIcon ) {
    //получаем активный индекс в текущей моделе
    QPersistentModelIndex itemIndex = m_IdModelIndexContainer.getValue( idItem );
    /*
    QModelIndex itemIndex =  idItem.sibling( idItem.row(),
                                             idItem.column() );
                                             */
    assert( itemIndex.isValid() == true );
    if ( itemIndex.isValid() ) {
        m_pModel.data() -> setData( itemIndex,
                                    READ_POINTER pIcon,
                                    Qt::DecorationRole );
    }
}


QSharedPointer < MyStandartItemModel > StandartItemBaseModel::getMyStandardItemModel() {

    return m_pModel;
}


void StandartItemBaseModel::modelItemSelected( const QModelIndex &itemIndex ) {

    if ( m_ModelIndexIdContainer.isContain( itemIndex ) ) {

        int idItem = m_ModelIndexIdContainer.getValue( itemIndex );
        //если эелемнт в данный момент ОПОВЕЩАЕТСЯ - прекратить это дело
        //ТАК КАК ПОЛЬЗОВАТЕЛЬ ТОЛЬКО ЧТО КЛИНКЛУ ПО НЕМУ
        m_ModelItemDescriptorContainer.getModelItemDescriptor( idItem ).data() -> setStopNotificationAsForPersonal( true );
        //Устанавливаем выбранный элемент АКТИВНЫМ в моделе
        QSharedPointer <ModelItemDescriptor > pModelItemDescriptor =  m_ModelItemDescriptorContainer.getTreeModelItemDescriptor( idItem );
        setActiveModelItemDescriptor( pModelItemDescriptor );
        emit sendIdItemSelected( idItem );
    }
}


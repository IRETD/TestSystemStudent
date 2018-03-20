#include "AbstractDataItemModel.h"


AbstractDataItemModel::AbstractDataItemModel() {

    m_ColumnData = false;
}


void AbstractDataItemModel::setIdColumn( int idColumn ) {

    m_IdColumn = idColumn;
    m_ColumnData = true;
}


int AbstractDataItemModel::getIdColumn() {

    return m_IdColumn;
}


void AbstractDataItemModel::setIdItem( int idItem ) {

    m_IdItem = idItem;
}


int AbstractDataItemModel::getIdItem() {

    return m_IdItem;
}


bool AbstractDataItemModel::isItColumnData() {

    return m_ColumnData;
}

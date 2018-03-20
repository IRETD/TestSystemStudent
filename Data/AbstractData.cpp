#include "AbstractData.h"


AbstractData::AbstractData( TypeData typeData ) {

    m_TypeData = typeData;
    m_ChangedFieldList.clear();
    m_DataInfo = DataInfo::THIS_IS_NEW_DATA;
}


TypeData AbstractData::getTypeData() {

    return m_TypeData;
}


void AbstractData::addChangedField( int field ) {

    m_ChangedFieldList.push_back( field );
}


QList < int > AbstractData::getChangedFieldList() {

    return m_ChangedFieldList;
}


void AbstractData::setDataInfo( DataInfo dataInfo ) {

    m_DataInfo = dataInfo;
}


DataInfo AbstractData::getDataInfo() {

    return m_DataInfo;
}

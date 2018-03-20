#ifndef ABSTRACTDATA_H
#define ABSTRACTDATA_H

#include <Enum/Data/TypeData.h>
#include <MyStorageType/SingleKeyContainer.h>
#include <Enum/Data/DataInfo.h>

/*
 * Сюда оборачиваются ЛЮБЫЕ данные поступившие в приложение ИЗ ВНЕ
 * Далее эта обертка поступает в модуль данных, который уже определяет,
 * Какому именно контейнеру доставлять эти данные.
 */

class AbstractData {

    TypeData m_TypeData;
    QList < int > m_ChangedFieldList;
    DataInfo m_DataInfo;

public:
    AbstractData( TypeData typeData );
    TypeData getTypeData();
    void addChangedField( int field );
    void removeChangedField( int field );
    QList < int > getChangedFieldList();
    void setDataInfo( DataInfo dataInfo );
    DataInfo getDataInfo();
};

#endif // ABSTRACTDATA_H

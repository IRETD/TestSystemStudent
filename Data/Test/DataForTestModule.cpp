#include "DataForTestModule.h"

DataForTestModule::DataForTestModule() : AbstractData( TypeData::TEST_DATA_TYPE ) {
}


void DataForTestModule::setHistory( History history ) {

    m_History = history;
}


History DataForTestModule::getHistory() {

    return m_History;
}


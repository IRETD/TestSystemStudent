#include "DataForAboutTestModule.h"


DataForAboutTestModule::DataForAboutTestModule() : AbstractData( TypeData::ABOUT_TEST_TYPE ) {
}


void DataForAboutTestModule::setAboutHistory( AboutHistory aboutHistory ) {

    m_AboutHistory = aboutHistory;
}


AboutHistory DataForAboutTestModule::getAboutHistory() {

    return m_AboutHistory;
}

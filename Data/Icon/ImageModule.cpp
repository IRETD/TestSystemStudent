#include "ImageModule.h"


ImageModule::ImageModule() {

    m_pIconItemManager = QSharedPointer < IconItemManager > ( new IconItemManager );
}


QSharedPointer < IconItemManager > ImageModule::getIconItemManager() {

    return m_pIconItemManager;
}

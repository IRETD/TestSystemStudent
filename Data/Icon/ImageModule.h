#ifndef ICONMODULE_H
#define ICONMODULE_H

#include <Data/Icon/IconItemManager.h>

class ImageModule {

     QSharedPointer < IconItemManager > m_pIconItemManager;
public:
    ImageModule();

    QSharedPointer < IconItemManager > getIconItemManager();
};

#endif

#ifndef ICONBUFFER_H
#define ICONBUFFER_H

#include <QIcon>
#include <Enum/Data/IconBuffer/IconName.h>
#include <Enum/Data/IconBuffer/IconStatus.h>
#include <Enum/Model/TypeModel.h>
#include <MyStorageType/DoubleKeyContainer.h>
#include <MyStorageType/TripleKeyContainer.h>
#include <Model/ModelItemDescriptor/ModelItemDescriptor.h>
#include <Data/Icon/IconInfo.h>

class IconBuffer {

    TripleKeyContainer < TypeModel,
                         IconStatus,
                         int,
                         QIcon* > m_ItemIconBuffer;
    TripleKeyContainer < TypeModel,
                         IconStatus,
                         int,
                         QIcon* > m_GroupIconBuffer;
    DoubleKeyContainer < TypeModel,
                         IconStatus,
                         QIcon* > m_DefaultIconBuffer;

    QIcon *getIconByResourcePath( QString resourcePath );
public:
    IconBuffer();
    ~IconBuffer();

    IconInfo getIcon( QSharedPointer < ModelItemDescriptor > targetItem,
                      IconStatus iconStatus,
                      QSharedPointer < ModelItemDescriptor > pParentItem =  QSharedPointer < ModelItemDescriptor > ( nullptr ) );

    QIcon *getDefaultIcon( TypeModel typeModel,
                           IconStatus iconStatus );

    void addDefaultIcon( TypeModel typeModel,
                         IconStatus iconStatus,
                         QIcon *pIcon );
    void addGroupIcon( TypeModel typeModel,
                       IconStatus iconStatus,
                       int idItem,
                       QIcon *pIcon );
    void addItemIcon( TypeModel typeModel,
                      IconStatus iconStatus,
                      int idItem,
                      QIcon *pIcon );
};

#endif

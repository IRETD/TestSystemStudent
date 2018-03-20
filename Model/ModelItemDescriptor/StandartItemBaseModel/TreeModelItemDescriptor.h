#ifndef TREEMODELITEMDESCRIPTOR_H
#define TREEMODELITEMDESCRIPTOR_H

#include <Model/ModelItemDescriptor/ModelItemDescriptor.h>

class TreeModelItemDescriptor : public ModelItemDescriptor {

     bool m_IsExpand;

public:
    TreeModelItemDescriptor( QSharedPointer < ModelItemDescriptor > pParentItem,
                             //TypeModel typeModel,
                             //TypeModelItem typeModelItem,
                             QSharedPointer < BaseModel > pModel,
                             int idItem,
                             bool visibleStatus,
                             NotificationType marketNotificationTypeValue );
    void setExpandStatus( bool expandStatus );
    bool getExpandStatus();
    void setClickedStatus();
    virtual void setVisibleStatus( bool visibleStatus );
};

#endif

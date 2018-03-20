#ifndef MODELBYQACTIONITEMDESCRIPTOR_H
#define MODELBYQACTIONITEMDESCRIPTOR_H

#include <Model/ModelItemDescriptor/ModelItemDescriptor.h>

class ModelByQActionItemDescriptor : public ModelItemDescriptor {
public:
    ModelByQActionItemDescriptor( QSharedPointer < ModelItemDescriptor > pParentItem,
                                  //TypeModel typeModel,
                                  //TypeModelItem typeModelItem,
                                  QSharedPointer < BaseModel > pModel,
                                  int idItem,
                                  bool visibleStatus,
                                  NotificationType marketNotificationTypeValue );

    void setActiveStatus( bool activeStatus );
};

#endif

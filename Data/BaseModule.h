#ifndef BASEMODULE_H
#define BASEMODULE_H

#include <Data/Icon/IconItemManager.h>
#include <Model/BaseModel/BaseModel.h>
#include <Model/BaseModel/DataItemModel/AbstractDataItemModel.h>
#include <Model/Notification/NotificationManager.h>

class BaseModule {

protected:
     QSharedPointer < IconItemManager > m_pIconItemManager;
     QSharedPointer < NotificationManager > m_pNotificationManager;

public:
    BaseModule( QSharedPointer < IconItemManager > pIconItemManager,
                QSharedPointer < NotificationManager > pNotificationManager );
    void addNewItem( QSharedPointer < BaseModel > pBaseModel,
                     QSharedPointer < AbstractDataItemModel > pData ,
                     QSharedPointer < ModelItemDescriptor > pParent = QSharedPointer < ModelItemDescriptor > ( nullptr ) );
    void addNewItemWithoutIconManager( QSharedPointer < BaseModel > pBaseModel,
                                       QSharedPointer < AbstractDataItemModel > pData ,
                                       QSharedPointer < ModelItemDescriptor > pParent = QSharedPointer < ModelItemDescriptor > ( nullptr ) );
    void clear( QSharedPointer < BaseModel > pBaseModel  );
};

#endif // BASEMODULE_H

#ifndef MENUMODULE_H
#define MENUMODULE_H

#include <Model/BaseModel/PureBaseModel/ModelByQActionItem.h>
#include <Data/Menu/DataForMenuModule.h>
#include <Data/BaseModule.h>
#include <Model/BaseModel/DataItemModel/PureBaseModel/DataItemModelForModelByQActionItem.h>

class MenuModule : public BaseModule {


    QSharedPointer < ModelByQActionItem > m_pMenuModel;

    QSharedPointer < DataItemModelForModelByQActionItem > initializeNewData( int idMenu,
                                                                             QString title,
                                                                             ViewContextType viewContextType );
    void updateTitle( int idMenu,
                      QString title ,
                      ViewContextType viewContext );
    void addMenu( Menu &menu );

public:
    MenuModule( QSharedPointer < IconItemManager > pIconItemManager,
                QSharedPointer < NotificationManager > pNotificationManager );

    void addData( QSharedPointer < DataForMenuModule > pData );
    QSharedPointer < ModelByQActionItem >  getMenuModel();
};

#endif // MENUMODULE_H

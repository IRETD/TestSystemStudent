#ifndef MENU_ITEM_CONTAINER_H
#define MENU_ITEM_CONTAINER_H

#include <QAction>
#include <QHash>
#include <Enum/View/ViewType.h>
#include "MenuItem.h"
#include "MenuItemFactory.h"
#include<QTimer>
#include <QObject>

class MenuItemContainer : public QObject {

    Q_OBJECT

    QHash < MenuItemName, MenuItem* > m_ActionTable;
    MenuItemFactory m_MenuItemFactory;

    QTimer timer;

    void createConnectionForAction( const ViewType &viewType,
                                    MenuItem* pMenuItem );

public:
    MenuItemContainer();
    void createMenuItem( QObject *parent,
                         const MenuItemName &name,
                         QString description,
                         QIcon *pIcon );
    QAction* getMenuItem( const MenuItemName &name );
    void createConnectionsForMenuItem( const ViewType &viewType,
                                       const MenuItemName &name );
    void cteateConnectionsForAllMenuItem( const ViewType &viewType );
};

#endif

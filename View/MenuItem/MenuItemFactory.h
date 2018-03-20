#ifndef MENUITEMFACTORY_H
#define MENUITEMFACTORY_H

#include "MenuItem.h"
#include <QObject>

#include <Enum/View/MenuItem/MenuItemName.h>

class MenuItemFactory {
public:
    MenuItemFactory();

    MenuItem *createMenuItem( const MenuItemName &menuItemName,
                              QObject *parent);
};

#endif // MENUITEMFACTORY_H

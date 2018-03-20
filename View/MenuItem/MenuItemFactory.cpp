#include "MenuItemFactory.h"
#include <View/MenuItem/DisciplineMenuItem.h>

MenuItemFactory::MenuItemFactory() {
}

MenuItem *MenuItemFactory::createMenuItem( const MenuItemName &menuItemName,
                                           QObject *parent ) {

    MenuItem *pMenuItem = nullptr;
    /*if ( menuItemName == MenuItemName::DISCIPLINE ) {

        pMenuItem = new DisciplineMenuItem( parent );
    }*/

    return pMenuItem;
}

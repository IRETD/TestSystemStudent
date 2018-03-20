#include "MenuItem.h"

MenuItem::MenuItem( QObject *parent ) : QAction( parent ) {
}


void MenuItem::createConnectionsForMainWindow() {
    //пусто, не все пункты меню могут принадлежать главному окну
    // следовательно не все пункты обязаны создавать соединения на это окно
}

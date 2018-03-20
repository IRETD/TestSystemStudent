#ifndef DISCIPLINEMENUITEM_H
#define DISCIPLINEMENUITEM_H

#include <QAction>
#include "MenuItem.h"

class DisciplineMenuItem : public MenuItem {
public:
    DisciplineMenuItem( QObject *parent );

    void createConnectionsForMainWindow();
};

#endif

#ifndef MENUITEM_H
#define MENUITEM_H

#include <QObject>
#include <QAction>

class MenuItem : public QAction {

public:
    MenuItem( QObject *parent );

    virtual void createConnectionsForMainWindow();
};

#endif // MENUITEM_H

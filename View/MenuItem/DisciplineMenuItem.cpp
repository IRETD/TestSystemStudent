#include "DisciplineMenuItem.h"
#include <View/MainWindowView.h>


DisciplineMenuItem::DisciplineMenuItem( QObject *parent ) : MenuItem( parent ) {
}


void DisciplineMenuItem::createConnectionsForMainWindow() {

    /*
    MainWindowView *pParent = ( MainWindowView* )this -> parentWidget();
    connect( this,
             &QAction::triggered,
             pParent,
             &MainWindowView::disciplineMenuChecked
           );
           */
}


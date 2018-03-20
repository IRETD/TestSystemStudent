#include "Initializer.h"
#include <QAction>
#include <MacroDefinitons/MyMacroDefinitions.h>

Initializer::Initializer() {
}


void Initializer::initializeDockWidgetOnWindow( QMainWindow *const window,
                                                QDockWidget &dockWidget,
                                                const QDockWidget::DockWidgetFeature &widgetFeatures,
                                                const Qt::DockWidgetAreas &allowedAreas,
                                                const Qt::DockWidgetArea &area,
                                                const QString &title
                                               ) {
    dockWidget.setFeatures( widgetFeatures );
    dockWidget.setAllowedAreas( allowedAreas );
    dockWidget.setWindowTitle( title );

    window -> addDockWidget( area, &dockWidget );

}

void Initializer::setWidgetOnDockWidget( QDockWidget &dockWidget,
                                         QWidget *widget
                                         ) {
    dockWidget.setWidget( widget );
}


void Initializer::initializeAction( QAction *pAction,
                                    const QString &text,
                                    const QIcon *pIcon
                                   ) {
    pAction -> setText( text );

    if ( pIcon != nullptr ) {
        pAction -> setIcon( READ_POINTER pIcon );
    }

    pAction -> setText( text );
}

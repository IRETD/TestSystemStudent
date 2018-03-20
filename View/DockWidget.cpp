#include "DockWidget.h"

void DockWidget::prepareVisibilityChanged( bool visible ) {

    if ( !visible ) {

        emit dockWidgetIsClosed();
    }
}

DockWidget::DockWidget( const QDockWidget::DockWidgetFeature &widgetFeatures,
                        const Qt::DockWidgetAreas &allowedAreas,
                        const QString &title ) {

    setFeatures( widgetFeatures );
    setAllowedAreas( allowedAreas );
    setWindowTitle( title );

    connect( this,
             &DockWidget::visibilityChanged,
             this,
             &DockWidget::prepareVisibilityChanged );

}

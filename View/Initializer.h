#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <QMainWindow>
#include <QDockWidget>

class Initializer {
public:
    Initializer();

    void initializeDockWidgetOnWindow( QMainWindow * const window,
                                       QDockWidget &dockWidget,
                                       const QDockWidget::DockWidgetFeature &widgetFeatures,
                                       const Qt::DockWidgetAreas &allowedAreas,
                                       const Qt::DockWidgetArea &area,
                                       const QString &title );
    void setWidgetOnDockWidget( QDockWidget &dockWidget,
                                QWidget *widget );
    void addActionOnToolBar( QToolBar &pToolBar,
                             QAction &pAction );
    void initializeAction( QAction *pAction,
                           const QString &text = "",
                           const QIcon *p_Icon = nullptr );
};

#endif // INITIALIZER_H

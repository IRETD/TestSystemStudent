#ifndef DOCKWIDGET_H
#define DOCKWIDGET_H

#include <QDockWidget>

class DockWidget : public QDockWidget {

    Q_OBJECT

    QSharedPointer < QWidget > m_DefaultWidget;

private slots:
    void prepareVisibilityChanged( bool visible );
public:
    DockWidget( const DockWidgetFeature &widgetFeatures,
                const Qt::DockWidgetAreas &allowedAreas,
                const QString &title );
    //сигнал испускается ТОЛЬКО при закрытии виджета - это то что нам нужно
signals:
    void dockWidgetIsClosed();
};

#endif

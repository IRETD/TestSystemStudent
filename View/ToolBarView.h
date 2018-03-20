#ifndef TOOLBARVIEW_H
#define TOOLBARVIEW_H

#include <QToolBar>

class ToolBarView : public QToolBar {

public:
    ToolBarView( Qt::ToolBarAreas allowedAreas,
                 Qt::ToolButtonStyle toolButtonStyle );
    void addMenuItem( QAction &action );
};

#endif

#include "ToolBarView.h"
#include <Enum/View/MenuItem/MenuItemIconParameters.h>

ToolBarView::ToolBarView( Qt::ToolBarAreas allowedAreas,
                          Qt::ToolButtonStyle toolButtonStyle
                         ) {

    setToolButtonStyle( toolButtonStyle );
    setAllowedAreas( allowedAreas );

    setIconSize( ( QSize( MenuItemIconParametes::WIDTH,
                          MenuItemIconParametes::HEIGHT
                        )
                  )
               );

    setMovable( false );
}

void ToolBarView::addMenuItem( QAction &action ) {

    addAction( &action );
}

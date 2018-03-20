#include "TreeView.h"
#include <Enum/View/ViewContext/DisciplineView/DisciplineViewIconSize.h>
#include <QHeaderView>

TreeView::TreeView( ViewContextType viewContextType ) : ViewContext( viewContextType ) {

    setIconSize( QSize( DisciplineViewIconSize::WIDTH,
                        DisciplineViewIconSize::HEGITH ) );
    header() -> resizeSections( QHeaderView::ResizeToContents );
}


QWidget *TreeView::getViewWidget() {

    return this;
}



void TreeView::createConnections() {

    connect( this,
             &QTreeView::doubleClicked,
             m_p_Model -> getDisciplineModel().data(),
             &TreeStandartItemBaseModel::modelItemSelected
           );
    connect ( this,
              &QTreeView::expanded,
              m_p_Model -> getDisciplineModel().data(),
              &TreeStandartItemBaseModel::itemIsExpanded );
    connect ( this,
              &QTreeView::collapsed,
              m_p_Model -> getDisciplineModel().data(),
              &TreeStandartItemBaseModel::itemIsCollapsed );

}

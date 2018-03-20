#include "AboutTestView.h"
#include <QHeaderView>


AboutTestView::AboutTestView( QSharedPointer < DynamicSwitchViewContext > pDynamicSwitchViewContext ) : TreeView( ViewContextType::ABOUT_TEST_VIEW_CONTEXT ) {

    m_pDynamicSwitchViewContext = pDynamicSwitchViewContext;

    header() -> setStretchLastSection(false);
    header()-> setSectionResizeMode(QHeaderView::Stretch);
   // header() -> setResizeMode(1, QHeaderView::Stretch);
}


void AboutTestView::setModelForView( Model *pModel ) {

    m_p_Model = pModel;
    setModel( m_p_Model -> getAboutTestModel().data() -> getMyStandardItemModel().staticCast < QStandardItemModel> ().data() );

    connect ( m_p_Model -> getAboutTestModel().data(),
              &TreeStandartItemBaseModel::showViewContext,
              m_pDynamicSwitchViewContext.data(),
              &DynamicSwitchViewContext::setCurrentView );
}

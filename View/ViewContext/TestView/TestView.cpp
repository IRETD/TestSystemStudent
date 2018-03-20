#include "TestView.h"

TestView::TestView() : TreeView( ViewContextType::TEST_VIEW_CONTEXT ){
}


void TestView::setModelForView( Model *pModel ) {

    m_p_Model = pModel;
    setModel( m_p_Model -> getTestModel().data() -> getMyStandardItemModel().staticCast < QStandardItemModel> ().data() );

    connect( this,
             &TestView::doubleClicked,
             m_p_Model -> getTestModel().data(),
             &TreeStandartItemBaseModel::modelItemSelected );

}

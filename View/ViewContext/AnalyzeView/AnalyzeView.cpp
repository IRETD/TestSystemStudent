#include "AnalyzeView.h"

AnalyzeView::AnalyzeView() : TreeView( ViewContextType::ANALYZE_VIEW_CONTEXT ) {
}

void AnalyzeView::setModelForView( Model *pModel ) {

    m_p_Model = pModel;
    setModel( m_p_Model -> getAnalyzeModel().data() -> getMyStandardItemModel().staticCast < QStandardItemModel> ().data() );
     //сигнал на обработку клика к DisciplineModel - если вдруг выбрана дисциплина
    connect( this,
             &AnalyzeView::doubleClicked,
             m_p_Model -> getAnalyzeModel().data(),
             &TreeStandartItemBaseModel::modelItemSelected );

    //сигнал на обработку клика к TaskModel - если вдруг выбрана лаба
    connect( this,
             &AnalyzeView::doubleClicked,
             m_p_Model -> getSubAnalyzeModel().data(),
             &TreeStandartItemBaseModel::modelItemSelected );
}

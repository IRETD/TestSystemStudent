#include "DisciplineView.h"

DisciplineView::DisciplineView() : TreeView( ViewContextType::DISCIPLINE_VIEW_CONTEXT ) {

}


//ОТСЮДА ОСУЩ. ПОСЛЫКА СИГНАЛА В СЛУЧАЕ ВЫБОРА КАКОЙ-ЛИБО ДИСЦПЛИНЫ
void DisciplineView::setModelForView( Model *pModel ) {

    m_p_Model = pModel;
    setModel( m_p_Model -> getDisciplineModel().data() -> getMyStandardItemModel().staticCast < QStandardItemModel> ().data() );
     //сигнал на обработку клика к DisciplineModel - если вдруг выбрана дисциплина
    connect( this,
             &DisciplineView::doubleClicked,
             m_p_Model -> getDisciplineModel().data(),
             &TreeStandartItemBaseModel::modelItemSelected );

    //сигнал на обработку клика к TaskModel - если вдруг выбрана лаба
    connect( this,
             &DisciplineView::doubleClicked,
             m_p_Model -> getTaskModel().data(),
             &TreeStandartItemBaseModel::modelItemSelected );

}

#include "DisciplineDescriptionView.h"
#include <assert.h>
#include <Enum/Model/TypeDataModel.h>
#include <QScrollBar>
#include <Model/BaseModel/PureBaseModel/ModelTextDescription/ModelTextDisciplineDescription.h>


/*
void DisciplineDescriptionView::getDataModelFromModel( DataModel *pDataModel ) {

    ///подумать о возможности СРАЗУ забирать значение текста.
    /// В принципе, какой смысл в этом executeDataModel???
    ///
    assert( pDataModel != nullptr );
    saveScrollBarStatus( m_IdDiscipline,
                         this -> verticalScrollBar() -> value() );

    if ( pDataModel -> getTypeDataModel() == TypeDataModel::DISCIPLINE_DESCRIPTION_DATA ) {
        pDataModel -> executeDataModel( this );
        //оповещаем, что описание может быть выведенено на экран
        emit elementWasTriggered( m_ViewContextType );
    }
}
*/


void DisciplineDescriptionView::setDisciplineDescription( int idItem,
                                                          QString &text ) {
    //На самом деле, метод берет на себя слишком много обязанностей
    //Помимо обычной установки текста для текущего отображения, он:
    // - запоминает текущее состояние ползунка для id текущей дисцилины
    // - восстанавливает состояние ползунка для вновь отображаемой дисциплины
    // сообщает, посредством испускания синала, о том, что это отображение
    // необходимо отобразить на главной форме.
    saveScrollBarStatus( m_IdDiscipline,
                         this -> verticalScrollBar() -> value() );
    //ОБЯЗАТЕЛЬНО!!!! СПЕРВА УСТАНАВЛИВАЕМ ТЕКСТ И ТОЛЬКО ПОТОМ СКРОЛЛ!!!
    setHtml( text );
    setScrollValueForCurrentElement( idItem );
}


DisciplineDescriptionView::DisciplineDescriptionView( Model *pModel,
                                                      ViewContextType viewContextType,
                                                      QSharedPointer < DynamicSwitchViewContext > pDynamicSwitchViewContext,
                                                      QSharedPointer < DockWidget > pCentralDockWidget ) : ViewContext( viewContextType ) {

    m_IdDiscipline = ScrollBarStatusConstants::UNDEFINED_ID_FOR_SCROLL_VALUE;
    m_p_Model = pModel;

    m_pDynamicSwitchViewContext = pDynamicSwitchViewContext;
    ////ЗДЕСЬ СКОРЕЕ ВСЕГО САМ ВИДЖЕТ УЖЕ НЕ НУЖЕН
    m_pCentralDockWidget = pCentralDockWidget;
}


void DisciplineDescriptionView::setScrollValueForCurrentElement( const quint32 &idDiscipline ) {

    m_IdDiscipline = idDiscipline;
    this -> verticalScrollBar() -> setValue( getScrollBarStatus( m_IdDiscipline) );
}


QWidget *DisciplineDescriptionView::getViewWidget() {

    return this;
}


void DisciplineDescriptionView::createConnections() {

/*
    connect( m_p_Model -> getMyStandartItemModel( TypeModel::DISCIPLINE_DESCRIPTION_TYPE_MODEL ),
             &DisciplineDescriptionModel::sendDisciplineDescriptionData,
             this,
             &DisciplineDescriptionView::getDisciplineDescriptionData );
             */

    connect( m_p_Model -> getDisciplineTextDescriptionModel().data(),
             &ModelTextDisciplineDescription::sendTextDescription,
             this,
             &DisciplineDescriptionView::setDisciplineDescription );

    connect( m_p_Model -> getDisciplineTextDescriptionModel().data(),
             &ModelTextDisciplineDescription::showViewContext,
             m_pDynamicSwitchViewContext.data(),
             &DynamicSwitchViewContext::setCurrentView );
}


void DisciplineDescriptionView::setModelForView( Model *pModel ) {

    m_p_Model = pModel;
}


void DisciplineDescriptionView::connectWithViewContextContainer( ViewContextContainer *vewContextContainer ) {


}

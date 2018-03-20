#include "TaskDescriptionView.h"
#include <assert.h>
#include <QScrollBar>


/*
void TaskDescriptionView::getDataModelFromModel( DataModel *pDataModel ) {

    assert( pDataModel != nullptr );
    saveScrollBarStatus( m_IdTask,
                         this -> verticalScrollBar() -> value() );


    if ( pDataModel -> getTypeDataModel() == TypeDataModel::TASK_DESCRIPTION_DATA ) {
         pDataModel -> executeDataModel( this );
         //оповещаем, что описание может быть выведенено на экран
         emit elementWasTriggered( m_ViewContextType );
    }

}
*/


void TaskDescriptionView::setScrollValueForCurrentElement( const quint32 &idTask ) {

    m_IdTask = idTask;
    this -> verticalScrollBar() -> setValue( getScrollBarStatus( m_IdTask) );
}

void TaskDescriptionView::setTaskDescription( int idItem,
                                              QString &text ) {


    saveScrollBarStatus( m_IdTask,
                         this -> verticalScrollBar() -> value() );
    //ОБЯЗАТЕЛЬНО!!!! СПЕРВА УСТАНАВЛИВАЕМ ТЕКСТ И ТОЛЬКО ПОТОМ СКРОЛЛ!!!
    setHtml( text );
    setScrollValueForCurrentElement( idItem );
}


TaskDescriptionView::TaskDescriptionView( Model *pModel,
                                          ViewContextType viewContextType ,
                                          QSharedPointer<DynamicSwitchViewContext> pDynamicSwitchViewContext ) : ViewContext( viewContextType ) {

    m_IdTask = ScrollBarStatusConstants::UNDEFINED_ID_FOR_SCROLL_VALUE;

    m_p_Model = pModel;

    m_pDynamicSwitchViewContext = pDynamicSwitchViewContext;
}


void TaskDescriptionView::setIdCurrentElement( const quint32 &idTask ) {


    m_IdTask = idTask;
    this -> verticalScrollBar() -> setValue( getScrollBarStatus( m_IdTask ) );
}


void TaskDescriptionView::createConnections() {

/*
    connect( m_p_Model -> getMyStandartItemModel( TypeModel::TASK_TYPE_MODEL ),
             &TaskDescriptionModel::sendTaskDescriptionData,
             this,
             &TaskDescriptionView::getTaskDescriptionData );
             */
    connect( m_p_Model -> getTaskTextDescriptionModel().data(),
             &ModelTextTaskDescription::sendTextDescription,
             this,
             &TaskDescriptionView::setTaskDescription );

    connect( m_p_Model -> getTaskTextDescriptionModel().data(),
             &ModelTextTaskDescription::showViewContext,
             m_pDynamicSwitchViewContext.data(),
             &DynamicSwitchViewContext::setCurrentView );
}


QWidget *TaskDescriptionView::getViewWidget()  {

    return this;
}


void TaskDescriptionView::connectWithViewContextContainer( ViewContextContainer *vewContextContainer ) {

    connect( this,
             &TaskDescriptionView::thisViewContexIsReadyForShow,
             vewContextContainer,
             &ViewContextContainer::viewContextIsReadyForShow );
}


void TaskDescriptionView::setModelForView( Model *pModel ) {

    m_p_Model = pModel;
}

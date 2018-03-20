#include "DynamicSwitchViewContext.h"


DynamicSwitchViewContext::DynamicSwitchViewContext( QSharedPointer < DockWidget > pDockWidget ) : m_pDockWidget( pDockWidget ) {

    m_pDockWidget.data() -> setWidget( this );


    m_DefaultWidget = QSharedPointer < QWidget > ( new QWidget );
    addWidget( m_DefaultWidget.data() );
    setCurrentWidget( m_DefaultWidget.data() );
}

void DynamicSwitchViewContext::addView( const ViewContextType &viewContextType,
                                        ViewContext *pView ) {

    if ( !m_ViewTable.contains( viewContextType ) ) {
        if ( pView != nullptr ) {
            m_ViewTable[ viewContextType ] = pView;
            addWidget( pView -> getViewWidget() );
        }
    }
}

void DynamicSwitchViewContext::setCurrentView( const ViewContextType &viewContexType ) {

    if ( m_ViewTable.contains( viewContexType ) ) {

        setCurrentWidget( m_ViewTable[ viewContexType ] -> getViewWidget() );
    }


    //если док виджет закрыт - делаем его видимым
    if ( m_pDockWidget.data() -> isHidden() ) {
        m_pDockWidget.data() -> setVisible( true );
    }
}

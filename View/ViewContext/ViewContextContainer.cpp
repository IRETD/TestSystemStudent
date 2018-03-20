#include "ViewContextContainer.h"
#include <MacroDefinitons/MyMacroDefinitions.h>
#include <View/ViewContext/DisciplineDescriptionView.h>
#include <View/ViewContext/TreeView.h>
#include <View/ViewContext/TaskDescriptionView.h>
#include <View/ViewContext/DisciplineView/DisciplineView.h>
#include <View/ViewContext/TestView/TestView.h>
#include <View/ViewContext/TestView/AboutTestView.h>
#include <View/ViewContext/AnalyzeView/AnalyzeView.h>
#include <View/ViewContext/AnalyzeDescriptionView.h>

ViewContextContainer::ViewContextContainer(Model *pModel,
                                            QSharedPointer < DynamicSwitchViewContext > pSideViewContextSwitch,
                                            QSharedPointer < DockWidget > pCentralDockWidget,
                                            QSharedPointer < DynamicSwitchViewContext > pCentralViewContextSwitch ) {

    m_pModel = pModel;
    m_pSideViewContextSwitch = pSideViewContextSwitch;
    m_pCentralDockWidget = pCentralDockWidget;
    m_pCentralViewContextSwitch = pCentralViewContextSwitch;
}



ViewContext *ViewContextContainer::createViewContext( ViewContextType viewContextType ) {

    ViewContext *pView = nullptr;
    if ( viewContextType == ViewContextType::DISCIPLINE_DESCRIPTION_VIEW_CONTEXT ) {

        pView = new DisciplineDescriptionView( m_pModel,
                                               ViewContextType::DISCIPLINE_DESCRIPTION_VIEW_CONTEXT,
                                               m_pCentralViewContextSwitch,
                                               m_pCentralDockWidget );
    }

    if ( viewContextType == ViewContextType::TASK_DESCRIPTION_VIEW_CONTEXT ) {

        pView = new TaskDescriptionView( m_pModel,
                                         ViewContextType::TASK_DESCRIPTION_VIEW_CONTEXT,
                                         m_pCentralViewContextSwitch );
    }


    if ( viewContextType == ViewContextType::DISCIPLINE_VIEW_CONTEXT ) {

        pView = new DisciplineView;
    }

    if ( viewContextType == ViewContextType::TEST_VIEW_CONTEXT ) {

        pView = new TestView;
    }

    if ( viewContextType == ViewContextType::ABOUT_TEST_VIEW_CONTEXT ) {

        pView = new AboutTestView( m_pCentralViewContextSwitch );
    }

    if ( viewContextType == ViewContextType::ANALYZE_VIEW_CONTEXT ) {

        pView = new AnalyzeView;
    }

    if ( viewContextType == ViewContextType::ANALYZE_DESSCRIPTION_VIEW_CONTEXT ) {

        pView = new AnalyzeDescriptionView( m_pModel,
                                            ViewContextType::ANALYZE_DESSCRIPTION_VIEW_CONTEXT,
                                            m_pCentralViewContextSwitch );
    }

    return pView;
}

void ViewContextContainer::createView( const ViewContextType &viewContextType ) {

    if ( !m_ViewContextTable.contains( viewContextType ) ) {

        ViewContext *pView = createViewContext( viewContextType );
        if ( pView != nullptr ) {

            m_ViewContextTable[ viewContextType ] = pView;
            //соединяем все предсталвния с сигналом их активности
            pView -> connectWithViewContextContainer( this );
            /*if ( pView -> getViewContextType() )
            connect( pView,
                     &View::viewContextIsTriggered,
                     this,
                     &ViewContextContainer::viewContextIsTriggered );*/
        }
    }
}


ViewContext *ViewContextContainer::getView( const ViewContextType &viewContextType ) {
    //ОЖИДАЕМ НА ВХОДЕ СУЩЕСТВУЮЩЕЕ (СОЗДАННОЕ) ПРЕДСТАВЛЕНИЕ

    return m_ViewContextTable[ viewContextType ];
}


void ViewContextContainer::createConnectionsForAllViewContext() {

    auto it = m_ViewContextTable.begin();
    auto itEnd = m_ViewContextTable.end();
    while ( it != itEnd ) {

        ViewContext *pView = it.value();
        pView -> createConnections();
        it++;
    }
}


void ViewContextContainer::setModelForAllViewContext() {

    auto it = m_ViewContextTable.begin();
    auto itEnd = m_ViewContextTable.end();
    while ( it != itEnd ) {

        ViewContext *pView = it.value();
        pView -> setModelForView( m_pModel );
        it++;
    }
}



#include "MainWindowView.h"
#include <QAction>
#include <QAbstractTableModel>
//#include "OurTreeModel/OurTreeWidgetItem.h"
//#include <Qsci/qsciscintilla.h>
//#include <Qsci/qscilexercpp.h>
#include <QMenu>
#include <MacroDefinitons/MyMacroDefinitions.h>
#include <MacroDefinitons/DestroyPointerMacro.h>
#include <Enum/View/TitleTreeWidget.h>
#include <MacroDefinitons/WidgetHeaderMacro.h>


MainWindowView::MainWindowView() {


    m_p_Model = new Model();

    m_pAttachProjectView = QSharedPointer < AttachProjectView > ( new AttachProjectView( m_p_Model ) );
    m_pRunProjectView = QSharedPointer < RunProjectView > ( new RunProjectView ( m_p_Model ) );

    //ИНИЦИАЛИЩАЦИЯ БОКОВОГО ДОК ВИДЖЕТА
    m_pSideDockWidget = QSharedPointer < DockWidget > ( new DockWidget( QDockWidget::DockWidgetClosable,
                                                                        Qt::LeftDockWidgetArea |
                                                                        Qt::RightDockWidgetArea,
                                                                        DEFAULT_HEADER_TEXT_OF_SIDE_DOCK_WIDGET )
                                                        );
    addDockWidget( Qt::LeftDockWidgetArea,
                   m_pSideDockWidget.data() );

    //настраиваем центральный сменный виджет
    m_pCentralDockWidget =  QSharedPointer < DockWidget > ( new DockWidget( QDockWidget::DockWidgetClosable,
                                                                            Qt::TopDockWidgetArea,
                                                                            DEFAULT_HEADER_TEXT_OF_SIDE_DOCK_WIDGET ) );
    m_pCentralViewContextSwitch = QSharedPointer < DynamicSwitchViewContext > ( new DynamicSwitchViewContext( m_pCentralDockWidget ) );
    setCentralWidget( m_pCentralDockWidget.data() );

    //Выводит элементы бокового виджета по выбранному пункту меню
    m_pSideViewContextSwitch = QSharedPointer < DynamicSwitchViewContext > ( new DynamicSwitchViewContext( m_pSideDockWidget ) );
    m_pSideDockWidget.data() -> setWidget( m_pSideViewContextSwitch.data() );
    m_pViewContextContainer = QSharedPointer < ViewContextContainer > ( new ViewContextContainer( m_p_Model,
                                                                                                  m_pSideViewContextSwitch,
                                                                                                  m_pCentralDockWidget,
                                                                                                  m_pCentralViewContextSwitch ) );

    m_pViewContextContainer.data() -> createView( ViewContextType::DISCIPLINE_DESCRIPTION_VIEW_CONTEXT );
    m_pViewContextContainer.data() -> createView( ViewContextType::DISCIPLINE_VIEW_CONTEXT );
    m_pViewContextContainer.data() -> createView( ViewContextType::TASK_DESCRIPTION_VIEW_CONTEXT );
    m_pViewContextContainer.data() -> createView( ViewContextType::TEST_VIEW_CONTEXT );
    m_pViewContextContainer.data() -> createView( ViewContextType::ABOUT_TEST_VIEW_CONTEXT );
    m_pViewContextContainer.data() -> createView( ViewContextType::ANALYZE_VIEW_CONTEXT );
    m_pViewContextContainer.data() -> createView( ViewContextType::ANALYZE_DESSCRIPTION_VIEW_CONTEXT );
    //m_ViewContextContainer.createView( ViewContextType::ATTACH_PROJECT_VIEW_CONTEXT );

    m_pSideViewContextSwitch.data() -> addView( ViewContextType::DISCIPLINE_VIEW_CONTEXT,
                                                m_pViewContextContainer.data() -> getView( ViewContextType::DISCIPLINE_VIEW_CONTEXT ) );
    m_pSideViewContextSwitch.data() -> addView( ViewContextType::TEST_VIEW_CONTEXT,
                                                m_pViewContextContainer.data() -> getView( ViewContextType::TEST_VIEW_CONTEXT ) );
    m_pSideViewContextSwitch.data() -> addView( ViewContextType::ANALYZE_VIEW_CONTEXT,
                                                m_pViewContextContainer.data() -> getView( ViewContextType::ANALYZE_VIEW_CONTEXT ) );

    m_pViewContextContainer.data() -> setModelForAllViewContext();

    m_pMoveableMenu = QSharedPointer < SideMenuView > ( new SideMenuView( m_pSideDockWidget,
                                                                          m_pSideViewContextSwitch ) );
    m_pMoveableMenu.data() -> setModelForView( m_p_Model );

    addToolBar( Qt::LeftToolBarArea,
                m_pMoveableMenu.data() );


    ///Коннект можно установить внутри представления ;)
    /// настроить обработку DataModel
    ///
    m_pViewContextContainer.data() -> createConnectionsForAllViewContext();


    /*
     m_pDisciplineDescriptionView = QSharedPointer < DisciplineDescriptionView > ( new DisciplineDescriptionView( m_p_Model,
                                                                                                                  ViewContextType::DISCIPLINE_DESCRIPTION_VIEW_CONTEXT,
                                                                                                                  m_pCentralViewContextSwitch,
                                                                                                                  m_pCentralDockWidget ) );
     m_pTaskDescriptionView = QSharedPointer < TaskDescriptionView > ( new TaskDescriptionView ( m_p_Model,
                                                                                                 ViewContextType::TASK_DESCRIPTION_VIEW_CONTEXT,
                                                                                                 m_pCentralViewContextSwitch ) );
     */


     ///ПЕРЕНЕСТИ ВСЕ ВЬЮХИ В VIEWCONTEXTCONTAINER!!!!
    //m_pAboutTestView = QSharedPointer < AboutTestView > ( new AboutTestView( ))
    //m_pDisciplineDescriptionView.data() -> createConnections();
    //m_pTaskDescriptionView.data() -> createConnections();
    m_pCentralViewContextSwitch.data() -> addView( ViewContextType::DISCIPLINE_DESCRIPTION_VIEW_CONTEXT,
                                                   m_pViewContextContainer.data() -> getView( ViewContextType::DISCIPLINE_DESCRIPTION_VIEW_CONTEXT )
                                                  );
    m_pCentralViewContextSwitch.data() -> addView( ViewContextType::TASK_DESCRIPTION_VIEW_CONTEXT,
                                                   m_pViewContextContainer.data() -> getView( ViewContextType::TASK_DESCRIPTION_VIEW_CONTEXT )
                                                  );
    m_pCentralViewContextSwitch.data() -> addView( ViewContextType::ABOUT_TEST_VIEW_CONTEXT,
                                                   m_pViewContextContainer.data() -> getView( ViewContextType::ABOUT_TEST_VIEW_CONTEXT )
                                                  );
    m_pCentralViewContextSwitch.data() -> addView( ViewContextType::ANALYZE_DESSCRIPTION_VIEW_CONTEXT,
                                                   m_pViewContextContainer.data() -> getView( ViewContextType::ANALYZE_DESSCRIPTION_VIEW_CONTEXT )
                                                  );

   /* m_pCentralViewContextSwitch.data() -> addView( ViewContextType::TASK_DESCRIPTION_VIEW_CONTEXT,
                                                   m_ViewContextContainer.getView( ViewContextType::TASK_DESCRIPTION_VIEW_CONTEXT )
                                                  );*/

    //m_pCentralViewContextSwitch.data() -> setCurrentView( ViewContextType::DISCIPLINE_DESCRIPTION_VIEW_CONTEXT );
    //m_MenuItemContainer.cteateConnectionsForAllMenuItem( ViewType::MAIN_WINDOW );
/*
    connect( &m_ViewContextContainer,
             &ViewContextContainer::viewContextIsReadyForShow,
             this,
             &MainWindowView::viewContextTriggered );*/
}


MainWindowView::~MainWindowView() {

   //DestroyPointer( m_p_Model )
}

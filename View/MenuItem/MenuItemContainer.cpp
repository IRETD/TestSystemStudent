#include "MenuItemContainer.h"
#include <MacroDefinitons/MyMacroDefinitions.h>


MenuItemContainer::MenuItemContainer() {

    //connect( &timer, &QTimer::timeout, this, &MenuItemContainer::slot1 );
   // timer.start( 1000 );
}


void MenuItemContainer::createConnectionForAction( const ViewType &viewType,
                                                   MenuItem *pMenuItem ) {

    if ( viewType == ViewType::MAIN_WINDOW ) {

        pMenuItem -> createConnectionsForMainWindow();
    }
}
/*
void MenuItemContainer::slot1() {

    static bool status = false;
    static int i = 0;
    QIcon *pIcon = nullptr;
    if ( i % 2 == 0 ) {
        pIcon = new QIcon( ":/Resources/images/Model/DisciplineModel/DefaultDisciplineImageLightOn.png");
    }
    else {
        pIcon = new QIcon( ":/Resources/images/Model/DisciplineModel/DefaultDisciplineImage.png" );
    }
    i++;
    auto it = m_ActionTable.begin();
    auto itEnd = m_ActionTable.end();

    while( it != itEnd ) {

        MenuItem *pMenuItem = it.value();
        pMenuItem->setIcon( *pIcon );
       // pMenuItem->setVisible( );
       // //pMenuItem->se
        it++;
    }
}
*/
void MenuItemContainer::createMenuItem( QObject *parent,
                                        const MenuItemName &name,
                                        QString description/* "" */,
                                        QIcon *pIcon /* nullptr */ ) {


    if ( !m_ActionTable.contains( name ) ) {
        MenuItem *pMenuItem = m_MenuItemFactory.createMenuItem( name,
                                                                parent );
        //объект в фабрике мо и не создаваться
        if ( pMenuItem != nullptr ) {
            pMenuItem -> setText( description );
            if ( pIcon != nullptr ) {
                QIcon p = QIcon( ":/Resources/images/Model/DisciplineModel/DefaultDisciplineImageLightOn.png");
                pMenuItem -> setIcon( p );
                p = QIcon( ":/Resources/images/Model/DisciplineModel/DefaultDisciplineImage.png" );
                pMenuItem -> setIcon( p );
            }
            m_ActionTable[ name ] = pMenuItem;

        }

    }
}


QAction *MenuItemContainer::getMenuItem( const MenuItemName &name ) {

    QAction *pMenuItem = nullptr;

    if ( m_ActionTable.contains( name ) ) {

        pMenuItem = m_ActionTable[ name ];
    }

    return pMenuItem;
}


void MenuItemContainer::createConnectionsForMenuItem( const ViewType &viewType,
                                                      const MenuItemName &name ) {

    if ( m_ActionTable.contains( name ) ) {

        createConnectionForAction( viewType,
                                   m_ActionTable[ name ] );
    }

}


void MenuItemContainer::cteateConnectionsForAllMenuItem( const ViewType &viewType ) {

    auto it = m_ActionTable.begin();
    auto itEnd = m_ActionTable.end();
    while ( it != itEnd ) {
        MenuItem *pMenuItem = it.value();
        createConnectionForAction( viewType, pMenuItem );
        it++;
    }
}

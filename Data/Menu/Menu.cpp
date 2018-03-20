#include "Menu.h"


Menu::Menu() {
}


void Menu::setId( int id ) {

    m_Id = id;
}


void Menu::setTitle( QString &title ) {

    m_Title = title;
}


void Menu::setViewContextType( ViewContextType viewContextType ) {

    m_ViewContextType = viewContextType;
}


ViewContextType Menu::getViewContextType() {

    return m_ViewContextType;
}


QString Menu::getTitle() {


    return m_Title;
}


int Menu::getId() {

    return m_Id;
}


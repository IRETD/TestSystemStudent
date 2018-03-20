#ifndef MENU_H
#define MENU_H

#include <QString>
#include <Enum/View/ViewContext/ViewContextType.h>

class Menu {

    int m_Id;
    QString m_Title;
    ViewContextType m_ViewContextType;
public:
    Menu();

    void setId( int id );
    void setTitle( QString &title );
    void setViewContextType( ViewContextType viewContextType );
    ViewContextType getViewContextType();
    QString getTitle();
    int getId();
};

#endif // MENU_H

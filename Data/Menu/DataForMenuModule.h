#ifndef DATAFORMENUMODULE_H
#define DATAFORMENUMODULE_H

#include <Data/AbstractData.h>
#include <Data/Menu/Menu.h>


class DataForMenuModule : public AbstractData {

    Menu m_Menu;

public:
    DataForMenuModule();

    void setTitle( QString &title );

    Menu getMenu();

};

#endif // DATAFORMENUMODULE_H

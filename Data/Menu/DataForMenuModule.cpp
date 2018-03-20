#include "DataForMenuModule.h"
#include <Enum/Data/Menu/MenuFieldName.h>


DataForMenuModule::DataForMenuModule() : AbstractData( TypeData::MENU_DATA_TYPE )  {
}


void DataForMenuModule::setTitle( QString &title ) {

    m_Menu.setTitle( title );
    addChangedField( MenuFieldName::MENU_TITLE_FIELD );
}


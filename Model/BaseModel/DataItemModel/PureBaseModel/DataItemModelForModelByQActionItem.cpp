#include "DataItemModelForModelByQActionItem.h"


DataItemModelForModelByQActionItem::DataItemModelForModelByQActionItem( int id,
                                                                        QString title,
                                                                        ViewContextType viewContextType ) {

    m_IdItem = id;
    m_Title = title;
    m_ViewContextType = viewContextType;
//    m_pIcon = nullptr;
}


void DataItemModelForModelByQActionItem::setTitle(QString title){

    m_Title = title;
}


QString DataItemModelForModelByQActionItem::getTitle() {

    return m_Title;
}


ViewContextType DataItemModelForModelByQActionItem::getViewContextType() {

    return m_ViewContextType;
}

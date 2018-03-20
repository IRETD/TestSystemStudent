#include "ScrollBarStatus.h"

void ScrollBarStatus::saveScrollBarStatus( const quint32 &id,
                                           const int &value ) {

    if ( id != ScrollBarStatusConstants::UNDEFINED_ID_FOR_SCROLL_VALUE ) {
        m_ScrollBarStatusTable[ id ] = value;
    }
}

int ScrollBarStatus::getScrollBarStatus( const quint32 &id ) {

    int value = 0;
    if ( m_ScrollBarStatusTable.contains( id ) ) {
        value = m_ScrollBarStatusTable[ id ];
    }

    return value;
}


ScrollBarStatus::ScrollBarStatus() {
}

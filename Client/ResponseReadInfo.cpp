#include "ResponseReadInfo.h"


ResponseReadInfo::ResponseReadInfo() {

    m_ReadStatus = ReadStatus::INPUT_DATA_ARE_COMPLETE;
}


ReadStatus ResponseReadInfo::getReadStatus() {

    return m_ReadStatus;
}


void ResponseReadInfo::setReadStatus( const ReadStatus &readStatus ) {

    m_ReadStatus = readStatus;
}


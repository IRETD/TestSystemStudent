#include "ReqAnalyzer.h"
#include <MacroDefinitons/Request/RequestSenderInitialization.h>

ReqAnalyzer::ReqAnalyzer() : REQUEST_SENDER_INITIALIZATION {
}


void ReqAnalyzer::setIdHistory( quint32 idHistory ) {

    m_IdHistory = idHistory;
}


void ReqAnalyzer::setIdAboutHistory( quint32 idAboutHistory ) {

    m_IdAboutHistory = idAboutHistory;
}


void ReqAnalyzer::writeInStream() {

    clearStream();
    m_Stream << static_cast < int > ( RequestType::ANALYZE ) <<
                m_IdHistory <<
                m_IdAboutHistory;
    prepareStream();
}

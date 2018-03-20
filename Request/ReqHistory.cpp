#include "ReqHistory.h"
#include <MacroDefinitons/Request/RequestSenderInitialization.h>

ReqHistory::ReqHistory() : REQUEST_SENDER_INITIALIZATION {
}


void ReqHistory::writeInStream() {

    clearStream();
    m_Stream << static_cast < int > ( RequestType::HISTORY );
    prepareStream();
}

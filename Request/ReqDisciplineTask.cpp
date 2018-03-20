#include "ReqDisciplineTask.h"
#include <MacroDefinitons/Request/RequestSenderInitialization.h>


ReqDisciplineTask::ReqDisciplineTask() : REQUEST_SENDER_INITIALIZATION {

}


void ReqDisciplineTask::writeInStream() {

    clearStream();
    m_Stream << static_cast < int > ( RequestType::DISCIPLINE_TASK );
    prepareStream();
}

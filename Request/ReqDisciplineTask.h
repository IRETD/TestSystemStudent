#ifndef REQLABLIST_H
#define REQLABLIST_H

#include <request/Request.h>
#include <QString>


class ReqDisciplineTask : public Request {

public:
    ReqDisciplineTask();

    void writeInStream();
};

#endif

#ifndef REQHISTORY_H
#define REQHISTORY_H

#include <request/Request.h>

class ReqHistory : public Request {

public:
    ReqHistory();

    void writeInStream();
};

#endif // REQHISTORY_H

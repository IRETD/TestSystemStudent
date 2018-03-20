#ifndef DATAFORABOUTTESTMODULE_H
#define DATAFORABOUTTESTMODULE_H

#include <Data/Test/AboutHistory.h>
#include <Data/AbstractData.h>

class DataForAboutTestModule : public AbstractData {

    AboutHistory m_AboutHistory;

public:
    DataForAboutTestModule();

    void setAboutHistory( AboutHistory aboutHistory );
    AboutHistory getAboutHistory();
};

#endif // DATAFORABOUTTESTMODULE_H

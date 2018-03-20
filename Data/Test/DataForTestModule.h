#ifndef DATAFORTESTMODULE_H
#define DATAFORTESTMODULE_H

#include "../../../../Diplom/TestSystem/TestSystem/data/history/History.h"
#include <Data/AbstractData.h>

class DataForTestModule : public AbstractData {

    History m_History;

public:
    DataForTestModule();

    void setHistory( History history );
    History getHistory();
};

#endif // DATAFORTESTMODULE_H

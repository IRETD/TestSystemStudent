#ifndef TEST_H
#define TEST_H

#include "../../Diplom/TestSystem/TestSystem/MacroDefinitions/Data/Test/TestResult.h"
#include <QDateTime>

class Test {

    int m_IdUserLab;
    int m_IdHistory;
    TestResult m_TestResult;
    QDateTime m_TestDate;

public:
    Test();
};

#endif // TEST_H

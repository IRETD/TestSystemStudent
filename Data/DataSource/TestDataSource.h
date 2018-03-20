#ifndef TESTDATASOURCE_H
#define TESTDATASOURCE_H

#include <Data/DataSource/DataSource.h>

class TestDataSource : public DataSource {

public:
    TestDataSource( QSharedPointer < DataModule > pDataModule );

    void generateDisciplineData();
    void generateTaskData();
};

#endif

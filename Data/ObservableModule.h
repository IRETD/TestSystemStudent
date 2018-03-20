#ifndef OBSERVABLEMODULE_H
#define OBSERVABLEMODULE_H

#include <MyStorageType/DoubleKeyContainer.h>
#include <Model/ModelItemDescriptor/ModelItemDescriptor.h>

class ObservableModule {

    DoubleKeyContainer < int,
                         int,
                         ModelItemDescriptor* > m_ObserverTable;
public:
    ObservableModule();

    void addObserver( int field,
                      ModelItemDescriptor* pObserver );
    void removeObserver( int field,
                         ModelItemDescriptor *pObserver );
    void notificateObservers( int idItem,
                              QList < int > &changedFieldList );
};

#endif // OBSERVABLEMODULE_H

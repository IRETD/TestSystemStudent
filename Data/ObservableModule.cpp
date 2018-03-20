#include "ObservableModule.h"
#include <MyStorageType/SingleKeyWithContainerValueContainer.h>

ObservableModule::ObservableModule()
{
}

void ObservableModule::addObserver( int field,
                                    ModelItemDescriptor *pObserver ) {
    int idObserver = pObserver -> getIdItem();
    m_ObserverTable.addValue( field,
                              idObserver,
                              pObserver );
}

void ObservableModule::removeObserver( int field,
                                       ModelItemDescriptor *pObserver ) {

    int idObserver = pObserver -> getIdItem();
    m_ObserverTable.removeKey2( field,
                                idObserver );
}

void ObservableModule::notificateObservers( int idItem,
                                            QList < int > &changedFieldList ) {

    SingleKeyWithContainerValueContainer < ModelItemDescriptor*,
                                           int > observersWithChangedFields;
    for ( int i = 0; i < changedFieldList.size(); i++ ) {
        int changedField = changedFieldList.at( i );
        QList < ModelItemDescriptor* > observerList = m_ObserverTable.getValueList( changedField );

        for ( int j = 0; j < observerList.size(); j++ ) {
            ModelItemDescriptor *pObserver = observerList.at( j );
            observersWithChangedFields.addValue( pObserver,
                                                 changedField
                                                );
        }
    }
}



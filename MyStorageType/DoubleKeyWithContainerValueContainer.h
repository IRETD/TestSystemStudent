#ifndef DOUBLEKEYWITHCONTAINERVALUECONTAINER_H
#define DOUBLEKEYWITHCONTAINERVALUECONTAINER_H

#include <QHash>
#include <assert.h>

template < class Key1,
           class Key2,
           class Value,
           template < typename ValueType > class ContainerValue = QList>
class DoubleKeyWithContainerValueContainer {

    QHash < Key1,
            QHash < Key2,
                    ContainerValue < Value > >
           > m_DoubleKeyContainer;
public:
    DoubleKeyWithContainerValueContainer() {

    }

    void addValue( Key1 firstKey,
                   Key2 secondKey,
                   Value value ) {

        auto &valueTable = m_DoubleKeyContainer[ firstKey ];
        valueTable[ secondKey ].push_back( value );
    }


    QList < Key2 > getKey2List( Key1 firstKey ) {

        return m_DoubleKeyContainer[ firstKey ].keys();
    }


    ContainerValue < Value > &getContainerValue( Key1 firstKey,
                                                 Key2 secondKey ) {

        assert( m_DoubleKeyContainer.contains( firstKey ) );
        auto &valueTable = m_DoubleKeyContainer[ firstKey ];

        assert( valueTable.contains( secondKey ) );
        return valueTable[ secondKey ];
    }

    bool isContainsKey1( Key1 const &firstKey ) {

        return m_DoubleKeyContainer.contains( firstKey );
    }

    bool isContainsKey1Key2( Key1 const &firstKey,
                             Key2 const &secondKey ) {

        return ( isContainsKey1( firstKey ) &&
                 m_DoubleKeyContainer[ firstKey ].contains( secondKey ) );
    }

    /*
    bool getValueIfExists( Key1 firstKey,
                           Key2 secondKey ,
                           Value &destinationValue ) {

        bool resultOfExists = false;
        if ( isContainsKey1Key2( firstKey,
                                 secondKey ) ) {
            destinationValue = getValue( firstKey,
                                         secondKey );
            resultOfExists = true;
        }

        return resultOfExists;
    }
    */

    void removeKey2( Key1 const &firstKey,
                     Key2 const &secondKey ) {

        if ( isContainsKey1Key2( firstKey,
                                 secondKey ) ) {

            m_DoubleKeyContainer[ firstKey ].remove( secondKey );
        }
    }

};

#endif // DOUBLEKEYWITHCONTAINERVALUECONTAINER_H

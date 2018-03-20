#ifndef DOUBLEKEYCONTAINER_H
#define DOUBLEKEYCONTAINER_H

#include <QHash>
#include <assert.h>

template < class Key1,
           class Key2,
           class Value >
class DoubleKeyContainer {

    QHash < Key1,
            QHash < Key2,
                    Value >
           > m_DoubleKeyContainer;
public:
    DoubleKeyContainer() {

    }

    void addValue( Key1 firstKey,
                   Key2 secondKey,
                   Value value ) {

        auto &valueTable = m_DoubleKeyContainer[ firstKey ];
        valueTable[ secondKey ] = value;
    }


    QHash < Key2,
            Value > getValueByFirstKey( Key1 firstKey ) {

        return m_DoubleKeyContainer[ firstKey ];
    }

    Value &getValue( Key1 firstKey,
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

    void removeKey2( Key1 const &firstKey,
                     Key2 const &secondKey ) {

        if ( isContainsKey1Key2( firstKey,
                                 secondKey ) ) {

            m_DoubleKeyContainer[ firstKey ].remove( secondKey );
        }
    }

    QList < Value > getValueList( Key1 &firstKey ) {

        QList < Value > itemList;
        if ( isContainsKey1( firstKey ) ) {

            itemList = m_DoubleKeyContainer[ firstKey ].values();
        }

        return itemList;
    }

    void clear() {

        m_DoubleKeyContainer.clear();
    }
};

#endif // DOUBLEKEYCONTAINER_H

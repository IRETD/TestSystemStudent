#ifndef TRIPLEKEYCONTAINER_H
#define TRIPLEKEYCONTAINER_H

#include <QHash>

template < class Key1,
           class Key2,
           class Key3,
           class Value >
class TripleKeyContainer {

    QHash < Key1,
            QHash < Key2,
                    QHash < Key3,
                            Value >
                  >
          > m_TripleKeyTable;

public:
    TripleKeyContainer() {

    }

    void addValue( Key1 firstKey,
                   Key2 secondKey,
                   Key3 thirdKey,
                   Value value ) {

        auto &doubleKeyTable = m_TripleKeyTable[ firstKey ];
        auto &valueTable = doubleKeyTable[ secondKey ];
        valueTable[ thirdKey ] = value;
    }

    Value &getValue( Key1 &firstKey,
                     Key2 &secondKey,
                     Key3 &thirdKey ) {

        auto &doubleKeyTable = m_TripleKeyTable[ firstKey ];
        auto &valueTable = doubleKeyTable[ secondKey ];

        return valueTable[ thirdKey ];
    }

    bool isContainsKey1( Key1 const &firstKey ) {

        return m_TripleKeyTable.contains( firstKey );
    }

    bool isContainsKey1Key2( Key1 const &firstKey,
                             Key2 const &secondKey ) {

        return ( isContainsKey1( firstKey ) &&
                 m_TripleKeyTable[ firstKey ].contains( secondKey ) );
    }

    bool isContainsKey1Key2Key3( Key1 const &firstKey,
                                 Key2 const &secondKey,
                                 Key3 const &thirdKey ) {

        return ( isContainsKey1Key2( firstKey,
                                     secondKey ) &&
                 m_TripleKeyTable[ firstKey ][ secondKey ].contains( thirdKey ) );
    }

    bool getValueIfExists( Key1 &firstKey,
                           Key2 &secondKey,
                           Key3 &thirdKey,
                           Value &destinationValue ) {

        bool resultOfExists = false;
        if ( isContainsKey1Key2Key3( firstKey,
                                     secondKey,
                                     thirdKey ) ) {
            destinationValue = getValue( firstKey,
                                         secondKey,
                                         thirdKey );
            resultOfExists = true;
        }

        return resultOfExists;
    }

    QList < Key2 > getKey2List( Key1 const &firstKey ) {

        QList < Key2 > key2List;
        if ( isContainsKey1( firstKey ) ) {

            key2List = m_TripleKeyTable[ firstKey ].keys();
        }

        return key2List;
    }

    QList < Key3 > getKey3List( Key1 &firstKey,
                                Key2 &secondKey ) {

        return m_TripleKeyTable[ firstKey ][ secondKey ].keys();
    }

    void removeKey3( Key1 &firstKey,
                     Key2 &secondKey,
                     Key3 &thirdKey ) {

        m_TripleKeyTable[ firstKey ][ secondKey ].remove( thirdKey );
    }

    QList < Value > getValueList( Key1 &firstKey,
                                  Key2 &secondKey ) {

         return m_TripleKeyTable[ firstKey ][ secondKey ].values();
    }
};

#endif

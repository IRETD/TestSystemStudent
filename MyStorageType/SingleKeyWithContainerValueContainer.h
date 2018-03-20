#ifndef SINGLEKEYWITHCONTAINERVALUECONTAINER_H
#define SINGLEKEYWITHCONTAINERVALUECONTAINER_H

#include <QList>
#include <QHash>

template < class Key1,
           class Key2,
           template < typename ValueType > class ContainerValue = QList
         >
class SingleKeyWithContainerValueContainer {

    QHash < Key1,
            ContainerValue < Key2 >
           > m_Container;
public:
    SingleKeyWithContainerValueContainer() {

    }

    void addValue( Key1 const &key1,
                   Key2 const &value ) {

        m_Container[ key1 ].push_back( value );
    }

    ContainerValue < Key2 > &getContainerValue( Key1 const &key ) {
        assert( m_Container.contains( key ) );
        return m_Container[ key ];
    }

    bool isContain( Key1 const &key ) {

        return m_Container.contains( key );
    }


};

#endif // SINGLEKEYWITHCONTAINERVALUECONTAINER_H

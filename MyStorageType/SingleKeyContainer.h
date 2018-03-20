#ifndef SINGLEKEYCONTAINER_H
#define SINGLEKEYCONTAINER_H

#include <QHash>
#include <assert.h>
#include <QMap>

template < typename Key,
           typename Value,
           template < typename containerKey,
                      typename containerValue > class Container = QHash >
class SingleKeyContainer {

    Container < Key,
                Value > m_Container;

public:
    SingleKeyContainer() {

    }

    SingleKeyContainer( Container < Key,
                                    Value > container ) {

        m_Container = container;
    }

    void addValue( Key const key,
                   Value const value ) {

        m_Container[ key ] = value;
    }

    Value &getValue( Key const key ) {

        assert( m_Container.contains( key ) );
        return m_Container[ key ];
    }

    bool isContain( Key const &key ) {

        return m_Container.contains( key );
    }

    QList < Key > getKeys() {

        return m_Container.keys();
    }

    void removeByKey( Key const &key ) {

        m_Container.remove( key );
    }

    void clear() {

        m_Container.clear();
    }
};

#endif // SINGLEKEYCONTAINER_H

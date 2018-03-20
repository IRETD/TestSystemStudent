#ifndef MODELITEMSTORAGE_H
#define MODELITEMSTORAGE_H

#include <QHash>
#include <QPersistentModelIndex>
#include <assert.h>

template < class TypeStorage >
class ModelItemStorage {

    QHash < QPersistentModelIndex, int > m_ModelIndexIdTable;
    QHash < int, QPersistentModelIndex > m_IdModelIndexTable;
    QHash < int, TypeStorage > m_IdDataTable;

public:
    ModelItemStorage() {

    }

    void addModelIndexToId( QPersistentModelIndex modelIndex,
                            int id ) {

        m_IdModelIndexTable[ id ] = modelIndex;
    }

    QPersistentModelIndex &getModelIndexById( int id ) {

        assert( m_IdModelIndexTable.contains( id ) == true );
        return m_IdModelIndexTable[ id ];
    }

    void addIdToModelIndex( int id,
                            QPersistentModelIndex modelIndex ) {

        m_ModelIndexIdTable[ modelIndex ] = id;
    }

    void addDataToId( TypeStorage data,
                      int id ) {

        m_IdDataTable[ id ] = data;
    }

    void addModelItemData( QPersistentModelIndex modelIndex,
                           int id,
                           TypeStorage data ) {

        m_ModelIndexIdTable[ modelIndex ] = id;
        m_IdModelIndexTable[ id ] = modelIndex;
        m_IdDataTable[ id ] = data;
    }

    TypeStorage getDataById( int id ) {

        return m_IdDataTable[ id ];
    }

    bool isModelIndexExists( QPersistentModelIndex &modelIndex ) {

        return m_ModelIndexIdTable.contains( modelIndex );
    }


    int getIdByModelIndex( QPersistentModelIndex &modelIndex ) {

        return m_ModelIndexIdTable[ modelIndex ];
    }

};

#endif

#ifndef GROUP_H
#define GROUP_H

#include "Student/Student.h"
#include <QList>

class Group {

    quint32 m_IdGroup;
    QString m_Name;
    QList < Student > m_StudentList;

public:
    Group();

    void setIdGroup( quint32 idGroup );
    void setName( QString name );
    void addStudent( Student student );

    quint32 getIdGroup();
    QString getName();
};

#endif

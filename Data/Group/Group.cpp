#include "Group.h"


Group::Group() {
}


void Group::setIdGroup( quint32 idGroup ) {

    m_IdGroup = idGroup;
}


void Group::setName( QString name ) {

    m_Name = name;
}


void Group::addStudent(Student student) {

    m_StudentList.append( student );
}


quint32 Group::getIdGroup() {

    return m_IdGroup;
}


QString Group::getName() {

    return m_Name;
}

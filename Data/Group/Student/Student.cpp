#include "Student.h"


Student::Student() {
}


void Student::setIdStudent( quint32 idStudent ) {

    m_IdStudent = idStudent;
}


void Student::setSurname( QString surname ) {

    m_Surname = surname;
}


void Student::setPatronymic( QString patronymic ) {

    m_Patronymic = patronymic;
}


quint32 Student::getIdStudent() {

    return m_IdStudent;
}


QString Student::getSurname() {

    return m_Surname;
}


QString Student::getName() {

    return m_Name;
}


QString Student::getPatronymic() {

    return m_Patronymic;
}

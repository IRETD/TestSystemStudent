#ifndef STUDENT_H
#define STUDENT_H


#include <QString>


class Student {

    quint32 m_IdStudent;
    QString m_Surname;
    QString m_Name;
    QString m_Patronymic;

public:
    Student();

    void setIdStudent( quint32 idStudent );
    void setSurname( QString surname );
    void setName( QString name );
    void setPatronymic( QString patronymic );

    quint32 getIdStudent();
    QString getSurname();
    QString getName();
    QString getPatronymic();
};

#endif // STUDENT_H

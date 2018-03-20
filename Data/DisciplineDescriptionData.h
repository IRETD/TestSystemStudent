#ifndef DISCIPLINE_DESCRIPTION_H
#define DISCIPLINE_DESCRIPTION_H

#include <QString>

class DisciplineDescriptionData {

    int m_IdDiscipline;
    QString m_Text;
    int m_LastPosition;
    void calculateLastPositionOfText();
public:
    DisciplineDescriptionData();
    void setIdDiscipline( int &idDiscipline );
    int getIdDiscipline();
    void setTitle( const QString &title );
    void addDescription( const QString &description );
    void addFileLink(const QString imagePath,
                      const QString descriptionFile );
    QString getHTMLText();
};

#endif

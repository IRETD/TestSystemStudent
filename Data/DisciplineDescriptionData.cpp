#include "DisciplineDescriptionData.h"
#include <MacroDefinitons/Model/Data/DisciplieDescriptionText.h>


void DisciplineDescriptionData::calculateLastPositionOfText() {

    m_LastPosition = m_Text.length();
}

DisciplineDescriptionData::DisciplineDescriptionData() {

    m_Text.clear();
    m_LastPosition = 0;
}


void DisciplineDescriptionData::setIdDiscipline( int &idDiscipline ) {

    m_IdDiscipline = idDiscipline;
}


int DisciplineDescriptionData::getIdDiscipline() {

    return m_IdDiscipline;
}


void DisciplineDescriptionData::setTitle( const QString &title ) {

    m_Text += "<BODY BACKGROUND="":/Resources/images/Model/DisciplineModel/7554.jpg"">";

    m_Text += "<h2><p align=""center""><font color=""black""><b>";
    m_Text += title;
    m_Text += "</b></p></h2></font>";
    calculateLastPositionOfText();
}


void DisciplineDescriptionData::addDescription( const QString &description ) {

    QString text;
    text += "<font color=""black""><br><h3><i>" + DISCRIPTION + "</i>";
    text += "<br>" + description + "</h3><br></font>";
    text += "<h3><font color=""black"">Список лабораторных работ по курсу:<br><ul>";
    text += "<li>Лабораторная работа №1. Динамический массив.</li>";
    text += "<li>Лабораторная работа №2. Однонаправленный связный список</li>";
    text += "<li>Лабораторная работа №3. Двунаправленный связный список (будет доступно с 20.10.2015)</li>";
    text += "</ul></h3></font>";
    m_Text.insert( m_LastPosition, text );
    calculateLastPositionOfText();
}

void DisciplineDescriptionData::addFileLink( const QString imagePath,
                                         const QString descriptionFile) {

    QString text;
    text += "<br>";
    text += "<img src ='" + imagePath +  "'> <a href=""hello"">" + descriptionFile + "</a>";
    m_Text.insert( m_LastPosition, text );
}


QString DisciplineDescriptionData::getHTMLText() {

    return m_Text;
}

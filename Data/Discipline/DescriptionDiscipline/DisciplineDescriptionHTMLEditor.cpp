#include "DisciplineDescriptionHTMLEditor.h"


void DisciplineDescriptionHTMLEditor::refreshPosDescription() {

    m_PosDescription = m_HTML.size();
}


DisciplineDescriptionHTMLEditor::DisciplineDescriptionHTMLEditor() {

    m_HTML.clear();

    m_HTML = "<BODY BACKGROUND="":/Resources/images/Model/DisciplineTypeModel/7554.jpg"">";
    //подготавливаем заголовок для TITLE
    m_HTML += "<h2><p align=""center""><font color=""black""><b>";
    m_PosTitle = m_HTML.size();
    m_HTML += "</b></p></h2></font><br>";

    //подготавливаем заголовок для описания
    m_HTML += "<font color=""black""><br><h3><i>Описание:</i><br>";
    refreshPosDescription();
}


void DisciplineDescriptionHTMLEditor::setTitle( QString title ) {

    if ( !m_OldTitle.isEmpty() ) {
        //даляем старый заголовок
        m_HTML.remove( m_PosTitle,
                       m_OldTitle.size() );
    }
    //вставляем новый
    m_HTML.insert( m_PosTitle,
                   title );
    refreshPosDescription();

    //запоминаем его у себя
    m_OldTitle = title;

    /*
       textlab1 += "<h2><p align=""center""><font color=""black""><b>";
       textlab1 += t.getName();
       textlab1 += "</b></p></h2></font><br>";
       textlab1 += "<h3><font color=""black"">Языки программирования:</h3></font><br>";

       textlab1 += "<img src =':/Resources/images/Model/Language/c.png'>\
               <img src =':/Resources/images/Model/Language/cpp.png'>\
               <img src =':/Resources/images/Model/Language/pas.png'>\
               <br>";

       textlab1 += "<font color=""black""><br><h3><i>Описание:</i>";
       textlab1 += "<br> Здесь краткое описание постановки задачи в лабораторной работе. </h3><br></font>";
       textlab1 += "<h3><font color=""black"">Пример тестовых данных:<br>";
       textlab1 += " <table cellspacing=""2"" border=""2"" cellpadding=""5"" width=""600"">\
       <tr><td width=30>№</td><td>INPUT.TXT</td><td>OUTPUT.TXT</td></tr>\
       <tr><td align=center>1</td><td>5</td><td>15</td></tr>\
       </table></font><br><br>";
       textlab1 += "<h3><font color=""black"">Желательный срок сдачи: 20.10.2015<br>\
               Крайний срок сдачи: 12.12.2015</font></h3><br><br>";
       textlab1 += "<img src =':/Resources/images/Model/DisciplineModel/WordLogo.png'> <a href=""hello"">Скачать методические указания</a>";
*/
}


void DisciplineDescriptionHTMLEditor::setDescription( QString description ) {

    if ( !m_OldDescription.isEmpty() ) {

        m_HTML.remove( m_PosDescription,
                       m_OldDescription.size() );
    }

    m_HTML.insert( m_PosDescription,
                   description );

    m_OldDescription = description;
}


QString &DisciplineDescriptionHTMLEditor::getHTML() {

    return m_HTML;
}

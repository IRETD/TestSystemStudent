#include "mainwindow.h"
#include <Qsci/qscilexercpp.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    textEdit = new QsciScintilla; // инитилизируем редактор
    textEdit->setUtf8(true); // мы же хотим читать кириллицу
    setCentralWidget(textEdit); // задаем редактор в ui
    QsciLexerCPP * lexCpp = new QsciLexerCPP(this); // создаем лексер (схему подсветки)
    textEdit->setLexer(lexCpp); // задаем С++ лексер нашему редактору
    lexCpp->setFont( QFont("Courier New") ); // шрифт лексера

    //! Текущая строка кода и ее подсветка
    textEdit->setCaretLineVisible(true);
    textEdit->setCaretLineBackgroundColor(QColor("gainsboro"));

    //! Выравнивание
    textEdit->setAutoIndent(true);
    textEdit->setIndentationGuides(false);
    textEdit->setIndentationsUseTabs(true);
    textEdit->setIndentationWidth(4);

    //! margin это полоска слева, на которой обычно распологаются breakpoints
    textEdit->setMarginsBackgroundColor(QColor("gainsboro"));
    textEdit->setMarginLineNumbers(1, true);
    textEdit->setMarginWidth(1, 50);

    //! Авто-дополнение кода в зависимости от источника
    textEdit->setAutoCompletionSource(QsciScintilla::AcsAll);
    textEdit->setAutoCompletionCaseSensitivity(true);
    textEdit->setAutoCompletionReplaceWord(true);
    textEdit->setAutoCompletionUseSingle(QsciScintilla::AcusAlways);
    textEdit->setAutoCompletionThreshold(0);

    //! Подсветка соответствий скобок
    textEdit->setBraceMatching(QsciScintilla::SloppyBraceMatch);
    textEdit->setMatchedBraceBackgroundColor(Qt::yellow);
    textEdit->setUnmatchedBraceForegroundColor(Qt::blue);
}

MainWindow::~MainWindow()
{
    
}

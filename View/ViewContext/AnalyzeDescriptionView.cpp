#include "AnalyzeDescriptionView.h"
#include <Qsci/qscilexercpp.h>


void AnalyzeDescriptionView::setCodeText( QString &codeText ) {

    setText( codeText );
}


AnalyzeDescriptionView::AnalyzeDescriptionView( Model *pModel,
                                                ViewContextType viewContextType,
                                                QSharedPointer < DynamicSwitchViewContext > pDynamicSwitchViewContext ) : ViewContext( viewContextType ) {

    m_pDynamicSwitchViewContext = pDynamicSwitchViewContext;
    m_p_Model = pModel;

    QsciLexerCPP * lexCpp = new QsciLexerCPP(this); // создаем лексер (схему подсветки)
    setLexer(lexCpp); // задаем С++ лексер нашему редактору
    lexCpp -> setFont( QFont("Courier New") ); // шрифт лексера

    //! Текущая строка кода и ее подсветка
    setCaretLineVisible(true);
    setCaretLineBackgroundColor(QColor("gainsboro"));

    //! Выравнивание
    setAutoIndent(true);
    setIndentationGuides(false);
    setIndentationsUseTabs(true);
    setIndentationWidth(4);

    //! margin это полоска слева, на которой обычно распологаются breakpoints
    setMarginsBackgroundColor(QColor("gainsboro"));
    setMarginLineNumbers(1, true);
    setMarginWidth(1, 50);

    //! Авто-дополнение кода в зависимости от источника
    setAutoCompletionSource(QsciScintilla::AcsAll);
     setAutoCompletionCaseSensitivity(true);
     setAutoCompletionReplaceWord(true);
     setAutoCompletionUseSingle(QsciScintilla::AcusAlways);
     setAutoCompletionThreshold(0);

    //! Подсветка соответствий скобок
     setBraceMatching(QsciScintilla::SloppyBraceMatch);
     setMatchedBraceBackgroundColor(Qt::yellow);
     setUnmatchedBraceForegroundColor(Qt::blue);

}


QWidget *AnalyzeDescriptionView::getViewWidget() {

    return this;
}


void AnalyzeDescriptionView::createConnections() {

    connect( m_p_Model -> getSubStaticAnalyzerModule().data(),
             &SubStaticAnalyzerModule::sendCodeText,
             this,
             &AnalyzeDescriptionView::setCodeText );

    connect( m_p_Model -> getSubStaticAnalyzerModule().data(),
             &SubStaticAnalyzerModule::showViewContext,
             m_pDynamicSwitchViewContext.data(),
             &DynamicSwitchViewContext::setCurrentView );
}


void AnalyzeDescriptionView::setModelForView( Model *pModel ) {

    m_p_Model = pModel;
}

void AnalyzeDescriptionView::connectWithViewContextContainer(ViewContextContainer *vewContextContainer) {

}

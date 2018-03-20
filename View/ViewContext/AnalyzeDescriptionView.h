#ifndef ANALYZEDESCRIPTIONVIEW_H
#define ANALYZEDESCRIPTIONVIEW_H

#include <QTextBrowser>
#include <View/ViewContext/ViewContext.h>
#include <View/ViewContext/DynamicSwitchViewContext.h>
#include <Qsci/qsciscintilla.h>

class AnalyzeDescriptionView : public QsciScintilla,
                               public ViewContext {

    Q_OBJECT

    QSharedPointer < DynamicSwitchViewContext > m_pDynamicSwitchViewContext;
    QSharedPointer < DockWidget > m_pCentralDockWidget;

public slots:
    void setCodeText( QString &codeText );

public:
    AnalyzeDescriptionView( Model *pModel,
                            ViewContextType viewContextType,
                            QSharedPointer < DynamicSwitchViewContext > pDynamicSwitchViewContext );

    QWidget *getViewWidget();
    void createConnections();
    void setModelForView( Model *pModel );

    //связывает сигнал elementWasTriggered с контейнером виджетов
    void connectWithViewContextContainer( ViewContextContainer *vewContextContainer );
};

#endif // ANALYZEDESCRIPTIONVIEW_H

#ifndef TASK_DESCRIPTION_VIEW_H
#define TASK_DESCRIPTION_VIEW_H


/////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
 * Класс считай что полностью дублирует DisciplineDescriptionView :(
 * Надо подумать что делать.... :(((
 *
 * //////////////
*/
/////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
///

#include <QTextBrowser>
#include <View/ViewContext/ViewContext.h>
#include <View/WidgetSupport/ScrollBarStatus.h>

#include "../SharedModules/Task.h"

#include <View/ViewContext/DynamicSwitchViewContext.h>

class TaskDescriptionView : public QTextBrowser,
                            public ViewContext,
                            public ScrollBarStatus {

    Q_OBJECT

    QSharedPointer < DynamicSwitchViewContext > m_pDynamicSwitchViewContext;

    qint32 m_IdTask;

protected:
    void setScrollValueForCurrentElement( const quint32 &idTask );

public slots:
    //virtual void getDataModelFromModel( DataModel *pDataModel );
     void setTaskDescription( int idItem,
                              QString &text );

signals:
     void thisViewContexIsReadyForShow( ViewContextType &viewContextType );

public:
    TaskDescriptionView( Model *pModel,
                         ViewContextType viewContextType,
                         QSharedPointer < DynamicSwitchViewContext > pDynamicSwitchViewContext );
    void setIdCurrentElement( const quint32 &idTask );
    void createConnections();
    QWidget *getViewWidget();
    void connectWithViewContextContainer( ViewContextContainer *vewContextContainer );
    void setModelForView( Model *pModel );

};

#endif // TASKDESCRIPTIONVIEW_H

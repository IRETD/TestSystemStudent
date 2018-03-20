#ifndef DISCIPLINE_DESCRIPTION_VIEW_H
#define DISCIPLINE_DESCRIPTION_VIEW_H

/*
 * Данный класс, как отображение, берет на себя обязанности отображать описание той или иной дисциплины
 * Также было решено, что положение ползунка, а именно запоминание этого положения для каждой из
 * имеющихся дисциплин, берет на себя этот класс
 *
*/
#include <QTextBrowser>
#include <View/ViewContext/ViewContext.h>
#include <View/WidgetSupport/ScrollBarStatus.h>
#include <Data/DisciplineDescriptionData.h>
#include <View/ViewContext/DynamicSwitchViewContext.h>
#include <View/DockWidget.h>

//class View;

class DisciplineDescriptionView : public QTextBrowser,
                                  public ViewContext,
                                  public ScrollBarStatus {

    Q_OBJECT


    //хранит id текущей дисциплины
    //используется для запоминание положения ползунка при смене описания на другую дисциплину
    qint32 m_IdDiscipline;

    QSharedPointer < DynamicSwitchViewContext > m_pDynamicSwitchViewContext;
    QSharedPointer < DockWidget > m_pCentralDockWidget;

protected:
    //метод для установки полосы прокрутки для текущего элемента (номер элемента передается
    //в качестве параметра)
    void setScrollValueForCurrentElement( const quint32 &idDiscipline );

public slots:

    //слот вызывается при передаче данных о дисциплине от модели DisciplineDescriptionModel
    void setDisciplineDescription( int idItem,
                                   QString &text );


public:
    DisciplineDescriptionView( Model *pModel,
                               ViewContextType viewContextType,
                               QSharedPointer < DynamicSwitchViewContext > pDynamicSwitchViewContext,
                               QSharedPointer < DockWidget > pCentralDockWidget );
    QWidget *getViewWidget();
    void createConnections();
    void setModelForView( Model *pModel );

    //связывает сигнал elementWasTriggered с контейнером виджетов
    void connectWithViewContextContainer( ViewContextContainer *vewContextContainer );
};

#endif

#ifndef RUNPROJECTVIEW_H
#define RUNPROJECTVIEW_H

#include <Model/Model.h>
#include <QObject>

/*
 * RunProjectView (как и AttachProjectView) необходимы, т.к.
 * перед обработкой какиех-либо данных или отправки запроса серверу
 * необходимо, быть может, что-нибудь вывести на экран
 * По большему счету этот View - некая заглушка передв виде вывода какого-либо окна на экран
 * перед самой обработкой данных
 */

class RunProjectView : public QObject {

    Q_OBJECT

public:
    RunProjectView( Model *pModel );

public slots:
    void runProjectModuleSlot();

signals:
    //когда необходимо НАЧАТЬ обработку запроса на отправку кода
    void runProjectItemSelected();

};

#endif // RUNPROJECTVIEW_H

#ifndef ATTACHPROJECTVIEW_H
#define ATTACHPROJECTVIEW_H

#include <Model/Model.h>
#include <QObject>

class AttachProjectView : public QObject {

    Q_OBJECT

public:
    AttachProjectView( Model *pModel );

signals:
    void sendAttachProjectPath( QString path );

public slots:
    void attachProjectItemSelected();
};

#endif // ATTACHPROJECTVIEW_H

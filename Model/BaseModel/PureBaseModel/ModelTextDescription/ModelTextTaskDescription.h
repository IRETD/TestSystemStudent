#ifndef MODELTEXTTASKDESCRIPTION_H
#define MODELTEXTTASKDESCRIPTION_H

#include <QObject>
#include <MyStorageType/SingleKeyContainer.h>
#include <Data/Task/DescriptionTask/TaskDescriptionHTMLEditor.h>

#include "../SharedModules/Task.h"

#include <Model/BaseModel/BaseModel.h>
#include <Enum/View/ViewContext/ViewContextType.h>

class ModelTextTaskDescription : public QObject {

    Q_OBJECT

    SingleKeyContainer < int,
                         TaskDescriptionHTMLEditor > m_IdTextContainer;
    TypeModel m_TypeModel;

public:
    ModelTextTaskDescription( TypeModel typeModel );

    void addItemInModel( Task &task );
    TypeModel getTypeModel();
    TaskDescriptionHTMLEditor &getTaskDescription( int idItem );

signals:
    void sendTextDescription( int idItem,
                              QString &text );
    void showViewContext( ViewContextType viewContextType );

public slots:
    void taskItemSelected( int idItem );

};

#endif // MODELTEXTTASKDESCRIPTION_H

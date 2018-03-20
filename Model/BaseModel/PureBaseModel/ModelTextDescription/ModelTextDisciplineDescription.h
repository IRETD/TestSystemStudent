#ifndef MODEL_TEXT_DISCIPLINE_DESCRIPTION_H
#define MODEL_TEXT_DISCIPLINE_DESCRIPTION_H

#include <Model/BaseModel/BaseModel.h>
#include <MyStorageType/SingleKeyContainer.h>
#include <QString>
#include <Data/Discipline/DescriptionDiscipline/DisciplineDescriptionHTMLEditor.h>

#include "../SharedModules/Discipline.h"

#include <Enum/View/ViewContext/ViewContextType.h>

class ModelTextDisciplineDescription : public QObject {

    Q_OBJECT

    SingleKeyContainer < int,
                         DisciplineDescriptionHTMLEditor > m_IdTextContainer;
    TypeModel m_TypeModel;

public:
    ModelTextDisciplineDescription( TypeModel typeModel );

    void addItemInModel( Discipline const &discipline );
    TypeModel getTypeModel();
    DisciplineDescriptionHTMLEditor &getDisciplineDescription( int idItem );

signals:
    void sendTextDescription( int idItem,
                              QString &text );
    void showViewContext( ViewContextType viewContextType );

public slots:
    void disciplineItemSelected( int idItem );

};

#endif

#ifndef DISCIPLINETEXTDESCRIPTIONMODULE_H
#define DISCIPLINETEXTDESCRIPTIONMODULE_H

#include <Model/BaseModel/PureBaseModel/ModelTextDescription/ModelTextDisciplineDescription.h>

class DisciplineTextDescriptionModule {

      QSharedPointer < ModelTextDisciplineDescription > m_pModelTextDescription;

public:
    DisciplineTextDescriptionModule();

    void updateTitle( int idDiscipline,
                      QString &title );
    void addData( Discipline const &discipline );

    QSharedPointer < ModelTextDisciplineDescription > getDisciplineTextDescriptionModel();

};

#endif // DISCIPLINETEXTDESCRIPTIONMODULE_H

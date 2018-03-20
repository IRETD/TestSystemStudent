#ifndef DATAFORDISCIPLINEMODULE_H
#define DATAFORDISCIPLINEMODULE_H

#include <Data/AbstractData.h>
#include "../SharedModules/Discipline.h"

class DataForDisciplineModule : public AbstractData {

    Discipline m_Discipline;
    int m_OldId;
public:
    DataForDisciplineModule();

    void setIdDiscipline( int &idDiscipline );
    void setOldId( int &oldId );
    int getOldId();
    void setName( QString &name );
    void setDescription( QString &description );
    void setDiscipline( Discipline &discipline );
    Discipline &getDiscipline();
};

#endif // DATAFORDISCIPLINEMODULE_H

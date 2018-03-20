#ifndef ABOUTHISTORY_H
#define ABOUTHISTORY_H

#include <QString>
//#include <data/history/History.h>

#include "../../../../Diplom/TestSystem/TestSystem/MacroDefinitions/Data/Test/TestResult.h"

class History;

/////????????????????????????????????????????????????????
/// #include <../../../Diplom/TestSystem/TestSystem/MacroDefinitions/Data/Test/AboutTest.h>
/// Почему то не инклудится, БРЕД КАКОЙ-ТО!
enum class StepType {

    UNDEFINED = 0,
    //СООТВЕТСТВИЕ В БАЗЕ ДАННЫХ - СПРАВОЧНИК
    COMPILATION = 1,
    TEST = 2,
    ANALYZE = 3
};

class AboutHistory {

    int m_idAboutHistory;
    int m_IdHistory;
    TestResult m_Result;
    StepType m_StepType;
    QString m_Description;
    QString m_TextResult;
    QString m_Memory;
    QString m_Time;
    QString m_AdditionalColumn;

public:
    AboutHistory();

    void setIdAboutHistory( const int &idAboutHistory );
    void setResult( const TestResult &result );
    void setIdHistory( const int &idHistory );
    void setTextResult( const QString &textResult );
    void setDescription( const QString &description );
    void setMemory( QString memory );
    void setTime( QString time );
    void setStepType( StepType stepType );
    //void setColumnName( const QString &columnName );
    void setAdditionalColumn( QString additionalColumn );

    int getIdHistory() const;
    quint32 getIdAboutHistory() const;
    TestResult getResult() const;
    StepType getStepType();
    QString getTextResult() const;
    QString getMemory();
    QString getTime();
    QString getDescription() const;
    QString getAdditionalColumn();
};

#endif

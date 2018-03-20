#ifndef HISTORY_H
#define HISTORY_H

#include <QString>
#include <QDateTime>
//#include <MacroDefinitions/Data/Test/TestResult.h>

enum class TestResult;

class History {

    int m_IdUserLab;
    int m_IdHistory;
    TestResult m_Result;
    QString m_TextResult;
    QDateTime m_DateHistory;

public:
    History();

    void setIdHistory( const int &idHistory );
    void setTextResult( const QString &textResult );
    void setResult( const TestResult &result );
    void setDateHistory( const QDateTime &dateHistory );
    void setIdUserLab( const int idUserLab );

    int getIdHistory() const;
    QString getTextResult() const;
    TestResult getResult() const;
    QDateTime getDateHistory() const;
    int getIdUserLab() const;
};

#endif // HISTORY_H

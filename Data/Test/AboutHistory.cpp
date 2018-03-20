#include "AboutHistory.h"


AboutHistory::AboutHistory() {

    m_Description.clear();
    m_TextResult.clear();
    m_Memory.clear();
    m_Time.clear();
}


void AboutHistory::setIdAboutHistory( const int &idAboutHistory ) {

    m_idAboutHistory = idAboutHistory;
}



void AboutHistory::setResult( const TestResult &result ) {

    m_Result = result;
}



void AboutHistory::setStepType( StepType stepType ) {

    m_StepType = stepType;
}


void AboutHistory::setIdHistory( const int &idHistory ) {

    m_IdHistory = idHistory;
}


void AboutHistory::setTextResult( const QString &textResult ) {

    m_TextResult = textResult;
}


void AboutHistory::setDescription( const QString &description ) {

    m_Description = description;
}


void AboutHistory::setMemory( QString memory ) {

    m_Memory = memory;
}

void AboutHistory::setTime(QString time) {

    m_Time = time;
}


void AboutHistory::setAdditionalColumn( QString additionalColumn ) {

    m_AdditionalColumn = additionalColumn;
}


/*
void AboutHistory::setColumnName( const QString &columnName ) {

    m_ColumnName = columnName;
}
*/


int AboutHistory::getIdHistory() const {

    return m_IdHistory;
}


StepType AboutHistory::getStepType() {

    return m_StepType;
}



quint32 AboutHistory::getIdAboutHistory() const {

    return m_idAboutHistory;
}



TestResult AboutHistory::getResult() const {

    return m_Result;
}


QString AboutHistory::getTextResult() const {

    return m_TextResult;
}


QString AboutHistory::getMemory() {

    return m_Memory;
}


QString AboutHistory::getTime() {

    return m_Time;
}


QString AboutHistory::getDescription() const {

    return m_Description;
}


QString AboutHistory::getAdditionalColumn() {

    return m_AdditionalColumn;
}


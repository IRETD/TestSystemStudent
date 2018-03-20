#ifndef SCROLLBARSTATUS_H
#define SCROLLBARSTATUS_H

/*
 * Я решил вынести задачу запоминания положения скролла для текстового окна
 * в отдельный метод, дабы снять возложение данной задачи с соотв. отображения.
 * Что поможет упростить сопровождение класса отображения.
 *
 * Логика проста - запоминает id элемента и положение скролла для него.
 * Забираем положение скролла по id элемента
 *
*/

#include <QHash>
#include <Enum/View/WidgetSupport/ScrollBarStatusConstants.h>

class ScrollBarStatus {

    QHash < quint32, int > m_ScrollBarStatusTable;
public:

    void saveScrollBarStatus( const quint32 &id, const int &value );
    int getScrollBarStatus( const quint32 &id );
    ScrollBarStatus();
};

#endif // SCROLLBARSTATUS_H

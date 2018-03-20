#ifndef TREE_VIEW_H
#define TREE_VIEW_H

/*
 * Это отображение выводит список доступных дисциплин в виде древовидной структуры
 * узлами которой являются лабораторные назначенные на каждую из дисциплин.
 *
*/

#include <QTreeView>
#include <View/ViewContext/ViewContext.h>

class TreeView : public QTreeView,
                 public ViewContext {

   // QString *m_Title;

public:

    TreeView( ViewContextType viewContextType );
    QWidget *getViewWidget();
    void createConnections();
};

#endif // DISCIPLINEVIEW_H

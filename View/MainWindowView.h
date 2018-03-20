#ifndef MAINWINDOWVIEW_H
#define MAINWINDOWVIEW_H

enum TypeTree {

    TREE_PROJECT = 1,
    TREE_CODE_EDITOR = 2,
    TREE_TEST = 3,
    TREE_HISTORY = 4
};

#include <QMainWindow>
#include <QObject>
#include <QtWidgets>
#include <model/Model.h>
#include <View/ToolBarView.h>
#include <View/MenuView.h>
#include <View/Initializer.h>
#include <View/MenuItem/MenuItemContainer.h>
#include <View/ViewContext/ViewContextContainer.h>
#include <View/ViewContext/SideMenuView.h>

#include <Enum/View/TitleTreeWidget.h>
#include <Enum/Model/TypeModel.h>
#include <View/ViewContext/DynamicSwitchViewContext.h>
#include <View/DockWidget.h>
#include <View/ViewContext/DisciplineDescriptionView.h>
#include <View/ViewContext/TaskDescriptionView.h>
#include <View/ViewContext/AttachProjectView/AttachProjectView.h>
#include <View/ViewContext/RunProjectView/RunProjectView.h>
#include <View/ViewContext/TestView/AboutTestView.h>

class Model;

class MainWindowView : public QMainWindow {

    Q_OBJECT

    Model *m_p_Model;

    //ДОК ВИДЖЕТЫ
    QSharedPointer < DockWidget > m_pSideDockWidget;
    QSharedPointer < DockWidget > m_pCentralDockWidget;

    QSharedPointer < AttachProjectView > m_pAttachProjectView;
    QSharedPointer < RunProjectView > m_pRunProjectView;

    QSharedPointer < ViewContextContainer > m_pViewContextContainer;

    /*
    QSharedPointer < DisciplineDescriptionView > m_pDisciplineDescriptionView;
    QSharedPointer < TaskDescriptionView > m_pTaskDescriptionView;
    */

    QSharedPointer < SideMenuView > m_pMoveableMenu;
    QToolBar m_EditorToolBar;

    QSharedPointer < DynamicSwitchViewContext > m_pSideViewContextSwitch;
    QSharedPointer < DynamicSwitchViewContext > m_pCentralViewContextSwitch;
    QTableView m_AboutHistoryTable;


public:
    MainWindowView();
    ~MainWindowView();
};

#endif

#ifndef MODELBYQACTIONITEM_H
#define MODELBYQACTIONITEM_H

#include <MyStorageType/SingleKeyContainer.h>
#include <QAction>
#include <Enum/Model/MenuModel/TypeMenu.h>
#include <Model/BaseModel/BaseModel.h>
#include <Enum/View/ViewContext/ViewContextType.h>

class ModelByQActionItem : public BaseModel {

    Q_OBJECT

    SingleKeyContainer < int,
                         QSharedPointer < QAction >,
                         QMap > m_IdMenuContainer;

    SingleKeyContainer < int,
                         ViewContextType > m_IdViewContextType;

    //сигнал о кликнутом элементе посылает указатель на элемент QAction
    //так что пришлось создать независимый контейнере с УКАЗАТЕЛЕМ.
    ///КОСТЫЛЬ :(((
    SingleKeyContainer < QAction* const,
                         int > m_MenuIdContainer;

    //последний активный пункт меню;
    int m_IdLastActiveItem;

    void checkForSpecificSignals( TypeMenu typeMenu );

signals:
    void sendMenuItem( QAction &action );
    void showViewContextType( ViewContextType viewContextType );

    //спец сигналы!
    //ЯВНО о нажатых кнопках,
    //т.к. нет ViewContext я этих моделей

    //Кнопка указания пути к проекту
    void attachProjectSelected();
    //отправка работы на проверку
    void runProjectSelected();
    //отобразить тесты
    void testSelected(); //testMenuItem

public:
    ModelByQActionItem( TypeModel typeModel );

    virtual void addItemInModel( QSharedPointer < AbstractDataItemModel > pItemData );
    virtual void updateItemInModel( QSharedPointer < AbstractDataItemModel > pItemData );
    virtual void changeIconIntoItem( int idItem,
                                     QIcon *pIcon );
    void clearItemsInModel();
    void sendAllDataBySignal();
    void setEnableStatus( int idItem,
                          bool status );

public slots:
    void modelItemSelected( QAction *action );
    void currentModelItemIsInActive();
};

#endif

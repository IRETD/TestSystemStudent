#ifndef TREE_STANDART_ITEM_BASE_MODEL_H
#define TREE_STANDART_ITEM_BASE_MODEL_H


#include <Model/BaseModel/StandardItemBaseModel/StandartItemBaseModell.h>
#include <Enum/Model/BaseModel/StandartItemBaseModel/SubClasses/TreeStandartItemModelConstants.h>
#include <Enum/View/ViewContext/ViewContextType.h>
//ДРЕВОВИДНЫЕ МОДЕЛИ

class TreeStandartItemBaseModel : public StandartItemBaseModel {

    Q_OBJECT

    void setExpandedStatus( const QModelIndex &index,
                            EXPAND_STATUS expandStatus );
public:
    TreeStandartItemBaseModel( QSharedPointer < MyStandartItemModel > pModel,
                               TypeModel typeModel );
    //элемент раскрылся
    void itemIsExpanded( const QModelIndex &index );
    //элемент скрылся
    void itemIsCollapsed( const QModelIndex &index );

signals:
    //просьба отобразить необходимый виджет
    void showViewContext( ViewContextType viewContextType );
};

#endif // TREE_STANDART_ITEM_BASE_MODEL_H

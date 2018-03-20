#include "TreeStandartItemBaseModel.h"



void TreeStandartItemBaseModel::setExpandedStatus( const QModelIndex &index,
                                                   EXPAND_STATUS expandStatus ) {

    int idItem = m_ModelIndexIdContainer.getValue( index );
    m_ModelItemDescriptorContainer.getTreeModelItemDescriptor( idItem ).data() -> setExpandStatus( expandStatus );
}


TreeStandartItemBaseModel::TreeStandartItemBaseModel( QSharedPointer < MyStandartItemModel > pModel,
                                                      TypeModel typeModel ) : StandartItemBaseModel( pModel,
                                                                                                     typeModel,
                                                                                                     ModelItemDescriptorType::TREE_MODEL_ITEM_DESCRIPTOR ) {
}


void TreeStandartItemBaseModel::itemIsExpanded( const QModelIndex &index ) {


    ////!!!!!!!!!!!!!!!!!!!!!!!!
   /*
   setExpandedStatus( index,
                      EXPAND_STATUS::EXPANDED );
  */
}


void TreeStandartItemBaseModel::itemIsCollapsed( const QModelIndex &index ) {

    ////!!!!!!!!!!!!!!!!!!!!!!!!
   /*
    setExpandedStatus( index,
                       EXPAND_STATUS::NOT_EXPANDED);
   */
}

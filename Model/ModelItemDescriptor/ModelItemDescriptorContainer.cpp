#include "ModelItemDescriptorContainer.h"


ModelItemDescriptorContainer::ModelItemDescriptorContainer( ModelItemDescriptorType modelItemDescriptorType ) {

    m_ModelItemDescriptorType = modelItemDescriptorType;
}


void ModelItemDescriptorContainer::addModelItemDescriptor( int idItem,
                                                           QSharedPointer < BaseModel > pBaseModel ,
                                                           QSharedPointer < ModelItemDescriptor > pParentItem ) {

    //assert( !m_ModelItemDescriptorTable.isContain( idItem ) );
    if ( !m_ModelItemDescriptorTable.isContain( idItem ) ) {

        QSharedPointer < ModelItemDescriptor > pModelItemDescriptor;

        if ( m_ModelItemDescriptorType == ModelItemDescriptorType::BASED_MODEL_ITEM_DESCRIPTOR ) {
            pModelItemDescriptor = QSharedPointer < ModelItemDescriptor > ( new ModelItemDescriptor( pParentItem,
                                                                                                     pBaseModel,
                                                                                                     idItem,
                                                                                                     false,
                                                                                                     NotificationType::NONE ) );
        }

        if ( m_ModelItemDescriptorType == ModelItemDescriptorType::TREE_MODEL_ITEM_DESCRIPTOR ) {

            pModelItemDescriptor = QSharedPointer < TreeModelItemDescriptor > ( new TreeModelItemDescriptor( pParentItem,
                                                                                                             pBaseModel,
                                                                                                             idItem,
                                                                                                             false,
                                                                                                             NotificationType::NONE ) );
        }

        if ( m_ModelItemDescriptorType == ModelItemDescriptorType::MODEL_BY_QACTION_ITEM_DESCRIPTOR ) {

            //менюхи делаем видимыми по умолчанию!
            pModelItemDescriptor = QSharedPointer < ModelByQActionItemDescriptor > ( new ModelByQActionItemDescriptor( pParentItem,
                                                                                                                       pBaseModel,
                                                                                                                       idItem,
                                                                                                                       true,
                                                                                                                       NotificationType::NONE ) );
        }

        m_ModelItemDescriptorTable.addValue( idItem,
                                             pModelItemDescriptor );
    }
}


QSharedPointer < ModelItemDescriptor > ModelItemDescriptorContainer::getModelItemDescriptor( int idItem ) {

    return m_ModelItemDescriptorTable.getValue( idItem );
}


QSharedPointer < TreeModelItemDescriptor > ModelItemDescriptorContainer::getTreeModelItemDescriptor( int idItem ) {

    /////////////!!!!!!!!!!!!!!!!!!!!!!!!!
    return m_ModelItemDescriptorTable.getValue( idItem ).staticCast < TreeModelItemDescriptor > ();
}


QSharedPointer < ModelByQActionItemDescriptor > ModelItemDescriptorContainer::getModelByQActionItemDescriptor( int idItem ) {

    return m_ModelItemDescriptorTable.getValue( idItem ).staticCast < ModelByQActionItemDescriptor > ();
}

#include "BaseModel.h"

BaseModel::BaseModel( TypeModel typeModel,
                      ModelItemDescriptorType modelItemDescriptorType ) : m_ModelItemDescriptorContainer( modelItemDescriptorType ),
                                                                          m_ActiveModelItemDescriptor( nullptr ),
                                                                          m_pThis( this ) {

    m_TypeModel = typeModel;
}


 QSharedPointer < ModelItemDescriptor > BaseModel::getModelItemDescriptor( int idItem ) {

    return m_ModelItemDescriptorContainer.getModelItemDescriptor( idItem );
}


TypeModel BaseModel::getTypeModel()  {

    return m_TypeModel;
}


QSharedPointer < ModelItemDescriptor > BaseModel::getActiveModelItemDescriptor() {

    return m_ActiveModelItemDescriptor;
}


void BaseModel::setActiveModelItemDescriptor( QSharedPointer < ModelItemDescriptor > modelItemDescriptor ) {

    m_ActiveModelItemDescriptor = modelItemDescriptor;
}


void BaseModel::addModelItemDescritor( int idItem,
                                       QSharedPointer < ModelItemDescriptor > pParentModelItemDescriptor ) {

    m_ModelItemDescriptorContainer.addModelItemDescriptor( idItem,
                                                           m_pThis, //здесь была бомба замедленного действия :) QSharedPointer (this ) =)
                                                           pParentModelItemDescriptor );
}

#ifndef MODEL_ITEM_DESCRIPTOR_CONTAINER_H
#define MODEL_ITEM_DESCRIPTOR_CONTAINER_H

#include <MyStorageType/SingleKeyContainer.h>
#include <Model/ModelItemDescriptor/ModelItemDescriptor.h>
#include <Model/ModelItemDescriptor/StandartItemBaseModel/TreeModelItemDescriptor.h>
#include <Model/ModelItemDescriptor/PureBaseModel/ModelByQActionItemDescriptor.h>
#include <Enum/Model/ModelItemDescriptor/ModelItemDescriptorType.h>

class ModelItemDescriptor;
class BaseModel;

class ModelItemDescriptorContainer {

    SingleKeyContainer < int,
                         QSharedPointer < ModelItemDescriptor > > m_ModelItemDescriptorTable;

    ModelItemDescriptorType m_ModelItemDescriptorType;

public:
    ModelItemDescriptorContainer( ModelItemDescriptorType modelItemDescriptorType );
    void addModelItemDescriptor( int idItem,
                                 QSharedPointer < BaseModel > pBaseModel,
                                 QSharedPointer < ModelItemDescriptor > pParentItem );

    QSharedPointer < ModelItemDescriptor > getModelItemDescriptor( int idItem );
    QSharedPointer < TreeModelItemDescriptor > getTreeModelItemDescriptor( int idItem );
    QSharedPointer < ModelByQActionItemDescriptor > getModelByQActionItemDescriptor( int idItem );
};

#endif // MODEL_ITEM_DESCRIPTOR_CONTAINER_H

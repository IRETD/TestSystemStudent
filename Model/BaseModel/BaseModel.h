#ifndef BASE_MODEL_H
#define BASE_MODEL_H

#include <Model/ModelItemDescriptor/ModelItemDescriptor.h>
#include <QIcon>
#include <Model/BaseModel/DataItemModel/AbstractDataItemModel.h>
#include <Model/ModelItemDescriptor/ModelItemDescriptorContainer.h>

class ModelItemDescriptorContainer;
class ModelItemDescriptor;

class BaseModel : public QObject {

    Q_OBJECT
    TypeModel m_TypeModel;
    QSharedPointer < ModelItemDescriptor > m_ActiveModelItemDescriptor;
    QSharedPointer < BaseModel > m_pThis;
    //ДЕРЖАТЬ ТОЛЬКО ВНУТРИ МОДЕЛИ, т.к. изменять дескрипторы необходимо по отлову сигналов с польз. интерфейса
protected:
    ModelItemDescriptorContainer m_ModelItemDescriptorContainer;

public:
    BaseModel( TypeModel typeModel,
               ModelItemDescriptorType modelItemDescriptorType );
    virtual void changeIconIntoItem( int idItem,
                                     QIcon *pIcon ) = 0;
    virtual void addItemInModel( QSharedPointer < AbstractDataItemModel > pItemData ) = 0;
    virtual void updateItemInModel( QSharedPointer < AbstractDataItemModel > pItemData ) = 0;
    virtual void clearItemsInModel() = 0;
    void addModelItemDescritor( int idItem,
                                QSharedPointer < ModelItemDescriptor > pParentModelItemDescriptor =  QSharedPointer < ModelItemDescriptor > ( nullptr ) );
    QSharedPointer < ModelItemDescriptor > getModelItemDescriptor( int idItem );
    TypeModel getTypeModel();

    QSharedPointer < ModelItemDescriptor > getActiveModelItemDescriptor();
    void setActiveModelItemDescriptor( QSharedPointer < ModelItemDescriptor > modelItemDescriptor );


signals:
    void sendIdItemSelected( int idItem );

};

#endif // BASEMODEL_H

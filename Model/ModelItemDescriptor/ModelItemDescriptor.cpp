#include "ModelItemDescriptor.h"
#include <Model/ModelItemDescriptor/ModelItemDescriptor.h>
#include <Model/BaseModel/BaseModel.h>

void ModelItemDescriptor::setIdItem( const int &idItem ) {

    m_IdItem = idItem;
}


void ModelItemDescriptor::setBaseModel( QSharedPointer < BaseModel > pModel ) {

    m_p_Model = pModel;
}


void ModelItemDescriptor::setIconType( IconType iconType ) {


    m_IconType = iconType;
}


void ModelItemDescriptor::setIconStatus( IconStatus iconStatus ) {

    m_IconStatus = iconStatus;
}

/*
void ModelItemDescriptor::setTypeModel( TypeModel typeModel ) {

    m_TypeModel = typeModel;
}


void ModelItemDescriptor::setTypeModelItem( TypeModelItem typeModelItem ) {

    m_TypeModelItem = typeModelItem;
}
*/

void ModelItemDescriptor::setParentItem( QSharedPointer < ModelItemDescriptor > pParentItem ) {

    m_p_ParentItem = pParentItem;
}


void ModelItemDescriptor::setMarketNotificationTypeValue( NotificationType notificationTypeValue ) {

    m_MarketNotificationTypeValue = notificationTypeValue;
}


void ModelItemDescriptor::addChildItem( QSharedPointer < ModelItemDescriptor > pModelItemDescriptor ) {

    m_ChildItemList.push_back( pModelItemDescriptor );
}


void ModelItemDescriptor::setVisibleStatusForChildItems( bool visibleStatus ) {

    for ( int i = 0; i < m_ChildItemList.count(); i++ ) {

        m_ChildItemList[ i ] -> setVisibleStatus( visibleStatus );
    }
}


void ModelItemDescriptor::setStopNotificationAsForPersonal( bool flag ) {

    if ( !m_StopNotificationgAsForPersonal &&
         flag ) {

        emit sendModelItemDescriptorEvent( ModelItemDescriptorEvent::STOP_NOTIFICATION_ITEM_AS_PERSONAL,
                                           this );
    }
    m_StopNotificationgAsForPersonal = flag;
}


void ModelItemDescriptor::setStopNotificationAsForParent( bool flag ) {

    if ( !m_StopNotificatonAsForParent &&
         flag ) {

        emit sendModelItemDescriptorEvent( ModelItemDescriptorEvent::STOP_NOTIFICATION_ITEM_AS_PARENT,
                                           this );
    }

    m_StopNotificatonAsForParent = flag;
}


void ModelItemDescriptor::setVisibleStatus( bool visibleStatus ) {

    m_VisibleStatus = visibleStatus;
    setVisibleStatusForChildItems( m_VisibleStatus );
}

/*
void ModelItemDescriptor::setMarketStatus( const bool &marketStatus ) {

    m_IsMarket = marketStatus;
}
*/

int ModelItemDescriptor::getIdItem() {

    return m_IdItem;
}

/*
TypeModelItem ModelItemDescriptor::getTypeModelItem() {

    return m_TypeModelItem;
}
*/


QSharedPointer < BaseModel > ModelItemDescriptor::getBaseModel() {

    return m_p_Model;
}


IconType ModelItemDescriptor::getIconType() {

    return m_IconType;
}


IconStatus ModelItemDescriptor::getIconStatus() {

    return m_IconStatus;
}

/*
TypeModel ModelItemDescriptor::getTypeModel() {

    return m_TypeModel;
}


TypeModelItem ModelItemDescriptor::getTypeModelItem() {

    return m_TypeModelItem;
}
*/

QSharedPointer < ModelItemDescriptor > ModelItemDescriptor::getParentItem() {

    return m_p_ParentItem;
}


bool ModelItemDescriptor::getStopNotificationAsForPersonal() {

    return m_StopNotificationgAsForPersonal;
}


bool ModelItemDescriptor::getStopNotificationAsForParent() {

    return m_StopNotificatonAsForParent;
}


NotificationType ModelItemDescriptor::getMatketNotificationTypeValue() {

    return m_MarketNotificationTypeValue;
}


/*
bool ModelItemDescriptor::getMarkedStatus() {

    return m_IsMarket;
}
*/



void ModelItemDescriptor::initializeAttributesByDefaultValue() {

    m_IconStatus = IconStatus::NONE_ICON_STATUS;
    m_IconType = IconType::NONE_ICON_TYPE;
    m_ChildItemList.clear();
    m_ModelItemDescriptorType = ModelItemDescriptorType::BASED_MODEL_ITEM_DESCRIPTOR;
    m_VisibleStatus = false;
    m_MarketNotificationTypeValue = NotificationType::NONE;
    m_StopNotificationgAsForPersonal = true;
    m_StopNotificatonAsForParent = true;

}


bool ModelItemDescriptor::getChangeIconPermission() {

    //если элемент виден
    bool result = m_VisibleStatus;
    if ( m_VisibleStatus ) {
        //берем у модели АКТИВНЫЙ дескриптор
        QSharedPointer < ModelItemDescriptor > activeDescriptor = m_p_Model.data() -> getActiveModelItemDescriptor();
        if ( !activeDescriptor.isNull() ) {
            //дескриптор ТОЙЖЕ модели и id элементов совпадают, значит текущий дескриптор и
            //дескриптор АКТИВНОГО (открытого) в данный момент элемента.
            bool activeStatus = ( activeDescriptor.data() -> getBaseModel().data() -> getTypeModel() ==
                                m_p_Model.data() -> getTypeModel() )
                                &&
                                ( activeDescriptor.data() -> getIdItem() ==
                                m_IdItem );

            //если элемент НЕ АКТИВЕН - мы дает разрешение на замену иконки.
            result = !activeStatus;
        }
    }

    return result;
}


void ModelItemDescriptor::addThisDescriptorToParentItemAsChild( QSharedPointer < ModelItemDescriptor > pParentItem ) {

    if ( !pParentItem.isNull() ) {
        QSharedPointer < ModelItemDescriptor > descriptor( this );
        pParentItem.data() -> addChildItem( descriptor );
    }
}


ModelItemDescriptor::ModelItemDescriptor() {

    initializeAttributesByDefaultValue();
    m_p_Model = QSharedPointer < BaseModel > ( nullptr );
    m_p_ParentItem = QSharedPointer < ModelItemDescriptor > ( nullptr );
   // m_TypeModel = TypeModel::NONE_TYPE_MODEL;
}


ModelItemDescriptor::ModelItemDescriptor( QSharedPointer < ModelItemDescriptor > pParentItem,
                                          QSharedPointer < BaseModel > pModel,
                                          int idItem,
                                          bool visibleStatus,
                                          NotificationType marketNotificationTypeValue ) {

    initializeAttributesByDefaultValue();
    m_IdItem = idItem;
    //m_TypeModel = typeModel;
   // m_TypeModelItem = typeModelItem;
    m_p_Model = pModel;
    m_p_ParentItem = pParentItem;
    m_VisibleStatus = visibleStatus;
    m_MarketNotificationTypeValue = marketNotificationTypeValue;
    addThisDescriptorToParentItemAsChild( pParentItem );
}


ModelItemDescriptor::ModelItemDescriptor( QSharedPointer < ModelItemDescriptor > pParentItem,
                                          QSharedPointer < BaseModel > pModel,
                                          int idItem ) {

    initializeAttributesByDefaultValue();
    m_IdItem = idItem;
   // m_TypeModel = typeModel;
   // m_TypeModelItem = typeModelItem;
    m_p_Model = pModel;
    m_p_ParentItem = pParentItem;
    initializeAttributesByDefaultValue();
    addThisDescriptorToParentItemAsChild( pParentItem );
}

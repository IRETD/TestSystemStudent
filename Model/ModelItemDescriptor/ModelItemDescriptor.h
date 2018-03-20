#ifndef NOTIFIACTION_ITEM_H
#define NOTIFIACTION_ITEM_H

#include <Enum/Model/TypeModelItem.h>
#include <QList>
#include <Enum/Data/IconBuffer/IconStatus.h>
#include <Enum/Model/Notification/NotificationType.h>
#include <Enum/Model/TypeModel.h>
#include <Enum/Data/IconBuffer/IconType.h>
#include <QSharedPointer>
#include <Enum/Model/ModelItemDescriptor/ModelItemDescriptorEvent.h>

#include <Enum/Model/ModelItemDescriptor/ModelItemDescriptorType.h>
#include <Enum/Model/ModelItemDescriptor/ModelItemDescriptorNotification.h>

/*
 * Хранит всю информацию о элементе оповещения
 * - id элемента
 * - Тип этого элемента в модельной структуре (модель может представлять из себя,
 * к примеру, двухуровневую организацию. Соотв. необходимо определять,
 * к какому именно уровню принадлежит данный элемент.
 * - ну и сама модель этого этого элемента.
 *
*/

class BaseModel;

class ModelItemDescriptor : public QObject {

    Q_OBJECT

protected:
    int m_IdItem;
    //TypeModel m_TypeModel;
    //TypeModelItem m_TypeModelItem;
    QSharedPointer < BaseModel > m_p_Model;
    IconType m_IconType;
    IconStatus m_IconStatus;
    QSharedPointer < ModelItemDescriptor > m_p_ParentItem;
    QList < QSharedPointer < ModelItemDescriptor > > m_ChildItemList;
    bool m_VisibleStatus;
    NotificationType m_MarketNotificationTypeValue;

    //элемент был кликнут пользователем
    bool m_StopNotificationgAsForPersonal;
    bool m_StopNotificatonAsForParent;

    void initializeAttributesByDefaultValue();

    //чтобы была возможность изменить тип дескриптора внутри класса наследника без лишней передачи через конструктор
    //базовому
protected:
    ModelItemDescriptorType m_ModelItemDescriptorType;
    //подсчет разрешения на замену иконки у текущего типа дескрипиора (BaseDescriptorType = ModelITemDescriptor)
    bool getPermissionChangeIconForBaseDescriptor();
    void addThisDescriptorToParentItemAsChild( QSharedPointer < ModelItemDescriptor > pParentItem );

signals:
    void sendModelItemDescriptorEvent( ModelItemDescriptorEvent event,
                                       ModelItemDescriptor *const pDescriptor );
public:
    ModelItemDescriptor();
    ModelItemDescriptor( QSharedPointer < ModelItemDescriptor > pParentItem,
                         //TypeModel typeModel,
                         //TypeModelItem typeModelItem,
                         QSharedPointer < BaseModel > pModel,
                         int idItem,
                         bool visibleStatus,
                         NotificationType marketNotificationTypeValue );
    ModelItemDescriptor( QSharedPointer < ModelItemDescriptor > pParentItem,
                        // TypeModel typeModel,
                        // TypeModelItem typeModelItem,
                         QSharedPointer < BaseModel > pModel,
                         int idItem );
    void setIdItem( const int &idItem );
    //void setTypeModelItem( const TypeModelItem &typeModelItem );
    void setBaseModel( QSharedPointer < BaseModel > pModel );
    void setIconType( IconType iconType );
    void setIconStatus( IconStatus iconStatus );
    //void setTypeModel( TypeModel typeModel );
    //void setTypeModelItem( TypeModelItem typeModelItem );
    void setParentItem( QSharedPointer < ModelItemDescriptor > pParentItem );
    void setMarketNotificationTypeValue( NotificationType notificationTypeValue );
    void addChildItem( QSharedPointer < ModelItemDescriptor > pNotificationItem );
    void setVisibleStatusForChildItems( bool visibleStatus );
    void setStopNotificationAsForPersonal( bool flag );
    void setStopNotificationAsForParent( bool flag );
    virtual void setVisibleStatus( bool visibleStatus );

    //разрешение на замену иконки
    bool getChangeIconPermission();

    int getIdItem();
    //TypeModelItem getTypeModelItem();
    QSharedPointer < BaseModel > getBaseModel();
    IconType getIconType();
    IconStatus getIconStatus();
    //TypeModel getTypeModel();
    //TypeModelItem getTypeModelItem();
    QSharedPointer < ModelItemDescriptor > getParentItem();
    bool getVisibleStatus();
    bool getStopNotificationAsForPersonal();
    bool getStopNotificationAsForParent();
    NotificationType getMatketNotificationTypeValue();

};


#endif

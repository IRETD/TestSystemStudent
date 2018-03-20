#include "ModelByQActionItemDescriptor.h"

//ПУНКТ МЕНЮ ВСЕГДА ВИДЕН!!!
//ЕГО НЕВОЗМОЖНО ЗАКРЫТЬ
ModelByQActionItemDescriptor::ModelByQActionItemDescriptor( QSharedPointer<ModelItemDescriptor> pParentItem,
                                                            QSharedPointer<BaseModel> pModel,
                                                            int idItem,
                                                            bool visibleStatus,
                                                            NotificationType marketNotificationTypeValue ) :  ModelItemDescriptor( pParentItem,
                                                                                                                                   pModel,
                                                                                                                                   idItem,
                                                                                                                                   visibleStatus,
                                                                                                                                   marketNotificationTypeValue ) {
}


//делеая пункт меню активным, мы можем быть уверены, что пользователь щелкнул по нему
void ModelByQActionItemDescriptor::setActiveStatus( bool activeStatus ) {

    //делая НЕ АКТИВНЫМ пункт меню - мы делаем невидимым все элементы входящие в это меню.
    setVisibleStatusForChildItems( activeStatus );

    setStopNotificationAsForParent( ModelItemDescriptorNotification::STOP_NOTIFICATION );
    setStopNotificationAsForPersonal( ModelItemDescriptorNotification::STOP_NOTIFICATION );
}

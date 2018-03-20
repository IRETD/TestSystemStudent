#include "NotificationStepByStep.h"
#include <QIcon>

NotificationStepByStep::NotificationStepByStep( QSharedPointer < IconItemManager > pIconItemManager ) : NotificationAlgorithm( pIconItemManager ) {

    m_CurrentNotificationStep = NotificationType::NONE;
    m_CurrentNotificationList.clear();
}


void NotificationStepByStep::prepareAlgortihm() {

    //мы СБРАСЫВАЕМ текущий шаг, если он не равен шагу по умолчанию,
    //чтобы сбросить иконки
    if ( m_CurrentNotificationStep != NotificationType::NONE ) {

        m_CurrentNotificationStep = NotificationType::NONE;
    }
    //переходим к следующей группе оповещения
    else {
        //очищаем лист - так как сейчас дбудем оповещать НОВЫЕ элементы
        m_CurrentNotificationList.clear();

        //вдруг у нас больше нечего оповещать после удаления элементов из списка оповещения
        //УБЕЖДАЕМСЯ ЧТО ЕСТЬ ЧТО ОПОВЕЩАТЬ
        if ( !m_NotificationTypeQueue.isEmpty() ) {

            m_CurrentNotificationStep = m_NotificationTypeQueue.getNextNotificationType();
            m_CurrentNotificationList = m_NotificationTypeQueue.getDescriptorsByNotificationType( m_CurrentNotificationStep );
        }
        else {
            //если ничего нет в списке оповещения - сбрасываем иконки
            m_CurrentNotificationStep = NotificationType::NONE;
        }
    }
}


void NotificationStepByStep::doNextStepOfNotification() {

    for ( int i = 0; i < m_CurrentNotificationList.size(); i++ ) {

        QSharedPointer < ModelItemDescriptor > pModelItemDescriptor = m_CurrentNotificationList.at( i );

        //если можно заменять иконку у текущего элемента
        if ( pModelItemDescriptor -> getChangeIconPermission() ) {
            //TypeModel typeModel = pModelItemDescriptor -> getTypeModel();
            //TypeModelItem typeModelItem = pModelItemDescriptor -> getTypeModelItem();

            //если сейчас идет процесс сброса иконки
            IconStatus iconStatus = ( IconStatus ) m_CurrentNotificationStep;

            if ( m_CurrentNotificationStep == NotificationType::NONE ) {

                iconStatus = pModelItemDescriptor.data() -> getIconStatus();
            }

            m_pIconItemManager -> setItemIcon( pModelItemDescriptor,
                                               iconStatus,
                                               IconSetReason::NOTIFICATION_SET_REASON );
        }
        else {
            QSharedPointer < ModelItemDescriptor > parentOfItem = pModelItemDescriptor;
            //помечаем ТЕКУЩИЙ ЭЛЕМЕНТ текущим ШАГОМ
            parentOfItem -> setMarketNotificationTypeValue( m_CurrentNotificationStep );
            while( true ) {
                //если нельзя, продвигаемся наверх, к родителю
                parentOfItem = parentOfItem.data() -> getParentItem();
                if ( parentOfItem == nullptr ) {
                    //СЮДА МЫ НИКОГДА НЕ ПОПАДЕМ, Т.К. ЭЛЕМЕНТ МЕНЮ МЫ ВСЕГДА СМОЖЕМ ПОДСВЕТИТЬ
                    assert( parentOfItem != nullptr );
                }

                if ( parentOfItem -> getMatketNotificationTypeValue() == m_CurrentNotificationStep ) {

                    break;
                }
                else {

                    parentOfItem -> setMarketNotificationTypeValue( m_CurrentNotificationStep );

                    if ( parentOfItem -> getChangeIconPermission() ) {

                        addNotification( NotificationType::CHILD_ITEM_IS_UPDATED,
                                         parentOfItem );
                        break;
                    }
                }
            }
        }
    }
}

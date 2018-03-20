#include "TreeModelItemDescriptor.h"


TreeModelItemDescriptor::TreeModelItemDescriptor( QSharedPointer < ModelItemDescriptor> pParentItem,
                                                  QSharedPointer<BaseModel> pModel,
                                                  int idItem,
                                                  bool visibleStatus,
                                                  NotificationType marketNotificationTypeValue ) : ModelItemDescriptor( pParentItem,
                                                                                                                        pModel,
                                                                                                                        idItem,
                                                                                                                        visibleStatus,
                                                                                                                        marketNotificationTypeValue ) {

    m_IsExpand = false;
}


void TreeModelItemDescriptor::setExpandStatus( bool expandStatus ) {

    m_IsExpand = expandStatus;
    setVisibleStatusForChildItems( expandStatus );

    //если элемент раскрылся -уведомлять элемент как РОДИТЕЛЬне имеет смысла
    // Точее говоря, если элементы (его дети) попросили данный элемент обновляться
    //после раскрытия это необхдимо ПРЕКРАТИТЬ
    //ДА ДА и ИМЕННО В ДЕСКРИПТОРЕ И НИГДЕ БОЛЬШЕ.
    //Если в дескрипторе реализован метод отлова статуса expand
    //то почему бы и здесь не организовать установку запроета оповещения как родителя для элемента
    setStopNotificationAsForParent( true );
}


bool TreeModelItemDescriptor::getExpandStatus() {

    return m_IsExpand;
}

void TreeModelItemDescriptor::setClickedStatus() {

    setStopNotificationAsForParent( true );
    setStopNotificationAsForPersonal( true );
}

//Активным статус - щелкнули по элементу

void TreeModelItemDescriptor::setVisibleStatus( bool visibleStatus ) {

    m_VisibleStatus = visibleStatus;
    if ( m_IsExpand ) {

        setVisibleStatusForChildItems( m_VisibleStatus );
    }
}

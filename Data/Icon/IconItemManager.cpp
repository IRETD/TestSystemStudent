#include "IconItemManager.h"
#include <Model/BaseModel/BaseModel.h>

IconItemManager::IconItemManager() {
}


void IconItemManager::setItemIcon( QSharedPointer < ModelItemDescriptor > pModelItemDescriptor,
                                   IconStatus iconStatus,
                                   IconSetReason iconSetReason ) {

    //получаем иконку
    IconInfo iconInfo = m_IconBuffer.getIcon( pModelItemDescriptor,
                                              iconStatus,
                                              pModelItemDescriptor.data() -> getParentItem() );

    //изменяем иконку
    int idItem = pModelItemDescriptor -> getIdItem();
    IconType iconType = iconInfo.getIconType();
    QIcon *pIcon = iconInfo.getIcon();
    pModelItemDescriptor -> getBaseModel() -> changeIconIntoItem( idItem,
                                                                  pIcon );

    //если это НЕ ОПОВЕЩЕНИЕ, то изменяем базу
    if ( iconSetReason != IconSetReason::NOTIFICATION_SET_REASON ) {
        IconType currentIconType = pModelItemDescriptor -> getIconType();
        //если новый тип иконки отличается от текущего у элемента
        if ( currentIconType != iconType ) {
            itemChangeIconType( pModelItemDescriptor,
                                currentIconType,
                                iconType );
            //переустанавливаем состояние типа иконки у дескриптора
            //Так как мы только что сменили ТИП иконки у элемента, запоминаем его.
            pModelItemDescriptor -> setIconType( iconType );
            pModelItemDescriptor -> setIconStatus( iconStatus );
        }
    }
}


void IconItemManager::addDefaultIcon( TypeModel typeModel,
                                      IconStatus iconStatus,
                                      QIcon *pIcon) {
    m_IconBuffer.addDefaultIcon( typeModel,
                                 iconStatus,
                                 pIcon );

    QList < QSharedPointer < ModelItemDescriptor > > itemList = m_DefaultItemTable.getValueList( typeModel );
    changeIconsIntoItemList( itemList,
                             pIcon,
                             iconStatus );
    /*findItemsAndChangeIconsIntoThem( typeModel,
                                     IconType::DEFAULT_ICON_TYPE,
                                     iconStatus,
                                     pIcon );*/
}


void IconItemManager::addGroupIcon( TypeModel typeModel,
                                    IconStatus iconStatus,
                                    int idGroup,
                                    QIcon *pIcon ) {

    m_IconBuffer.addGroupIcon( typeModel,
                               iconStatus,
                               idGroup,
                               pIcon );
    //определяем, если такая ГРУППА отсутствует, то формируем ее.
    // значит она сформировалась вот только сейчас, и до этого ее не было
    if ( !m_GroupItemTable.isContainsKey1Key2Key3( typeModel,
                                                   iconStatus,
                                                   idGroup ) ) {
        selectItemsIntoGroupFromDefault( typeModel,
                                         idGroup );
    }

    QList < QSharedPointer < ModelItemDescriptor >  > itemList = m_GroupItemTable.getValueList( typeModel,
                                                                             idGroup );
    changeIconsIntoItemList( itemList,
                             pIcon,
                             iconStatus );
}


void IconItemManager::addItemIcon( TypeModel typeModel,
                                   IconStatus iconStatus,
                                   int idItem,
                                   QIcon *pIcon ) {

    m_IconBuffer.addItemIcon( typeModel,
                              iconStatus,
                              idItem,
                              pIcon );
    QSharedPointer < ModelItemDescriptor > pModelItemDescriptor = QSharedPointer < ModelItemDescriptor > ( nullptr );
    if ( !m_IconItemTable.getValueIfExists( typeModel,
                                            idItem,
                                            pModelItemDescriptor ) ) {

        //сперва пытаемся найти в таблице иконок по умолчанию
        pModelItemDescriptor = selectItemFromDefault( typeModel,
                                                      idItem );
        if ( pModelItemDescriptor == nullptr ) {

            pModelItemDescriptor = selectItemFromGroup( typeModel,
                                                        idItem );
        }
    }

    //если по окончанию ВСЕХ поисков, элемент был найден
    if ( pModelItemDescriptor != nullptr ) {

        //сверяем его текущий статус с желаемым (если статусы не равным, то сменять иконку прямо
        // сейчас не имеем права
        if ( pModelItemDescriptor->getIconStatus() == iconStatus ) {

            changeIconIntoItem( pModelItemDescriptor,
                                pIcon );
        }
    }
}


void IconItemManager::removeItem( QSharedPointer < ModelItemDescriptor > pModelItemDescriptor,
                                  IconType iconType ) {


    TypeModel typeModel = pModelItemDescriptor -> getBaseModel() -> getTypeModel();
    int idItem = pModelItemDescriptor -> getIdItem();

    if ( m_IconItemTable.isContainsKey1Key2( typeModel,
                                             idItem ) ) {

        m_IconItemTable.removeKey2( typeModel,
                                    idItem );
    }
}


void IconItemManager::changeIconsIntoItemList( QList < QSharedPointer < ModelItemDescriptor > > &itemList,
                                               QIcon *pIcon,
                                               IconStatus iconStatus ) {

    for ( int i = 0; i < itemList.size(); i++ ) {

        if ( itemList[ i ] -> getIconStatus() == iconStatus ) {
            changeIconIntoItem( itemList[ i ],
                                pIcon );
        }
    }
}

void IconItemManager::changeIconIntoItem( QSharedPointer < ModelItemDescriptor > pModelItemDescriptor,
                                          QIcon *pIcon ) {
    int idItem = pModelItemDescriptor -> getIdItem();
    pModelItemDescriptor -> getBaseModel() -> changeIconIntoItem( idItem,
                                                                pIcon );
}


void IconItemManager::selectItemsIntoGroupFromDefault( TypeModel typeModel,
                                                       int idGroup ) {

    QList < QSharedPointer < ModelItemDescriptor >  > itemList = m_DefaultItemTable.getValueList( typeModel );
    for ( int i = 0; i < itemList.size(); i++ ) {

        QSharedPointer < ModelItemDescriptor > pParent = itemList[ i ] -> getParentItem();
        if ( pParent != nullptr ) {

            int idItemParent = pParent -> getIdItem();
            if ( idItemParent == idGroup ) {
                int idItem = itemList[ i ] -> getIdItem();
                m_DefaultItemTable.removeKey2( typeModel,
                                               idItem );
                m_GroupItemTable.addValue( typeModel,
                                           idGroup,
                                           idItem,
                                           itemList[ i ] );
            }
        }
    }
}


QSharedPointer < ModelItemDescriptor > IconItemManager::selectItemFromDefault( TypeModel typeModel,
                                                             int idItem ) {

    QSharedPointer < ModelItemDescriptor > pModelItemDescriptor = QSharedPointer < ModelItemDescriptor > ( nullptr );
    //если нашли элемент в таблице иконок ПО УМОЛЧАНИЮ
    if ( m_DefaultItemTable.getValueIfExists( typeModel,
                                              idItem,
                                              pModelItemDescriptor ) ) {

        //Удаляем его, предже чем перенесем в новую таблицу
        m_DefaultItemTable.removeKey2( typeModel,
                                       idItem );
        //заносим в новую таблицу (таблицу индивидульных иконок)
        m_IconItemTable.addValue( typeModel,
                                  idItem,
                                  pModelItemDescriptor );
    }

    return pModelItemDescriptor;
}


QSharedPointer < ModelItemDescriptor > IconItemManager::selectItemFromGroup( TypeModel typeModel,
                                                           int idItem ) {
    QSharedPointer < ModelItemDescriptor > pModelItemDescriptor = QSharedPointer < ModelItemDescriptor > ( nullptr );
    //получаем все имеющиеся группы
    QList < int > groupList = m_GroupItemTable.getKey2List( typeModel );
    for ( int i = 0; i < groupList.size(); i++ ) {

        int idGroup = groupList[ i ];
        //если в текущей группе найден искомый элемент по его id
        if ( m_GroupItemTable.getValueIfExists( typeModel,
                                                idGroup,
                                                idItem,
                                                pModelItemDescriptor ) ) {
            //удаляем найденный элемент из группы
            m_GroupItemTable.removeKey3( typeModel,
                                         idGroup,
                                         idItem );

            //заносим его в таблицу индивидуальных элементов
            m_IconItemTable.addValue( typeModel,
                                      idItem,
                                      pModelItemDescriptor );
            break;
        }
    }

    return pModelItemDescriptor;
}


void IconItemManager::itemChangeIconType( QSharedPointer < ModelItemDescriptor > pModelItemDescriptor,
                                          IconType oldIconType,
                                          IconType newIconType ) {

    assert( pModelItemDescriptor != nullptr );
    removeItem( pModelItemDescriptor,
                oldIconType );
    addItem( pModelItemDescriptor,
             newIconType );
}


/*void IconItemManager::changeItemsIcon( TypeModel typeModel,
                                       IconType iconType,
                                       QIcon *pIcon ) {

    QList < QSharedPointer < ModelItemDescriptor >  > itemList = m_IconItemTable.getValueList( typeModel,
                                                                            iconType );
    int size = itemList.size();
    for ( int i = 0 ; i < size; i++ ) {

        int idItem = itemList[ i ] -> getIdItem();
        itemList[ i ] -> getBaseModel() -> changeIconIntoItem( idItem,
                                                               pIcon );
    }
}*/


void IconItemManager::addItem( QSharedPointer < ModelItemDescriptor > pModelItemDescriptor ,
                               IconType iconType ) {

    assert( pModelItemDescriptor != nullptr );
    TypeModel typeModel = pModelItemDescriptor -> getBaseModel() -> getTypeModel();
    int idItem = pModelItemDescriptor -> getIdItem();

    m_IconItemTable.addValue( typeModel,
                              idItem,
                              pModelItemDescriptor );
}



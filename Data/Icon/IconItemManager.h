#ifndef ICON_ITEM_MANAGER_H
#define ICON_ITEM_MANAGER_H

#include <MyStorageType/TripleKeyContainer.h>
#include <MyStorageType/DoubleKeyContainer.h>
#include <Model/ModelItemDescriptor/ModelItemDescriptor.h>
#include <Enum/Data/IconBuffer/IconType.h>
#include <Data/Icon/IconBuffer.h>
#include <Enum/Data/Icon/IconSetReason.h>
#include <QIcon>

class IconItemManager {

    DoubleKeyContainer < TypeModel,
                         int,
                         QSharedPointer < ModelItemDescriptor > > m_IconItemTable;

    TripleKeyContainer < TypeModel,
                         int,
                         int,
                         QSharedPointer < ModelItemDescriptor > > m_GroupItemTable;

    DoubleKeyContainer < TypeModel,
                         int,
                         QSharedPointer < ModelItemDescriptor > > m_DefaultItemTable;


    IconBuffer m_IconBuffer;

    void itemChangeIconType( QSharedPointer < ModelItemDescriptor > pModelItemDescriptor,
                             IconType oldIconType,
                             IconType newIconType );
    void addItem( QSharedPointer < ModelItemDescriptor > pModelItemDescriptor,
                  IconType iconType );
    void removeItem( QSharedPointer < ModelItemDescriptor > pModelItemDescriptor,
                     IconType iconType );

    //просто лишь несколько упрощение обрабтки НЕСКОЛЬКИХ дескрипторов по замене
    void changeIconsIntoItemList( QList < QSharedPointer < ModelItemDescriptor > > &itemList,
                                  QIcon *pIcon,
                                  IconStatus iconStatus );

    //изменяем иконку по заданному дескриптору
    void changeIconIntoItem( QSharedPointer < ModelItemDescriptor > pModelItemDescriptor,
                             QIcon *pIcon );

    //отбираем элементы из таблицы иконок по умолчанию в отдельную группу
    void selectItemsIntoGroupFromDefault( TypeModel typeModel,
                                          int idGroup );

    //Ищем конкретный элемент в группах и в таблице иконок по умолчанию
    QSharedPointer < ModelItemDescriptor >selectItemFromDefault( TypeModel typeModel,
                                                                 int idItem );
    QSharedPointer < ModelItemDescriptor > selectItemFromGroup( TypeModel typeModel,
                                                                int idItem );

public:
    IconItemManager();
    void setItemIcon( QSharedPointer < ModelItemDescriptor > pModelItemDescriptor,
                      IconStatus iconStatus,
                      IconSetReason iconSetReason );
    void addDefaultIcon( TypeModel typeModel,
                         IconStatus iconStatus,
                         QIcon *pIcon );
    void addGroupIcon( TypeModel typeModel,
                       IconStatus iconStatus,
                       int idGroup,
                       QIcon *pIcon );
    void addItemIcon( TypeModel typeModel,
                      IconStatus iconStatus,
                      int idItem,
                      QIcon *pIcon );
};

#endif

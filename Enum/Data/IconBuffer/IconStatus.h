#ifndef ICONSTATUS_H
#define ICONSTATUS_H
#include <Enum/Model/Notification/NotificationType.h>

enum IconStatus {

    NONE_ICON_STATUS = 0,
    DEFAULT_ICON_STATUS = NotificationType::NONE,
    UPDATE_ICON_STATUS = NotificationType::ITEM_IS_UPDATED,
    NEW_ICON_STATUS = NotificationType::ITEM_IS_NEW,
    CHILD_CHANGE_ICON_STATUS = NotificationType::CHILD_ITEM_IS_UPDATED
};

#endif

#include "IconInfo.h"


IconInfo::IconInfo() {
}


void IconInfo::setIcon( QIcon *pIcon ) {

    m_pIcon = pIcon;
}


void IconInfo::setIconType( IconType iconType ) {

    m_IconType = iconType;
}


QIcon *IconInfo::getIcon() {

    return m_pIcon;
}


IconType IconInfo::getIconType() {

    return m_IconType;
}

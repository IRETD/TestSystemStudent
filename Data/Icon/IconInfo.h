#ifndef ICONINFO_H
#define ICONINFO_H

#include <QIcon>
#include <Enum/Data/IconBuffer/IconType.h>

class IconInfo {

    QIcon *m_pIcon;
    IconType m_IconType;

public:
    IconInfo();

    void setIcon( QIcon *pIcon );
    void setIconType( IconType iconType );

    QIcon *getIcon();
    IconType getIconType();
};

#endif // ICONINFO_H

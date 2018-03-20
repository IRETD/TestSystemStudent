#ifndef DATAITEMMODEL_H
#define DATAITEMMODEL_H

#include <Model/BaseModel/DataItemModel/AbstractDataItemModel.h>
#include <Enum/View/ViewContext/ViewContextType.h>
#include <QIcon>
#include <QString>


class DataItemModelForModelByQActionItem : public AbstractDataItemModel {

    QString m_Title;
    ViewContextType m_ViewContextType;

public:
    DataItemModelForModelByQActionItem( int id,
                                        QString title,
                                        ViewContextType viewContextType );
    void setTitle( QString title );

    QString getTitle();
    ViewContextType getViewContextType();
};

#endif

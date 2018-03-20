#ifndef STANDARTITEMDATAITEMMODEL_H
#define STANDARTITEMDATAITEMMODEL_H

#include <QPersistentModelIndex>
#include <Model/BaseModel/DataItemModel/AbstractDataItemModel.h>
#include <QSharedPointer>

class DataItemModelForStandartItemBaseModel : public AbstractDataItemModel {

    QString m_Title;
    QPersistentModelIndex m_PersistentModelIndex;

public:

    DataItemModelForStandartItemBaseModel();
    void setParent( QPersistentModelIndex &pPersistentModelIndex );
    QPersistentModelIndex getParent();
    void setTitle( QString title );
    QString getTitle();
};

#endif

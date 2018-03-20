#ifndef DATAITEMFORMODELTEXTDESCRIPTION_H
#define DATAITEMFORMODELTEXTDESCRIPTION_H

#include <Model/BaseModel/DataItemModel/AbstractDataItemModel.h>
#include <QString>

class DataItemForModelTextDescription : public AbstractDataItemModel {

    QString m_Text;

public:
    DataItemForModelTextDescription();
    QString getText();
    void setText( QString text );
};

#endif // DATAITEMFORMODELTEXTDESCRIPTION_H

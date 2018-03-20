#ifndef ABSTRACTDATAITEMMODEL_H
#define ABSTRACTDATAITEMMODEL_H

#include <QString>

class AbstractDataItemModel {

    //это поле все равно имеют все наследуемые классы.
    //Общие поля проще вынести в общий класс, чтобы к примеру, в дальнейшем,
    //по указателю на этот класс хоть ЧТО_ТО узнать о объекте
protected:
    int m_IdItem;
    int m_IdColumn;
    bool m_ColumnData;

public:
    AbstractDataItemModel();

    void setIdColumn( int idColumn );
    int getIdColumn();
    void setIdItem( int idItem );
    int getIdItem();
    bool isItColumnData();
};

#endif // ABSTRACTDATAITEMMODEL_H

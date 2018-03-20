#include <Model/BaseModel/DataItemModel/StandartItemBaseModel/DataItemModelForStandartItemBaseModel.h>


DataItemModelForStandartItemBaseModel::DataItemModelForStandartItemBaseModel()  {

}


void DataItemModelForStandartItemBaseModel::setParent( QPersistentModelIndex &pPersistentModelIndex ) {

    m_PersistentModelIndex = pPersistentModelIndex;
}


QPersistentModelIndex DataItemModelForStandartItemBaseModel::getParent() {

    return m_PersistentModelIndex;
}


void DataItemModelForStandartItemBaseModel::setTitle( QString title ){

    m_Title = title;
}


QString DataItemModelForStandartItemBaseModel::getTitle() {

    return m_Title;
}

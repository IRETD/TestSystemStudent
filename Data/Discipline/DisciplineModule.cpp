#include "DisciplineModule.h"
#include <Model/BaseModel/DataItemModel/StandartItemBaseModel/DataItemModelForStandartItemBaseModel.h>
#include <Enum/Model/MenuModel/TypeMenu.h>
#include <QScopedPointer>
#include <QtAlgorithms>


void DisciplineModule::updateIdDiscipline( const int &oldId,
                                           const int &newId ) {

    //реализовать интерфейс замены id в модели
}


void DisciplineModule::updateDescription( const int &idDiscipline,
                                          const QString &textDescription ) {

    // потом добавлю, да
}


void DisciplineModule::updateTitle( int const &idDiscipline,
                                    QString const &title ) {

    QSharedPointer < DataItemModelForStandartItemBaseModel > pData = initializeNewDataForStandartItemBaseModel( idDiscipline,
                                                                                                                title );
    m_pDisciplineModel.data() -> updateItemInModel( pData );
}


void DisciplineModule::addDiscipline( Discipline const &discipline ) {

    int idDiscipline = discipline.getIdDiscipline();

    QSharedPointer < DataItemModelForStandartItemBaseModel > pData = initializeNewDataForStandartItemBaseModel( idDiscipline,
                                                                                                                discipline.getName() );
    addNewItem( m_pDisciplineModel,
                pData,
                m_pMenuModel.data() -> getModelItemDescriptor( TypeMenu::DISCIPLINE_MENU_ITEM ) );
    m_pNotificationManager.data() -> addNotification( NotificationType::ITEM_IS_NEW,
                                                      m_pDisciplineModel.data() -> getModelItemDescriptor( idDiscipline) );
    m_pDisciplineTextDescriptionModule.data() -> addData( discipline );

    /*
    m_pDisciplineModel.data() -> addItemInModel( pData );
    //инициализируем дескриптор добавленного элемента
    m_pDisciplineModel.data() -> addModelItemDescritor( idDiscipline,
                                                        m_pMenuModel.data() -> getModelItemDescriptor( TypeMenu::DISCIPLINE_MENU_ITEM ) );
    //устанавливаем иконку для добавленного элемента.
    m_pIconItemManager.data() -> setItemIcon(  m_pDisciplineModel.data()->getModelItemDescriptor( idDiscipline),
                                               IconStatus::DEFAULT_ICON_STATUS,
                                               IconSetReason::FOREVER_SET_REASON );
   */
}


DisciplineModule::DisciplineModule( QSharedPointer<ModelByQActionItem> pMenuModel,
                                    QSharedPointer < DisciplineTextDescriptionModule> pDisciplineTextDescriptionModule,
                                    QSharedPointer < IconItemManager > pIconItemManager ,
                                    QSharedPointer < NotificationManager > pNotificationManager ) : BaseModule( pIconItemManager,
                                                                                                                pNotificationManager ) {

    m_pMenuModel = pMenuModel;
    m_pDisciplineModel =  initializeNewStandartItemBaseModel( TypeModel::DISCIPLINE_TYPE_MODEL );
    m_pDisciplineTextDescriptionModule = pDisciplineTextDescriptionModule;

    QObject::connect( m_pDisciplineModel.data(),
                      &TreeStandartItemBaseModel::sendIdItemSelected,
                      m_pDisciplineTextDescriptionModule.data()-> getDisciplineTextDescriptionModel().data(),
                      &ModelTextDisciplineDescription::disciplineItemSelected );
}


void DisciplineModule::addData( QSharedPointer < DataForDisciplineModule > pData ) {

    Discipline discipline = pData.data() -> getDiscipline();
    int idDiscipline = discipline.getIdDiscipline();

    //Если это НОВЫЕ ДАННЫЕ, обновляем ВСЕ
    if ( pData.data() -> getDataInfo() == DataInfo::THIS_IS_NEW_DATA ) {

        m_DisciplineContainer.addValue( idDiscipline,
                                        discipline );
        addDiscipline( discipline );
    }

    //если это апдейт, начинаем пробегать по списку и смотреть какие поля могли обновиться
    if ( pData.data() -> getDataInfo() == DataInfo::THIS_IS_JUST_UPDATE_DATA ) {

        QList < int > changedFields = pData.data() -> getChangedFieldList();
        //СОРТИРУЕМ, ЧТОБЫ ИЗМЕНЕНИЕ НОВОГО ID ПРОШЛО СРАЗУ!
        ////Я думаю имеет смысл вынести сортировку в get метод
        qSort( changedFields.begin(),
               changedFields.end() );
        int size = changedFields.size();
        for ( int i = 0; i < size; i++ ) {

            if( changedFields.at( i ) == DisciplineFieldName::ID_DISCIPLINE_FIELD ) {
                //если заменился id дисциплины, нам ведь необходимо сперва получить старый
                int oldId = pData.data() -> getOldId();
                Discipline discipline = m_DisciplineContainer.getValue( oldId );
                discipline.setIdDiscipline( idDiscipline );
                m_DisciplineContainer.removeByKey( oldId );
                m_DisciplineContainer.addValue( idDiscipline,
                                                discipline );
                updateIdDiscipline( oldId,
                                    idDiscipline );
            }

            //обновляем имя дисциплины
            if( changedFields.at( i ) == DisciplineFieldName::NAME_DISCIPLINE_FIELD ) {
                m_DisciplineContainer.getValue( idDiscipline).setName( discipline.getName() );
                updateTitle( idDiscipline,
                             discipline.getName() );
            }

            //обновляем описание дисциплины
            if( changedFields.at( i ) == DisciplineFieldName::DESCRIPTION_DISCIPLINE_FIELD ) {
                m_DisciplineContainer.getValue( idDiscipline ).setDescription( discipline.getDescription() );
                updateDescription( idDiscipline,
                                   discipline.getDescription() );
            }
        }
    }
}


QSharedPointer < TreeStandartItemBaseModel > DisciplineModule::getDisciplineModel() {

    return m_pDisciplineModel;
}

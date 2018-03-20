#include "IconBuffer.h"
#include <MacroDefinitons/DestroyPointerMacro.h>
#include <assert.h>
#include <QScopedPointer>
#include <Model/BaseModel/BaseModel.h>
#include <Enum/Model/MenuModel/TypeMenu.h>
#include <Data/StaticAnalyzer/StaticAnalyzer.h>
/*
void IconBuffer::initializeNewIcon( QString &pathIconToResources,
                                    const IconName &iconName,
                                    const IconStatus &iconStatus ) {

    QIcon *pIcon = new QIcon;
    pIcon -> addFile( pathIconToResources );
    auto &iconStatusTable = m_IconTable[ iconName ];
    iconStatusTable[ iconStatus ] = pIcon;
}
*/


QIcon *IconBuffer::getIconByResourcePath( QString resourcePath ) {

    QIcon *pIcon = new QIcon;
    pIcon -> addFile( resourcePath );
    return pIcon;
}


IconBuffer::IconBuffer() {

    QIcon *icon = nullptr;
/*
    QIcon *icon = new QIcon;
    icon -> addFile( ":/images/tree/discipline/subject_128.png" );
    m_IconTable[ IconName::TREE_DISCIPLINE ] = icon;

    icon = new QIcon;
    icon -> addFile( ":/images/tree/lab/list_256.png" );
    m_IconTable[ IconName::TREE_LAB ] = icon;

    icon = new QIcon;
    icon -> addFile( ":/images/tree/notification/warnings_256.png" );
    m_IconTable[ IconName::TREE_NOTIFICATION_WARNING ] = icon;

    icon = new QIcon;
    icon -> addFile( ":/images/tree/notification/files_info_256.png" );
    m_IconTable[ IconName::TREE_NOTIFICATION_ADD_PROJECT ] = icon;

    icon = new QIcon;
    icon -> addFile( ":/images/tree/discipline/subject_ok_128.png" );
    m_IconTable[ IconName::TREE_DISCIPLINE_ACTIVE ] = icon;

    icon = new QIcon;
    icon -> addFile( ":/images/tree/button_ok.png" );
    m_IconTable[ IconName::TREE_ACTIVE ] = icon;

    icon = new QIcon;
    icon -> addFile( ":/images/tree/history/test_ok_256.png" );
    m_IconTable[ IconName::TREE_HISTORY_OK ] = icon;

    icon = new QIcon;
    icon -> addFile( ":/images/tree/history/test_close_256.png" );
    m_IconTable[ IconName::TREE_HISTORY_FAIL ] = icon;

    icon = new QIcon;
    icon -> addFile( ":/images/tree/history/test_256.png" );
    m_IconTable[ IconName::TABLE_HISTORY_TEST ] = icon;

    icon = new QIcon;
    QPixmap *pixmap = new QPixmap( ":/images/tree/history/Date And Time.png" );
    pixmap->scaled( QSize( 20, 20 ) );
    icon -> addPixmap( *pixmap, QIcon::Selected );
    m_IconTable[ IconName::TABLE_HISTORY_DATETIME ] = icon;

    icon = new QIcon;
    icon -> addFile( ":/images/tree/history/results_256.png" );
    m_IconTable[ IconName::TABLE_HISTORY_RESULT ] = icon;

    icon = new QIcon;
    icon -> addFile( ":/images/tree/history/numbering_256.png" );

    m_IconTable[ IconName::TREE_HISTORY_NUM ] = icon;
*/
    //Загружаем по умолчанию иконку Дисциплины
    /*initializeNewIcon( ":/Resources/images/Model/DisciplineModel/DefaultDisciplineImage.png",
                       IconName::SIDE_MENU_DISCIPLINE_ICON,
                       IconStatus::DEFAULT_ICON_STATUS );

    initializeNewIcon( ":/Resources/images/Model/DisciplineModel/DefaultTaskImage.png",
                       IconName::TASK_MODEL_ICON,
                       IconStatus::DEFAULT_ICON_STATUS );

    initializeNewIcon( ":/Resources/images/Model/DisciplineModel/DefaultDisciplineImage.png",
                       IconName::DISCIPLINE_MODEL_ICON,
                       IconStatus::DEFAULT_ICON_STATUS );
*/
    /*icon = new QIcon;
    icon -> addFile( ":/Resources/images/Model/DisciplineModel/THERE_IS_NO_AVAILABLE_DISCIPLINE.png" );
    m_IconTable[ IconName::DISCIPLINE_MODEL_NO_DISCIPLINE ] = icon;

    icon = new QIcon;
    icon -> addFile( ":/Resources/images/Model/DisciplineModel/DefaultDisciplineImage.png" );
    m_IconTable[ IconName::DISCIPLINE_MODEL_DEFAULT_ICON ] = icon;

    icon = new QIcon;
    icon -> addFile( ":/Resources/images/Model/DisciplineModel/DefaultTaskImage.png" );
    m_IconTable[ IconName::TASK_MODEL_DEFAULT_ICON ] = icon;

    icon = new QIcon;
    icon -> addFile( ":/Resources/images/Model/DisciplineModel/WordLogo.png" );
    m_IconTable[ IconName::DISCIPLINE_FILES_WORD ] = icon;

    icon = new QIcon;
    icon -> addFile( ":/Resources/images/Model/DisciplineModel/DefaultDisciplineImageLightOn.png" );
    m_IconTable[ IconName::SIDE_MENU_DISCIPLINE_WARNING ] = icon;*/

    //МЕНЮ
    addItemIcon( TypeModel::MENU_TYPE_MODEL,
                 IconStatus::DEFAULT_ICON_STATUS,
                 TypeMenu::DISCIPLINE_MENU_ITEM,
                 getIconByResourcePath( QString( ":/MenuDisciplineModelItem/DefaultMenuDisciplineModelItem" ) ) );
    addItemIcon( TypeModel::MENU_TYPE_MODEL,
                 IconStatus::CHILD_CHANGE_ICON_STATUS,
                 TypeMenu::DISCIPLINE_MENU_ITEM,
                 getIconByResourcePath( QString( ":/MenuDisciplineModelItem/DefaultMenuDisciplineModelItem_ChildItemIsUpdate" ) ) );

    addItemIcon( TypeModel::MENU_TYPE_MODEL,
                 IconStatus::DEFAULT_ICON_STATUS,
                 TypeMenu::TEST_MENU_ITEM,
                 getIconByResourcePath( QString( ":/MenuTest/DefaultMenuTest" ) ) );

    addItemIcon( TypeModel::MENU_TYPE_MODEL,
                 IconStatus::DEFAULT_ICON_STATUS,
                 TypeMenu::ANALYZE_MENU_ITEM,
                 getIconByResourcePath( QString( ":/Analyze/DefaultAnalyze" ) ) );

    addItemIcon( TypeModel::MENU_TYPE_MODEL,
                 IconStatus::DEFAULT_ICON_STATUS,
                 TypeMenu::ATTACH_PROJECT_MENU_ITEM,
                 getIconByResourcePath( QString( ":/AttachProject/DefaultAttachProject" ) ) );

    addItemIcon( TypeModel::MENU_TYPE_MODEL,
                 IconStatus::DEFAULT_ICON_STATUS,
                 TypeMenu::RUN_PROJECT_MENU_ITEM,
                 getIconByResourcePath( QString( ":/Run/DefaultRun" ) ) );


    //ЛАБОРАТОРНАЯ
    addDefaultIcon( TypeModel::TASK_TYPE_MODEL,
                    IconStatus::DEFAULT_ICON_STATUS,
                    getIconByResourcePath( QString( ":/TaskModelItem/DefaultTaskModelItem" ) ) );
    addDefaultIcon( TypeModel::TASK_TYPE_MODEL,
                    IconStatus::NEW_ICON_STATUS,
                    getIconByResourcePath( QString( ":/TaskModelItem/DefaultTaskModelItem_NewItem" ) ) );


    //ДИСЦИПЛИНЫ
    addDefaultIcon( TypeModel::DISCIPLINE_TYPE_MODEL,
                    IconStatus::NEW_ICON_STATUS,
                    getIconByResourcePath( QString( ":/DisciplineModelItem/DefaultDisciplineModelItem_NewItem" ) ) );
    addDefaultIcon( TypeModel::DISCIPLINE_TYPE_MODEL,
                    IconStatus::CHILD_CHANGE_ICON_STATUS,
                    getIconByResourcePath( QString( ":/DisciplineModelItem/DefaultDisciplineModelItem_ChildItemIsUpdate" ) ) );
    addDefaultIcon( TypeModel::DISCIPLINE_TYPE_MODEL,
                    IconStatus::DEFAULT_ICON_STATUS,
                    getIconByResourcePath( QString( ":/DisciplineModelItem/DefaultDisciplineModelItem" ) ) );

    //ТЕСТЫ
    addDefaultIcon( TypeModel::TEST_TYPE_MODEL,
                    IconStatus::DEFAULT_ICON_STATUS,
                    getIconByResourcePath( QString( ":/Test/DefaultTestModelItem" ) ) );

    //STATIC ANALYZER
    addItemIcon( TypeModel::STATIC_ANALYZE_MODEL,
                 IconStatus::DEFAULT_ICON_STATUS,
                 static_cast < int > ( TypeStaticAnalyzer::ERROR_ANALYZE ),
                 getIconByResourcePath( QString( ":/StaticAnalyzer/DefaultErrorStaticAnalyzer" ) ) );

    //ABOUT_STATIC_ANALYZER
    addDefaultIcon( TypeModel::ABOUT_STATIC_ANALYZE_MODEL,
                    IconStatus::DEFAULT_ICON_STATUS,
                    getIconByResourcePath( QString( ":/AboutStaticAnalyzer/DefaultAboutStaticAnalyzer" ) ) );

}


IconBuffer::~IconBuffer() {

    /*auto it = m_IconTable.begin();
    auto itEnd = m_IconTable.end();
    while ( it != itEnd ) {
        //УДАЛЕНИЕ ИКОНОК!!!!
       // DestroyPointer( it.value() )
    }
    */
}


//БЫТЬ МОЖЕТ ИМЕЕТ СМЫСЛ ИЗМЕНИТЬ АЛГОРИТМ ПОИСКА
//Я ДУМАЮ, ЧТО В БОЛЬШИНСТВЕ СЛУЧАЕВ ИКОНКИ БУДУТ ПО УМОЛЧАНИЮ
// ПОСЕМУ, ПРОБЕГАТЬ 2 ХЭШ-ТАБЛИЦЫ ДО ТАБЛИЦЫ С ИКОНКАМИ ПО УМОЛЧАНИЮ.
///НО ЭТО ОСТАВИТЬ НА ПОТОМ
IconInfo IconBuffer::getIcon( QSharedPointer < ModelItemDescriptor > targetItem,
                              IconStatus iconStatus,
                              QSharedPointer < ModelItemDescriptor > pParentItem ) {

    assert( targetItem != nullptr );

    IconInfo iconInfo;

    QIcon *pIcon = nullptr;
    int idTargetItem = targetItem -> getIdItem();
    TypeModel typeModelTargetItem = targetItem -> getBaseModel() -> getTypeModel();

    //если нашли СОБСТВЕННУЮ иконку
    if ( m_ItemIconBuffer.getValueIfExists( typeModelTargetItem,
                                            iconStatus,
                                            idTargetItem,
                                            pIcon ) ) {
        iconInfo.setIconType( IconType::ITEM_ICON_TYPE );
    }
    else {

        //Если указан родитель, то поиск не исключает вомзожности
        //присутствия иконки для элемента в какой-либо группе,
        //которая создана на имя его предка
        bool resultOfExists = false;
        if ( pParentItem != nullptr ) {

            idTargetItem = pParentItem -> getIdItem();
            TypeModel parentTypeModel = pParentItem -> getBaseModel() -> getTypeModel();
            resultOfExists = m_GroupIconBuffer.getValueIfExists( parentTypeModel,
                                                                 iconStatus,
                                                                 idTargetItem,
                                                                 pIcon );
            //resultOfExists = true;
            iconInfo.setIconType( IconType::GROUP_ICON_TYPE );
        }

        //группу не нашли, остается брать иконку по умолчанию.
        if ( resultOfExists != true ) {

            m_DefaultIconBuffer.getValueIfExists( typeModelTargetItem,
                                                  iconStatus,
                                                  pIcon );
            iconInfo.setIconType( IconType::DEFAULT_ICON_TYPE );
        }
    }

    assert( pIcon != nullptr );
    iconInfo.setIcon( pIcon );

    return iconInfo;
}


QIcon *IconBuffer::getDefaultIcon( TypeModel typeModel,
                                   IconStatus iconStatus ) {

    return m_DefaultIconBuffer.getValue( typeModel,
                                         iconStatus );
}


void IconBuffer::addDefaultIcon( TypeModel typeModel,
                                 IconStatus iconStatus,
                                 QIcon *pIcon ) {

    m_DefaultIconBuffer.addValue( typeModel,
                                  iconStatus,
                                  pIcon );
}


void IconBuffer::addGroupIcon( TypeModel typeModel,
                               IconStatus iconStatus,
                               int idItem,
                               QIcon *pIcon ) {

    m_GroupIconBuffer.addValue( typeModel,
                                iconStatus,
                                idItem,
                                pIcon );
}


void IconBuffer::addItemIcon( TypeModel typeModel,
                              IconStatus iconStatus,
                              int idItem,
                              QIcon *pIcon ) {

    m_ItemIconBuffer.addValue( typeModel,
                               iconStatus,
                               idItem,
                               pIcon );
}


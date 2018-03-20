#include "DataModule.h"


DataModule::DataModule( QSharedPointer < RequestHandler > pRequestHandler ) {

    m_pRequestHandler = pRequestHandler;

    m_pDisciplineTextDescriptionModule = QSharedPointer < DisciplineTextDescriptionModule > ( new DisciplineTextDescriptionModule );
    m_pTaskTextDescriptionModule = QSharedPointer < TaskTextDescriptionModule > ( new TaskTextDescriptionModule );

    m_pImageModule = QSharedPointer < ImageModule > ( new ImageModule );
    QSharedPointer < IconItemManager > pIconItemManager = m_pImageModule.data() -> getIconItemManager();
    m_pNotificationModule = QSharedPointer < NotificationModule > ( new NotificationModule( pIconItemManager ) );
    QSharedPointer < NotificationManager > pNotificationManager = m_pNotificationModule.data() -> getNotificationManager();

    m_pMenuModule = QSharedPointer < MenuModule > ( new MenuModule( pIconItemManager,
                                                                    pNotificationManager ) );

    QSharedPointer < ModelByQActionItem > pMenuModel = m_pMenuModule.data() -> getMenuModel();
    m_pDisciplineModule = QSharedPointer < DisciplineModule > ( new DisciplineModule( pMenuModel,
                                                                                      m_pDisciplineTextDescriptionModule,
                                                                                      pIconItemManager,
                                                                                      pNotificationManager ) );

    QSharedPointer < TreeStandartItemBaseModel > pDisciplineModel = m_pDisciplineModule.data() -> getDisciplineModel();
    m_pTaskModule = QSharedPointer < TaskModule > ( new TaskModule ( pDisciplineModel,
                                                                     m_pTaskTextDescriptionModule,
                                                                     pIconItemManager,
                                                                     pNotificationManager ) );
    QSharedPointer < TreeStandartItemBaseModel > pTaskModel = m_pTaskModule.data() -> getTaskModel();

    m_pRunProjectModule = QSharedPointer < RunProjectModule > ( new RunProjectModule ( pMenuModel,
                                                                                       m_pRequestHandler ) );

    m_pAttachProjectModule = QSharedPointer < AttachProjectModule > ( new AttachProjectModule ( pMenuModel,
                                                                                                pTaskModel,
                                                                                                pDisciplineModel,
                                                                                                m_pRunProjectModule,
                                                                                                m_pTaskModule) );

    //Инициализация отдельным МЕТОДОМ. Печаль беда :)
    m_pRunProjectModule.data() -> setAttachProjectModule( m_pAttachProjectModule );

    m_pAboutTestModule = QSharedPointer < AboutTestModule > ( new AboutTestModule( pIconItemManager,
                                                                                   pNotificationManager,
                                                                                   m_pRequestHandler ) );


    m_pTestModule =  QSharedPointer < TestModule > ( new TestModule( pMenuModel,
                                                                     pIconItemManager,
                                                                     pNotificationManager,
                                                                     m_pTaskModule,
                                                                     m_pAboutTestModule ) );

    m_pServerConnectionSettingsModule = QSharedPointer < ServerConnectionSettingsModule > ( new ServerConnectionSettingsModule() );


    //m_pSubSubStaticAnalyzerModule = QSharedPointer < SubStaticAnalyzerModule > ( new SubStaticAnalyzerModule( pIconItemManager,
    //                                                                                                          pNotificationManager ) );
   /* m_pStaticAnalyzerModule = QSharedPointer < StaticAnalyzerModule > ( new StaticAnalyzerModule( pMenuModel,
                                                                                                  pIconItemManager,
                                                                                                  pNotificationManager ));
    */

}


void DataModule::addData( QSharedPointer < AbstractData > pData ) {


    switch ( pData.data() -> getTypeData() ) {

        case TypeData::DISCIPLINE_DATA_TYPE:
            m_pDisciplineModule.data() -> addData( pData.staticCast < DataForDisciplineModule > () );
            break;

        case TypeData::TASK_DATA_TYPE:
            m_pTaskModule.data() -> addData( pData.staticCast < DataForTaskModule> () );
            break;

        case TypeData::TEST_DATA_TYPE:
            m_pTestModule.data()->addData( pData.staticCast < DataForTestModule > ());
            break;

        case TypeData::ABOUT_TEST_TYPE:
            m_pAboutTestModule.data() -> addData( pData.staticCast < DataForAboutTestModule > () );
            break;

        case TypeData::ANALYZE_TYPE_DATA:
            m_pTestModule.data() -> getStaticAnalyzerModule().data() -> addData( pData.staticCast < DataForStaticAnalyzer >() );
            break;
    }
}


QSharedPointer < DisciplineModule > DataModule::getDisciplineModule() {

    return m_pDisciplineModule;
}


QSharedPointer < TaskModule > DataModule::getTaskModule() {

    return m_pTaskModule;
}

QSharedPointer < MenuModule > DataModule::getMenuModule() {

    return m_pMenuModule;
}


QSharedPointer < ImageModule > DataModule::getImageModule() {

    return m_pImageModule;
}


QSharedPointer < TestModule > DataModule::getTestModule() {

    return m_pTestModule;
}


QSharedPointer < AboutTestModule > DataModule::getAboutTestModule() {

    return m_pAboutTestModule;
}


QSharedPointer < DisciplineTextDescriptionModule > DataModule::getDisciplineTextDescriptionModule() {

    return m_pDisciplineTextDescriptionModule;
}


QSharedPointer < TaskTextDescriptionModule > DataModule::getTaskTextDescriptionModule() {

    return m_pTaskTextDescriptionModule;
}


QSharedPointer < ServerConnectionSettingsModule > DataModule::getServerConnectionSettingsModule() {

    return m_pServerConnectionSettingsModule;
}


QSharedPointer < AttachProjectModule > DataModule::getAttachProjectModule() {

    return m_pAttachProjectModule;
}


QSharedPointer < RunProjectModule > DataModule::getRunProjectModule() {

    return m_pRunProjectModule;
}


QSharedPointer < StaticAnalyzerModule > DataModule::getStaticAnalyzerModule() {

    return m_pTestModule.data() -> getStaticAnalyzerModule();
}


QSharedPointer < SubStaticAnalyzerModule > DataModule::getSubStaticAnalyzerModule() {

    return m_pTestModule.data() -> getStaticAnalyzerModule().data() -> getSubStaticAnalyzerModule();
}

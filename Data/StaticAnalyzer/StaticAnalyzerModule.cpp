#include "StaticAnalyzerModule.h"

#include <Model/BaseModel/DataItemModel/StandartItemBaseModel/DataItemModelForStandartItemBaseModel.h>
#include <Enum/Model/MenuModel/TypeMenu.h>
#include <QScopedPointer>
#include <QtAlgorithms>
#include "../../Diplom/TestSystem/TestSystem/MacroDefinitions/code/Analyzer/TypeStaticAnalyzerText.h"


void StaticAnalyzerModule::addStaticAnalyzer( quint32 idHistory,
                                              quint32 idAboutHistory,
                                              QList < StaticAnalyzer > staticAnalyzerList,
                                              SingleKeyContainer < quint32,
                                                                   QString > idSourceCode ) {

    foreach( StaticAnalyzer staticAnalyzer, staticAnalyzerList ) {

        //quint32 idAboutStaticAnalyzer = staticAnalyzer.getIdAboutStaticAnalyzer();
        m_IdAboutHistoryStaticAnalyzer.addValue( idHistory,
                                                 static_cast < int > ( staticAnalyzer.getTypeStaticAnalyzer() ),
                                                 staticAnalyzer );
        //запоминаем данные об исходном коде :)
        QList < quint32 > idCodeList = idSourceCode.getKeys();

        foreach( quint32 idCode, idCodeList ) {

            QString sourceCode = idSourceCode.getValue( idCode );
            m_IdAboutHistoryIdCode.addValue( idHistory,
                                             idCode,
                                             sourceCode );
        }
    }
}


StaticAnalyzerModule::StaticAnalyzerModule( QSharedPointer < ModelByQActionItem > pMenuModel,
                                            QSharedPointer < IconItemManager > pIconItemManager ,
                                            QSharedPointer < NotificationManager > pNotificationManager ) : BaseModule( pIconItemManager,
                                                                                                                        pNotificationManager ) {
    m_pStaticAnalyzerModel = initializeNewStandartItemBaseModel( TypeModel::STATIC_ANALYZE_MODEL );

    m_pSubStaticAnalyzeModule = QSharedPointer < SubStaticAnalyzerModule > ( new SubStaticAnalyzerModule( m_pStaticAnalyzerModel,
                                                                                                          pIconItemManager,
                                                                                                          pNotificationManager ) );

    m_pMenuModel = pMenuModel;

    m_TypeStaticAnalyzerTextContainer.addValue( static_cast < int > ( TypeStaticAnalyzer::ERROR_ANALYZE ),
                                                ERROR_TYPE_ANALYZE_DESCRIPTION );
    m_TypeStaticAnalyzerTextContainer.addValue( static_cast < int > ( TypeStaticAnalyzer::STYLE_ANALYZE ),
                                                STYLE_TYPE_ANALYZE_DESCRIPTION );
    m_TypeStaticAnalyzerTextContainer.addValue( static_cast < int > ( TypeStaticAnalyzer::WARNING_ANALYZE ),
                                                WARNING_TYPE_ANALYZE_DESCRIPTION );
}


void StaticAnalyzerModule::addData( QSharedPointer < DataForStaticAnalyzer > pData ) {

    addStaticAnalyzer( pData.data() -> getIdHistory(),
                       pData.data() -> getIdAboutHistory(),
                       pData.data() -> getStaticAnalyzer(),
                       pData.data() -> getIdCodeContainer() );
}


QSharedPointer < TreeStandartItemBaseModel > StaticAnalyzerModule::getStaticAnalyzerModel() {

    return m_pStaticAnalyzerModel;
}


void StaticAnalyzerModule::setCurrentAboutHistory( quint32 idHistory ) {

    ///ИСПРАВИТЬ ЭТО БЕЗОБРАЗИЕ!!!!!!
   // m_pStaticAnalyzerModel.data() -> clearItemsInModel();

    //получаем исходные коды
    SingleKeyContainer < quint32,
                         QString > idCodeContainer( m_IdAboutHistoryIdCode.getValueByFirstKey( idHistory ) );
    m_pSubStaticAnalyzeModule.data() -> setIdCode( idCodeContainer );
    QList < quint32 > typeStaticAnalyzerList = m_IdAboutHistoryStaticAnalyzer.getKey2List( idHistory );
    //получаем ТИПЫ ошибок.
    foreach( quint32 typeStaticAnalyzer, typeStaticAnalyzerList ) {

        QString text = m_TypeStaticAnalyzerTextContainer.getValue( typeStaticAnalyzer );
        QSharedPointer < DataItemModelForStandartItemBaseModel > pData = initializeNewDataForStandartItemBaseModel( typeStaticAnalyzer,
                                                                                                                    text );
        addNewItem( m_pStaticAnalyzerModel,
                    pData,
                    m_pMenuModel.data() -> getModelItemDescriptor( TypeMenu::ANALYZE_MENU_ITEM ) );
        /*
        m_pNotificationManager.data() -> addNotification( NotificationType::ITEM_IS_NEW,
                                                          m_pDisciplineModel.data() -> getModelItemDescriptor( idDiscipline) );
                                                          */
        QList < StaticAnalyzer > staticAnalyzerList = m_IdAboutHistoryStaticAnalyzer.getContainerValue( idHistory,
                                                                                                        static_cast < quint32 > ( typeStaticAnalyzer ) );
        QSharedPointer < ModelItemDescriptor > pParentModelItemDescriptor = m_pStaticAnalyzerModel.data() ->
                                                                            getModelItemDescriptor( static_cast < int > ( typeStaticAnalyzer ) );
        QPersistentModelIndex parent = m_pStaticAnalyzerModel.data() -> getModelIndexById( typeStaticAnalyzer );
        foreach( StaticAnalyzer staticAnalyzer, staticAnalyzerList ) {

            //добавляем файлы к типу ошибки

            m_pSubStaticAnalyzeModule.data() -> addSubStaticAnalyzeInModel( staticAnalyzer,
                                                                            pParentModelItemDescriptor,
                                                                            parent );
        }

    }
}


QSharedPointer < SubStaticAnalyzerModule > StaticAnalyzerModule::getSubStaticAnalyzerModule() {

    return m_pSubStaticAnalyzeModule;
}

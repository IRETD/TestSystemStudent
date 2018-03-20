#include "SubStaticAnalyzerModule.h"


QString SubStaticAnalyzerModule::prepareCode( QString sourceCode,
                                              QString comment,
                                              quint32 line ) {

    quint32 index = 0;
    quint32 count = 0;
    for ( int i = 0; i < sourceCode.size(); i++ ) {

        if ( sourceCode[ i ] == '\n' ||
             sourceCode[ i ] == '\r\n' ) {

            count++;
        }

        if ( count == ( line - 1 ) ) {
            index = i;
            break;
        }
    }

    sourceCode.insert( index, "//" + comment );

    return sourceCode;
}

SubStaticAnalyzerModule::SubStaticAnalyzerModule(QSharedPointer < TreeStandartItemBaseModel > pStaticAnalyzerModel,
                                                  QSharedPointer < IconItemManager > pIconItemManager,
                                                  QSharedPointer < NotificationManager > pNotificationManager) : BaseModule( pIconItemManager,
                                                                                                                             pNotificationManager ) {

    m_pSubStaticAnalyzerModel = initializeNewStandartItemBaseModel( pStaticAnalyzerModel.data() -> getMyStandardItemModel(),
                                                                    TypeModel::ABOUT_STATIC_ANALYZE_MODEL );

    connect( m_pSubStaticAnalyzerModel.data(),
             &TreeStandartItemBaseModel::sendIdItemSelected,
             this,
             &SubStaticAnalyzerModule::itemSubStaticAnalyzerSelected );
}


void SubStaticAnalyzerModule::addIdStaticAnalyzer( quint32 idAboutStaticAnalyzer,
                                                   StaticAnalyzer &staticAnalyzer ) {

    m_IdStaticAnalyzer.addValue( idAboutStaticAnalyzer,
                                 staticAnalyzer );
}


void SubStaticAnalyzerModule::setIdCode( SingleKeyContainer < quint32,
                                                             QString > idCode ) {

    m_IdCode = idCode;
}


void SubStaticAnalyzerModule::addSubStaticAnalyzeInModel( StaticAnalyzer &staticAnalyzer,
                                                          QSharedPointer < ModelItemDescriptor > pParentModelItemDescriptor,
                                                          QPersistentModelIndex &pParent ) {

    m_IdStaticAnalyzer.addValue( staticAnalyzer.getIdAboutStaticAnalyzer(),
                                 staticAnalyzer );
    QString fileLocation = staticAnalyzer.getLocationFile();

    quint32 idAboutStaticAnalyzer = staticAnalyzer.getIdAboutStaticAnalyzer();
    QSharedPointer < DataItemModelForStandartItemBaseModel > pNewData = initializeNewDataForStandartItemBaseModel( idAboutStaticAnalyzer,
                                                                                                                   fileLocation,
                                                                                                                   pParent );
    addNewItem( m_pSubStaticAnalyzerModel,
                pNewData,
                pParentModelItemDescriptor
               );
}


QSharedPointer < TreeStandartItemBaseModel > SubStaticAnalyzerModule::getSubStaticAnalyzerModel() {

    return m_pSubStaticAnalyzerModel;
}


void SubStaticAnalyzerModule::itemSubStaticAnalyzerSelected( int idItem ) {

    quint32 idCode = m_IdStaticAnalyzer.getValue( idItem ).getIdLocationFile();
    quint32 line = m_IdStaticAnalyzer.getValue( idItem ).getLine();
    QString comment = m_IdStaticAnalyzer.getValue( idItem ).getDescription();
    QString code = prepareCode( m_IdCode.getValue( idCode ),
                                comment,
                                line );
    emit sendCodeText( code );
    emit showViewContext( ViewContextType::ANALYZE_DESSCRIPTION_VIEW_CONTEXT );
}

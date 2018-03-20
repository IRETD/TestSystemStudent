#include "RequestHandler.h"
#include <Request/ReqAuth.h>
#include <Request/ReqDisciplineTask.h>
#include <Data/ServerConnectionSettings/ServerConnectionSettings.h>
#include <MacroDefinitons/MyMacroDefinitions.h>
#include <Request/ReqCode.h>
#include <Request/ReqHistory.h>
#include <Request/ReqAnalyzer.h>


RequestHandler::RequestHandler(QSharedPointer < Client > pClient ) {

    m_pClient = pClient;
}


void RequestHandler::doAuth() {

    ServerConnectionSettings connectionSettings = getServerConnectionSettings;
    QString login = connectionSettings.getLogin();
    QString password = connectionSettings.getPassword();

    ReqAuth reqAuth;
    reqAuth.setLogin( login );
    reqAuth.setPassword( password );
    reqAuth.writeInStream();

    m_pClient.data() -> sendToServer( reqAuth.getBuffer() );
}


void RequestHandler::doConnectionToServer() {

    ServerConnectionSettings connectionSettings = getServerConnectionSettings;
    QString hostAddress = connectionSettings.getHostAddress();
    quint32 hostPort = connectionSettings.getHostPort();

    m_pClient.data() -> connectToServer( hostAddress,
                                         hostPort );
}


void RequestHandler::doDisciplineTaskList() {

    ReqDisciplineTask reqDisciplineTask;
    reqDisciplineTask.writeInStream();

    m_pClient.data() -> sendToServer( reqDisciplineTask.getBuffer() );
}


void RequestHandler::doDisciplineList() {

}


void RequestHandler::doHistoryList() {

    ReqHistory reqHistory;
    reqHistory.writeInStream();
    m_pClient.data() -> sendToServer( reqHistory.getBuffer() );
}


void RequestHandler::doConnectionToServerAndDoAuth() {

    doConnectionToServer();
    doAuth();
}


void RequestHandler::doPersonalInitialData() {

    //Из data module в дальнейшем сможем корректировать - что -запрашивать,  а что нет :)
    //пока что просим только все лабы и дисциплины
    doDisciplineTaskList();
    doHistoryList();
}


void RequestHandler::doRunModule( int idUserLab,
                                  QString path ) {

    ReqCode reqCode;
    reqCode.setFilePath( path );
    reqCode.setIdUserLab( idUserLab );

    //все успешно упаковалось
    if ( reqCode.prepareFileProject() ) {

        reqCode.writeInStream();
        m_pClient.data() -> sendToServer( reqCode.getBuffer() );
    }
}


void RequestHandler::doAnalyzeData( quint32 idHistory,
                                    quint32 idAboutHistory ) {

    ReqAnalyzer reqAnalyzer;
    reqAnalyzer.setIdHistory( idHistory );
    reqAnalyzer.setIdAboutHistory( idAboutHistory );
    reqAnalyzer.writeInStream();
    m_pClient.data() -> sendToServer( reqAnalyzer.getBuffer() );

}


void RequestHandler::setDataModule( QSharedPointer < DataModule > pDataModule ) {

    m_pDataModule = pDataModule;
}

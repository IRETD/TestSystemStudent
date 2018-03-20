#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H


#include <Client/Client.h>

#include <QObject>

class DataModule;
class Client;

class RequestHandler : public QObject {

    Q_OBJECT
    //храним источник всех данных
    QSharedPointer < DataModule > m_pDataModule;

    //Храним Хэндл на подключение к серверу
    QSharedPointer < Client > m_pClient;

    void doAuth();
    void doConnectionToServer();
    void doDisciplineTaskList();
    void doDisciplineList();
    void doHistoryList();
    void doTaskList();

public:
    RequestHandler( QSharedPointer < Client > pClient );


    void doConnectionToServerAndDoAuth();

    //запрос на свои первоначальные данные
    void doPersonalInitialData();

    //запрос на отправку кода
    void doRunModule( int idUserLab,
                      QString path );
    void doAnalyzeData( quint32 idHistory,
                        quint32 idAboutHistory );
    void setDataModule( QSharedPointer < DataModule > pDataModule );
};

#endif // REQUESTHANDLER_H

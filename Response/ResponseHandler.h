#ifndef RESPONSEHANDLER_H
#define RESPONSEHANDLER_H

#include <Response/Response.h>
#include <QObject>
#include <QSharedPointer>
#include <Data/DataModule.h>
#include <Data/DataSource/DataSource.h>
#include <Request/RequestHandler.h>

// Задача:
// Перенаправить Response в нужный модуль на его дальнейшую обработку

class ResponseHandler : public QObject  {

    Q_OBJECT

    QSharedPointer < DataModule > m_pDataModule;
    QSharedPointer < DataSource > m_pDataSource;
    QSharedPointer < RequestHandler > m_pRequestHandler;

public:
    ResponseHandler( QSharedPointer < DataModule > pDataModule,
                     QSharedPointer < RequestHandler > pRequestHandler );

public slots:
    void getResponse( QSharedPointer < Response > pResponse );
};

#endif // RESPONSEHANDLER_H

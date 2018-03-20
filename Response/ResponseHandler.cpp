#include "ResponseHandler.h"

ResponseHandler::ResponseHandler( QSharedPointer < DataModule > pDataModule,
                                  QSharedPointer < RequestHandler > pRequestHandler ) {

    m_pDataModule = pDataModule;
    m_pRequestHandler = pRequestHandler;
    m_pDataSource = QSharedPointer < DataSource >( new DataSource( m_pDataModule ) );
}


void ResponseHandler::getResponse( QSharedPointer < Response > pResponse ) {


    pResponse.data() -> setDataSource( m_pDataSource );
    pResponse.data()-> setRequestHandler( m_pRequestHandler );
    pResponse.data() -> doResponse();
    /*
    if ( pResponse.data() -> getType() == ResponseType::DISCIPLINE ) {

        m_pDataSource.data() -> prepareDisciplineDataFromResponse( pResponse );
    }

    if ( pReponse.data() -> getType() == ResponseType::AUTHORIZATION ) {


    }
    */
}

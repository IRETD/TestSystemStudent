#include "ReqCode.h"
#include <Zip/ZipArchiver.h>
#include <MacroDefinitons/Request/RequestSenderInitialization.h>

ReqCode::ReqCode() : REQUEST_SENDER_INITIALIZATION {

    m_FilePath.clear();
}


void ReqCode::setIdUserLab(const int &idUserLab) {

    m_IdUserLab = idUserLab;
}


void ReqCode::setFilePath( QString path ) {

    m_FilePath = path;
}


bool ReqCode::prepareFileProject() {

    bool result = false;
    //если путь к проекту указан
    if ( !m_FilePath.isEmpty() ) {

        ZipArchiver zip;
        result = zip.packDirectory( m_FilePath,
                                    m_FileZipBuffer );
    }

    return result;
}


/*
void ReqCode::setFileZipBuffer( const QByteArray &byteArray ) {

    m_FileZipBuffer = byteArray;
}
*/

void ReqCode::writeInStream() {

    clearStream();
    m_Stream << static_cast < int > ( RequestType::CODE ) <<
                m_IdUserLab <<
                m_FileZipBuffer;
    prepareStream();
}

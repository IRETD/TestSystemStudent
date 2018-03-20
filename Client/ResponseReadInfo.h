#ifndef RESPONSEREADINFO_H
#define RESPONSEREADINFO_H

enum class ReadStatus {

    INPUT_DATA_ARE_COMPLETE = 0,
    INPUT_DATA_ARE_INCOMPLETE = -1,
    INPUT_DATA_ARE_UNEXPECTED = -2
};


class ResponseReadInfo {

    ReadStatus m_ReadStatus;
public:
    ResponseReadInfo();

    ReadStatus getReadStatus();
    void setReadStatus( const ReadStatus &readStatus );
};


#endif // RESPONSEREADINFO_H

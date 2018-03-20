#ifndef MYMACRODEFINITIONS_H
#define MYMACRODEFINITIONS_H

#define READ_POINTER *


#define getServerConnectionSettingsModule m_pDataModule.data() ->\
                                          getServerConnectionSettingsModule().data()

#define getServerConnectionSettings getServerConnectionSettingsModule -> \
                                    getServerConnectionSetting()

#endif // MYMACRODEFINITIONS_H

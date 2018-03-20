#ifndef DATAMODULE_H
#define DATAMODULE_H

#include <Data/AbstractData.h>
#include <Data/Discipline/DisciplineModule.h>
#include <Data/Task/TaskModule.h>
#include <Data/Menu/MenuModule.h>
#include <Data/Icon/ImageModule.h>
#include <Data/Notification/NotificationModule.h>
#include <Data/Test/TestModule.h>
#include <Data/AttachProjectModule/AttachProjectModule.h>
#include <Data/ServerConnectionSettings/ServerConnectionSettingsModule.h>
#include <Data/RunProject/RunProjectModule.h>
#include <Data/AboutTest/AboutTestModule.h>
#include <Data/StaticAnalyzer/StaticAnalyzerModule.h>
#include <Data/StaticAnalyzer/SubStaticAnalyzerModule.h>

class AttachProjectModule;
class RunProjectModule;
class RequestHandler;
class TestModule;
class AboutTestModule;

class DataModule {

    QSharedPointer < AttachProjectModule > m_pAttachProjectModule;
    QSharedPointer < DisciplineModule > m_pDisciplineModule;
    QSharedPointer < TaskModule > m_pTaskModule;
    QSharedPointer < MenuModule > m_pMenuModule;
    QSharedPointer < ImageModule > m_pImageModule;
    QSharedPointer < NotificationModule > m_pNotificationModule;

    QSharedPointer < TestModule > m_pTestModule;
    QSharedPointer < AboutTestModule > m_pAboutTestModule;

    QSharedPointer < DisciplineTextDescriptionModule > m_pDisciplineTextDescriptionModule;
    QSharedPointer < TaskTextDescriptionModule > m_pTaskTextDescriptionModule;
    QSharedPointer < ServerConnectionSettingsModule > m_pServerConnectionSettingsModule;
    QSharedPointer < RunProjectModule > m_pRunProjectModule;

    //QSharedPointer < StaticAnalyzerModule > m_pStaticAnalyzerModule;
    //QSharedPointer < SubStaticAnalyzerModule > m_pSubSubStaticAnalyzerModule;

    QSharedPointer < RequestHandler > m_pRequestHandler;

public:
    DataModule( QSharedPointer < RequestHandler > pRequestHandler );

    void addData( QSharedPointer < AbstractData > pData );

    QSharedPointer < DisciplineModule > getDisciplineModule();
    QSharedPointer < TaskModule > getTaskModule();
    QSharedPointer < MenuModule > getMenuModule();
    QSharedPointer < ImageModule > getImageModule();
    QSharedPointer < TestModule > getTestModule();
    QSharedPointer < AboutTestModule > getAboutTestModule();
    QSharedPointer < DisciplineTextDescriptionModule > getDisciplineTextDescriptionModule();
    QSharedPointer < TaskTextDescriptionModule > getTaskTextDescriptionModule();
    QSharedPointer < ServerConnectionSettingsModule > getServerConnectionSettingsModule();
    QSharedPointer < AttachProjectModule > getAttachProjectModule();
    QSharedPointer < RunProjectModule > getRunProjectModule();
    QSharedPointer < StaticAnalyzerModule > getStaticAnalyzerModule();
    QSharedPointer < SubStaticAnalyzerModule > getSubStaticAnalyzerModule();
};

#endif

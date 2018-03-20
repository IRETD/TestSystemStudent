#-------------------------------------------------
#
# Project created by QtCreator 2015-09-10T22:44:02
#
#-------------------------------------------------

QT       += core gui widgets network gui-private

LIBS += -lqscintilla2

DEFINES += IT_IS_STUDENT_CLIENT

QMAKE_CXXFLAGS += -std=gnu++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestStudent
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Model/Model.cpp \
    Client/Client.cpp \
    Client/ResponseFactory.cpp \
    Client/ResponseReadInfo.cpp \
    Client/StreamReader.cpp \
    View/MainWindowView.cpp \
    View/ToolBarView.cpp \
    View/MenuView.cpp \
    View/Initializer.cpp \
    Request/ReqAuth.cpp \
    Request/ReqCode.cpp \
    Request/ReqHistory.cpp \
    Request/Request.cpp \
    Response/RespAuth.cpp \
    Response/RespHistory.cpp \
    Response/Response.cpp \
    Update/UpdateDisciplineDescription.cpp \
    Update/Update.cpp \
    View/MenuItem/DisciplineMenuItem.cpp \
    View/MenuItem/MenuItemContainer.cpp \
    View/MenuItem/MenuItem.cpp \
    View/MenuItem/MenuItemFactory.cpp \
    View/ViewContext/DisciplineDescriptionView.cpp \
    View/ViewContext/DynamicSwitchViewContext.cpp \
    View/ViewContext/ViewContextFactory.cpp \
    View/ViewContext/ViewContextContainer.cpp \
    View/WidgetSupport/ScrollBarStatus.cpp \
    View/ViewContext/TaskDescriptionView.cpp \
    View/ViewContext/SideMenuView.cpp \
    View/ViewContext/ViewContext.cpp \
    Data/DisciplineDescriptionData.cpp \
    Model/Notification/NotificationTimer.cpp \
    Model/Notification/NotificationManager.cpp \
    Model/Notification/NotificationTypeQueue.cpp \
    MyStorageType/TripleKeyContainer.cpp \
    MyStorageType/SingleKeyContainer.cpp \
    Model/BaseModel/DataItemModel/AbstractDataItemModel.cpp \
    Model/BaseModel/DataItemModel/StandartItemBaseModel/DataItemModelForStandartItemBaseModel.cpp \
    Model/BaseModel/DataItemModel/PureBaseModel/DataItemModelForModelByQActionItem.cpp \
    Model/Notification/NotificationAlgorithm/NotificationAlgorithm.cpp \
    Model/Notification/NotificationAlgorithm/NotificationStepByStep.cpp \
    MyStorageType/DoubleKeyContainer.cpp \
    Data/Icon/IconItemManager.cpp \
    Data/Icon/IconBuffer.cpp \
    Data/Icon/IconInfo.cpp \
    Data/DataModule.cpp \
    Data/AbstractData.cpp \
    Data/Discipline/DataForDisciplineModule.cpp \
    Data/Discipline/DisciplineModule.cpp \
    Data/ObservableModule.cpp \
    MyStorageType/SingleKeyWithContainerValueContainer.cpp \
    Data/Task/TaskModule.cpp \
    Model/ModelItemStorage.cpp \
    Data/Task/DataForTaskModule.cpp \
    Data/Menu/MenuModule.cpp \
    Data/Menu/DataForMenuModule.cpp \
    Data/Menu/Menu.cpp \
    Data/BaseModule.cpp \
    Data/Icon/DataForImageModule.cpp \
    Data/Icon/ImageModule.cpp \
    Data/SubBaseModuleForStandartItemBaseModel.cpp \
    Data/DataSource/DataSource.cpp \
    Data/DataSource/TestDataSource.cpp \
    Data/Notification/NotificationModule.cpp \
    Model/BaseModel/StandardItemBaseModel/MyStandartItemModel.cpp \
    Model/BaseModel/StandardItemBaseModel/StandartItemBaseModel.cpp \
    Model/ModelItemDescriptor/ModelItemDescriptor.cpp \
    Model/ModelItemDescriptor/ModelItemDescriptorContainer.cpp \
    Model/BaseModel/StandardItemBaseModel/SubClasses/TreeStandartItemBaseModel.cpp \
    Model/BaseModel/BaseModel.cpp \
    Data/SubBaseModuleForTreeStandartItemBaseModel.cpp \
    Model/ModelItemDescriptor/PureBaseModel/ModelByQActionItemDescriptor.cpp \
    Model/BaseModel/PureBaseModel/ModelByQActionItem.cpp \
    Model/ModelItemDescriptor/StandartItemBaseModel/TreeModelItemDescriptor.cpp \
    View/ViewContext/TreeView.cpp \
    View/ViewContext/DisciplineView/DisciplineView.cpp \
    View/ViewContext/TestView/TestView.cpp \
    Data/Test/TestModule.cpp \
    Data/Test/DataForTestModule.cpp \
    Data/Test/Test.cpp \
    View/DockWidget.cpp \
    Model/BaseModel/DataItemModel/PureBaseModel/DataItemForModelTextDescription.cpp \
    Data/Discipline/DescriptionDiscipline/DisciplineTextDescriptionModule.cpp \
    Data/Discipline/DescriptionDiscipline/DisciplineDescriptionHTMLEditor.cpp \
    Model/BaseModel/PureBaseModel/ModelTextDescription/ModelTextDisciplineDescription.cpp \
    Response/ResponseHandler.cpp \
    Response/RespDiscipline.cpp \
    Request/RequestHandler.cpp \
    Data/ServerConnectionSettings/ServerConnectionSettingsModule.cpp \
    Data/ServerConnectionSettings/ServerConnectionSettings.cpp \
    Response/RespServerConnectionStatus.cpp \
    Response/RespDisciplineTask.cpp \
    Request/ReqDisciplineTask.cpp \
    Data/Task/DescriptionTask/TaskTextDescriptionModule.cpp \
    Model/BaseModel/PureBaseModel/ModelTextDescription/ModelTextTaskDescription.cpp \
    Data/Task/DescriptionTask/TaskDescriptionHTMLEditor.cpp \
    View/ViewContext/AttachProjectView/AttachProjectView.cpp \
    Data/AttachProjectModule/AttachProjectModule.cpp \
    View/ViewContext/RunProjectView/RunProjectView.cpp \
    Data/RunProject/RunProjectModule.cpp \
    Zip/ZipArchiver.cpp \
    Data/Test/AboutHistory.cpp \
    Data/Test/History.cpp \
    View/ViewContext/TestView/AboutTestView.cpp \
    Data/AboutTest/AboutTestModule.cpp \
    Data/AboutTest/DataForAboutTestModule.cpp \
    Data/StaticAnalyzer/StaticAnalyzerModule.cpp \
    Data/StaticAnalyzer/StaticAnalyzer.cpp \
    Data/StaticAnalyzer/DataForStaticAnalyzer.cpp \
    MyStorageType/DoubleKeyWithContainerValueContainer.cpp \
    Response/RespAnalyzer.cpp \
    View/ViewContext/AnalyzeView/AnalyzeView.cpp \
    Data/StaticAnalyzer/SubStaticAnalyzerModule.cpp \
    Request/ReqAnalyzer.cpp \
    View/ViewContext/AnalyzeDescriptionView.cpp \
    Data/Group/GroupModule.cpp \
    Data/Group/Group.cpp \
    Data/Group/Student/Student.cpp \
    Data/Group/DataForGroupModule.cpp \
    ../SharedModules/Discipline.cpp \
    ../SharedModules/Task.cpp

HEADERS  += mainwindow.h \
    Model/Model.h \
    Client/Client.h \
    Client/ResponseFactory.h \
    Client/ResponseReadInfo.h \
    Client/StreamReader.h \
    View/MainWindowView.h \
    View/ToolBarView.h \
    View/MenuView.h \
    View/Initializer.h \
    Request/ReqAuth.h \
    Request/ReqCode.h \
    Request/ReqHistory.h \
    Request/Request.h \
    Response/RespAuth.h \
    Response/RespHistory.h \
    Response/Response.h \
    MacroDefinitons/MyMacroDefinitions.h \
    MacroDefinitons/MacroModelName.h \
    MacroDefinitons/DestroyPointerMacro.h \
    MacroDefinitons/WidgetHeaderMacro.h \
    Enum/TitleTreeWidget.h \
    Enum/TypeModel.h \
    Enum/TypeUpdateModel.h \
    Update.h \
    Update/UpdateDisciplineDescription.h \
    Update/Update.h \
    Enum/TypeDataModel.h \
    View/MenuItem/DisciplineMenuItem.h \
    View/MenuItem/MenuItemContainer.h \
    Enum/ViewContextType.h \
    Enum/ViewType.h \
    View/MenuItem/MenuItem.h \
    View/MenuItem/MenuItemFactory.h \
    Enum/MenuItemName.h \
    View/ViewContext/DisciplineDescriptionView.h \
    View/ViewContext/DynamicSwitchViewContext.h \
    View/ViewContext/ViewContextFactory.h \
    View/ViewContext/ViewContextContainer.h \
    Enum/MenuItemIconParameters.h \
    Enum/View/MenuItem/MenuItemIconParameters.h \
    Enum/View/MenuItem/MenuItemName.h \
    Enum/View/ViewContext/ViewContextType.h \
    Enum/View/ViewType.h \
    View/WidgetSupport/ScrollBarStatus.h \
    View/ViewContext/TaskDescriptionView.h \
    MacroDefinitons/Model/Data/DisciplieDescriptionText.h \
    Enum/Model/TypeDataModel.h \
    Enum/Model/TypeModel.h \
    Enum/Model/TypeUpdateModel.h \
    Enum/View/TitleTreeWidget.h \
    Enum/Model/MenuModel/TypeMenu.h \
    Enum/Model/BaseModel/BaseModelConstants.h \
    Enum/Model/TypeModelItem.h \
    View/ViewContext/SideMenuView.h \
    View/ViewContext/ViewContext.h \
    Data/DisciplineDescriptionData.h \
    Enum/View/ViewContext/DisciplineView/DisciplineViewIconSize.h \
    Enum/View/WidgetSupport/ScrollBarStatusConstants.h \
    View/WidgetSupport/ScrollBarStatusConstants.h \
    Enum/View/ViewContext/SideMenuView/SideMenuIconParameters.h \
    Enum/Data/IconBuffer/IconStatus.h \
    Enum/Data/IconBuffer/IconName.h \
    Model/Notification/NotificationTimer.h \
    Enum/Model/DisciplineModel/TypeDisciplineModel.h \
    Enum/Model/Notification/NotificationType.h \
    Enum/Model/Notification/MarkType.h \
    Model/Notification/NotificationManager.h \
    Model/Notification/NotificationTypeQueue.h \
    MyStorageType/TripleKeyContainer.h \
    MyStorageType/SingleKeyContainer.h \
    Model/BaseModel/BaseModel.h \
    Model/BaseModel/DataItemModel/AbstractDataItemModel.h \
    Model/BaseModel/DataItemModel/StandartItemBaseModel/DataItemModelForStandartItemBaseModel.h \
    Model/BaseModel/DataItemModel/PureBaseModel/DataItemModelForModelByQActionItem.h \
    Model/Notification/NotificationAlgorithm/NotificationAlgorithm.h \
    Model/Notification/NotificationAlgorithm/NotificationStepByStep.h \
    MyStorageType/DoubleKeyContainer.h \
    Data/Icon/IconItemManager.h \
    Data/Icon/IconBuffer.h \
    Enum/Data/IconBuffer/IconType.h \
    Data/Icon/IconInfo.h \
    Enum/Data/Icon/IconSetReason.h \
    Data/DataModule.h \
    Data/AbstractData.h \
    Enum/Data/TypeData.h \
    Data/Discipline/DataForDisciplineModule.h \
    Data/Discipline/DisciplineModule.h \
    Data/ObservableModule.h \
    MyStorageType/SingleKeyWithContainerValueContainer.h \
    Data/Task/TaskModule.h \
    Model/ModelItemStorage.h \
    Data/Task/DataForTaskModule.h \
    Enum/Data/Discipline/DisciplineFieldName.h \
    Enum/Data/Task/TaskFieldName.h \
    Enum/Data/DataInfo.h \
    Data/Menu/MenuModule.h \
    Data/Menu/DataForMenuModule.h \
    Data/Menu/Menu.h \
    Enum/Data/Menu/MenuFieldName.h \
    Data/BaseModule.h \
    Data/Icon/ImageModule.h \
    Data/Icon/DataForImageModule.h \
    Data/SubBaseModuleForStandartItemBaseModel.h \
    Data/DataSource/DataSource.h \
    Data/DataSource/TestDataSource.h \
    Data/Notification/NotificationModule.h \
    Model/BaseModel/StandardItemBaseModel/MyStandartItemModel.h \
    Model/BaseModel/StandardItemBaseModel/StandartItemBaseModell.h \
    Model/ModelItemDescriptor/ModelItemDescriptor.h \
    Model/ModelItemDescriptor/ModelItemDescriptorContainer.h \
    Model/BaseModel/StandardItemBaseModel/SubClasses/TreeStandartItemBaseModel.h \
    Enum/Model/ModelItemDescriptor/ModelItemDescriptorType.h \
    Enum/Model/BaseModel/StandartItemBaseModel/SubClasses/TreeStandartItemModelConstants.h \
    Data/SubBaseModuleForTreeStandartItemBaseModel.h \
    Model/ModelItemDescriptor/PureBaseModel/ModelByQActionItemDescriptor.h \
    Enum/Model/MenuModel/MenuModelConstants.h \
    Model/BaseModel/PureBaseModel/ModelByQActionItem.h \
    Model/ModelItemDescriptor/StandartItemBaseModel/TreeModelItemDescriptor.h \
    Enum/Model/ModelItemDescriptor/ModelItemDescriptorConstants.h \
    Enum/Model/ModelItemDescriptor/ModelItemDescriptorEvent.h \
    View/ViewContext/TreeView.h \
    View/ViewContext/DisciplineView/DisciplineView.h \
    View/ViewContext/TestView/TestView.h \
    Data/Test/TestModule.h \
    Data/Test/DataForTestModule.h \
    Data/Test/Test.h \
    View/DockWidget.h \
    Enum/Model/ModelItemDescriptor/ModelItemDescriptorNotification.h \
    Model/BaseModel/DataItemModel/PureBaseModel/DataItemForModelTextDescription.h \
    Data/Discipline/DescriptionDiscipline/DisciplineTextDescriptionModule.h \
    Data/Discipline/DescriptionDiscipline/DisciplineDescriptionHTMLEditor.h \
    Model/BaseModel/PureBaseModel/ModelTextDescription/ModelTextDisciplineDescription.h \
    Response/ResponseHandler.h \
    Response/RespDiscipline.h \
    Request/RequestHandler.h \
    Data/ServerConnectionSettings/ServerConnectionSettingsModule.h \
    Data/ServerConnectionSettings/ServerConnectionSettings.h \
    Response/RespServerConnectionStatus.h \
    Response/RespDisciplineTask.h \
    Request/ReqDisciplineTask.h \
    Data/Task/DescriptionTask/TaskTextDescriptionModule.h \
    Model/BaseModel/PureBaseModel/ModelTextDescription/ModelTextTaskDescription.h \
    Data/Task/DescriptionTask/TaskDescriptionHTMLEditor.h \
    View/ViewContext/AttachProjectView/AttachProjectView.h \
    Data/AttachProjectModule/AttachProjectModule.h \
    View/ViewContext/RunProjectView/RunProjectView.h \
    Data/RunProject/RunProjectModule.h \
    Zip/ZipArchiver.h \
    Data/Test/AboutHistory.h \
    Data/Test/History.h \
    View/ViewContext/TestView/AboutTestView.h \
    Data/AboutTest/AboutTestModule.h \
    Data/AboutTest/DataForAboutTestModule.h \
    MacroDefinitons/Model/BaseModel/StandartItemBaseModel/TypeStandartItemModel.h \
    Data/StaticAnalyzer/StaticAnalyzerModule.h \
    Data/StaticAnalyzer/StaticAnalyzer.h \
    Data/StaticAnalyzer/DataForStaticAnalyzer.h \
    MyStorageType/DoubleKeyWithContainerValueContainer.h \
    Response/RespAnalyzer.h \
    View/ViewContext/AnalyzeView/AnalyzeView.h \
    Data/StaticAnalyzer/SubStaticAnalyzerModule.h \
    Request/ReqAnalyzer.h \
    View/ViewContext/AnalyzeDescriptionView.h \
    Data/Group/GroupModule.h \
    Data/Group/Group.h \
    Data/Group/Student/Student.h \
    Data/Group/DataForGroupModule.h \
    MacroDefinitons/Request/RequestSenderInitialization.h \
    ../SharedModules/Discipline.h \
    ../SharedModules/Task.h

RESOURCES += \
    images.qrc

FORMS +=
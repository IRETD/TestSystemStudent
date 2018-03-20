#include "AttachProjectView.h"
#include <QFileDialog>


AttachProjectView::AttachProjectView( Model *pModel ) {

    connect( pModel -> getAttachProjectModule().data(),
             &AttachProjectModule::attachProjectSelectedSignal,
             this,
             &AttachProjectView::attachProjectItemSelected );
    connect( this,
             &AttachProjectView::sendAttachProjectPath,
             pModel->getAttachProjectModule().data(),
             &AttachProjectModule::attachProjectPathSlot );
}


void AttachProjectView::attachProjectItemSelected() {

    QString attachProjectPath = QFileDialog::getExistingDirectory();
    if ( !attachProjectPath.isEmpty() ) {
        //отправляем модулю attachProject выбранный путь к проекту
        sendAttachProjectPath( attachProjectPath );
    }
}

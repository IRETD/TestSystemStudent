#include "RunProjectView.h"

RunProjectView::RunProjectView( Model *pModel ) {

    connect( pModel -> getRunProjectModule().data(),
             &RunProjectModule::runProjectItemSelected,
             this,
             &RunProjectView::runProjectModuleSlot );
    connect( this,
             &RunProjectView::runProjectItemSelected,
             pModel -> getRunProjectModule().data(),
             &RunProjectModule::runProjectViewSlot );
}


void RunProjectView::runProjectModuleSlot() {

    //пока что просто отправялем ответный сигнал
    //В дальнейнешем, я думаю, здесь потребуется вывод доп. окон :)
    emit runProjectItemSelected();
}

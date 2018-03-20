#include "ViewContextFactory.h"
#include <View/ViewContext/DisciplineDescriptionView.h>
#include <View/ViewContext/TreeView.h>
#include <View/ViewContext/TaskDescriptionView.h>
#include <View/ViewContext/DisciplineView/DisciplineView.h>
#include <View/ViewContext/TestView/TestView.h>

ViewContextFactory::ViewContextFactory() {
}

ViewContext *ViewContextFactory::createViewContext( const ViewContextType &viewContextType ) {

    ViewContext *pView = nullptr;
    /*if ( viewContextType == ViewContextType::DISCIPLINE_DESCRIPTION_VIEW_CONTEXT ) {

        pView = new DisciplineDescriptionView( ViewContextType::DISCIPLINE_DESCRIPTION_VIEW_CONTEXT );
    }*/
/*
    if ( viewContextType == ViewContextType::TASK_DESCRIPTION_VIEW_CONTEXT ) {

        pView = new TaskDescriptionView( ViewContextType::TASK_DESCRIPTION_VIEW_CONTEXT );
    }
    */

    if ( viewContextType == ViewContextType::DISCIPLINE_VIEW_CONTEXT ) {

        pView = new DisciplineView;
    }

    if ( viewContextType == ViewContextType::TEST_VIEW_CONTEXT ) {

        pView = new TestView;
    }

    return pView;
}

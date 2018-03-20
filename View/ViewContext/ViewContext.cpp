#include <View/ViewContext/ViewContext.h>
/*
void View::getDisciplineText( const QString &text ) {

    m_pMainWindow -> updateEditor( text );
}


void View::getLabText( const QString &text ) {

     m_pMainWindow -> updateEditor( text );
}


void View::authorization( const QString &login, const QString &password ) {

    if ( m_pController -> connectToServer() ) {
        m_pController -> authorization( login, password );
    }
}


//void View::projectItemSeleted( const QModelIndex &index ) {

//    m_pController -> projectItemSelected( index );
//}


View::View( Controller *controller, Model *model ) {

    m_pController = controller;
    m_pModel = model;

    m_pAuthForm = new AuthorizationForm;
    m_pMainWindow = new MainWindow( m_pModel, m_pController );

    QObject::connect( m_pAuthForm, &AuthorizationForm::doAuthorization, this, &View::authorization );

//    QObject::connect( m_pMainWindow, &MainWindow::projectItemSelected, this, &View::projectItemSeleted );
}


void View::showAuthForm() {

    m_pAuthForm -> showForm();
}


void View::showMainWindow() {

    m_pMainWindow -> show();
}


void View::showDialogMessage( const QString &title, const QString &text ) {

    showMessageBox( title, text );
}


MainWindow *View::getMainWindow() {

    return m_pMainWindow;
}


AuthorizationForm *View::getAuthWindow() {

    return m_pAuthForm;
}
*/



ViewContext::ViewContext( ViewContextType viewContextType ) {

    m_ViewContextType = viewContextType;
    m_p_Model = nullptr;
}


void ViewContext::setModelForView( Model *pModel ) {
    //некоторые представления не нуждаются в назначении модели
}


void ViewContext::createConnections() {

}


ViewContextType ViewContext::getViewContextType() {

    return m_ViewContextType;
}

void ViewContext::connectWithViewContextContainer( ViewContextContainer *viewContextContainer ) {
//заглушка, т.к. не каждому отображению необходимо связываться с контейнером отображений
}

#include "mainwindow.h"
#include <QApplication>
#include <View/MainWindowView.h>

int main(int argc, char *argv[]) {
    //Ошибка в IconBuffer - при создании QIcon  в конструкторе
    //Model model;
    QApplication app(argc, argv);
    MainWindowView w;
    w.show();

    QFile file( ":css/style.css" );
    file.open( QFile::ReadOnly );
    QString styleCSS = QLatin1String( file.readAll() );
    app.setStyleSheet( styleCSS );

    return app.exec();
}

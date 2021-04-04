#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Connexion c ;

    bool test = c.create_connexion();

    if(test) { // if(test) = if(test == true)
            w.show();
            QMessageBox::information(nullptr,QObject::tr("database is opened "),
                                     QObject::tr("connected successfully.\n click cancel to exit"),QMessageBox::Cancel);
    }
    else {
        QMessageBox::information(nullptr,QObject::tr("database is not opened "),
                                 QObject::tr("connection failed .\n click cancel to exit"),QMessageBox::Cancel);
    }
    return a.exec();
}

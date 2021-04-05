#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QtDebug>
#include <connexion.h>




int main(int argc, char *argv[])
{




    QApplication a(argc, argv);

    connexion C;
     bool test=C.createConnection();
       MainWindow w;
     if(test)
        // qDebug() <<"connexion reussite";
         QMessageBox::information(nullptr, QObject::tr("database is open"),
                 QObject::tr("connexion succesful:\n"
    "click ok to exit"),QMessageBox::Ok);
     else
        // qDebug() <<"erreur de connexion";
         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                 QObject::tr("connexion failed:\n"
    "click exit to exit"),QMessageBox::Cancel);

     w.show();

    return a.exec();
}

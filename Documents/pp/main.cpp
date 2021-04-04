#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include<QDebug>
#include <QMessageBox>
int main(int argc, char *argv[])
{QApplication a(argc, argv);
    connexion c;
    bool test=c.createconnexion();
     MainWindow w;




     if(test) QMessageBox::information(nullptr, QObject::tr("database is open"),QObject::tr("connexion reussite\n" "click OK to exist"),
                                       QMessageBox::Ok);
         //qDebug() <<"connexion reussite";


     else
         QMessageBox::critical(nullptr, QObject::tr("database is not open"),QObject::tr("connexion failed\n" "click Cancel to exist"),
                                                QMessageBox::Cancel);
         //qDebug() <<"erreur de connexion";
     w.show();
    return a.exec();
}

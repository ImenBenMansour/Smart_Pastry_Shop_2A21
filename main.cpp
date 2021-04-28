#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>
#include<QFile>
#include<QTranslator>
#include<QInputDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    QFile styleSheetFile("C:/Users/ASUS/Desktop/solo/semestre 2/projet c++/cuisine/Adaptic.qss");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet=QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);

  QTranslator T;
  QStringList langs;
  langs << "English" << "French" <<"Arabic";
  const QString lang= QInputDialog::getItem(NULL,"Language","Select a language :",langs);
  if(lang=="English")
  {
      T.load(":/new/prefix1/english.qm");
  }else if(lang=="Arabic")
  {
      T.load(":/new/prefix1/arabe.qm");
  }
  if(lang!="French")
  {
      a.installTranslator(&T);
  }
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

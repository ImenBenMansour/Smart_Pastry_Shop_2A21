#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include<QFile>
#include<QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile styleSheetFile("C:/Users/HP/Desktop/projet/Adaptic.qss");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet=QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);
    MainWindow w;
    Connection c;
    QTranslator t;
        QStringList languages;
        languages <<"French" <<"anglais" << "Arabe";

        const QString lang = QInputDialog::getItem(NULL,"Select language",
                                             "language", languages);

        if (lang == "anglais")
        {
            //t.load("C:/Qt/5.9.9/mingw53_32/translations/qtbase_en.qm");

            t.load(":/anglais.qm");

        }
        else if (lang == "Arabe" )
        {
           t.load(":/arabe.qm");
        }
        if(lang !="French"){
            a.installTranslator(&t);
        }
    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}

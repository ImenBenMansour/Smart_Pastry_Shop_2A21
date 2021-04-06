#ifndef RECLAMATION_H
#define RECLAMATION_H
#include<QString>
#include <QSqlQueryModel>
#include <QDate>
#include <QFile>
#include <QFileDialog>
#include <QApplication>
#include <QPrinter>
#include <QTextDocument>
#include <QSqlQuery>
#include <QTableView>

class reclamation
{
public:
    reclamation();
    reclamation(int id_rec,QString des_rec,QString mail_rec,QDate dat);

    int getid_rec();
    QString getdes_rec();
    QString getmail_rec();
    QDate getdat();
    void setid_rec(int);
    void setdes_rec(QString);
    void setmail_rec(QString);
    void setdat(QDate);
    bool ajouter();
    QSqlQueryModel* afficher();

     bool supprimer(int);
     bool modifier(int,QString,QString,QDate);
     bool testmail(QString);
    void exporter(QTableView *table );

private:
    int id_rec;
    QString des_rec;
    QString mail_rec;
    QDate dat;


};

#endif // RECLAMATION_H

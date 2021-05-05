#ifndef OFFRES_H
#define OFFRES_H
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


class offres
{
public:
    offres();
    offres(int id_of,QString nom_of,int prix_of,QDate dat_deb_of,QDate dat_fin_of);

    int getid_of();
    QString getnom_of();
    int getprix_of();
    QDate getdat_deb_of();
    QDate getdat_fin_of();
    void setid_of(int);
    void setnom_of(QString);
    void setprix_of(int);
    void setdat_deb_of(QDate);
    void setdat_fin_of(QDate);
    bool ajouter();
    QSqlQueryModel* afficher();

     bool supprimer(int);
     bool modifier(int,QString,int,QDate,QDate);

    //void rechercher(QTableView * table ,int);
    //void cleartable (QTableView * table);
    QSqlQueryModel* afficher_id_of(QString);
    bool search_id_of(QString);
    QSqlQueryModel* afficher_nom_of(QString);
    bool search_nom_of(QString);
    QSqlQueryModel* afficher_dat_deb_of(QString);
    bool search_dat_deb_of(QString);
    QSqlQueryModel * reset();

    QSqlQueryModel* trier_id_of();
    QSqlQueryModel* trier_prix_of();
    QSqlQueryModel* trier_nom_of();

private:
    int id_of , prix_of;
    QString nom_of;
    QDate dat_deb_of, dat_fin_of;


};

#endif // OFFRES_H

#include "promotion.h"
#include  <QSqlQuery>
#include <QtDebug>
#include<QObject>


QString promotion::getnom(){return nom;}
QDate  promotion::getdat_cre(){return dat_cre;}
QDate promotion::getdat_exp(){return dat_exp;}
int promotion::getid(){return id;}
void promotion::setnom(QString nom) {this->nom=nom;}
void promotion::setdat_cre(QDate dat_cre){this->dat_cre=dat_cre;}
void promotion::setdat_exp(QDate dat_exp){this->dat_exp=dat_exp;}
void promotion::setid(int id){this->id=id;}

promotion::promotion()
{}
promotion::promotion(int id,QString nom,QDate dat_cre,QDate dat_exp)
{
   this->nom=nom;
 this->dat_cre=dat_cre;
 this->dat_exp=dat_exp;
 this->id=id;

//m
}
bool promotion::ajouter2()
{
    QSqlQuery query;

         query.prepare("INSERT INTO Promotion ( NOM, DAT_CRE,DAT_EXP,ID) "
                       "VALUES ( :nom, :dat_cre, :dat_exp, :id)");
         query.bindValue(":nom", nom);
         query.bindValue(":dat_cre", dat_cre);
         query.bindValue(":dat_exp", dat_exp);
         query.bindValue(":id", id);


    return query.exec();
}
bool promotion::supprimer2(int id)
{
     QSqlQuery query;
    query.prepare("Delete from promotion where id=:id");
    query.bindValue(":id", id);

   return query.exec();
}
QSqlQueryModel* promotion::afficher2()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM promotion");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("dat_cre"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("dat_exp"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("id"));

    return model;
}
bool promotion::modifier2(int id,QString nom,QDate dat_cre,QDate dat_exp)
{

    QSqlQuery query;
    query.prepare("UPDATE promotion set nom=:nom, dat_cre=:dat_cre, dat_exp=:dat_exp , id=:id  WHERE id=:id");
    query.bindValue(":nom",nom);
    query.bindValue(":dat_cre",dat_cre);
    query.bindValue(":dat_exp",dat_exp);
     query.bindValue(":id",id);

    return query.exec();
}
QSqlQueryModel* promotion::trier_id()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from PROMOTION ORDER BY id");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DAT_CRE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DAT_EXP"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));

        return model ;
}

QSqlQueryModel* promotion::trier_nom()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from PROMOTION ORDER BY nom");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DAT_CRE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DAT_EXP"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));

        return model ;
}

QSqlQueryModel* promotion::trier_date()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from PROMOTION ORDER BY dat_cre");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DAT_CRE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DAT_EXP"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));

        return model ;
}

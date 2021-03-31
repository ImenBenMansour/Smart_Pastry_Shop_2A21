#include "fournisseurs.h"
#include <QSqlQuery>
#include <QDebug>
#include<QString>
#include "connexion.h"

fournisseurs::fournisseurs()
{
 nom="";
 adresse="";
 tel=0;
 mail="";
}

fournisseurs::fournisseurs(QString nom,QString adresse,int tel,QString mail)
{
        this->nom=nom;
        this->adresse=adresse;
        this->tel=tel;
        this->mail=mail;
 }


void fournisseurs::setNom(QString nom){this->nom=nom;}
void fournisseurs::setAdresse(QString adresse){this->adresse=adresse;}
void fournisseurs::setTel(int tel){this->tel=tel;}
void fournisseurs::setMail(QString mail){this->mail=mail;}



QString fournisseurs::getNom(){return nom;}
QString fournisseurs::getAdresse(){return adresse;}
int fournisseurs::getTel(){return tel;}
QString fournisseurs::getMail(){return mail;}



bool fournisseurs::ajouter_fournisseur()
{
QSqlQuery query;

QString res= QString::number(tel);
query.prepare("INSERT INTO FOURNISSEURS (NOM,ADRESSE,TEL,MAIL) "

                    "VALUES (:nom,:adresse,:tel,:mail)");
query.bindValue(":nom", nom);
query.bindValue(":adresse", adresse);
query.bindValue(":tel", res);
query.bindValue(":mail", mail);

return    query.exec();

}


QSqlQueryModel* fournisseurs::afficher_fournisseur()

{
    QSqlQueryModel* model= new QSqlQueryModel();
model->setQuery("select * from FOURNISSEURS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEL"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));

    return model;
}



bool fournisseurs::supprimer_fournisseur(QString nom)
{
QSqlQuery query;

query.prepare("Delete from FOURNISSEURS where NOM = :nom ");

query.bindValue(":nom", nom);

return    query.exec();
}



bool fournisseurs::modifier_fournisseur()
{
    QSqlQuery query ;
           query.prepare("update FOURNISSEURS set NOM=:nom,ADRESSE=:adresse,TEL=:tel,MAIL=:mail where NOM=:nom ");

           query.bindValue(":nom",nom);
           query.bindValue(":adresse",adresse);
           query.bindValue(":tel",tel);
           query.bindValue(":mail",mail);

           return query.exec();
}



QSqlQueryModel* fournisseurs::afficher_four(QString nom)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM FOURNISSEURS WHERE NOM=:nom ");
    query.bindValue(":nom", nom);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));

    return model;
}

bool fournisseurs::search_nom(QString nom)
{
    QSqlQuery query;
    query.prepare("SELECT NOM FROM FOURNISSEURS WHERE NOM=:nom");
    query.bindValue(":nom", nom);
    query.exec();

    if(query.size()!=nom){return false;}
    else return true;
}













/*

QSqlQueryModel* fournisseurs::afficher_four_adr(QString adresse)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM FOURNISSEURS WHERE ADRESSE=:adresse ");
    query.bindValue(":adresse", adresse);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));

    return model;
}

bool fournisseurs::search_adr(QString adresse)
{
    QSqlQuery query;
    query.prepare("SELECT ADRESSE FROM FOURNISSEURS WHERE ADRESSE=:adresse");
    query.bindValue(":adresse", adresse);
    query.exec();

    if(query.size()!=adresse){return false;}
    else return true;
}


QSqlQueryModel* fournisseurs::afficher_four_mail(QString mail)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM FOURNISSEURS WHERE MAIL=:mail ");
    query.bindValue(":mail", mail);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));

    return model;
}

bool fournisseurs::search_mail(QString mail)
{
    QSqlQuery query;
    query.prepare("SELECT MAIL FROM FOURNISSEURS WHERE MAIL=:mail");
    query.bindValue(":mail", mail);
    query.exec();

    if(query.size()!=mail){return false;}
    else return true;
}

*/









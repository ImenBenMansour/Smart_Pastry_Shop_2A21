#include "fournisseurs.h"
#include <QSqlQuery>
#include <QDebug>
#include<QString>
#include "connexion.h"

fournisseurs::fournisseurs()
{
id="";
 nom="";
 adresse="";
 tel=0;
 mail="";
}

fournisseurs::fournisseurs(QString id,QString nom,QString adresse,int tel,QString mail)
{
        this->id=id;
        this->nom=nom;
        this->adresse=adresse;
        this->tel=tel;
        this->mail=mail;
 }

void fournisseurs::setId(QString id){this->id=id;}
void fournisseurs::setNom(QString nom){this->nom=nom;}
void fournisseurs::setAdresse(QString adresse){this->adresse=adresse;}
void fournisseurs::setTel(int tel){this->tel=tel;}
void fournisseurs::setMail(QString mail){this->mail=mail;}


QString fournisseurs::getId(){return id;}
QString fournisseurs::getNom(){return nom;}
QString fournisseurs::getAdresse(){return adresse;}
int fournisseurs::getTel(){return tel;}
QString fournisseurs::getMail(){return mail;}



bool fournisseurs::ajouter_fournisseur()
{
QSqlQuery query;

QString res= QString::number(tel);
query.prepare("INSERT INTO FOURNISSEUR (ID,NOM,ADRESSE,TEL,MAIL) "

                    "VALUES (:id,:nom,:adresse,:tel,:mail)");
query.bindValue(":id", id);
query.bindValue(":nom", nom);
query.bindValue(":adresse", adresse);
query.bindValue(":tel", res);
query.bindValue(":mail", mail);

return    query.exec();

}


QSqlQueryModel* fournisseurs::afficher_fournisseur()

{
    QSqlQueryModel* model= new QSqlQueryModel();
model->setQuery("select * from FOURNISSEUR");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("MAIL"));

    return model;
}



bool fournisseurs::supprimer_fournisseur(QString id)
{
QSqlQuery query;

query.prepare("Delete from FOURNISSEUR where ID = :id ");

query.bindValue(":id", id);

return    query.exec();
}



bool fournisseurs::modifier_fournisseur()
{
    QSqlQuery query ;
           query.prepare("update FOURNISSEUR set NOM=:nom,ADRESSE=:adresse,TEL=:tel,MAIL=:mail where ID=:id ");

           query.bindValue(":id",id);
           query.bindValue(":nom",nom);
           query.bindValue(":adresse",adresse);
           query.bindValue(":tel",tel);
           query.bindValue(":mail",mail);

           return query.exec();
}




QSqlQueryModel* fournisseurs::afficher_four_id(QString id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM FOURNISSEUR WHERE ID=:id ");
    query.bindValue(":id", id);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MAIL"));

    return model;
}

bool fournisseurs::search_id(QString id)
{
    QSqlQuery query;
    query.prepare("SELECT ID FROM FOURNISSEUR WHERE ID=:id");
    query.bindValue(":id", id);
    query.exec();

    if(query.size()!=id){return false;}
    else return true;
}





// recherhe par nom
QSqlQueryModel* fournisseurs::afficher_four_nom(QString nom)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM FOURNISSEUR WHERE NOM=:nom ");
    query.bindValue(":nom", nom);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MAIL"));

    return model;
}

bool fournisseurs::search_nom(QString nom)
{
    QSqlQuery query;
    query.prepare("SELECT NOM FROM FOURNISSEUR WHERE NOM=:nom");
    query.bindValue(":nom", nom);
    query.exec();

    if(query.size()!=nom){return false;}
    else return true;
}


QSqlQueryModel* fournisseurs::afficher_four_adr(QString adresse)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM FOURNISSEUR WHERE ADRESSE=:adresse ");
    query.bindValue(":adresse", adresse);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MAIL"));

    return model;
}

bool fournisseurs::search_adr(QString adresse)
{
    QSqlQuery query;
    query.prepare("SELECT ADRESSE FROM FOURNISSEUR WHERE ADRESSE=:adresse");
    query.bindValue(":adresse", adresse);
    query.exec();

    if(query.size()!=adresse){return false;}
    else return true;
}
bool fournisseurs::testmail(QString mail){
    int test=0;
    for(int i = 0; i < mail.size(); i++) {
if(mail[i]=="@")
{test++;

}}
    for(int i = 0; i < mail.size(); i++) {
if((test==1)&&(mail[i]=="."))
{if(mail.size()>i+1)
    return true;
}}
return false;}









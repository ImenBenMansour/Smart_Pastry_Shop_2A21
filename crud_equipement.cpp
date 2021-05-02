#include "crud_equipement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

crud_equipement::crud_equipement()
{


}
crud_equipement::crud_equipement (int ide ,QString nome ,int quantitee , QString etate )
{ this->ide=ide ;
    this->nome=nome ;
    this->quantitee=quantitee ;
this->etate=etate ;
}
int crud_equipement::getide () {return ide ;}
QString crud_equipement::getnome() {return nome ;}
int crud_equipement::getquantitee() {return quantitee;}
QString crud_equipement::getetate() {return etate;}
void crud_equipement::setide(int ide){this->ide=ide;}
void crud_equipement::setnome(QString nome){this->nome=nome;}
void crud_equipement::setquantitee (int quantitee) {this->quantitee=quantitee;}
void crud_equipement::setetate (QString etate) {this->etate=etate;}


bool crud_equipement::ajoutere()

{

    QSqlQuery query;
    query.prepare("INSERT INTO EQUIPEMENT (IDE, NOME, QUANTITEE , ETATE) "
                  "VALUES (:ide, :nome, :quantitee, :etate )");
    query.bindValue(":ide", ide);
    query.bindValue(":nome", nome);
    query.bindValue(":quantitee",quantitee);
    query.bindValue(":etate",etate);

    return query.exec();
}
bool crud_equipement::supprimere(int ide)
{

    QSqlQuery query;
    query.prepare("Delete from EQUIPEMENT where ide=:ide");
    query.bindValue(":ide", ide);


    return query.exec();
}




QSqlQueryModel* crud_equipement::affichere()
{
    // Création d'une instance lorsque on a parle là des widgets
     QSqlQueryModel * model = new QSqlQueryModel();
     //
     model->setQuery("SELECT * FROM EQUIPEMENT ");// Récupération des données men table
     // Pour que l'affichage iji mnathem,les colonnes bahtha bathhom et mnathmin on fait comme ça :
     // Qt::horizontal manha table bel rekda ijiw les colonnes

     model->setHeaderData(0, Qt::Horizontal,"Id_Equipement");

     model->setHeaderData(1, Qt::Horizontal,"Nom_Equipement");
     model->setHeaderData(2, Qt::Horizontal,"Quantité_Equipement");
     model->setHeaderData(3, Qt::Horizontal,"Etat_Equipement");

     return model;

}




bool crud_equipement::modifiere(int ide, QString nome,int quantitee , QString etate )
{

    QSqlQuery query;
    query.prepare("UPDATE EQUIPEMENT set ide=:ide, nome=:nome, quantitee=:quantitee , etate=:etate  WHERE ide=:ide");
    query.bindValue(":ide",ide);
    query.bindValue(":nome",nome);
    query.bindValue(":quantitee",quantitee);
    query.bindValue(":etate",etate);


    return query.exec();
}

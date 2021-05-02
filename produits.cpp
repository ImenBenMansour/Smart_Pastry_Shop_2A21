#include "produits.h"
#include <QSqlQuery>
#include <QDebug>
#include<QString>
#include "connexion.h"

produits::produits()
{
    id="";
    nom="";
    prix=0;
    quantite=0;
}


produits::produits(QString id,QString nom,int prix,int quantite)
{
        this->id=id;
        this->nom=nom;
        this->prix=prix;
        this->quantite=quantite;
 }


void produits::setId(QString id){this->id=id;}
void produits::setNom(QString nom){this->nom=nom;}
void produits::setPrix(int prix){this->prix=prix;}
void produits::setQuantite(int quantite){this->quantite=quantite;}



QString produits::getId(){return id;}
QString produits::getNom(){return nom;}
int produits::getPrix(){return prix;}
int produits::getQuantite(){return quantite;}


bool produits::ajouter_produit()
{
    QSqlQuery query;

    QString res= QString::number(prix);
    QString res1= QString::number(quantite);
    query.prepare("INSERT INTO PRODUITS (ID,NOM,PRIX,QUANTITE) "

                        "VALUES (:id,:nom,:prix,:quantite)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prix", res);
    query.bindValue(":quantite", res1);

return    query.exec();

}

QSqlQueryModel* produits::afficher_produit()
 {
   /*

   QSqlQueryModel* model= new QSqlQueryModel();
model->setQuery("select * from PRODUITS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));

    return model; */

    QSqlQueryModel* model=new QSqlQueryModel();


             model->setQuery("SELECT ca.id,cl.nom, ca.prix, ca.quantite  FROM  PRODUITS ca ,FOURNISSEUR cl where ca.nom=:cl.id");
             model->setQuery("select * from PRODUITS");
              model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
              model->setHeaderData(1, Qt::Horizontal,QObject::tr("id fournisseur"));
              model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRIX"));
              model->setHeaderData(3, Qt::Horizontal,QObject::tr("QUANTITE"));

        return model;
}



bool produits::supprimer_produit(QString id)
{
QSqlQuery query;

query.prepare("Delete from PRODUITS where ID = :id ");

query.bindValue(":id", id);

return    query.exec();
}

bool produits::modifier_produit()
{
    QSqlQuery query ;
           query.prepare("update PRODUITS set NOM=:nom,PRIX=:prix,QUANTITE=:quantite where ID=:id ");

           query.bindValue(":id",id);
           query.bindValue(":nom",nom);
           query.bindValue(":prix",prix);
           query.bindValue(":quantite",quantite);

           return query.exec();
}


QSqlQueryModel* produits::trier_id()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from PRODUITS ORDER BY id");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));

        return model ;
}

QSqlQueryModel* produits::trier_nom()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from PRODUITS ORDER BY nom");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));

        return model ;
}

QSqlQueryModel* produits::trier_prix()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from PRODUITS ORDER BY prix");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));

        return model ;
}

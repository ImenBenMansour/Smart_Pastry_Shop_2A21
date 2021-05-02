#ifndef PRODUITS_H
#define PRODUITS_H
#include "connexion.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class produits
{
private:
QString id;
QString nom;
int prix;
int quantite;

public:
produits();
produits(QString,QString,int,int);

void setId(QString);
void setNom(QString);
void setPrix(int);
void setQuantite(int);

QString getId();
QString getNom();
int getPrix();
int getQuantite();

QSqlQueryModel* afficher_produit();
bool ajouter_produit();
bool supprimer_produit(QString);
bool modifier_produit();


QSqlQueryModel* trier_id();
QSqlQueryModel* trier_nom();
QSqlQueryModel* trier_prix();




};


#endif // PRODUITS_H

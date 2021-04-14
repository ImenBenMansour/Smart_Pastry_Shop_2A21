#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H
#include "connexion.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fournisseurs
{
private:
QString id;
QString nom;
QString adresse;
int tel;
QString mail;

public:
fournisseurs();
fournisseurs(QString,QString,QString,int,QString);

void setId(QString);
void setNom(QString);
void setAdresse(QString);
void setTel(int);
void setMail(QString);

QString getId();
QString getNom();
QString getAdresse();
int getTel();
QString getMail();


//bool ajouter_fournisseur();
QSqlQueryModel* afficher_fournisseur();
bool ajouter_fournisseur();
bool supprimer_fournisseur(QString);
bool modifier_fournisseur();

QSqlQueryModel* afficher_four_id(QString);
bool search_id(QString);

QSqlQueryModel* afficher_four_nom(QString);
bool search_nom(QString);


QSqlQueryModel* afficher_four_adr(QString);
bool search_adr(QString);
bool testmail(QString);


};

#endif // FOURNISSEURS_H

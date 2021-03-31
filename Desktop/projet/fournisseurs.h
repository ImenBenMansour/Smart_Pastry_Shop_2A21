#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H
#include "connexion.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fournisseurs
{
private:
QString nom;
QString adresse;
int tel;
QString mail;

public:
fournisseurs();
fournisseurs(QString,QString,int,QString);

void setNom(QString);
void setAdresse(QString);
void setTel(int);
void setMail(QString);

QString getNom();
QString getAdresse();
int getTel();
QString getMail();


bool ajouter_fournisseur();
QSqlQueryModel* afficher_fournisseur();
bool supprimer_fournisseur(QString);
bool modifier_fournisseur();

QSqlQueryModel* afficher_four(QString);
bool search_nom(QString);

/*
QSqlQueryModel* afficher_four_adr(QString);
bool search_adr(QString);

QSqlQueryModel* afficher_four_mail(QString);
bool search_mail(QString);
*/

};

#endif // FOURNISSEURS_H

#ifndef CRUD_EQUIPEMENT_H
#define CRUD_EQUIPEMENT_H

#include <QVariant>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>

class crud_equipement
{
    int ide ;
    QString nome ;
    int quantitee ;
    QString etate ;
public:
    crud_equipement();
  crud_equipement (int,QString,int,QString);
  int getide () ;
  QString getnome() ;
  int getquantitee () ;
  QString getetate () ;

  void setide(int) ;
  void setnome(QString) ;
  void setquantitee (int) ;
  void setetate (QString) ;
  bool ajoutere () ;
  QSqlQueryModel* affichere();
  bool supprimere (int) ;
  bool modifiere(int,QString,int,QString);
};

#endif // CRUD_EQUIPEMENT_H

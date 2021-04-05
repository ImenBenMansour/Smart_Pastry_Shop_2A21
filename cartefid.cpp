#include "cartefid.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

int Cartefid::getcin(){return cin;}
QString Cartefid::getpoint(){return point;}
int Cartefid::getid_carte(){return id_carte;}
QDate Cartefid::getda(){return da;}
void Cartefid::setcin(int cin){this->cin=cin;}
void Cartefid::setpoint(QString point){this->point=point;}
void Cartefid::setid_carte(int id_carte){this->id_carte=id_carte;}
void Cartefid::setda(QDate da){this->da=da;}
Cartefid::Cartefid()
{}

Cartefid::Cartefid(int cin,QString point,int id_carte,QDate da)
{
 this->cin =cin;
 this->point=point;
 this->id_carte=id_carte;
  this->da=da;

}




bool Cartefid::ajouter()
{

    QSqlQuery query;

    query.prepare("INSERT INTO Cartefid (CIN, POINT,ID_CARTE,DA) "
                  "VALUES (:cin, :point, :id_carte, :da)");
    query.bindValue(":cin", cin);
    query.bindValue(":point", point);
    query.bindValue(":id_carte", id_carte);
     query.bindValue(":da", da);

   return query.exec();






}
bool   Cartefid::supprimer(int cin)
{QSqlQuery query;

    query.prepare("Delete from cartefid where cin=:cin");
    query.bindValue(":cin", cin);



   return query.exec();



}



QSqlQueryModel* Cartefid::afficher()
{QSqlQueryModel* model=new QSqlQueryModel();


         model->setQuery("SELECT ca.cin ,ca.da,ca.point,ca.id_carte ,cl.nom , cl.prenom  FROM  cartefid ca ,clientfid cl where ca.cin=cl.cin");

         model->setHeaderData(0, Qt::Horizontal,QObject::tr("Cin"));
          model->setHeaderData(3, Qt::Horizontal,QObject::tr("id_carte"));
          model->setHeaderData(5, Qt::Horizontal,QObject::tr("prenom"));
          model->setHeaderData(2, Qt::Horizontal,QObject::tr("point"));
          model->setHeaderData(4, Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(1, Qt::Horizontal,QObject::tr("date"));



    return model;

}
QSqlQueryModel* Cartefid::afficher2()
{QSqlQueryModel* model=new QSqlQueryModel();


         model->setQuery("SELECT* FROM cartefid");
         model->setHeaderData(0, Qt::Horizontal,QObject::tr("Cin"));
         model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prenom"));
          model->setHeaderData(3, Qt::Horizontal,QObject::tr("Da"));

    return model;

}
bool Cartefid::modifier(int cin,QString point,int id_carte,QDate da){

    QSqlQuery query;
    query.prepare("UPDATE cartefid set cin=:cin, nom=:nom, prenom=:prenom, da=:da WHERE cin=:cin");
    query.bindValue(":cin",cin);
    query.bindValue(":point",point);
    query.bindValue(":id_carte",id_carte);
    query.bindValue(":da",da);
    return query.exec();
}


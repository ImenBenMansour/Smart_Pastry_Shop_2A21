#include "reclamation.h"
#include  <QSqlQuery>
#include <QtDebug>
#include<QObject>

int reclamation::getid_rec(){return id_rec;}
QString reclamation::getdes_rec(){return des_rec;}
QString  reclamation::getmail_rec(){return mail_rec;}
QDate reclamation::getdat(){return dat;}
void reclamation::setid_rec(int id_rec){this->id_rec=id_rec;}
void reclamation::setdes_rec(QString des_rec){this->des_rec=des_rec;}
void reclamation::setmail_rec(QString mail_rec){this->mail_rec=mail_rec;}
void reclamation::setdat(QDate dat){this->dat=dat;}
reclamation::reclamation()
{}

reclamation::reclamation(int id_rec,QString des_rec,QString mail_rec,QDate dat)
{
   this->id_rec=id_rec;
 this->des_rec=des_rec;
 this->mail_rec=mail_rec;
   this->dat=dat;


}
bool reclamation::ajouter()
{
    QSqlQuery query;

         query.prepare("INSERT INTO Reclamation (ID_REC, DES_REC, MAIL_REC,DAT) "
                       "VALUES (:id_rec, :des_rec, :mail_rec, :dat)");
         query.bindValue(":id_rec", id_rec);
         query.bindValue(":des_rec", des_rec);
         query.bindValue(":mail_rec", mail_rec);
         query.bindValue(":dat",dat);


    return query.exec();
}
bool reclamation::supprimer(int id_rec)
{
     QSqlQuery query;
    query.prepare("Delete from reclamation where id_rec=:id_rec");
    query.bindValue(":id_rec", id_rec);

   return query.exec();
}
QSqlQueryModel* reclamation::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM reclamation");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_rec"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("des_rec"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("mail_rec"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("dat"));



    return model;
}
bool reclamation::modifier(int id_rec,QString des_rec,QString mail_rec,QDate dat)
{

    QSqlQuery query;
    query.prepare("UPDATE reclamation set id_rec=:id_rec, des_rec=:des_rec, mail_rec=:mail_rec ,dat=:dat  WHERE id_rec=:id_rec");
    query.bindValue(":id_rec",id_rec);
    query.bindValue(":des_rec",des_rec);
    query.bindValue(":mail_rec",mail_rec);
    query.bindValue(":dat",dat);

    return query.exec();
}

bool reclamation::testmail(QString mail_rec){
    int test=0;
    for(int i = 0; i < mail_rec.size(); i++) {
if(mail_rec[i]=="@")
{test++;

}}
    for(int i = 0; i < mail_rec.size(); i++) {
if((test==1)&&(mail_rec[i]=="."))
{if(mail_rec.size()>i+1)
    return true;
}}
return false;}

#include "clientfid.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include<QtCharts>
#include<QPieSeries>
#include<QPieSlice>
int Clientfid::getcin(){return cin;}
QString Clientfid::getnom(){return nom;}
QString Clientfid::getprenom(){return prenom;}
int Clientfid::getnum(){return num;}
QString Clientfid::getmail(){return mail;}
void Clientfid::setcin(int cin){this->cin=cin;}
void Clientfid::setnom(QString nom){this->nom=nom;}
void Clientfid::setprenom(QString prenom){this->prenom=prenom;}
void Clientfid::setnum(int num){this->num=num;}
void Clientfid::setmail(QString mail){this->mail=mail;}

Clientfid::Clientfid()
{}

Clientfid::Clientfid(int cin,QString nom,QString prenom,int num,QString mail)
{
 this->cin =cin;
 this->nom=nom;
 this->prenom=prenom;
  this->num=num;
 this->mail=mail;
}




bool Clientfid::ajouter()
{

    QSqlQuery query;

    query.prepare("INSERT INTO Clientfid (CIN, NOM, PRENOM,NUM,MAIL) "
                  "VALUES (:cin, :nom, :prenom, :num, :mail)");
    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":num", num);
    query.bindValue(":mail", mail);
   return query.exec();






}
bool   Clientfid::supprimer(int cin)
{QSqlQuery query;


   // query.prepare("Select from CLIENTFID where cin=:cin");
   // query.bindValue(":cin", cin);
   // if(query.exec()==true)  // kifeh naaref est_ce_que selecteha walle ?
   // {test=true;}


    query.prepare("Delete from CLIENTFID where cin=:cin");
    query.bindValue(":cin", cin);


   return query.exec();



}
QSqlQueryModel *Clientfid::afficher2(QString cin,QString nom ,QString prenom)
{
    QSqlQuery query;

    QSqlQueryModel *model = new QSqlQueryModel();

    if(cin=="XYZ" && nom=="XYZ" && prenom=="XYZ")
    {
     model->setQuery("SELECT * FROM CLIENTFID");
    }
    else if(cin!="XYZ" && nom=="XYZ" && prenom=="XYZ")
       {
        query.prepare("SELECT * FROM CLIENTFID WHERE CIN= :cin");
        query.bindValue(":cin",cin);
        query.exec();
        model->setQuery(query);
       }
    else if(cin=="XYZ" && nom !="XYZ" && prenom=="XYZ")
    {
        query.prepare("SELECT * FROM CLIENTFID WHERE NOM= :nom");
        query.bindValue(":nom",nom);
        query.exec();
        model->setQuery(query);
    }
    else if(cin=="XYZ" && nom =="XYZ" && prenom!="XYZ")
    {
        query.prepare("SELECT * FROM CLIENTFID WHERE PRENOM= :prenom");
        query.bindValue(":prenom",prenom);
        query.exec();
        model->setQuery(query);
    }
    else if(cin!="XYZ" && nom!="XYZ" && prenom!="XYZ")
    {
        query.prepare("SELECT * FROM CLIENTFID WHERE CIN= :cin AND NOM= :nom AND PRENOM= :prenom");
        query.bindValue(":cin",cin);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.exec();
        model->setQuery(query);
    }


    else if(cin=="XYZ" && nom!="XYZ" && prenom!="XYZ")
    {
        query.prepare("SELECT * FROM CLIENTFID WHERE NOM= :nom AND PRENOM= :prenom");
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.exec();
        model->setQuery(query);
    }
    else if(cin!="XYZ" && nom=="XYZ" && prenom!="XYZ")
    {
        query.prepare("SELECT * FROM CLIENTFID WHERE CIN= :cin AND  PRENOM= :prenom");
        query.bindValue(":cin",cin);
        query.bindValue(":prenom",prenom);
        query.exec();
        model->setQuery(query);
    }
    else if(cin!="XYZ" && nom!="XYZ" && prenom=="XYZ")
    {
        query.prepare("SELECT * FROM CLIENTFID WHERE CIN= :cin AND NOM= :nom ");
        query.bindValue(":cin",cin);
        query.bindValue(":nom",nom);
        query.exec();
        model->setQuery(query);
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));

    return model;
}





/*QSqlQueryModel* Clientfid::afficher2()
{QSqlQueryModel* model=new QSqlQueryModel();


         model->setQuery("SELECT* FROM Clientfid");
         model->setHeaderData(0, Qt::Horizontal,QObject::tr("Cin"));
         model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prenom"));
        model->setHeaderData(3, Qt::Horizontal,QObject::tr("Num"));
        model->setHeaderData(4, Qt::Horizontal,QObject::tr("Mail"));
    return model;

}*/


bool Clientfid::modifier(int cin,QString nom,QString prenom,int num,QString mail){

    QSqlQuery query;
    query.prepare("UPDATE Clientfid set cin=:cin, nom=:nom, prenom=:prenom, num=:num, mail=:mail WHERE cin=:cin");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":num", num);
    query.bindValue(":mail", mail);
    return query.exec();
}
bool Clientfid::testmail(QString mail){
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

/*QSqlQueryModel *  Clientfid::rechercher(int cin)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(cin);

    model->setQuery("select * from CLIENTFID where (cin LIKE '"+res+"%' ) ");


            return  model;


}*/
QSqlQueryModel * Clientfid::reset(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from CLIENTFID  ");

    return  model;
}
QString Clientfid::affecter_nom(QString nom)
{
 QString b;
    QSqlQuery query;

    query.prepare("Select * from CLIENT where NOM= :nom");
    query.bindValue(":nom", nom);
    if (query.exec())
    {
        while (query.next())
        {
            b = query.value(0).toString();
        }
    }
    return b;
}
QString Clientfid::affecter_cin(QString cin)
{
    QString t;
    QSqlQuery query;
    query.prepare("Select * from CLIENTFID where CIN= :cin");
    query.bindValue(":cin", cin);
    if (query.exec())
    {
        while (query.next())
        {
            t = query.value(1).toString();
        }
    }
    return t;
}
QSqlQueryModel* Clientfid::trier_cin()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from CLIENTFID ORDER BY cin");

        model->setHeaderData(0, Qt::Horizontal,QObject::tr("Cin"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prenom"));
       model->setHeaderData(3, Qt::Horizontal,QObject::tr("Num"));
       model->setHeaderData(4, Qt::Horizontal,QObject::tr("Mail"));


        return model ;
}

QSqlQueryModel* Clientfid::trier_nom()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from CLIENTFID ORDER BY nom");

        model->setHeaderData(0, Qt::Horizontal,QObject::tr("Cin"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prenom"));
       model->setHeaderData(3, Qt::Horizontal,QObject::tr("Num"));
       model->setHeaderData(4, Qt::Horizontal,QObject::tr("Mail"));

        return model ;
}



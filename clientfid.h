#ifndef CLIENTFID_H
#define CLIENTFID_H

#include <QString>
#include <QSqlQueryModel>
class Clientfid
{
public:
    Clientfid();
    Clientfid(int cin,QString nom,QString prenom,int num,QString mail);
    int getcin();
    QString getnom();
    QString getprenom();
    int getnum();
    QString getmail();
    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    void setnum(int);
    void setmail(QString);
    bool ajouter();
   // QSqlQueryModel* afficher2();
    bool testmail(QString);



    bool supprimer(int);
    bool modifier(int,QString,QString,int,QString);
QString affecter_cin(QString cin);
QString affecter_nom(QString nom);
QSqlQueryModel *afficher2(QString cin, QString nom,QString prenom);
     //QSqlQueryModel * rechercher(int);
QSqlQueryModel* trier_cin();
QSqlQueryModel* trier_nom();
     QSqlQueryModel * reset();

private:
    int cin,num;
    QString nom, prenom,mail;



};

#endif // CLIENTFID_H

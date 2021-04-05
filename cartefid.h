#ifndef CARTEFID_H
#define CARTEFID_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
class Cartefid
{
public:
    Cartefid();
    Cartefid(int cin,QString point,int id_carte,QDate da);
    int getcin();
    QString getpoint();
   int getid_carte();
    QDate getda();
    void setcin(int);
    void setpoint(QString);
   void setid_carte(int);
    void setda(QDate);
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher2();
    bool supprimer(int);
    bool modifier(int,QString,int,QDate);
    //void statistique_med();
private:
    int cin,id_carte;
    QString point;
    QDate da;



};

#endif // CARTEFID_H

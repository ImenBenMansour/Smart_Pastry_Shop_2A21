#ifndef RECLAMATION_H
#define RECLAMATION_H
#include<QString>
#include <QSqlQueryModel>
#include <QDate>


class reclamation
{
public:
    reclamation();
    reclamation(int id_rec,QString des_rec,QString mail_rec,QDate dat);

    int getid_rec();
    QString getdes_rec();
    QString getmail_rec();
    QDate getdat();
    void setid_rec(int);
    void setdes_rec(QString);
    void setmail_rec(QString);
    void setdat(QDate);
    bool ajouter();
    QSqlQueryModel* afficher();
     bool supprimer(int);
     bool modifier(int,QString,QString,QDate);
     bool testmail(QString);


private:
    int id_rec;
    QString des_rec;
    QString mail_rec;
    QDate dat;


};

#endif // RECLAMATION_H

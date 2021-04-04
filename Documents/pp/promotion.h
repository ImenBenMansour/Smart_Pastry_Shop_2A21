#ifndef PROMOTION_H
#define PROMOTION_H
#include<QString>
#include <QSqlQueryModel>
#include <QDate>

class promotion
{
public:
    promotion();
    promotion(int id,QString nom,QDate dat_exp,QDate dat_cre);

    int getid();
    QString getnom();
    QDate getdat_exp();
    QDate getdat_cre();

    void setnom(QString);
    void setdat_exp(QDate);
    void setdat_cre(QDate);
    void setid(int);
    bool ajouter2();
    QSqlQueryModel* afficher2();
     bool supprimer2(int);
     bool modifier2(int,QString,QDate,QDate);

     QSqlQueryModel* trier_id();
     QSqlQueryModel* trier_nom();
     QSqlQueryModel* trier_date();
private:

    QString nom;
    QDate dat_exp;
    QDate dat_cre;
    int id;


};

#endif // PROMOTION_H

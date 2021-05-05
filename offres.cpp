#include "offres.h"
#include  <QSqlQuery>
#include <QtDebug>
#include<QObject>

int offres::getid_of(){return id_of;}
QString offres::getnom_of(){return nom_of;}
int offres::getprix_of(){return prix_of;}
QDate offres::getdat_deb_of(){return dat_deb_of;}
QDate offres::getdat_fin_of(){return dat_fin_of;}
void offres::setid_of(int id_of){this->id_of=id_of;}
void offres::setnom_of(QString nom_of){this->nom_of=nom_of;}
void offres::setprix_of(int prix_of){this->prix_of=prix_of;}
void offres::setdat_deb_of(QDate dat_deb_of){this->dat_deb_of=dat_deb_of;}
void offres::setdat_fin_of(QDate dat_fin_of){this->dat_fin_of=dat_fin_of;}
offres::offres()
{}

offres::offres(int id_of,QString nom_of,int prix_of,QDate dat_deb_of,QDate dat_fin_of)
{
   this->id_of=id_of;
 this->nom_of=nom_of;
 this->prix_of=prix_of;
   this->dat_deb_of=dat_deb_of;
    this->dat_fin_of=dat_fin_of;


}
bool offres::ajouter()
{
    QSqlQuery query;

         query.prepare("INSERT INTO offres (ID_OF, NOM_OF, PRIX_OF,DAT_DEB_OF,DAT_FIN_OF) "
                       "VALUES (:id_of, :nom_of, :prix_of, :dat_deb_of, :dat_fin_of)");
         query.bindValue(":id_of", id_of);
         query.bindValue(":nom_of", nom_of);
         query.bindValue(":prix_of", prix_of);
         query.bindValue(":dat_deb_of",dat_deb_of);
         query.bindValue(":dat_fin_of",dat_fin_of);


    return query.exec();
}
bool offres::supprimer(int id_of)
{
     QSqlQuery query;
    query.prepare("Delete from offres where id_of=:id_of");
    query.bindValue(":id_of", id_of);

   return query.exec();
}
QSqlQueryModel* offres::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM offres");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_of"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_of"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix_of"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("dat_deb_of"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("dat_fin_of"));



    return model;
}

bool offres::modifier(int id_of,QString nom_of,int prix_of,QDate dat_deb_of,QDate dat_fin_of)
{

    QSqlQuery query;
    query.prepare("UPDATE offres set id_of=:id_of, nom_of=:nom_of, prix_of=:prix_of ,dat_deb_of=:dat_deb_of ,dat_fin_of=:dat_fin_of  WHERE id_of=:id_of");
    query.bindValue(":id_of",id_of);
    query.bindValue(":nom_of",nom_of);
    query.bindValue(":prix_of",prix_of);
    query.bindValue(":dat_deb_of",dat_deb_of);
    query.bindValue(":dat_fin_of",dat_fin_of);

    return query.exec();
}


/*void offres:: rechercher(QTableView * table ,int  id_of )
{

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from offres where regexp_like(id_of,:id_of);");
    query->bindValue(":id_of",id_of);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
void offres::cleartable(QTableView * table)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->clear();
    table->setModel(model);

}*/
QSqlQueryModel* offres::afficher_id_of(QString id_of)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM OFFRES WHERE ID_OF=:id_of ");
    query.bindValue(":id_of", id_of);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_OF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_OF"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX_OF"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DAT_DEB_OF"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DAT_FIN_OF"));
    return model;
}

bool offres::search_id_of(QString id_of)
{
    QSqlQuery query;
    query.prepare("SELECT ID FROM OFFRES WHERE ID_OF=:id_of");
    query.bindValue(":id_of", id_of);
    query.exec();

    if(query.size()!=id_of){return false;}
    else return true;
}

QSqlQueryModel* offres::afficher_dat_deb_of(QString dat_deb_of)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM OFFRES WHERE DAT_DEB_OF=:dat_deb_of ");
    query.bindValue(":dat_deb_of", dat_deb_of);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_OF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_OF"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX_OF"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DAT_DEB_OF"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DAT_FIN_OF"));
    return model;
}

bool offres::search_dat_deb_of(QString dat_deb_of)
{
    QSqlQuery query;
    query.prepare("SELECT NOM FROM OFFRES WHERE DAT_DEB_OF=:dat_deb_of");
    query.bindValue(":dat_deb_of", dat_deb_of);
    query.exec();

    if(query.size()!=dat_deb_of){return false;}
    else return true;
}
QSqlQueryModel* offres::afficher_nom_of(QString nom_of)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM OFFRES WHERE NOM_OF=:nom_of ");
    query.bindValue(":nom_of", nom_of);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_OF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_OF"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX_OF"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DAT_DEB_OF"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("DAT_FIN_OF"));
    return model;
}
QSqlQueryModel * offres::reset(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from OFFRES  ");

    return  model;
}

bool offres::search_nom_of(QString nom_of)
{
    QSqlQuery query;
    query.prepare("SELECT NOM FROM OFFRES WHERE NOM_OF=:nom_of");
    query.bindValue(":nom_of", nom_of);
    query.exec();

    if(query.size()!=nom_of){return false;}
    else return true;
}
QSqlQueryModel* offres::trier_id_of()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from OFFRES ORDER BY id_of");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_OF"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_OF"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX_OF"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DAT_DEB_OF"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DAT_FIN_OF"));

        return model ;
}

QSqlQueryModel* offres::trier_nom_of()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from OFFRES ORDER BY nom_of");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_OF"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_OF"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX_OF"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DAT_DEB_OF"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DAT_FIN_OF"));

        return model ;
}

QSqlQueryModel* offres::trier_prix_of()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * from OFFRES ORDER BY prix_of");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_OF"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_OF"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX_OF"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DAT_DEB_OF"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DAT_FIN_OF"));

        return model ;
}


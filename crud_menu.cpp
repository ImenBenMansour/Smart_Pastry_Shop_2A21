#include "crud_menu.h"

#include <QMessageBox>
Crud_Menu::Crud_Menu() {


}
Crud_Menu::Crud_Menu(int idMenu,QString nomMenu,QString categorieMenu, double prixMenu)
{

        this->idMenu = idMenu;
        this->nomMenu = nomMenu;
        this->categorieMenu = categorieMenu;
        this->prixMenu = prixMenu;
}


bool Crud_Menu::ajouter_menu( ) {
    QSqlQuery query; //QsqlQuery : Classe QsqlQuery qui admet une instance query qui contient des méthodes prédefinies comme bindValue/prepare
    query.prepare("INSERT INTO MENU (idMenu,nomMenu,categorieMenu,prixMenu) VALUES(:id, :nom, :categorie, :prix)");//initiliastion requete Insert into
    query.bindValue(":id",idMenu);
    query.bindValue(":nom",nomMenu);
    query.bindValue(":categorie",categorieMenu);
    query.bindValue(":prix",prixMenu);
    return query.exec();// keni exec() traja3 false =====> mathmch ajout thama problème sinon raw ajout jawo behi !
}

bool Crud_Menu::modifier_menu() {
    QSqlQuery query;
    //query.prepare("UPDATE MENU  SET nomMenu =:nomMenu, cateogrieMenu =:categorie , prixMenu =:prix WHERE idMenu = '"+nomMenu+"'"));

    query.prepare("UPDATE MENU  SET nomMenu =:nom, categorieMenu =:categorie, prixMenu =:prix WHERE idMenu = :id");
    query.bindValue(":id",idMenu);
    query.bindValue(":nom",nomMenu);
    query.bindValue(":categorie",categorieMenu);
    query.bindValue(":prix",prixMenu);
    return query.exec();

}
bool Crud_Menu::supprimer_menu(int i)
{
    QSqlQuery query;
    query.prepare("DELETE FROM MENU where idMenu=:id");
    QString res= QString::number(i);// int i bch y7awlha lel qstring,cette méthode,on l'utilise pour éviter les problémes lorsque on a un passage par paramétres
    query.bindValue(":id",res);
    return query.exec();
}

bool Crud_Menu::recupere_menu(int i)
{
    QSqlQuery query;
    QString res= QString::number(i);// int i bch y7awlha lel qstring,cette méthode,on l'utilise pour éviter les problémes lorsque on a un passage par paramétres

    query.prepare("select * from MENU WHERE idMenu = '"+res+"'");
    return query.exec();
}

QSqlQueryModel * Crud_Menu::afficher_menu()
{
   // Création d'une instance lorsque on a parle là des widgets
    QSqlQueryModel * model = new QSqlQueryModel();
    //
    model->setQuery("SELECT * FROM MENU ");// Récupération des données men table
    // Pour que l'affichage iji mnathem,les colonnes bahtha bathhom et mnathmin on fait comme ça :
    // Qt::horizontal manha table bel rekda ijiw les colonnes

    model->setHeaderData(0, Qt::Horizontal,"Id_Menu");

    model->setHeaderData(1, Qt::Horizontal,"Categorie_Menu");
    model->setHeaderData(2, Qt::Horizontal,"Nom_Menu");
    model->setHeaderData(3, Qt::Horizontal,"Prix_Menu");

    return model;

}



QSqlQueryModel * Crud_Menu::recherche_menu_selon_nom(QString nomMenu)
{
   // Création d'une instance lorsque on a parle là des widgets
    QSqlQueryModel * model = new QSqlQueryModel();
    //
    model->setQuery("select * from MENU WHERE nomMenu = '"+nomMenu+"'");

    // Pour que l'affichage iji mnathem,les colonnes bahtha bathhom et mnathmin on fait comme ça :
    // Qt::horizontal manha table bel rekda ijiw les colonnes
    model->setHeaderData(0, Qt::Horizontal,"Id_Menu");
    model->setHeaderData(1, Qt::Horizontal,"Categorie_Menu");
    model->setHeaderData(2, Qt::Horizontal,"Nom_Menu");
    model->setHeaderData(3, Qt::Horizontal,"Prix_Menu");

    return model;

}

QSqlQueryModel * Crud_Menu::recherche_menu_selon_categorie(QString categorieMenu)
{
   // Création d'une instance lorsque on a parle là des widgets
    QSqlQueryModel * model = new QSqlQueryModel();
    //
    model->setQuery("select * from MENU WHERE categorieMenu = '"+categorieMenu+"'");

    // Pour que l'affichage iji mnathem,les colonnes bahtha bathhom et mnathmin on fait comme ça :
    // Qt::horizontal manha table bel rekda ijiw les colonnes
    model->setHeaderData(0, Qt::Horizontal,"Id_Menu");
    model->setHeaderData(1, Qt::Horizontal,"Categorie_Menu");
    model->setHeaderData(2, Qt::Horizontal,"Nom_Menu");
    model->setHeaderData(3, Qt::Horizontal,"Prix_Menu");

    return model;

}

QSqlQueryModel * Crud_Menu::recherche_menu_selon_id(int idMenu)
{
   // Création d'une instance lorsque on a parle là des widgets
    QSqlQueryModel * model = new QSqlQueryModel();
    //
    QString res=QString::number(idMenu);
    model->setQuery("select * from MENU WHERE idMenu = '"+res+"'");

    // Pour que l'affichage iji mnathem,les colonnes bahtha bathhom et mnathmin on fait comme ça :
    // Qt::horizontal manha table bel rekda ijiw les colonnes
    model->setHeaderData(0, Qt::Horizontal,"Id_Menu");
    model->setHeaderData(1, Qt::Horizontal,"Categorie_Menu");
    model->setHeaderData(2, Qt::Horizontal,"Nom_Menu");
    model->setHeaderData(3, Qt::Horizontal,"Prix_Menu");

    return model;

}


QSqlQueryModel * Crud_Menu::trie_id(){
   // Création d'une instance lorsque on a parle là des widgets
    QSqlQueryModel * model = new QSqlQueryModel();
    //
    model->setQuery("SELECT * FROM MENU order by idMenu ");// Récupération des données men table
    // Pour que l'affichage iji mnathem,les colonnes bahtha bathhom et mnathmin on fait comme ça :
    // Qt::horizontal manha table bel rekda ijiw les colonnes

    model->setHeaderData(0, Qt::Horizontal,"Id_Menu");

    model->setHeaderData(1, Qt::Horizontal,"Categorie_Menu");
    model->setHeaderData(2, Qt::Horizontal,"Nom_Menu");
    model->setHeaderData(3, Qt::Horizontal,"Prix_Menu");

    return model;

}



QSqlQueryModel * Crud_Menu::trie_nom(){
   // Création d'une instance lorsque on a parle là des widgets
    QSqlQueryModel * model = new QSqlQueryModel();
    //
    model->setQuery("SELECT * FROM MENU order by nomMenu ");// Récupération des données men table
    // Pour que l'affichage iji mnathem,les colonnes bahtha bathhom et mnathmin on fait comme ça :
    // Qt::horizontal manha table bel rekda ijiw les colonnes

    model->setHeaderData(0, Qt::Horizontal,"Id_Menu");

    model->setHeaderData(1, Qt::Horizontal,"Categorie_Menu");
    model->setHeaderData(2, Qt::Horizontal,"Nom_Menu");
    model->setHeaderData(3, Qt::Horizontal,"Prix_Menu");

    return model;

}

QSqlQueryModel * Crud_Menu::trie_categorie(){
   // Création d'une instance lorsque on a parle là des widgets
    QSqlQueryModel * model = new QSqlQueryModel();
    //
    model->setQuery("SELECT * FROM MENU order by categorieMenu ");// Récupération des données men table
    // Pour que l'affichage iji mnathem,les colonnes bahtha bathhom et mnathmin on fait comme ça :
    // Qt::horizontal manha table bel rekda ijiw les colonnes

    model->setHeaderData(0, Qt::Horizontal,"Id_Menu");

    model->setHeaderData(1, Qt::Horizontal,"Categorie_Menu");
    model->setHeaderData(2, Qt::Horizontal,"Nom_Menu");
    model->setHeaderData(3, Qt::Horizontal,"Prix_Menu");

    return model;

}
int Crud_Menu::total_menu() {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM MENU");

     query.exec();
     int rows = 0;
     while(query.next()) {
         rows = query.value(0).toInt();
     }

     return rows ;
}

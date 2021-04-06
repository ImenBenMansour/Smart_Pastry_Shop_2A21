#include "crud_recette.h"

Crud_Recette::Crud_Recette()
{

}

Crud_Recette::Crud_Recette(int idRecette,QString nomRecette,QString categorieRecette,QString ingredientsRecette)
{
    this->idRecette= idRecette;
    this->nomRecette=nomRecette;
    this->categorieRecette=categorieRecette;
    this->ingredientsRecette=ingredientsRecette;

}

bool Crud_Recette::ajouter_recette()
{
    QSqlQuery query;
    query.prepare("INSERT INTO RECETTE(idRecette,nomRecette,categorieRecette,ingredientsRecette)VALUES(:id,:nom,:categorie,:ingredients)");
    query.bindValue(":id",idRecette);
    query.bindValue(":nom",nomRecette);
    query.bindValue(":categorie",categorieRecette);
    query.bindValue(":ingredients",ingredientsRecette);
    return query.exec();

}

QSqlQueryModel * Crud_Recette::afficher_recette()
{
     QSqlQueryModel * model = new QSqlQueryModel();

     model->setQuery("SELECT * FROM RECETTE");
     model->setHeaderData(0, Qt::Horizontal,"Id_Recette");
     model->setHeaderData(1, Qt::Horizontal,"Nom_Recette");
     model->setHeaderData(2, Qt::Horizontal,"Categorie_Recette");
     model->setHeaderData(3, Qt::Horizontal,"Ingredients_Recette");
     return model;
}





bool Crud_Recette::supprimer_recette(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM RECETTE WHERE idRecette=:id");
    QString i=QString::number(id);
    query.bindValue(":id",i);
    return query.exec();
}

bool Crud_Recette::modifier_recette() {
    QSqlQuery query;
    query.prepare("UPDATE RECETTE  SET nomRecette =:nom, categorieRecette =:categorie, ingredientsRecette =:ingredients WHERE idRecette = :id");
    query.bindValue(":id",idRecette);
    query.bindValue(":nom",nomRecette);
    query.bindValue(":categorie",categorieRecette);
    query.bindValue(":ingredients",ingredientsRecette);
    return query.exec();
}


int Crud_Recette::total_recette() {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM RECETTE");

     query.exec();
     int rows = 0;
     while(query.next()) {
         rows = query.value(0).toInt();
     }

     return rows ;
}

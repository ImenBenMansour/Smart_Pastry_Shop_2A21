#ifndef CRUD_RECETTE_H
#define CRUD_RECETTE_H

#include <QVariant>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>

class Crud_Recette
{
private :
       int idRecette;
       QString nomRecette;
       QString categorieRecette;
       QString ingredientsRecette;

public:
    Crud_Recette();
    Crud_Recette(int,QString,QString,QString);

     //-----------Start GETTERS-------------//

    int getIdRecette(){return idRecette;}
    QString getNomRecette(){return nomRecette;}
    QString getCategorieRecette(){return categorieRecette;}
    QString getIngredientsRecette(){return ingredientsRecette;}

      //-----------End GETTERS-------------//


    //-----------Start SETTERS-------------//

    void setIdRecette(int idRecette){ this->idRecette=idRecette;}
    void setNomRecette(QString nomRecette){ this->nomRecette=nomRecette;}
    void setCategorieRecette(QString categorieRecette){ this->categorieRecette=categorieRecette;}
    void setIngredientsRecette(QString ingredientsRecette){ this->ingredientsRecette=ingredientsRecette;}

    //-----------End SETTERS-------------//

    bool ajouter_recette();
    bool modifier_recette();
    bool supprimer_recette(int id);
    QSqlQueryModel* afficher_recette();


    int total_recette();





};

#endif // CRUD_RECETTE_H

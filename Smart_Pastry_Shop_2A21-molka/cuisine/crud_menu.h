#ifndef CRUD_MENU_H
#define CRUD_MENU_H

#include <QVariant>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>


class Crud_Menu
{

    int idMenu;
    QString nomMenu;
    QString categorieMenu;
    double  prixMenu;


public:
    Crud_Menu();
    Crud_Menu(int,QString, QString, double);

         //-----------Start GETTERS-------------//

            int getIdMenu() { return idMenu;}
            QString getNomMenu() {return nomMenu;}
            QString getCategorieMenu() { return categorieMenu;}
            double getPrixMenu() { return prixMenu;}

        //-----------End GETTERS---------------//


        //-----------Start SETTERS-------------//

        void setIdMenu(int idMenu) { this->idMenu=idMenu;}
        void setNomMenu(QString nomMenu) { this->nomMenu=nomMenu;}
        void setCatgorieMenu(QString categorieMenu) { this->categorieMenu=categorieMenu;}
        void setPrixMenu(double prixMenu) { this->prixMenu=prixMenu;}

        //-----------End SETTERS---------------//


           bool ajouter_menu();
           bool modifier_menu();
           bool supprimer_menu(int);
           QSqlQueryModel * afficher_menu();
           void trie();



};

#endif // CRUD_MENU_H

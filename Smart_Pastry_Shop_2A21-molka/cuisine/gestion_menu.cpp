#include "gestion_menu.h"
#include "ui_gestion_menu.h"
#include "crud_menu.h"
#include <QMessageBox>

gestion_menu::gestion_menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_menu)
{
    ui->setupUi(this);
    this->setWindowTitle("GESTION DES MENUS");
}

gestion_menu::~gestion_menu()
{
    delete ui;
}void gestion_menu::on_pb_ajouter_clicked()
{

    int id = ui->le_id->text().toInt();
    QString nom = ui->le_nom->text();
    double prix = ui->le_prix->text().toDouble();
    QString categorie = ui->la_categorie->text();
    // Création d'un objet normal,on parle pas de widgets içi :
    Crud_Menu m;
    m = Crud_Menu(id,nom,categorie,prix);
    //
    bool test = m.ajouter_menu();

    if(test) {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                   QObject::tr("Menu ajouté !\n"
                        "click ok to exit"),QMessageBox::Ok);

    }
else{QMessageBox::information(nullptr, QObject::tr("database is open"),
                              QObject::tr("erreur d'ajout !\n"
                   "click ok to exit"),QMessageBox::Ok);}

}





void gestion_menu::on_pb_supprimer_clicked()
{
    int id = ui->text_delete->text().toInt();
    bool test = crudMenu->supprimer_menu(id);

    if(test) {
        QMessageBox::information(nullptr,"Supprimer un menu","le menu a été supprimé avec succès !");//Qwidget ==> les composants mt3 qt dima initliasation ta3 ay QWidget heya nullptr manha maytpointa ala chay
    }
    else {
        QMessageBox::information(nullptr,"Supprimer un menu ","suppression échouée !");//Qwidget ==> les composants mt3 qt dima initliasation ta3 ay QWidget heya nullptr;

    }



}

void gestion_menu::on_tabWidget_currentChanged(int index)// ki t7ot index = 1 ya3ni action tsir kif temchi teckliki ala colonne el indice mt3o 1 sinon mat7ot chy kol mat7el ay colone ysir execution mt3 méthode
{
    //  setmodel heya la partie blanche ta3 widget tableview
    ui->tableView->setModel(crudMenu->afficher_menu());

}



void gestion_menu::on_pb_modifier_clicked()
{
    int id = ui->lineEdit->text().toInt();
    QString nom = ui->lineEdit_2->text();
    QString categorie = ui->lineEdit_3->text();
    double prix = ui->lineEdit_4->text().toDouble();
    Crud_Menu m ;
    m = Crud_Menu(id,nom,categorie,prix);
    bool  test = m.modifier_menu();

    if(test) {
        QMessageBox::information(nullptr,"Modifier un menu","le menu a été modifié avec succès !");
    }
    else {
        QMessageBox::information(nullptr,"Modifier un menu ","Modification échouée !");

    }
}




#include "gestion_recette.h"
#include "ui_gestion_recette.h"
#include "crud_recette.h"
#include<QMessageBox>

gestion_recette::gestion_recette(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_recette)
{
    ui->setupUi(this);
    this->setWindowTitle("GESTION DES RECETTES");
}

gestion_recette::~gestion_recette()
{
    delete ui;
}

void gestion_recette::on_pb_ajouter1_clicked()
{
     int id=ui->le_id1->text().toInt();
     QString nom=ui->le_nom1->text();
     QString categorie=ui->la_categorie1->text();
     QString ingredients=ui->les_ingredients->text();
     Crud_Recette r;
     r=Crud_Recette(id,nom,categorie,ingredients);
     bool test=r.ajouter_recette();

     if(test) {
         QMessageBox::information(nullptr, QObject::tr("database is open"),
                                    QObject::tr("Recette ajoutée !\n"
                         "click ok to exit"),QMessageBox::Ok);

     }
 else{QMessageBox::information(nullptr, QObject::tr("database is open"),
                               QObject::tr("erreur d'ajout !\n"
                    "click ok to exit"),QMessageBox::Ok);}
}

void gestion_recette::on_tabWidget_currentChanged(int index)
{
   ui->tableView1->setModel(crudRecette->afficher_recette());
}

void gestion_recette::on_pb_supprimer1_clicked()
{
    int id = ui->text_delete1->text().toInt();
    bool test = crudRecette->supprimer_recette(id);

    if(test) {
        QMessageBox::information(nullptr,"Supprimer une recette","la recette a été supprimée avec succès !");
    }
    else {
        QMessageBox::information(nullptr,"Supprimer une recette ","suppression échouée !");

    }
}

void gestion_recette::on_pb_modifier1_clicked()
{
    int id = ui->lineEdit1->text().toInt();
    QString nom = ui->lineEdit_22->text();
    QString categorie = ui->lineEdit_33->text();
    QString ingredients = ui->lineEdit_44->text();
    Crud_Recette r ;
    r = Crud_Recette(id,nom,categorie,ingredients);
    bool  test = r.modifier_recette();

    if(test) {
        QMessageBox::information(nullptr,"Modifier un menu","la recette a été modifiée avec succès !");
    }
    else {
        QMessageBox::information(nullptr,"Modifier un menu ","Modification échouée !");

    }
}

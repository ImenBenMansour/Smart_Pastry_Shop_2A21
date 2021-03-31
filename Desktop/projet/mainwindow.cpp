#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseurs.h"
#include "produits.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include<QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabfournisseur->setModel(tmpfournisseur.afficher_fournisseur());
    ui->tabproduit->setModel(tmpProd.afficher_produit());


    connect(ui->pb_ajouter, SIGNAL(clicked(bool)), this, SLOT(on_pb_ajouter_clicked())); //ajout

    connect(ui->pb_supprimer, SIGNAL(clicked(bool)), this, SLOT(on_pb_supprimer_clicked())); //suppr

    connect(ui->pb_modifier, SIGNAL (clicked(bool)), this, SLOT(on_pb_modifier_collab_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
     QString nom= ui->lineEdit_nom_four->text();
     QString adresse= ui->lineEdit_adresse_four->text();
     int tel= ui->lineEdit_tel_four->text().toInt();
     QString mail= ui->lineEdit_mail_four->text();

    fournisseurs f(nom,adresse,tel,mail);
    bool test=f.ajouter_fournisseur();
    ui->tabfournisseur->setModel(tmpfournisseur.afficher_fournisseur());

    if(test){
        foreach(QLineEdit* le, findChildren<QLineEdit*>())
        { le->clear(); }

      QMessageBox::information(this, QObject::tr("Ajouter un fournisseur"),
      QObject::tr(" fournisseur ajouté.\n"
                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::information(this, QObject::tr("Ajouter un fournisseur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_pb_supprimer_clicked()
{
    QString nom= ui->lineEdit_nom_four_2->text();
    bool test=tmpfournisseur.supprimer_fournisseur(nom);
    ui->tabfournisseur->setModel(tmpfournisseur.afficher_fournisseur());//refresh

     if(test){
    foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
         le->clear();}

    QMessageBox::information(this, QObject::tr("Supprimer un fournisseur"),
            QObject::tr("fournisseur supprimé.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);

    }else
    QMessageBox::information(this, QObject::tr("Supprimer un fournisseur"),
            QObject::tr("Erreur !.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pb_modifier_clicked()
{
         QString nom= ui->lineEdit_nom_four_3->text();
         QString adresse= ui->lineEdit_adresse_four_3->text();
         int tel= ui->lineEdit_tel_four_3->text().toInt();
         QString mail= ui->lineEdit_mail_four_3->text();

        fournisseurs f(nom,adresse,tel,mail);

         bool test=f.modifier_fournisseur();
         ui->tabfournisseur->setModel(tmpfournisseur.afficher_fournisseur());

         if (test)
         {
             foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                  le->clear();}
             QMessageBox::information(this, QObject::tr("Modifier un fournisseur"),
                     QObject::tr("fournisseur modifié.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

         }else
             QMessageBox::critical(this, QObject::tr("Modifier un fournisseur"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}








void MainWindow::on_pb_ajouter_prod_clicked()
{
    QString id= ui->lineEdit_id_prod->text();
    QString nom= ui->lineEdit_nom_prod->text();
    int prix= ui->lineEdit_prix_prod->text().toInt();
    int quantite= ui->lineEdit_quantite_prod->text().toInt();

   produits p(id,nom,prix,quantite);
   bool test=p.ajouter_produit();
   ui->tabproduit->setModel(tmpProd.afficher_produit());

   if(test){
       foreach(QLineEdit* le, findChildren<QLineEdit*>())
       { le->clear(); }

     QMessageBox::information(this, QObject::tr("Ajouter un produit"),
     QObject::tr(" produit ajouté.\n"
                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else
       QMessageBox::information(this, QObject::tr("Ajouter un produit"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_supprimer_prod_clicked()
{
    QString id= ui->lineEdit_id_prod_2->text();
    bool test=tmpProd.supprimer_produit(id);
    ui->tabproduit->setModel(tmpProd.afficher_produit());//refresh

     if(test){
    foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
         le->clear();}

    QMessageBox::information(this, QObject::tr("Supprimer un produit"),
            QObject::tr("produit supprimé.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);

    }else
    QMessageBox::information(this, QObject::tr("produit un fournisseur"),
            QObject::tr("Erreur !.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_modifier_prod_clicked()
{
    QString id= ui->lineEdit_id_prod_3->text();
    QString nom= ui->lineEdit_nom_prod_3->text();
    int prix= ui->lineEdit_prix_prod_3->text().toInt();
    int quantite= ui->lineEdit_quantite_prod_3->text().toInt();

   produits p(id,nom,prix,quantite);

    bool test=p.modifier_produit();
    ui->tabproduit->setModel(tmpProd.afficher_produit());

    if (test)
    {
        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
             le->clear();}
        QMessageBox::information(this, QObject::tr("Modifier un produit"),
                QObject::tr("produit modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    }else
        QMessageBox::critical(this, QObject::tr("Modifier un produit"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_radioB_tri_id_clicked()
{
    ui->tabproduit->setModel(tmpProd.afficher_produit());
    ui->tabproduit->setModel(tmpProd.trier_id());
}

void MainWindow::on_radioB_tri_nom_clicked()
{
    ui->tabproduit->setModel(tmpProd.afficher_produit());
    ui->tabproduit->setModel(tmpProd.trier_nom());
}

void MainWindow::on_radioB_tri_prix_clicked()
{
    ui->tabproduit->setModel(tmpProd.afficher_produit());
    ui->tabproduit->setModel(tmpProd.trier_prix());
}

void MainWindow::on_pb_rechercher_clicked()
{
    QString nom = ui->lineEdit_nom_four_4->text();
    ui->tabfournisseur->setModel(tmpfournisseur.afficher_fournisseur());
}

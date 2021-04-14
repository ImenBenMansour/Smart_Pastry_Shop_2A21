#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseurs.h"
#include "produits.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include<QDialog>
#include <QFile>
#include <QFileDialog>
#include <QApplication>
#include <QTextDocument>
#include <QSqlQuery>
#include <QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
     ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabfournisseur->setModel(tmpfournisseur.afficher_fournisseur());
    ui->tabproduit->setModel(tmpProd.afficher_produit());
    ui->lineEdit_id_four->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->lineEdit_tel_four->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->lineEdit_nom_four->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->lineEdit_adresse_four->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    fournisseurs tmpfournisseur(ui->lineEdit_id_four->text(),ui->lineEdit_nom_four->text(),ui->lineEdit_adresse_four->text(),ui->lineEdit_tel_four->text().toInt(),ui->lineEdit_mail_four->text());
           QString id= ui->lineEdit_id_four->text();
           QString nom= ui->lineEdit_nom_four->text();
           QString adresse=ui->lineEdit_adresse_four->text();
           int tel=ui->lineEdit_tel_four->text().toInt();

        bool test=tmpfournisseur.ajouter_fournisseur();
             if(id==""||nom==""||adresse=="" ||tel==0 ||tmpfournisseur.testmail(tmpfournisseur.getMail())==false)
             {
                QMessageBox::critical(nullptr, QObject::tr("vide"),
                                                 QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

             }

               else if(test==true){
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                                QObject::tr("fournisseur ajoutée:\n"
                     "click ok to exit"),QMessageBox::Ok);
                tmpfournisseur. ajouter_fournisseur();
               ui->tabfournisseur->setModel(tmpfournisseur.afficher_fournisseur());}
             else{
                 QMessageBox::information(nullptr, QObject::tr("database is open"),
                                           QObject::tr("fournisseur existe deja:\n"
                                "click ok to exit"),QMessageBox::Ok);
             }


}



void MainWindow::on_pb_supprimer_clicked()
{

    QString id= ui->lineEdit_id_four_2->text();
    bool test=tmpfournisseur.supprimer_fournisseur(id);
    ui->tabfournisseur->setModel(tmpfournisseur.afficher_fournisseur());  //refresh

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
         QString id= ui->lineEdit_id_four_3->text();
         QString nom= ui->lineEdit_nom_four_3->text();
         QString adresse= ui->lineEdit_adresse_four_3->text();
         int tel= ui->lineEdit_tel_four_3->text().toInt();
         QString mail= ui->lineEdit_mail_four_3->text();

        fournisseurs f(id,nom,adresse,tel,mail);

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





void MainWindow::on_pb_rechercher_id_clicked()
{
    QString id = ui->lineEdit_id_four_4->text();
    ui->four_trouve->setModel(tmpfournisseur.afficher_four_id(id));
}

void MainWindow::on_pb_rechercher_nom_clicked()
{
    QString nom = ui->lineEdit_nom_four_4->text();
    ui->four_trouve->setModel(tmpfournisseur.afficher_four_nom(nom));
}

void MainWindow::on_pb_rechercher_adresse_clicked()
{
    QString adresse = ui->lineEdit_adresse_four_4->text();
    ui->four_trouve->setModel(tmpfournisseur.afficher_four_adr(adresse));
}







void MainWindow::on_pb_imprimer_clicked()
{
    QPdfWriter pdf("C:/Users/HP/Desktop/projet/Pdfproduit.pdf");
                             QPainter painter(&pdf);
                            int i = 4000;
                                 painter.setPen(Qt::red);

                                 painter.setFont(QFont("Arial", 30));
                                 painter.drawText(2300,1200,"Liste Des produit");
                                 painter.setPen(Qt::black);
                                 painter.setFont(QFont("Arial", 50));
                                 painter.drawRect(1000,200,7000,2000);
                                 painter.drawRect(0,3000,9600,500);
                                 painter.setFont(QFont("Arial", 9));
                                 painter.drawText(300,3300,"ID");
                                 painter.drawText(2300,3300,"NOM");
                                 painter.drawText(4300,3300,"PRIX");
                                 painter.drawText(6300,3300,"QUANTITE");




                                 QSqlQuery query;
                                 query.prepare("select * from PRODUIT");
                                 query.exec();
                                 while (query.next())
                                 {
                                     painter.drawText(300,i,query.value(0).toString());
                                     painter.drawText(2300,i,query.value(1).toString());
                                     painter.drawText(4300,i,query.value(2).toString());
                                     painter.drawText(6300,i,query.value(3).toString());




                                    i = i +500;
                                 }
                                 int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                                     QMessageBox::Yes |  QMessageBox::No);
                                     if (reponse == QMessageBox::Yes)
                                     {
                                         QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/HP/Desktop/projet/Pdfproduit.pdf"));

                                         painter.end();
                                     }
                                     else
                                     {
                                          painter.end();
}}

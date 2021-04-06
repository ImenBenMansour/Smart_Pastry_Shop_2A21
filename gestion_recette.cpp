#include "gestion_recette.h"
#include "ui_gestion_recette.h"
#include "crud_recette.h"
#include<QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include "statistics.h"
#include<QPixmap>
gestion_recette::gestion_recette(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_recette)
{
    ui->setupUi(this);
    this->setWindowTitle("GESTION DES RECETTES");

    if(ui->le_nom1->text() == " ") {
        QMessageBox::information(nullptr, QObject::tr("Verifier les champs"),
                                   QObject::tr("champ id recette ne doit etre pas vide"
                        "click ok to exit"),QMessageBox::Ok);

    }

    ui->le_id1->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
        ui->le_nom1->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->la_categorie1->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->les_ingredients->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
         ui->lineEdit1->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
        ui->lineEdit_22->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->lineEdit_33->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->lineEdit_44->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
         ui->text_delete1->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));


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

void gestion_recette::on_lineEdit1_textChanged(const QString &arg1)
{  QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM recette  WHERE IDRECETTE LIKE'"+arg1+"%' or NOMRECETTE  LIKE'"+arg1+"%' or CATEGORIERECETTE LIKE'"+arg1+"%' or INGREDIENTSRECETTE LIKE'"+arg1+"%' ");
     query->exec();
     if (query->next()) { }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         ui->lineEdit1->clear();}

}

void gestion_recette::on_text_delete1_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        query->prepare("SELECT * FROM recette  WHERE IDRECETTE LIKE'"+arg1+"%' or NOMRECETTE  LIKE'"+arg1+"%' or CATEGORIERECETTE LIKE'"+arg1+"%' or INGREDIENTSRECETTE LIKE'"+arg1+"%' ");
         query->exec();
         if (query->next()) { }
         else {
             QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                             QObject::tr("NO MATCH FOUND !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->text_delete1->clear();}

}

void gestion_recette::on_pb_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/ASUS/Desktop/cuisine/cuisinePdf.pdf");

                          QPainter painter(&pdf);
                         int i = 4000;
                              painter.setPen(Qt::red);
                              painter.setFont(QFont("Arial", 30));
                              painter.drawText(2300,1200,"Liste Des Recettes");
                              painter.setPen(Qt::black);
                              painter.setFont(QFont("Arial", 50));
                             // painter.drawText(1100,2000,afficheDC);
                              painter.drawRect(1500,200,7300,2600);
                              painter.drawPixmap(QRect(100,700,600,600),QPixmap("C:/Users/ASUS/Desktop/cuisine/150123410_1102641506814079_4892972152459660250_n.png"));
                              painter.drawRect(0,3000,9600,500);
                              painter.setFont(QFont("Arial", 9));
                              painter.drawText(300,3300,"ID_RECETTE");
                              painter.drawText(2300,3300,"NOM_RECETTE");
                              painter.drawText(4300,3300,"CATEGORIE_RECETTE");
                              painter.drawText(6300,3300,"INGREDIENTS_RECETTE");




                              QSqlQuery query;
                              query.prepare("select * from RECETTE");
                              query.exec();
                              while (query.next())
                              {
                                  painter.drawText(300,i,query.value(0).toString());
                                  painter.drawText(2300,i,query.value(1).toString());
                                  painter.drawText(4300,i,query.value(2).toString());
                                  painter.drawText(6300,i,query.value(3).toString());




                                 i = i +500;
                              }
                              int reponse = QMessageBox::question(this, "Génération PDF", "<PDF Enregistré>...Voudrez vous Afficher Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                  if (reponse == QMessageBox::Yes)
                                  {
                                      QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/cuisine/cuisinePdf.pdf"));

                                      painter.end();
                                  }
                                  if (reponse == QMessageBox::No)
                                  {
                                       painter.end();
                                  }
}

void gestion_recette::on_pushButton_4_clicked()
{
    statistics *g = new statistics(this);
    g->show();
}

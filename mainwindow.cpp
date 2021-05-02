#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
#include<QMessageBox>
#include"QApplication"
#include<QIntValidator>
#include"promotion.h"
#include<QComboBox>
#include <QPixmap>
#include  <QSqlQuery>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

#include "cartefid.h"
#include "clientfid.h"
#include"QApplication"
#include<QMessageBox>
#include <QIntValidator>
#include "smtp.h"
#include <QtNetwork>
#include <QSslSocket>
#include<QObject>
#include <QSqlQuery>
#include<QtCharts>
#include<QPieSeries>
#include<QPieSlice>
//#include <QSound>
//malek

#include "reservation.h"
#include<QMessageBox>
#include"QApplication"
#include<QIntValidator>
#include"commande.h"
#include  <QSqlQuery>
/*#include<QtCharts>
#include<QPieSeries>
#include<QPieSlice>*/
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>
#include"chat.h"
//yassin
#include "employe.h"
#include "poste.h"
//molka
#include "crud_equipement.h"
#include<QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include "statistics.h"
#include <QPixmap>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include "crud_menu.h"
#include <QMessageBox>
#include "crud_menu.h"
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include "crud_recette.h"
#include<QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>

#include <QPixmap>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>

#include<QMediaPlayer>
#include<QFileDialog>
#include<QVideoWidget>
#include<QLayout>
#include<QVBoxLayout>
#include<QBoxLayout>

#include"video_play.h"
#include<QDebug>
//riadh
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
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    ui->tab_rec->setModel(R.afficher());
    ui->tableView->setModel(R.afficher());
    ui->tab_prom->setModel(P.afficher2());
     ui->aa->setModel(P.afficher2());
    ui->le_id_rec->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->le_des_rec->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->le_id2->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->le_nom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->le_id_supp2->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->id_modii2->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->nom_modi->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->le_id_supp->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->le_id_modi->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->le_des_modi->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));

   /* QPixmap pix("C:/Users/lenovo/Pictures/fond-mental-marron_53876-88822.jpg");
    pix = pix.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pix);
    this->setPalette(palette);
*/

    //dhia
    ui->tab_cartefid->setModel(E.afficher());
    ui->tab_cartefid_2->setModel(E.afficher());
    ui->stackedWidget->setCurrentIndex(0);
   // ui->tabWidget->setCurrentIndex(0);
    ui->tab_client->setModel(C.afficher2("XYZ","XYZ","XYZ"));
    ui->tableView_2->setModel(C.afficher2("XYZ","XYZ","XYZ"));
    ui->le_cin->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));

    ui->le_prenom->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->le_cin_supp->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->le_cin_modifier->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->le_nom_modifier->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->le_prenom_modifier->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));



    ui->c_cin->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->c_nom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->c_prenom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->c_num->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->c_supp->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));


    ui->c_cin_modifier->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->c_nom_modifier->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->c_prenom_modifier->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->c_num_modifier->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));

//yassin
    ui->id_line->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->line_nom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->line_datenaissance->setValidator(new QRegExpValidator(QRegExp("[0-9/]{15}")));
    ui->line_tel->setValidator(new QRegExpValidator(QRegExp("[0-9]{15}")));
  //  ui->line_tel->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->line_adresse->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{30}")));
   // ui->line_mdp->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]")));
    ui->line_id_poste->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    //controle de saisie poste
    ui->line_idposte->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->line_nbheures->setValidator(new QRegExpValidator(QRegExp("[0-9]{4}")));
    ui->linejourconges->setValidator(new QRegExpValidator(QRegExp("[0-9]{4}")));
    ui->line_salaire->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->line_prime->setValidator(new QRegExpValidator(QRegExp("[0-9]{20}")));
//molka
    this->setWindowTitle("GESTION DES EQUIPEMENTS");
        ui->le_ide->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
        ui->le_nome->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->le_quantitee->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
        ui->le_etate->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->ide_mod->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
        ui->nom_mod_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->quantite_mod_2->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
        ui->etate_mod->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));

        this->setWindowTitle("GESTION DES MENUS");
        ui->le_id->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
            ui->le_nom_3->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
            ui->la_categorie->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
            ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
            ui->text_delete->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
            ui->lineEdit_3->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
            ui->lineEdit_4->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
            ui->le_prix->setValidator(new QRegExpValidator(QRegExp("^[0-9]*(\.[0-9]+)?$")));

            this->setWindowTitle("GESTION DES RECETTES");

           /* if(ui->le_nom1->text() == " ") {
                QMessageBox::information(nullptr, QObject::tr("Verifier les champs"),
                                           QObject::tr("champ id recette ne doit etre pas vide"
                                "click ok to exit"),QMessageBox::Ok);

            }*/

                ui->le_id1->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
                ui->le_nom1->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
                ui->la_categorie1->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
                ui->les_ingredients->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
                 ui->lineEdit1->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
                ui->lineEdit_22->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
                ui->lineEdit_33->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
                ui->lineEdit_44->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
                 ui->text_delete1->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));


                 mediaPlayer = new QMediaPlayer(this);
                 videoWidget = new QVideoWidget(this);
                 mediaPlayer->setVideoOutput(videoWidget);
                // ui->verticalLayout->inserWidget(0,videoWidget);

                 /*auto L=static_cast<QVBoxLayout *>(layout());
                 L->insertWidget(0,videoWidget);*/

                 connect(mediaPlayer,&QMediaPlayer::positionChanged,[&](qint64 pos){
                     ui->avance->setValue(pos);
                 });
                connect(mediaPlayer,&QMediaPlayer::durationChanged,[&](qint64 dur){
                        ui->avance->setMaximum(dur);
                        mediaPlayer->setPosition(dur/2);

                });
                //riadh

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
    reclamation R(ui->le_id_rec->text().toInt(),ui->le_des_rec->text(),ui->le_mail_rec->text(),ui->le_dat->date());
       int id_rec= ui->le_id_rec->text().toInt();
       QString des_rec= ui->le_des_rec->text();
    bool test=R.ajouter();
         if(id_rec==0||des_rec==""||R.testmail(R.getmail_rec())==false)
         {
            QMessageBox::critical(nullptr, QObject::tr("vide"),
                                             QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

         }

           else if(test==true){
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("reclamation ajoutée:\n"
                 "click ok to exit"),QMessageBox::Ok);
            ui->tab_rec->setModel(R.afficher());
              ui->tableView->setModel(R.afficher());
         }
         else{QMessageBox::information(nullptr, QObject::tr("database is open"),
                                       QObject::tr("reclamation existe deja:\n"
                            "click ok to exit"),QMessageBox::Ok);}
 N.notification_ajoutReclamation();
             R.ajouter();




}

/*void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}*/

void MainWindow::on_pb_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

}

void MainWindow::on_pb_supprimer_clicked()
{  reclamation R1;
    R1.setid_rec(ui->le_id_supp->text().toInt());
    int id_rec= ui->le_id_supp->text().toInt();
     N.notification_supprimerReclamation();
    bool test1=R1.supprimer(R1.getid_rec());



   if(id_rec==0)
    {
       QMessageBox::critical(nullptr, QObject::tr("vide"),
                                        QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

    }



    else if(test1==true)
       {QMessageBox::information(nullptr,QObject::tr("datavase is open"),
                                 QObject::tr("reclamation supprimée:\n"
         "click ok to exit"),QMessageBox::Ok);
     ui->tab_rec->setModel(R.afficher());
       ui->tableView->setModel(R.afficher());
    }
       else
    {QMessageBox::critical(nullptr,QObject::tr("database is open"),
                              QObject::tr("reclamation non supprimée:\n"
           "click ok to exit"),QMessageBox::Ok);}
   R.supprimer(R.getid_rec());
}

void MainWindow::on_pb_modifier_clicked()
{
    reclamation R2;
    R2.setid_rec(ui->le_id_modi->text().toInt());
        R2.setdes_rec(ui->le_des_modi->text());
        R2.setmail_rec(ui->le_mail_modi->text());
        R2.setdat(ui->date_modi->date());

       R2.modifier(R2.getid_rec(),R2.getdes_rec(),R2.getmail_rec(),R2.getdat());
       int id_rec= ui->le_id_modi->text().toInt();
       QString des_rec= ui->le_des_modi->text();
       N.notification_modifierReclamation();
       if(id_rec==0||des_rec==""||R2.testmail(R2.getmail_rec())==false)
            {
               QMessageBox::critical(nullptr, QObject::tr("vide"),
                                                QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

            }

       else {
           QMessageBox::information(nullptr, QObject::tr("database is open"),
                   QObject::tr("reclamation modifier:\n"
        "click ok to exit"),QMessageBox::Ok);
           ui->tab_rec->setModel(R.afficher());
             ui->tableView->setModel(R.afficher());

       }


     }
void MainWindow::on_pb_retour2_clicked()
{
     ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pb2_ajouter_clicked()
{
    promotion P(ui->le_id2->text().toInt(),ui->le_nom->text(),ui->dat_cre->date(),ui->dat_exp->date());
           int id= ui->le_id2->text().toInt();
           QString nom= ui->le_nom->text();
           N.notification_ajoutPromotion();
        bool test=P.ajouter2();
             if(id==0||nom=="")
             {
                QMessageBox::critical(nullptr, QObject::tr("vide"),
                                                 QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

             }

               else if(test==true){
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                                QObject::tr("promotion ajoutée:\n"
                     "click ok to exit"),QMessageBox::Ok);
                ui->tab_prom->setModel(P.afficher2());
                  ui->tableView->setModel(R.afficher());
             }
             else{QMessageBox::information(nullptr, QObject::tr("database is open"),
                                           QObject::tr("promotion existe deja:\n"
                                "click ok to exit"),QMessageBox::Ok);}

                 P.ajouter2();





}

/*void MainWindow::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}*/



void MainWindow::on_pb_retour3_clicked()
{
     ui->stackedWidget->setCurrentIndex(10);
}



void MainWindow::on_pb2_supprimer_clicked()
{

  promotion P1;
        P1.setid(ui->le_id_supp2->text().toInt());
        int id= ui->le_id_supp2->text().toInt();
        N.notification_supprimerPromotion();
        bool test2=P1.supprimer2(P1.getid());



       if(id==0)
        {
           QMessageBox::critical(nullptr, QObject::tr("vide"),
                                            QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

        }




        else if(test2)
           {QMessageBox::information(nullptr,QObject::tr("datavase is open"),
                                     QObject::tr("promotion supprimée:\n"
             "click ok to exit"),QMessageBox::Ok);
         ui->tab_prom->setModel(P.afficher2());
           ui->tableView->setModel(R.afficher());
          ui->aa->setModel(P.afficher2());
        }
           else
        {QMessageBox::critical(nullptr,QObject::tr("database is open"),
                                  QObject::tr("promotion non supprimée:\n"
               "click ok to exit"),QMessageBox::Ok);}



       P1.supprimer2(P1.getid());







}

void MainWindow::on_pushButton_3_clicked()
{

   promotion P2;
    P2.setid(ui->id_modii2->text().toInt());
        P2.setnom(ui->nom_modi->text());
        P2.setdat_cre(ui->dat_cre_modi->date());
        P2.setdat_exp(ui->dat_exp_modi->date());

       P2.modifier2(P2.getid(),P2.getnom(),P2.getdat_cre(),P2.getdat_exp());
       int id= ui->id_modii2->text().toInt();
       QString nom= ui->nom_modi->text();
       N.notification_modifierPromotion();
       if(id==0||nom=="")
            {
               QMessageBox::critical(nullptr, QObject::tr("vide"),
                                                QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

            }

       else {
           QMessageBox::information(nullptr, QObject::tr("database is open"),
                   QObject::tr("promotion modifie:\n"
        "click ok to exit"),QMessageBox::Ok);
           ui->tab_prom->setModel(P.afficher2());
             ui->tableView->setModel(R.afficher());

       }




    /*promotion P2;
    P2.setnom(ui->nom_modi->text());
        P2.setdat_cre(ui->dat_cre_modi->date());
        P2.setdat_exp(ui->dat_exp_modi->date());
        P2.setid(ui->id_modii2->text().toInt());


       P2.modifier2(P2.getid(),P2.getnom(),P2.getdat_cre(),P2.getdat_exp());
       QMessageBox::information(nullptr, QObject::tr("database is open"),
               QObject::tr("promotion modifier:\n"
    "click ok to exit"),QMessageBox::Ok);
       ui->tab_prom->setModel(P.afficher2());
       ui->aa->setModel(P.afficher2());*/
}

void MainWindow::on_pb_retour4_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}


void MainWindow::on_radioButton_clicked()
{
     ui->tab_prom->setModel( P.trier_id());
}

void MainWindow::on_radioButton_2_clicked()
{
     ui->tab_prom->setModel( P.trier_nom());
}

void MainWindow::on_radioButton_3_clicked()
{
     ui->tab_prom->setModel( P.trier_date());
}



void MainWindow::on_pdf_clicked()
{


        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
           if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("reclamation.pdf"); }

           QPrinter printer(QPrinter::PrinterResolution);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(fileName);

           QTextDocument doc;
           QSqlQuery q;
           q.prepare("SELECT * FROM reclamation ");
           q.exec();
           QString pdf="<br> <img src='file:///C:/Users/dhia/Downloads/150123410_1102641506814079_4892972152459660250_n.png' height='100' width='100'/> <h1  style='color:brown'> <i> <u>    LISTE DES RECALAMATIONS  </u> </i> <br></h1>\n <br> <table border>   <tr>  <th> ID_REC </th>      <th> DES_REC </th>    <th> MAIL_REC </th> <th> DATE  </th>  </tr>" ;


           while ( q.next()) {
               int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                   QMessageBox::Yes |  QMessageBox::No);
                   if (reponse == QMessageBox::Yes)
                   {
                       QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/dhia/Documents/pp - Copie/reclamation.pdf"));

                       //pdf.end();
                   }
                   else
                   {
                        pdf.end();
                   }
                pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>  <td>   " + q.value(1).toString() +"</td>  <td>" +q.value(2).toString() +"  "" " "</td>      <td>     "+q.value(3).toString()+"--------"+"</td>       <td>"+q.value(4).toString()+" <td>"+q.value(5).toString()+" <td>"+q.value(6).toString()+"       </td>"   ;
           }

           doc.setHtml(pdf);
           //doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
           //doc.print(&printer);








    /*QPdfWriter pdf("C:/Users/lenovo/PdfReclamation.pdf");
                         QPainter painter(&pdf);
                        int i = 4000;
                             painter.setPen(Qt::red);

                             painter.setFont(QFont("Arial", 30));
                             painter.drawText(2300,1200,"Liste Des Reclamtions");
                             painter.setPen(Qt::black);
                             painter.setFont(QFont("Arial", 50));
                            // painter.drawText(1100,2000,afficheDC);
                             painter.drawRect(1000,200,7000,2000);
                            // painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/lenovo/Downloads/Dulcis.ai"));
                             painter.drawRect(0,3000,9600,500);
                             painter.setFont(QFont("Arial", 9));
                             painter.drawText(300,3300,"ID_REC");
                             painter.drawText(2300,3300,"MAIL_REC");
                             painter.drawText(4300,3300,"DES_REC");
                             painter.drawText(6300,3300,"DAT");
                            // painter.drawText(8000,3300,"MAIL");



                             QSqlQuery query;
                             query.prepare("select * from RECLAMATION");
                             query.exec();
                             while (query.next())
                             {
                                 painter.drawText(300,i,query.value(0).toString());
                                 painter.drawText(2300,i,query.value(1).toString());
                                 painter.drawText(4300,i,query.value(2).toString());
                                 painter.drawText(6300,i,query.value(3).toString());
                                 //painter.drawText(8000,i,query.value(4).toString());



                                i = i +500;
                             }
                             int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                                 QMessageBox::Yes |  QMessageBox::No);
                                 if (reponse == QMessageBox::Yes)
                                 {
                                     QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/lenovo/PdfRecalamtion.pdf"));

                                     painter.end();
                                 }
                                 else
                                 {
                                      painter.end();
                                 }*/
}

void MainWindow::on_le_id_supp2_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        query->prepare("SELECT * FROM promotion  WHERE ID  LIKE'"+arg1+"%' or NOM  LIKE'"+arg1+"%' or DAT_CRE LIKE'"+arg1+"%' or DAT_EXP LIKE'"+arg1+"%' ");
         query->exec();
         if (query->next()) { }
         else {
             QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                             QObject::tr("NO MATCH FOUND !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->le_id_supp2->clear();}

}

void MainWindow::on_pushButton_4_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_5_clicked()
{
     ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_6_clicked()
{
 ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_id_modii2_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        query->prepare("SELECT * FROM promotion  WHERE ID  LIKE'"+arg1+"%' or NOM  LIKE'"+arg1+"%' or DAT_CRE LIKE'"+arg1+"%' or DAT_EXP LIKE'"+arg1+"%' ");
         query->exec();
         if (query->next()) { }
         else {
             QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                             QObject::tr("NO MATCH FOUND !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->id_modii2->clear();}

}



void MainWindow::on_le_id_supp_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        query->prepare("SELECT * FROM reclamation  WHERE ID_REC  LIKE'"+arg1+"%' or DES_REC  LIKE'"+arg1+"%' or MAIL_REC LIKE'"+arg1+"%' or DAT LIKE'"+arg1+"%' ");
         query->exec();
         if (query->next()) { }
         else {
             QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                             QObject::tr("NO MATCH FOUND !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->le_id_supp->clear();}
}

void MainWindow::on_le_id_modi_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        query->prepare("SELECT * FROM reclamation  WHERE ID_REC  LIKE'"+arg1+"%' or DES_REC  LIKE'"+arg1+"%' or MAIL_REC LIKE'"+arg1+"%' or DAT LIKE'"+arg1+"%' ");
         query->exec();
         if (query->next()) { }
         else {
             QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                             QObject::tr("NO MATCH FOUND !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->le_id_modi->clear();}
}

/*void MainWindow::on_recherche_textChanged(const QString &arg1)
{reclamation R;
    ui->tab_rec->setVisible(false);
    QSqlQuery *query=new QSqlQuery("SELECT * from RECLAMATION");
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery(*query);
    ui->tab_rec->setModel(model);
    ui->tab_rec->show();
    ui->tab_rec->resizeColumnsToContents();
    ui->tab_rec->setVisible(true);


 R.cleartable(ui->tab_rec);

int id_rec = ui->recherche->text().toInt();

R.rechercher(ui->tab_rec,id_rec);

if(ui->recherche->text().isEmpty())
{

          ui->tab_rec->setModel(R.afficher());
}

}*/

void MainWindow::on_rech_id_clicked()
{
    QString id_rec = ui->id_rech->text();
        ui->tab_rec->setModel(R.afficher_id_rec(id_rec));
}

void MainWindow::on_rech_mail_clicked()
{
    QString mail_rec = ui->mail_rech->text();
        ui->tab_rec->setModel(R.afficher_mail_rec(mail_rec));
}

void MainWindow::on_rech_des_clicked()
{
    QString des_rec = ui->des_rech->text();
        ui->tab_rec->setModel(R.afficher_des_rec(des_rec));
}

void MainWindow::on_pushButton_8_clicked()
{
    reclamation R;

        ui->tab_rec->setModel(R.reset());
}


//dhia

void MainWindow::on_pushButton_2clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
void MainWindow::on_pb_ajouter_2_clicked()
{bool test;
    Cartefid E(ui->le_cin->text().toInt(),ui->le_nom_2->text(),ui->le_prenom->text().toInt(),ui->dateTimeEdit->date());
   if(ui->le_nom_2->text().isEmpty())
    {
       QMessageBox::critical(nullptr, QObject::tr("vide"),
                                        QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
                                        test=false;
    }

      else{
       /*QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("cartefid ajoutée:\n"
            "click ok to exit"),QMessageBox::Ok);*/

       test= E.ajouter();}
   if(test==true){
           QMessageBox::information(nullptr, QObject::tr("database is open"),
                           QObject::tr("carte ajoutée:\n"
                "click ok to exit"),QMessageBox::Ok);

           ui->tab_cartefid->setModel(E.afficher());}
        else{QMessageBox::information(nullptr, QObject::tr("database is open"),
                                      QObject::tr(" impossible d'ajouter:\n"
                           "click ok to exit"),QMessageBox::Ok);

   ui->tab_cartefid->setModel(E.afficher());
ui->tab_cartefid_2->setModel(E.afficher());

}
ui->tab_cartefid->setModel(E.afficher());
ui->tab_cartefid_2->setModel(E.afficher());
}


void MainWindow::on_td_supp_clicked()
{
    bool test;
       Cartefid E1; E1.setcin(ui->le_cin_supp->text().toInt());
        test =E1.supprimer(E1.getcin());

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("cartefid supprimé:\n"
     "click ok to exit"),QMessageBox::Ok);
    ui->tab_cartefid->setModel(E.afficher());
    ui->tab_cartefid->setModel(E.afficher2());
}

void MainWindow::on_pb_modifier_2_clicked()
{
    Cartefid E2; E2.setcin(ui->le_cin_modifier->text().toInt());
    E2.setpoint(ui->le_nom_modifier->text());
    E2.setid_carte(ui->le_prenom_modifier->text().toInt());
    E2.setda(ui->dateTimeEdit_2->date());

   E2.modifier(E2.getcin(),E2.getpoint(),E2.getid_carte(),E2.getda());
    QMessageBox::information(nullptr, QObject::tr("database is open"),
            QObject::tr("cartefid modifier:\n"
 "click ok to exit"),QMessageBox::Ok);
    ui->tab_cartefid->setModel(E.afficher());
     ui->tab_cartefid->setModel(E.afficher());
}

void MainWindow::on_pushButton_3_2clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_a_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_bb_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_2_2clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}



void MainWindow::on_ajouterclie_clicked()

    {  bool test;
     Clientfid C(ui->c_cin->text().toInt(),ui->c_nom->text(),ui->c_prenom->text(),ui->c_num->text().toInt(),ui->c_mail->text());
        srand (time(NULL));
                 QDate d = QDate::currentDate() ;
                  QString datee =d.toString("dd / MM / yyyy ") ;
                  QString fn="ajouter" ;
                 QString nom1 = ui->le_nom->text();
               projeth pp(nom1,datee,fn) ;
               bool test1=pp.ajoutehis() ;
     if(C.testmail(C.getmail())==false)
     {
        QMessageBox::critical(nullptr, QObject::tr("vide"),
                                         QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

     }


       else
     {
        test=C.ajouter();

     }
     if(test==true){
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("client ajoutée:\n"
             "click ok to exit"),QMessageBox::Ok);
        ui->tab_client->setModel(C.afficher2("XYZ","XYZ","XYZ"));
      ui->tableView_2->setModel(C.afficher2("XYZ","XYZ","XYZ"));}
     else{QMessageBox::information(nullptr, QObject::tr("database is open"),
                                   QObject::tr("client existe deja:\n"
                        "click ok to exit"),QMessageBox::Ok);}



    }






void MainWindow::on_supp_clicked()
{Clientfid C;

    int cin = ui->c_supp->text().toInt();
      bool test= C.supprimer(cin);

        if (test)
        {

            ui->tab_client->setModel(C.afficher2("XYZ","XYZ","XYZ"));
             ui->tableView_2->setModel(C.afficher2("XYZ","XYZ","XYZ"));

            QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("client Successfully Deleted!\n"), QMessageBox::Ok);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Failed"), QObject::tr("Failed to delete client\n"
                                                                              "Click cancel."),
                                  QMessageBox::Cancel);
        }




     /*  Clientfid C;
    C.setcin(ui->c_supp->text().toInt());

      bool test1(C.supprimer(C.getcin())) ;
      //test1=C.supprimer(C.getcin());
      if(test1){


              QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                      QObject::tr("clientfid supprimé.\n"
           "click cancel to exit"),QMessageBox::Cancel);
          ui->tab_client->setModel(C.afficher2("XYZ","XYZ"));}
      else{QMessageBox::critical(nullptr, QObject::tr("supp erreur"),
                                    QObject::tr("client n'existe plus:\n"
                         "click cancel to exit:"),QMessageBox::Cancel);}*/







}

void MainWindow::on_modifierclient_clicked()
{
    Clientfid C2;
    C2.setcin(ui->c_cin_modifier->text().toInt());
    C2.setnom(ui->c_nom_modifier->text());
    C2.setprenom(ui->c_prenom_modifier->text());
    C2.setnum(ui->c_num_modifier->text().toInt());
    C2.setmail(ui->c_mail_modifier->text());

   C2.modifier(C2.getcin(),C2.getnom(),C2.getprenom(),C2.getnum(),C2.getmail());

   bool test2=C2.modifier(C2.getcin(),C2.getnom(),C2.getprenom(),C2.getnum(),C2.getmail());

   if(test2==true){
    QMessageBox::information(nullptr, QObject::tr("database is open"),
            QObject::tr("client modifier:\n"
 "click ok to exit"),QMessageBox::Ok);
    ui->tab_client->setModel(C2.afficher2("XYZ","XYZ","XYZ"));
    ui->tableView_2->setModel(C.afficher2("XYZ","XYZ","XYZ"));}
   else{QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("client nn:\n"
                      "click ok to exit"),QMessageBox::Ok);}


}

void MainWindow::on_pushButton_4_2clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_pushButton_mail_3_clicked()
{

    Smtp* smtp = new Smtp("adel9860@gmail.com", "dhia1620", "smtp.gmail.com", 465);
               connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


             smtp->sendMail("adel9860@gmail.com", "dhia1620" , "0A3DIN NTHABTOU OU BARA","testtttt");




}

void MainWindow::on_pushButton_5_2_clicked()
{ QString cin =ui->rechercher_clientfid->text().trimmed();
    QString nom =ui->rech_nom->text().trimmed();
    QString prenom=ui->rech_pre->text().trimmed();

    if (cin=="" && nom!="" && prenom!="")
    {
      ui->tab_client->setModel(C.afficher2("XYZ",nom,prenom));
    }
    if (cin !="" && nom=="" && prenom!="")
    {
      ui->tab_client->setModel(C.afficher2(cin,"XYZ",prenom));
    }
    if(cin!="" && nom!="" && prenom=="")
    {
        ui->tab_client->setModel(C.afficher2(cin,nom,"XYZ"));
    }
    if(cin!="" && nom=="" && prenom=="")
    {
        ui->tab_client->setModel(C.afficher2(cin,"XYZ","XYZ"));
    }
    if(cin=="" && nom!="" && prenom=="")
    {
        ui->tab_client->setModel(C.afficher2("XYZ",nom,"XYZ"));
    }
    if(cin=="" && nom=="" && prenom!="")
    {
        ui->tab_client->setModel(C.afficher2("XYZ","XYZ",prenom));
    }
    if(cin!="" && nom!="" && prenom!="")
    {
        ui->tab_client->setModel(C.afficher2(cin,nom,prenom));
    }
    if(cin=="" && nom!="" && prenom!="")
    {
        ui->tab_client->setModel(C.afficher2("XYZ",nom,prenom));
    }
    if(cin!="" && nom=="" && prenom!="")
    {
        ui->tab_client->setModel(C.afficher2(cin,"XYZ",prenom));
    }
    if(cin!="" && nom!="" && prenom=="")
    {
        ui->tab_client->setModel(C.afficher2(cin,nom,"XYZ"));
    }


   /* Clientfid C;
        int re = ui->rechercher_clientfid->text().toInt();

        ui->tab_client->setModel(C.rechercher(re));*/
}

void MainWindow::on_pushButton_7_2_clicked()
{
    Clientfid C;

    ui->tab_client->setModel(C.reset());
}
/*void MainWindow::statistique_med()
{

    QPieSeries *series = new QPieSeries();
    QSqlQuery qry("SELECT * FROM CARTEFID");

    while(qry.next())
    {
        series->append(qry.value(1).toString(),qry.value(2).toInt());
    }



    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("statistique selon SALAIRE");

    QChartView *chartview = new QChartView(chart);
    chartview->setParent(ui->horizontalFrame);

}*/

void MainWindow::on_pushButton_8_2clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_9_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_le_cin_supp_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM cartefid  WHERE CIN  LIKE'"+arg1+"%' or POINT LIKE'"+arg1+"%' or ID_CARTE LIKE'"+arg1+"%' or DA LIKE'"+arg1+"%'  ");
             query->exec();
             if (query->next()) { }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->le_cin_supp->clear();}
}


void MainWindow::on_le_cin_modifier_textChanged(const QString &arg1)
{

    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM cartefid  WHERE CIN  LIKE'"+arg1+"%' or POINT LIKE'"+arg1+"%' or ID_CARTE LIKE'"+arg1+"%' or DA LIKE'"+arg1+"%'  ");
             query->exec();
             if (query->next()) { }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->le_cin_modifier->clear();}
}




void MainWindow::on_satta_clicked()
{
    QPieSeries *series = new QPieSeries();
            QChart *chart = new QChart();

        QSqlQuery query;
        QPieSlice *slice;

        query.prepare("SELECT ca.cin ,ca.point,ca.id_carte ,cl.nom , cl.prenom  FROM  cartefid ca ,clientfid cl where ca.cin=cl.cin ");
        if(query.exec())
        {int i=0;
        while(query.next())
        {

           series->append(query.value(1).toString(), query.value(0).toInt());
        slice = series->slices().at(i);
           slice->setExploded();
            slice->setLabelVisible();
            slice->setPen(QPen(Qt::darkGreen, 2));

            slice->setBrush(Qt::green);
            i++;

        }}

        //![1]

        //![2]
          /*
           slice1->setExploded();
             slice1->setLabelVisible();
             slice1->setPen(QPen(Qt::darkGreen, 2));
             slice1->setBrush(Qt::green);*/
        //![2]

        //![3]
            chart->addSeries(series);
            chart->setTitle("Statisque ");



        QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                             chartView->show();
}



void MainWindow::on_pushButton_10_clicked()
{
   ui->stackedWidget->setCurrentIndex(8);
}



void MainWindow::on_tri_clicked()
{ Clientfid c;

    bool test=true;
            if(test){

                   { ui->tab_client->setModel(C.trier_nom());
                    QMessageBox::information(nullptr, QObject::tr("trier equipement"),
                                QObject::tr(" client trier.\n"
                                            "Voulez-vous enregistrer les modifications ?"),
                                       QMessageBox::Save
                                       | QMessageBox::Cancel,
                                      QMessageBox::Save);
    }

                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("trier  client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_11_clicked()
{
ui->stackedWidget->setCurrentIndex(1);

}




void MainWindow::on_pushButton_19_clicked()
{
    QString username= ui->username->text();
    QString password= ui->password->text();

    //if(ui->username->text().isEmpty()==false)
   // {
    if(password=="9999"&&username=="dhia")
    {QMessageBox::information(nullptr, QObject::tr("dhia"),
                           QObject::tr("Ravi de Vous Retrouver"), QMessageBox::Cancel);
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if(password=="0000"&&username=="nourhene")
    {
        QMessageBox::information(nullptr, QObject::tr("nourhene"),
                               QObject::tr("Bienvenue"), QMessageBox::Cancel);
       ui->stackedWidget->setCurrentIndex(10);
    }
    else if(password=="0000"&&username=="malek")
    {
        QMessageBox::information(nullptr, QObject::tr("malek"),
                               QObject::tr("Bienvenue"), QMessageBox::Cancel);
       ui->stackedWidget->setCurrentIndex(11);
    }
    else if(password=="0000"&&username=="yassin")
    {
        QMessageBox::information(nullptr, QObject::tr("yassine"),
                               QObject::tr("Bienvenue"), QMessageBox::Cancel);
       ui->stackedWidget->setCurrentIndex(14);
    }

    else if(password=="0000"&&username=="molka")
    {
        QMessageBox::information(nullptr, QObject::tr("molka"),
                               QObject::tr("Bienvenue"), QMessageBox::Cancel);
       ui->stackedWidget->setCurrentIndex(17);

    }
    else if(password=="0000"&&username=="riadh")
    {
        QMessageBox::information(nullptr, QObject::tr("riadh"),
                               QObject::tr("Bienvenue"), QMessageBox::Cancel);
       ui->stackedWidget->setCurrentIndex(22);
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Probleme"),
                               QObject::tr("Veuillez Verifier Vos informations"), QMessageBox::Cancel);


    }}
   // else {
      //  QMessageBox::critical(nullptr, QObject::tr("Probleme"),
                              // QObject::tr("Veuillez Verifier Vos informations"), QMessageBox::Cancel);

   // }

    //a.show();

//}



void MainWindow::on_pushButton_17_clicked()
{
     ui->stackedWidget->setCurrentIndex(9);
}



void MainWindow::on_pushButton_15_clicked()
{
    Clientfid c;

        bool test=true;
                if(test){

                       { ui->tab_client->setModel(C.trier_cin());
                        QMessageBox::information(nullptr, QObject::tr("trier equipement"),
                                    QObject::tr(" client trier.\n"
                                                "Voulez-vous enregistrer les modifications ?"),
                                           QMessageBox::Save
                                           | QMessageBox::Cancel,
                                          QMessageBox::Save);
        }

                    }
                    else
                        QMessageBox::critical(nullptr, QObject::tr("trier  client"),
                                    QObject::tr("Erreur !.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_pushButton_14_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_13_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_20_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_18_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}






void MainWindow::on_pushButton_21_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

//malek

void MainWindow::on_ajouter1_clicked()
{
    reservation RE(ui->id_r->text().toInt(),ui->num_tel->text().toInt(),ui->nbr_pr->text().toInt(),ui->dat->date());
           int id_r= ui->id_r->text().toInt();
            int nbr_pr= ui->nbr_pr->text().toInt();
             int num_tel= ui->num_tel->text().toInt();
        bool test=RE.ajouter();
             if(id_r==0||num_tel==0||nbr_pr==0)
             {
                QMessageBox::critical(nullptr, QObject::tr("vide"),
                                                 QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

             }

               else if(test==true){
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                                QObject::tr("reservation ajoutée:\n"
                     "click ok to exit"),QMessageBox::Ok);
                ui->tab_r->setModel(RE.afficher());}
             else{QMessageBox::information(nullptr, QObject::tr("database is open"),
                                           QObject::tr("reservation existe deja:\n"
                                "click ok to exit"),QMessageBox::Ok);}

                 RE.ajouter();
}

void MainWindow::on_retour1_clicked()
{
      ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_modifier1_clicked()
{
    reservation RE2;
          RE2.setid_r(ui->id_r2->text().toInt());
          RE2.setnum_tel(ui->num_tel2->text().toInt());
          RE2.setnbr_pr(ui->nbr_pr2->text().toInt());
          RE2.setdat(ui->dat2->date());

           RE2.modifier(RE2.getid_r(),RE2.getnum_tel(),RE2.getnbr_pr(),RE2.getdat());
           int id_r= ui->id_r2->text().toInt();
           int num_tel=ui->num_tel2->text().toInt();
            int nbr_pr=ui->nbr_pr2->text().toInt();
           if(id_r==0||num_tel==0||nbr_pr==0)
                {
                   QMessageBox::critical(nullptr, QObject::tr("vide"),
                                                    QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

                }

           else {
               QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("reservation modifiee:\n"
            "click ok to exit"),QMessageBox::Ok);
               ui->tab_r->setModel(RE.afficher());
    }

}

void MainWindow::on_retour2_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton0_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_supprimer1_clicked()
{
    reservation RE1;
      RE1.setid_r(ui->id_r3->text().toInt());
      bool test=RE1.supprimer(RE1.getid_r());
      QMessageBox msgBox;
      if(test)
         { msgBox.setText("suppression avec succes");
       ui->tab_r->setModel(RE.afficher());
      }
      else
          msgBox.setText("echec de la suppression");
      msgBox.exec();

}

void MainWindow::on_ajouter2_clicked()
{
    commande CO(ui->code->text().toInt(),ui->prix->text().toInt(),ui->cp->text().toInt(),ui->qt->text().toInt(),ui->num_telc->text().toInt(),ui->nom->text(),ui->datc->date());
           int code= ui->code->text().toInt();
            int prix= ui->prix->text().toInt();
             int cp= ui->cp->text().toInt();
             int qt= ui->qt->text().toInt();
             int num_telc= ui->num_telc->text().toInt();
             QString nom= ui->nom->text();

        bool test=CO.ajouter2();
             if(code==0||prix==0||cp==0||qt==0||num_telc==0||nom=="")
             {
                QMessageBox::critical(nullptr, QObject::tr("vide"),
                                                 QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

             }

               else if(test==true){
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                                QObject::tr("commande ajoutée:\n"
                     "click ok to exit"),QMessageBox::Ok);
                ui->tab_c->setModel(CO.afficher2());}
             else{QMessageBox::information(nullptr, QObject::tr("database is open"),
                                           QObject::tr("commande existe deja:\n"
                                "click ok to exit"),QMessageBox::Ok);}

                 CO.ajouter2();
}

void MainWindow::on_retour3_clicked()
{
     ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_22_clicked()
{
     ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_supprimer2_clicked()
{
    commande CO1;
      CO1.setcode(ui->code2->text().toInt());
      bool test=CO1.supprimer2(CO1.getcode());
      QMessageBox msgBox;
      if(test)
         { msgBox.setText("suppression avec succes");
       ui->tab_c->setModel(CO.afficher2());
      }
      else
          msgBox.setText("echec de la suppression");
      msgBox.exec();
}

void MainWindow::on_modifier2_clicked()
{
    commande CO2;
          CO2.setcode(ui->code3->text().toInt());
          CO2.setprix(ui->prix3->text().toInt());
          CO2.setcp(ui->cp3->text().toInt());
          CO2.setqt(ui->qt3->text().toInt());
          CO2.setnum_telc(ui->num_telc3->text().toInt());
          CO2.setnom(ui->nom3->text());
          CO2.setdatc(ui->datc3->date());

           CO2.modifier2(CO2.getcode(),CO2.getprix(),CO2.getcp(),CO2.getqt(),CO2.getnum_telc(),CO2.getnom(),CO2.getdatc());
           int code= ui->code->text().toInt();
            int prix= ui->prix->text().toInt();
             int cp= ui->cp->text().toInt();
             int qt= ui->qt->text().toInt();
             int num_telc= ui->num_telc->text().toInt();
             QString nom= ui->nom->text();
           if(code==0||prix==0||cp==0||qt==0||num_telc==0||nom=="")
                {
                   QMessageBox::critical(nullptr, QObject::tr("vide"),
                                                    QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

                }

           else {
               QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("commande modifiee:\n"
            "click ok to exit"),QMessageBox::Ok);
               ui->tab_c->setModel(CO.afficher2());
    }
}

void MainWindow::on_radioButton_4_clicked()
{
    ui->tab_c->setModel( CO.trier_code());

}

void MainWindow::on_radioButton_5_clicked()
{
    ui->tab_c->setModel( CO.trier_nom());
}

void MainWindow::on_radioButton_6_clicked()
{
    ui->tab_c->setModel( CO.trier_qt());
}

/*void MainWindow::on_id_r3_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM reservation  WHERE ID_R  LIKE'"+arg1+"%' or NBR_PR  LIKE'"+arg1+"%' or NUM_TEL LIKE'"+arg1+"%'or DAT LIKE'"+arg1+"%' ");
             query->exec();
             if (query->next()) { }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->id_r3->clear();}
}

void MainWindow::on_id_r2_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM reservation  WHERE ID_R  LIKE'"+arg1+"%' or NBR_PR  LIKE'"+arg1+"%' or NUM_TEL LIKE'"+arg1+"%' or DAT'"+arg1+"%' ");
             query->exec();
             if (query->next()) { }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->id_r2->clear();}
}


void MainWindow::on_code2_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM commande  WHERE CODE LIKE'"+arg1+"%' or PRIX  LIKE'"+arg1+"%' or CP LIKE'"+arg1+"%'or QT'"+arg1+"%'or NUM_TELC LIKE'"+arg1+"%'or NOM LIKE'"+arg1+"%'or DATC LIKE'"+arg1+"%' ");
             query->exec();
             if (query->next()) { }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->code2->clear();}
}

void MainWindow::on_code3_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM commande  WHERE CODE LIKE'"+arg1+"%' or PRIX  LIKE'"+arg1+"%' or CP LIKE'"+arg1+"%'or QT'"+arg1+"%'or NUM_TELC LIKE'"+arg1+"%'or NOM LIKE'"+arg1+"%'or DATC LIKE'"+arg1+"%' ");
             query->exec();
             if (query->next()) { }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->code3->clear();}
}*/

void MainWindow::on_rechercher_code_clicked()
{
    QString code = ui->recher_code->text();
    ui->tab_c->setModel(CO.afficher_code(code));
}


void MainWindow::on_rechercher_nom_clicked()
{
    QString nom = ui->recher_nom->text();
     ui->tab_c->setModel(CO.afficher_nom(nom));
}

void MainWindow::on_rechercher_qt_clicked()
{
    QString qt = ui->recher_qt->text();
     ui->tab_c->setModel(CO.afficher_qt(qt));
}


/*void MainWindow::on_stat_clicked()
{

     QPieSeries *series = new QPieSeries();
        QChart *chart = new QChart();

    QSqlQuery query;
    QPieSlice *slice;
    int id=0;
    query.prepare("SELECT* FROM commande ");
    if(query.exec())
    {int i=0;
    while(query.next())
    {

       series->append(query.value(1).toString(), query.value(0).toInt());
    slice = series->slices().at(i);
       slice->setExploded();
        slice->setLabelVisible();
        slice->setPen(QPen(Qt::darkGreen, 2));

        slice->setBrush(Qt::green);
        i++;

    }}

    //![1]

    //![2]

       slice1->setExploded();
         slice1->setLabelVisible();
         slice1->setPen(QPen(Qt::darkGreen, 2));
         slice1->setBrush(Qt::green);
    //![2]

    //![3]
        chart->addSeries(series);
        chart->setTitle("Statisque : nombre d'employés par département");



    QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
                         chartView->show();



}
*/

void MainWindow::on_pb_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/dhia/Documents/pp - Copie/Pdfreservation.pdf");
                          QPainter painter(&pdf);
                         int i = 4000;
                              painter.setPen(Qt::red);
                              painter.setFont(QFont("Arial", 30));
                              painter.drawText(2300,1200,"Liste Des Reservations");
                              painter.setPen(Qt::black);
                              painter.setFont(QFont("Arial", 50));
                             // painter.drawText(1100,2000,afficheDC);
                              painter.drawRect(1500,200,7300,2600);
                              painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/User/Downloads/150123410_1102641506814079_4892972152459660250_n (1).png"));
                              painter.drawRect(0,3000,9600,500);
                              painter.setFont(QFont("Arial", 9));
                              painter.drawText(300,3300,"ID_R");
                              painter.drawText(2300,3300,"NBR_PR");
                              painter.drawText(4300,3300,"NUM_TEL");
                              painter.drawText(6300,3300,"DAT");




                              QSqlQuery query;
                              query.prepare("select * from RESERVATION");
                              query.exec();
                              while (query.next())
                              {
                                  painter.drawText(300,i,query.value(0).toString());
                                  painter.drawText(2300,i,query.value(1).toString());
                                  painter.drawText(4300,i,query.value(2).toString());
                                  painter.drawText(6300,i,query.value(3).toString());



                                 i = i +500;
                              }
                              int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                  if (reponse == QMessageBox::Yes)
                                  {
                                      QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/User/Desktop/pp/pp/Pdfreservation.pdf"));

                                      painter.end();
                                  }
                                  if (reponse == QMessageBox::No)
                                  {
                                       painter.end();
                                  }
}








void MainWindow::on_historique_clicked()
{
    ui->tabhis->setModel(tmph.afficherhis()) ;
            ui->tabhis->setModel(tmph.afficherhis());//refresh
}

void MainWindow::on_chat_clicked()
{

    chat chat_window(this);
    chat_window.setModal(true);
    chat_window.show();
    chat_window.exec();
}



//yassin

void MainWindow::on_ajouter_button_clicked()
{   QSound bells("C:/Users/admin/Downloads/pro (2).wav");
    bells.play();
    QString idEmploye = ui->id_line->text();
    QString nom = ui->line_nom->text();
    QString DateNaiss = ui->line_datenaissance->text();
    int NumTel = ui->line_tel->text().toInt();
    QString Adress = ui->line_mdp->text();
    QString Mdp = ui->line_id_poste->text();
    int id_poste = ui->line_id_poste->text().toInt();

    Employe E(idEmploye,nom,DateNaiss,NumTel,Adress,Mdp,id_poste);
    bool test =E.ajouter();
    if (test)

    {
        ui->tableemploye->setModel(tempemploye.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout employe"),
                                 QObject::tr("employe ajouté :"), QMessageBox::Cancel);
    }
   else {
        QMessageBox::information(nullptr, QObject::tr("echec "),
                                 QObject::tr("les champs sont invalides :"), QMessageBox::Cancel);
    }
}



void MainWindow::on_SUPPRIMER8BUTTON_clicked()
{  QSound bells("C:/Users/admin/Downloads/pro (2).wav");
    bells.play();
    int idEmploye = ui->lineEdit_2->text().toInt();
     bool test = tempemploye.supprimer(idEmploye);
     if (test)
      {
         ui->tableemploye->setModel(tempemploye.afficher());
       QMessageBox::information(nullptr, QObject::tr(" suppression employe "),
                              QObject::tr("employe supprimé :"), QMessageBox::Cancel);
      }
}

/*void MainWindow::on_pushButton_3_clicked()
{
    close();
}*/

void MainWindow::on_pushButton_recherche_clicked()
{
    QSound bells("C:/Users/admin/Downloads/pro (2).wav");
    bells.play();
    {
        Employe p;
        QString text;

        if (ui->radioButton_ID->isChecked()==true)
       {
       text=ui->lineEdit_rechercher->text();
         if(text == "")
         {
             ui->tableemploye->setModel(p.afficher());
         }

         else
         {
             ui->tableemploye->setModel(p.chercher_emp_id(text));
         }
        }


       if(ui->radioButton_nom->isChecked()==true)
        {
            text=ui->lineEdit_rechercher->text();
                 if(text == "")

                 {
                     ui->tableemploye->setModel(p.afficher());

                 }

                 else

                 {
                     ui->tableemploye->setModel(p.chercher_emp_nom(text));
                 }

        }

         else if     (ui->radioButton_mdp->isChecked()==true)
         {

             text=ui->lineEdit_rechercher->text();
                  if(text == "")

                  {
                      ui->tableemploye->setModel(p.afficher());
                  }

                  else

                  {
                      ui->tableemploye->setModel(p.chercher_emp_mdp(text));
                  }
         }
    }
}

void MainWindow::on_tri_button_clicked()
{
    Employe p;
           /*QString critere=ui->cb_historique->currentText();*/
               QString mode;
               // if (ui->rb_asc_historique->isChecked()==true)
           {
                    ui->tableemploye->setModel(p.trie());


           }
               /* else if(ui->rb_desc_historique->isChecked()==true)

                    ui->tableemploye->setModel(p.trie2());*/
    }


void MainWindow::on_modifier_button_clicked()
{   QSound bells("C:/Users/admin/Downloads/pro (2).wav");
    bells.play();
    if (ui->modifier_button->isChecked())
          {
              ui->modifier_button->setDisabled(true);
              ui->modifier_button->setText("Modifiable");
              QSqlTableModel *tableModel= new QSqlTableModel();
              tableModel->setTable("EMPLOYE");
              tableModel->select();
              ui->tableemploye->setModel(tableModel);
          }
          else
          {
              ui->modifier_button->setText("Modifier");
              ui->tableemploye->setModel(tempemploye.afficher());

          }
}

/*void MainWindow::on_pushButton_clicked()
{   QSound bells("C:/Users/admin/Downloads/pro (2).wav");
    bells.play();
     ui->stackedWidget->setCurrentIndex(2);
}*/

/*void MainWindow::on_pushButton_2_clicked()
{   QSound bells("C:/Users/admin/Downloads/pro (2).wav");
    bells.play();
     ui->stackedWidget->setCurrentIndex(3);
}*/

void MainWindow::on_ajouter_button_2_clicked()
{  QSound bells("C:/Users/admin/Downloads/pro (2).wav");
    bells.play();
    int id_poste = ui->line_idposte->text().toInt();
    int nbr_heurs = ui->line_nbheures->text().toInt();
    int jours_conges = ui->linejourconges->text().toInt();
    QString salaire = ui->line_salaire->text();
    QString prime = ui->line_prime->text();

    poste p(id_poste,nbr_heurs,jours_conges,salaire,prime);
    bool test =p.ajouter();
    if (test)

    {
        ui->tablepostee->setModel(tempposte.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout poste"),
                                 QObject::tr("employe poste :"), QMessageBox::Cancel);
    }
    else {
         QMessageBox::information(nullptr, QObject::tr("echec "),
                                  QObject::tr("les champs sont invalides :"), QMessageBox::Cancel);
     }
    QPieSeries *series = new QPieSeries();
            QSqlQuery query;
                    query=tempposte.stat();
            while(query.next())
            {
                series->append(query.value(0).toString(),query.value(3).toInt());
            }

            QChart * chart=new  QChart();
            chart->addSeries(series);
            chart->setTitle("les statistiques des salaires");

            QChartView * chartView=new QChartView(chart);
            chartView ->setParent(ui->frame_4);
            chartView->setFixedSize(ui->frame_4->size());
}

/*void MainWindow::on_pushButton_4_clicked()
{
    close();
}*/

void MainWindow::on_modifier_button_2_clicked()
{   QSound bells("C:/Users/admin/Downloads/pro (2).wav");
    bells.play();
    if (ui->modifier_button_2->isChecked())
          {
              ui->modifier_button_2->setDisabled(true);
              ui->modifier_button_2->setText("Modifiable");
              QSqlTableModel *tableModel= new QSqlTableModel();
              tableModel->setTable("POSTEE");
              tableModel->select();
              ui->tablepostee->setModel(tableModel);
          }
          else
          {
              ui->modifier_button_2->setText("Modifier");
              ui->tablepostee->setModel(tempposte.afficher());

          }
}

void MainWindow::on_pushButton_recherche_2_clicked()
{   QSound bells("C:/Users/admin/Downloads/pro (2).wav");
    bells.play();
    {
        poste p;
        QString text;

        if (ui->radioButton_ID_2->isChecked()==true)
       {
       text=ui->lineEdit_rechercher_2->text();
         if(text == "")
         {
             ui->tablepostee->setModel(p.afficher());
         }

         else
         {
             ui->tablepostee->setModel(p.chercher_post_id(text));
         }
        }


       if(ui->radioButton_nom_2->isChecked()==true)
        {
            text=ui->lineEdit_rechercher_2->text();
                 if(text == "")

                 {
                     ui->tablepostee->setModel(p.afficher());

                 }

                 else

                 {
                     ui->tablepostee->setModel(p.chercher_post_slr(text));
                 }

        }

         else if     (ui->radioButton_mdp_2->isChecked()==true)
         {

             text=ui->lineEdit_rechercher_2->text();
                  if(text == "")

                  {
                      ui->tablepostee->setModel(p.afficher());
                  }

                  else

                  {
                      ui->tablepostee->setModel(p.chercher_post_nbrh(text));
                  }
         }
    }
}

void MainWindow::on_SUPPRIMER8BUTTON_2_clicked()
{  QSound bells("C:/Users/admin/Downloads/pro (2).wav");
    bells.play();
    int id_poste = ui->line_id_supp->text().toInt();
     bool test = tempposte.supprimer(id_poste);
     if (test)
      {
         ui->tablepostee->setModel(tempposte.afficher());
       QMessageBox::information(nullptr, QObject::tr(" suppression poste "),
                              QObject::tr("poste supprimé :"), QMessageBox::Cancel);
      }
     QPieSeries *series = new QPieSeries();
     QSqlQuery query;
             query=tempposte.stat();
     while(query.next())
     {
         series->append(query.value(0).toString(),query.value(3).toInt());
     }

     QChart * chart=new  QChart();
     chart->addSeries(series);
     chart->setTitle("les statistiques des salaires");

     QChartView * chartView=new QChartView(chart);
     chartView ->setParent(ui->frame_4);
     chartView->setFixedSize(ui->frame_4->size());

}

void MainWindow::on_tri_button_2_clicked()
{
    poste g;
           /*QString critere=ui->cb_historique->currentText();*/
               QString mode;
                if (ui->radioButto_h_asc->isChecked()==true)
           {
                    ui->tablepostee->setModel(g.trie());


           }
                else if(ui->radioButton_des->isChecked()==true)

                    ui->tablepostee->setModel(g.trie2());

}




void MainWindow::on_retour_button_2_clicked()
{  QSound bells("C:/Users/admin/Downloads/pro (2).wav");
    bells.play();
    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::on_retour_button_clicked()
{  QSound bells("C:/Users/admin/Downloads/pro (2).wav");
    bells.play();
    ui->stackedWidget->setCurrentIndex(14);
}



void MainWindow::on_pushButton_23_clicked()
{
    close();
}

void MainWindow::on_pushButton_24_clicked()
{
    close();
}

void MainWindow::on_employebutt_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_postebouton_clicked()
{ui->stackedWidget->setCurrentIndex(16);

}
//.......molka..........

void MainWindow::on_ajout_eq_clicked()
{
    crud_equipement E(ui->le_ide->text().toInt(),ui->le_nome->text(),ui->le_quantitee->text().toInt(),ui->le_etate->text());
       int ide= ui->le_ide->text().toInt();
       QString nome= ui->le_nome->text();
    bool test=E.ajoutere();
         if(ide==0||nome=="")
         {
            QMessageBox::critical(nullptr, QObject::tr("vide"),
                                             QObject::tr("Veuillez saisir tous les champs correctement !\n"), QMessageBox::Cancel);

         }

           else if(test==true){
            QMessageBox::information(nullptr, QObject::tr("database is opened"),
                            QObject::tr("Equipement ajouté !\n"
                 "click ok to exit"),QMessageBox::Ok);
           /* ui->tab_equipement->setModel(E.affichere());*/}
         else{QMessageBox::information(nullptr, QObject::tr("database is opened"),
                                       QObject::tr("Erreur d'ajout !\n"
                            "click ok to exit"),QMessageBox::Ok);}
        // N.notification_ajoutEquipement();

             E.ajoutere();

}

void MainWindow::on_tabWidget_7_currentChanged(int index)
{
       ui->tab_equipement->setModel(crudEquipement->affichere());
}

void MainWindow::on_pb_modifierequipement_clicked()
{

    crud_equipement E2;
    E2.setide(ui->ide_mod->text().toInt());
        E2.setnome(ui->nom_mod_2->text());
        E2.setquantitee(ui->quantite_mod_2->text().toInt());
        E2.setetate(ui->etate_mod->text());

       E2.modifiere(E2.getide(),E2.getnome(),E2.getquantitee(),E2.getetate());
       int ide= ui->ide_mod->text().toInt();
       QString nome= ui->nom_mod_2->text();
      // N.notification_modifierEquipement();
       if(ide==0||nome=="")
            {
               QMessageBox::critical(nullptr, QObject::tr("vide"),
                                                QObject::tr("Veuillez saisir tous les champs correctement !\n"), QMessageBox::Cancel);

            }

       else {
           QMessageBox::information(nullptr, QObject::tr("database is opened"),
                   QObject::tr("Equipement modifié !\n"
        "click ok to exit"),QMessageBox::Ok);
          // ui->tab_equipement->setModel(E.affichere());


}
}

void MainWindow::on_pb_suppeq_clicked()
{

    crud_equipement E1;
        E1.setide(ui->id_suppr->text().toInt());
        int ide= ui->id_suppr->text().toInt();
       // N.notification_supprimerEquipement();
        bool test1=E1.supprimere(E1.getide());



       if(ide==0)
        {
           QMessageBox::information(nullptr, QObject::tr("vide"),
                                            QObject::tr("Veuillez saisir tous les champs correctement !\n"), QMessageBox::Cancel);

        }



        else if(test1==true)
           {QMessageBox::information(nullptr,QObject::tr("database is opened"),
                                     QObject::tr("Equipement supprimé !\n"
             "click ok to exit"),QMessageBox::Ok);
        // ui->tab_equipement->setModel(E.affichere());
        }
           else
        {QMessageBox::critical(nullptr,QObject::tr("database is opened"),
                                  QObject::tr("Erreur de suppression !\n"
               "click ok to exit"),QMessageBox::Ok);}
      // E.supprimere(E.getide());
}

void MainWindow::on_pdf_eq_clicked()
{
    QPdfWriter pdf("C:/Users/dhia/Documents/pp - Copie/Equipements.pdf");

                          QPainter painter(&pdf);
                         int i = 4000;
                              painter.setPen(Qt::red);
                              painter.setFont(QFont("Arial", 30));
                              painter.drawText(2300,1200,"Liste Des Equipements");
                              painter.setPen(Qt::black);
                              painter.setFont(QFont("Arial", 50));
                             // painter.drawText(1100,2000,afficheDC);
                              painter.drawRect(1500,200,7300,2600);
                              painter.drawPixmap(QRect(100,700,600,600),QPixmap("C:/Users/ASUS/Desktop/solo/semestre 2/projet c++/cuisine/150123410_1102641506814079_4892972152459660250_n.png"));
                              painter.drawRect(0,3000,9600,500);
                              painter.setFont(QFont("Arial", 9));
                              painter.drawText(300,3300,"ID_EQUIPEMENT");
                              painter.drawText(2300,3300,"NOM_EQUIPEMENT");
                              painter.drawText(4300,3300,"QUANTITE_EQUIPEMENT");
                              painter.drawText(6300,3300,"ETAT_EQUIPEMENT");




                              QSqlQuery query;
                              query.prepare("select * from EQUIPEMENT");
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
                                      QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/solo/semestre 2/projet c++/cuisine/Equipements.pdf"));

                                      painter.end();
                                  }
                                  if (reponse == QMessageBox::No)
                                  {
                                       painter.end();
                                  }
}

void MainWindow::on_pb_imprimer_clicked()
{
    QString strStream;
                QTextStream out(&strStream);



                const int rowCount = ui->tab_equipement->model()->rowCount();
                const int columnCount = ui->tab_equipement->model()->columnCount();

                out <<  "<html>\n"
                    "<head>\n"

                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%60 les postes</title>\n").arg("poste")
                    <<  "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<table border=1 cellspacing=0 cellpadding=2>\n";
                out << "<thead><tr bgcolor=#f0f0f0>";
                for (int column = 0; column < columnCount; column++)
                    if (! ui->tab_equipement->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tab_equipement->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tab_equipement->isColumnHidden(column)) {
                            QString data = ui->tab_equipement->model()->data(ui->tab_equipement->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                if (dialog->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }

                delete document;
}
void MainWindow::on_pb_GM_clicked()
{
     ui->stackedWidget->setCurrentIndex(19);
}


void MainWindow::on_pb_GR_clicked()
{
      ui->stackedWidget->setCurrentIndex(20);
}



void MainWindow::on_pb_GE_clicked()
{
      ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_pb_trailer_clicked()
{
  ui->stackedWidget->setCurrentIndex(21);
}
//menu
void MainWindow::on_pb_ajouter_3_clicked()
{

    int id = ui->le_id->text().toInt();
    QString nom = ui->le_nom_3->text();
    double prix = ui->le_prix->text().toDouble();
    QString categorie = ui->la_categorie->text();
    // Création d'un objet normal,on parle pas de widgets içi :
    Crud_Menu m;
    m = Crud_Menu(id,nom,categorie,prix);
    //
    bool test = m.ajouter_menu();

    if(test) {
        QMessageBox::information(nullptr, QObject::tr("database is opened"),
                                   QObject::tr("Menu ajouté !\n"
                        "click ok to exit"),QMessageBox::Ok);

    }
else{QMessageBox::information(nullptr, QObject::tr("database is opened"),
                              QObject::tr("erreur d'ajout !\n"
                   "click ok to exit"),QMessageBox::Ok);}

}





void MainWindow::on_pb_supprimer_2_clicked()
{
    int id = ui->text_delete->text().toInt();
    bool exist = crudMenu->recupere_menu(id);
    bool test = crudMenu->supprimer_menu(id);


    if(test && exist ==true) {
        QMessageBox::information(nullptr,"Supprimer un menu","le menu a été supprimé avec succès !");//Qwidget ==> les composants mt3 qt dima initliasation ta3 ay QWidget heya nullptr manha maytpointa ala chay
    }
    else {
        QMessageBox::information(nullptr,"Supprimer un menu ","suppression échouée !");//Qwidget ==> les composants mt3 qt dima initliasation ta3 ay QWidget heya nullptr;

    }



}

void MainWindow::on_tabWidget_8_currentChanged(int index)// ki t7ot index = 1 ya3ni action tsir kif temchi teckliki ala colonne el indice mt3o 1 sinon mat7ot chy kol mat7el ay colone ysir execution mt3 méthode
{
    //  setmodel heya la partie blanche ta3 widget tableview
    ui->tableView_3->setModel(crudMenu->afficher_menu());

}



void MainWindow::on_pb_modifier_3_clicked()
{
    int id = ui->lineEdit->text().toInt();
    QString nom = ui->lineEdit_3->text();
    QString categorie = ui->lineEdit_4->text();
    double prix = ui->lineEdit_5->text().toDouble();
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




void MainWindow::on_check_box_id_clicked()
{


    ui->tableView_3->setModel(crudMenu->afficher_menu());

    if(ui->check_box_id->isChecked() == true)
         ui->tableView_3->setModel(crudMenu->trie_id());
   else
        ui->tableView_3->setModel(crudMenu->afficher_menu());

}




void MainWindow::on_pushButton_30_clicked()
{
    ui->tableView_3->setModel(crudMenu->afficher_menu());

    QString text_a_rechercher = ui->searchtxt->text();

    ui->tableView_3->setModel(crudMenu->recherche_menu_selon_nom(text_a_rechercher));

}



void MainWindow::on_check_box_nom_clicked()
{
    ui->tableView_3->setModel(crudMenu->afficher_menu());

    if(ui->check_box_nom->isChecked() == true)
         ui->tableView_3->setModel(crudMenu->trie_nom());
   else
        ui->tableView_3->setModel(crudMenu->afficher_menu());

}

void MainWindow::on_check_box_categorie_clicked()
{
    ui->tableView_3->setModel(crudMenu->afficher_menu());

    if(ui->check_box_categorie->isChecked() == true)
         ui->tableView_3->setModel(crudMenu->trie_categorie());
   else
        ui->tableView_3->setModel(crudMenu->afficher_menu());
}

void MainWindow::on_pushButton_31_clicked()
{ ui->tableView_3->setModel(crudMenu->afficher_menu());

    QString text_a_rechercher = ui->searchtxt_2->text();

    ui->tableView_3->setModel(crudMenu->recherche_menu_selon_categorie(text_a_rechercher));


}

/*void gestion_menu::on_lineEdit_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM menu  WHERE IDMENU LIKE'"+arg1+"%' or NOMMENU  LIKE'"+arg1+"%' or CATEGORIEMENU LIKE'"+arg1+"%' or PRIX LIKE'"+arg1+"%' ");
             query->exec();
             if (query->next()) { }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->lineEdit->clear();}
}

void gestion_menu::on_text_delete_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM menu  WHERE IDMENU LIKE'"+arg1+"%' or NOMMENU  LIKE'"+arg1+"%' or CATEGORIEMENU LIKE'"+arg1+"%' or PRIX LIKE'"+arg1+"%' ");
             query->exec();
             if (query->next()) { }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->text_delete->clear();}
}*/

void MainWindow::on_pushButton_32_clicked()
{
    ui->tableView_3->setModel(crudMenu->afficher_menu());

        int text_a_rechercher = ui->searchtxt_3->text().toInt();

        ui->tableView_3->setModel(crudMenu->recherche_menu_selon_id(text_a_rechercher));
}


void MainWindow::on_pb_imprimer_menu_clicked()
{
    QString strStream;
                QTextStream out(&strStream);



                const int rowCount = ui->tableView->model()->rowCount();
                const int columnCount = ui->tableView->model()->columnCount();

                out <<  "<html>\n"
                    "<head>\n"

                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%60 les postes</title>\n").arg("poste")
                    <<  "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<table border=1 cellspacing=0 cellpadding=2>\n";
                out << "<thead><tr bgcolor=#f0f0f0>";
                for (int column = 0; column < columnCount; column++)
                    if (! ui->tableView->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tableView->isColumnHidden(column)) {
                            QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                if (dialog->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }

                delete document;
}
//recette
void MainWindow::on_pb_ajouter1_clicked()
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

void MainWindow::on_tabWidget_9_currentChanged(int index)
{
   ui->tableView1->setModel(crudRecette->afficher_recette());
}

void MainWindow::on_pb_supprimer1_clicked()
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

void MainWindow::on_pb_modifier1_clicked()
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

void MainWindow::on_lineEdit1_textChanged(const QString &arg1)
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

void MainWindow::on_text_delete1_textChanged(const QString &arg1)
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

void MainWindow::on_pb_pdf_2_clicked()
{
    QPdfWriter pdf("C:/Users/dhia/Documents/pp - Copie/Recettes.pdf");

                          QPainter painter(&pdf);
                         int i = 4000;
                              painter.setPen(Qt::red);
                              painter.setFont(QFont("Arial", 30));
                              painter.drawText(2300,1200,"Liste Des Recettes");
                              painter.setPen(Qt::black);
                              painter.setFont(QFont("Arial", 50));
                             // painter.drawText(1100,2000,afficheDC);
                              painter.drawRect(1500,200,7300,2600);
                              painter.drawPixmap(QRect(100,700,600,600),QPixmap("C:/Users/ASUS/Desktop/solo/semestre 2/projet c++/cuisine/150123410_1102641506814079_4892972152459660250_n.png"));
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
                                      QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/solo/semestre 2/projet c++/cuisine/Recettes.pdf"));

                                      painter.end();
                                  }
                                  if (reponse == QMessageBox::No)
                                  {
                                       painter.end();
                                  }
}

void MainWindow::on_pb_consulter_clicked()
{
    statistics *g = new statistics(this);
    g->show();
}


void MainWindow::on_pb_imprimer_recette_clicked()
{
    QString strStream;
                QTextStream out(&strStream);



                const int rowCount = ui->tableView1->model()->rowCount();
                const int columnCount = ui->tableView1->model()->columnCount();

                out <<  "<html>\n"
                    "<head>\n"

                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%60 les postes</title>\n").arg("poste")
                    <<  "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<table border=1 cellspacing=0 cellpadding=2>\n";
                out << "<thead><tr bgcolor=#f0f0f0>";
                for (int column = 0; column < columnCount; column++)
                    if (! ui->tableView1->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView1->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tableView1->isColumnHidden(column)) {
                            QString data = ui->tableView1->model()->data(ui->tableView1->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                if (dialog->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }

                delete document;
}

//video
void MainWindow::on_ouvrir_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,"Ouvrir");
    if(filename.isEmpty())
    {
        return;
    }
    mediaPlayer->setMedia(QUrl::fromLocalFile(filename));
    mediaPlayer->setVolume(ui->volume->value());
    on_jouer_clicked();
}

void MainWindow::on_jouer_clicked()
{
    mediaPlayer->play();
}

void MainWindow::on_pause_clicked()
{
    mediaPlayer->pause();
}

void MainWindow::on_stop_clicked()
{
    mediaPlayer->stop();
}

void MainWindow::on_mute_clicked()
{
    if(ui->mute->text()=="Mute")
    {
    mediaPlayer->setMuted(true);
    ui->mute->setText("Unmute");
    }
    else
    {
        mediaPlayer->setMuted(false);
        ui->mute->setText("Mute");
    }
}

void MainWindow::on_volume_valueChanged(int value)
{
    mediaPlayer->setVolume(value);
}





void MainWindow::on_pb_retoureq_clicked()
{
     ui->stackedWidget->setCurrentIndex(17);
}
//riadh
void MainWindow::on_pb_ajouter_4_clicked()
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



void MainWindow::on_pb_supprimer_3_clicked()
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



void MainWindow::on_pb_modifier_4_clicked()
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







void MainWindow::on_pb_imprimer_2_clicked()
{
    QPdfWriter pdf("C:/Users/dhia/Documents/pp - Copie/Pdfproduit.pdf");
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

void MainWindow::on_checkBox_ARABE_clicked()
{
    if (ui->checkBox_ARABE->isChecked())
           {
         // mariemmmm -----------------------------------

           ui->gerer_f_2->setTabText(0,"إدارة المورد");
           ui->gerer_f_2->setTabText(1,"إدارة المنتج");
           ui->tabWidget->setTabText(0,"إضافة مورد");
           ui->tabWidget->setTabText(1,"عرض المورد");
           ui->tabWidget->setTabText(2,"تعديل المورد");





           ui->tabWidget_2->setTabText(0,"إضافة المنتج");
           ui->tabWidget_2->setTabText(1,"عرض المنتج");
           ui->tabWidget_2->setTabText(2,"تعديل المنتج");






         // ajouter four
         ui->pb_ajouter->setText( tr("أضف"));
         ui->label_23->setText( tr("المعرف"));
         ui->label->setText( tr("الإسم"));
         ui->label_2->setText( tr("العنوان"));
         ui->label_3->setText( tr("الهاتف"));
         ui->label_4->setText( tr("البريد الإلكتروني"));

         // afficher four

         ui->pb_supprimer->setText( tr("إزالة"));
         ui->label_5->setText( tr("المعرف"));
         ui->pb_rechercher_id->setText( tr("البحث عن طريق معرف"));
         ui->label_6->setText( tr("المعرف"));
         ui->pb_rechercher_nom->setText( tr("البحث عن طريق الإسم"));
         ui->label_21->setText( tr("الإسم"));
          ui->pb_rechercher_adresse->setText( tr("البحث عن طريق العنوان"));
         ui->label_22->setText( tr("العنوان"));

         // modifier four

         ui->pb_modifier->setText( tr("تعديل"));
         ui->label_24->setText( tr("المعرف"));
         ui->label_8->setText( tr("الإسم"));
         ui->label_9->setText( tr("العنوان"));
         ui->label_10->setText( tr("الهاتف"));
         ui->label_11->setText( tr("البريد الإلكتروني"));

         // ajout prod
         ui->pb_ajouter_prod->setText( tr("أضف"));
         ui->label_7->setText( tr("المعرف"));
         ui->label_12->setText( tr(" معرف المزود"));
         ui->label_13->setText( tr("سعر"));
         ui->label_14->setText( tr("كمية"));

         // afficher prod
         ui->pb_supprimer_prod->setText( tr("إزالة"));
         ui->label_15->setText( tr("المعرف"));
         ui->pb_imprimer->setText( tr("طباعة"));
         ui->label_16->setText( tr("المعرف"));

         ui->radioB_tri_id->setText( tr("الترتيب حسب المعرف"));
         ui->radioB_tri_nom->setText( tr("الترتيب حسب الاسم"));
         ui->radioB_tri_prix->setText( tr("الترتيب حسب السعر"));

         // modifier prod
         ui->pb_modifier_prod->setText( tr("تعديل"));
         ui->label_17->setText( tr("المعرف"));
         ui->label_18->setText( tr("الإسم"));
         ui->label_19->setText( tr("سعر"));
         ui->label_20->setText( tr("كمية"));








       }

       else
       {
            // mariemmmm -----------------------------------


        ui->gerer_f_2->setTabText(0,"gerer fournisseur");
        ui->gerer_f_2->setTabText(1,"gerer produit");
        ui->tabWidget->setTabText(0,"ajouter fournisseur");
        ui->tabWidget->setTabText(1,"afficher fournisseur");
        ui->tabWidget->setTabText(2,"modifier fournisseur");




        ui->tabWidget_2->setTabText(0,"ajouter produits");
        ui->tabWidget_2->setTabText(1,"afficher produits");
        ui->tabWidget_2->setTabText(2,"modifier produits");


        ui->pb_ajouter->setText( tr("Ajouter"));
        ui->label_23->setText( tr("Id"));
        ui->label->setText( tr("Nom"));
        ui->label_2->setText( tr("Adresse"));
        ui->label_3->setText( tr("Tel"));
        ui->label_4->setText( tr("Mail"));


        ui->pb_supprimer->setText( tr("Supprimer"));
        ui->label_5->setText( tr("Id"));
        ui->pb_rechercher_id->setText( tr("Rechercher par id"));
        ui->label_6->setText( tr("Id"));
        ui->pb_rechercher_nom->setText( tr("Rechercher par nom"));
        ui->label_21->setText( tr("Nom"));
         ui->pb_rechercher_adresse->setText( tr("Rechercher par adresse"));
        ui->label_22->setText( tr("Adresse"));



        ui->pb_modifier->setText( tr("Modifier"));
        ui->label_24->setText( tr("Id"));
        ui->label_8->setText( tr("Nom"));
        ui->label_9->setText( tr("Adresse"));
        ui->label_10->setText( tr("Tel"));
        ui->label_11->setText( tr("Mail"));



        ui->pb_ajouter_prod->setText( tr("Ajouter"));
        ui->label_7->setText( tr("Id"));
        ui->label_12->setText( tr("Id fournisseur"));
        ui->label_13->setText( tr("Prix"));
        ui->label_14->setText( tr("Quantite"));



        ui->pb_supprimer_prod->setText( tr("Supprimer"));
        ui->label_15->setText( tr("Id"));
        ui->pb_imprimer->setText( tr("Imprimer"));
        ui->label_16->setText( tr("Id"));

        ui->radioB_tri_id->setText( tr("Trie par id"));
        ui->radioB_tri_nom->setText( tr("Trie par nom"));
         ui->radioB_tri_prix->setText( tr("Trie par prix"));



         ui->pb_modifier_prod->setText( tr("Modifier"));
         ui->label_17->setText( tr("Id"));
         ui->label_18->setText( tr("Nom"));
         ui->label_19->setText( tr("Prix"));
         ui->label_20->setText( tr("Quantite"));












       }
}


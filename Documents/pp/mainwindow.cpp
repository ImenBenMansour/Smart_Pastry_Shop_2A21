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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    ui->tab_rec->setModel(R.afficher());
    ui->tab_prom->setModel(P.afficher2());
    ui->le_id_rec->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->le_des_rec->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    QPixmap pix("C:/Users/lenovo/Pictures/fond-mental-marron_53876-88822.jpg");
    pix = pix.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pix);
    this->setPalette(palette);



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
            ui->tab_rec->setModel(R.afficher());}
         else{QMessageBox::information(nullptr, QObject::tr("database is open"),
                                       QObject::tr("reclamation existe deja:\n"
                            "click ok to exit"),QMessageBox::Ok);}

             R.ajouter();




}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pb_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pb_supprimer_clicked()
{  reclamation R1;
    R1.setid_rec(ui->le_id_supp->text().toInt());
    int id_rec= ui->le_id_supp->text().toInt();
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
    }
    else
    {QMessageBox::information(nullptr,QObject::tr("database is open"),
                              QObject::tr("error:\n"
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
       }


     }
void MainWindow::on_pb_retour2_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pb2_ajouter_clicked()
{
    promotion P(ui->le_id2->text().toInt(),ui->le_nom->text(),ui->dat_cre->date(),ui->dat_exp->date());
         QMessageBox::information(nullptr, QObject::tr("database is open"),
                 QObject::tr("promotion ajoutée:\n"
      "click ok to exit"),QMessageBox::Ok);


          P.ajouter2();
     ui->tab_prom->setModel(P.afficher2());


}

void MainWindow::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}



void MainWindow::on_pb_retour3_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_pb2_supprimer_clicked()
{
    promotion P1;
    P1.setid(ui->le_id_supp2->text().toInt());
    bool test=P1.supprimer2(P1.getid());
    QMessageBox msgBox;
    if(test)
       { msgBox.setText("suppression avec succes");
     ui->tab_prom->setModel(P.afficher2());
    }
    else
        msgBox.setText("echec de la suppression");
    msgBox.exec();

}

void MainWindow::on_pushButton_3_clicked()
{
    promotion P2;
    P2.setnom(ui->nom_modi->text());
        P2.setdat_cre(ui->dat_cre_modi->date());
        P2.setdat_exp(ui->dat_exp_modi->date());
        P2.setid(ui->id_modii2->text().toInt());


       P2.modifier2(P2.getid(),P2.getnom(),P2.getdat_cre(),P2.getdat_exp());
       QMessageBox::information(nullptr, QObject::tr("database is open"),
               QObject::tr("promotion modifier:\n"
    "click ok to exit"),QMessageBox::Ok);
       ui->tab_prom->setModel(P.afficher2());
}

void MainWindow::on_pb_retour4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
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
    QPdfWriter pdf("C:/Users/lenovo/PdfReclamation.pdf");
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
                             int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                 if (reponse == QMessageBox::Yes)
                                 {
                                     QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/lenovo/PdfRecalamtion.pdf"));

                                     painter.end();
                                 }
                                 if (reponse == QMessageBox::No)
                                 {
                                      painter.end();
                                 }
}

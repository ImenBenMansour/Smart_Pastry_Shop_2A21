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

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

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

void MainWindow::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}



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
           QString pdf="<br> <img src='C:/Users/lenovo/Downloads/150123410_1102641506814079_4892972152459660250_n (1).png' height='100' width='100'/> <h1  style='color:brown'> <i> <u>    LISTE DES RECALAMATIONS  </u> </i> <br></h1>\n <br> <table border>   <tr>  <th> ID_REC </th>      <th> DES_REC </th>    <th> MAIL_REC </th> <th> DATE  </th>  </tr>" ;


           while ( q.next()) {
               int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                   QMessageBox::Yes |  QMessageBox::No);
                   if (reponse == QMessageBox::Yes)
                   {
                       QDesktopServices::openUrl(QUrl::fromLocalFile("file:///C:/Users/lenovo/Documents/pp/reclamation.pdf"));

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
        QMessageBox::information(nullptr, QObject::tr("nourhene"),
                               QObject::tr("Bienvenue"), QMessageBox::Cancel);
       ui->stackedWidget->setCurrentIndex(11);
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

void MainWindow::on_id_r3_textChanged(const QString &arg1)
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
}

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
    QPdfWriter pdf("C:/Users/User/Desktop/pp/pp/Pdfreservation.pdf");
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






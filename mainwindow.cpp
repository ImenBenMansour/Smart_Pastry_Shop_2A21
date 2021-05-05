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
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include<QMenu>
#include <QAction>
#include <QFileDialog>
#include"offres.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //offres

    ui->tab_of->setModel(O.afficher());
    ui->id_of->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->nom_of->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->prix_of->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->off_supp->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->nom_modi1->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
    ui->prix_modi1->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
    ui->id_modi1->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));


    //cam
    mCamera =new QCamera(this);
    mCameraViewfinder =new QCameraViewfinder(this);
    mCameraImageCapture =new QCameraImageCapture(mCamera,this);
    mLayout =new QVBoxLayout;

    mOptionMenu = new QMenu("option",this);
    mAllumerAction= new QAction("allumer",this);
    mEteindreAction= new QAction("etteindre",this);
    mCapturerAction= new QAction("capturer",this);

    mOptionMenu->addActions({mAllumerAction,mEteindreAction,
                             mCapturerAction  });
    ui->option->setMenu(mOptionMenu);
    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->scrollArea->setLayout(mLayout);


    connect(mAllumerAction,&QAction::triggered  , [&](){
        mCamera->start();
    });
    connect(mEteindreAction,&QAction::triggered, [&](){
        mCamera->stop();
    });
    connect(mCapturerAction,&QAction::triggered, [&](){
        auto filename =QFileDialog::getSaveFileName(this,"Capturer","/",
                                     "Imagen (*.jpg;*.jpeg)");
        if(filename.isEmpty()){
           return;
        }
        mCameraImageCapture->setCaptureDestination(
                    QCameraImageCapture::CaptureToFile);
        QImageEncoderSettings imageEncoderSettings;
        imageEncoderSettings.setCodec("image/jpeg");
        imageEncoderSettings.setResolution(1600,1200);
        mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
        mCamera->setCaptureMode(QCamera::CaptureStillImage);
        mCamera->start();
        mCamera->searchAndLock();
        mCameraImageCapture->capture(filename);
        mCamera->unlock();
    });

    //ARDUINO
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";

    }

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
        N.notification_ajoutReclamation();
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
     ui->stackedWidget->setCurrentIndex(0);
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
     ui->stackedWidget->setCurrentIndex(3);
}



void MainWindow::on_pb_retour3_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
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
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_5_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_6_clicked()
{
 ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
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

void MainWindow::on_pb_comptage_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}






void MainWindow::on_Camera_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}
//offres


void MainWindow::on_pb_offres_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pb_ajouter_2_clicked()
{
    offres O(ui->id_of->text().toInt(),ui->nom_of->text(),ui->prix_of->text().toInt(),ui->dat_deb_of->date(),ui->dat_fin_of->date());
       int id_of= ui->id_of->text().toInt();
      int prix_of= ui->prix_of->text().toInt();
      QString nom_of= ui->nom_of->text();
      bool test=O.ajouter();
       N.notification_ajoutOffres();
         if(id_of==0||prix_of==0||nom_of=="")
         {
            QMessageBox::critical(nullptr, QObject::tr("vide"),
                                             QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

         }

           else if(test==true){
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("offres ajoutée:\n"
                 "click ok to exit"),QMessageBox::Ok);
            ui->tab_of->setModel(O.afficher());

         }
         else{QMessageBox::information(nullptr, QObject::tr("database is open"),
                                       QObject::tr("offres existe deja:\n"
                            "click ok to exit"),QMessageBox::Ok);}

            O.ajouter();
}

void MainWindow::on_pb_retour_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pb_supprimer_2_clicked()
{
   offres O1;
        O1.setid_of(ui->off_supp->text().toInt());
        int id_of= ui->off_supp->text().toInt();

        bool test1=O1.supprimer(O1.getid_of());

N.notification_supprimerOffres();

       if(id_of==0)
        {
           QMessageBox::critical(nullptr, QObject::tr("vide"),
                                            QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

        }



        else if(test1==true)
           {QMessageBox::information(nullptr,QObject::tr("datavase is open"),
                                     QObject::tr("offres supprimée:\n"
             "click ok to exit"),QMessageBox::Ok);
         ui->tab_of->setModel(O.afficher());

        }
           else
        {QMessageBox::critical(nullptr,QObject::tr("database is open"),
                                  QObject::tr("offres non supprimée:\n"
               "click ok to exit"),QMessageBox::Ok);}
       O.supprimer(O.getid_of());
}

void MainWindow::on_pb_modifier_2_clicked()
{

   offres O2;
     O2.setid_of(ui->id_modi1->text().toInt());
        O2.setnom_of(ui->nom_modi1->text());
         O2.setprix_of(ui->prix_modi1->text().toInt());
       O2.setdat_deb_of(ui->date_deb2->date());

 O2.modifier(O2.getid_of(),O2.getnom_of(),O2.getprix_of(),O2.getdat_deb_of(),O2.getdat_fin_of());
 int id_of= ui->id_modi1->text().toInt();
 int prix_of= ui->prix_modi1->text().toInt();
 QString nom_of= ui->nom_modi1->text();
N.notification_modifierOffres();
        if(id_of ==0||nom_of==""||prix_of==0)
             {
                QMessageBox::critical(nullptr, QObject::tr("vide"),
                                                 QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);

             }

        else {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("offres modifier:\n"
         "click ok to exit"),QMessageBox::Ok);
            ui->tab_of->setModel(O.afficher());


        }
}

void MainWindow::on_rech_id_2_clicked()
{
    QString id_of = ui->id_rech_2->text();
        ui->tab_of->setModel(O.afficher_id_of(id_of));
}

void MainWindow::on_rech_nom_clicked()
{
    QString nom_of = ui->nom_rech2->text();
        ui->tab_of->setModel(O.afficher_nom_of(nom_of));
}

void MainWindow::on_rech_date_clicked()
{
    QString dat_deb_of = ui->dat_rech->text();
        ui->tab_of->setModel(O.afficher_dat_deb_of(dat_deb_of));
}

void MainWindow::on_trie_id_clicked()
{
     ui->tab_of->setModel( O.trier_id_of());
}

void MainWindow::on_trie_nom_clicked()
{
    ui->tab_of->setModel( O.trier_nom_of());
}

void MainWindow::on_trie_prix_clicked()
{
    ui->tab_of->setModel( O.trier_prix_of());
}

void MainWindow::on_pb_reset_clicked()
{
    offres O;

        ui->tab_of->setModel(O.reset());
}

void MainWindow::on_off_supp_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        query->prepare("SELECT * FROM offres WHERE ID_OF  LIKE'"+arg1+"%' or NOM_OF LIKE'"+arg1+"%' or PRIX_OF LIKE'"+arg1+"%' or DAT_DEB_OF LIKE'"+arg1+"%'or DAT_FIN_OF LIKE'"+arg1+"%' ");
         query->exec();
         if (query->next()) { }
         else {
             QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                             QObject::tr("NO MATCH FOUND !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->off_supp->clear();}
}

void MainWindow::on_id_modi1_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        query->prepare("SELECT * FROM offres WHERE ID_OF  LIKE'"+arg1+"%' or NOM_OF LIKE'"+arg1+"%' or PRIX_OF LIKE'"+arg1+"%' or DAT_DEB_OF LIKE'"+arg1+"%'or DAT_FIN_OF LIKE'"+arg1+"%' ");
         query->exec();
         if (query->next()) { }
         else {
             QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                             QObject::tr("NO MATCH FOUND !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->id_modi1->clear();}
}

void MainWindow::on_pb_retour2_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

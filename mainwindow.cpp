#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include <QSound>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_cartefid->setModel(E.afficher());
    ui->tab_cartefid_2->setModel(E.afficher());
    ui->stackedWidget->setCurrentIndex(0);
    ui->tabWidget->setCurrentIndex(0);
    ui->tab_client->setModel(C.afficher2("XYZ","XYZ","XYZ"));
    ui->tableView->setModel(C.afficher2("XYZ","XYZ","XYZ"));
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
   // statistique_med();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pb_ajouter_clicked()
{bool test;
    Cartefid E(ui->le_cin->text().toInt(),ui->le_nom->text(),ui->le_prenom->text().toInt(),ui->dateTimeEdit->date());
   if(ui->le_nom->text().isEmpty())
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

void MainWindow::on_pb_modifier_clicked()
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

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_a_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_bb_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
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
      ui->tableView->setModel(C.afficher2("XYZ","XYZ","XYZ"));}
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
             ui->tableView->setModel(C.afficher2("XYZ","XYZ","XYZ"));

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
    ui->tableView->setModel(C.afficher2("XYZ","XYZ","XYZ"));}
   else{QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("client nn:\n"
                      "click ok to exit"),QMessageBox::Ok);}


}

void MainWindow::on_pushButton_4_clicked()
{ QSound bells("C:/Users/dhia/Documents/projet/bip.wave");
    bells.play();
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_pushButton_mail_3_clicked()
{

    Smtp* smtp = new Smtp("adel9860@gmail.com", "dhia1620", "smtp.gmail.com", 465);
               connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


             smtp->sendMail("adel9860@gmail.com", "dhia1620" , "0A3DIN NTHABTOU OU BARA","testtttt");




}

void MainWindow::on_pushButton_5_clicked()
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

void MainWindow::on_pushButton_7_clicked()
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

void MainWindow::on_pushButton_8_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_9_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
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

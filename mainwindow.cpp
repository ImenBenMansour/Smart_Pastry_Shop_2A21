#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "connection.h"
#include <QDebug>
#include <QSqlTableModel>
#include "poste.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->tableemploye->setModel(tempemploye.afficher());

    QPixmap pix(":/img/projet.png");
        int w = ui->label_pic->width();
        int h = ui->label_pic->height();
        ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

        QPixmap pix1(":/new/prefix1/img/delete.png");
            int w1 = ui->label_pic1->width();
            int h1 = ui->label_pic1->height();
            ui->label_pic1->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));



    //controle de saisie employe
        ui->id_line->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{8}")));
        ui->line_nom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->line_datenaissance->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{8}")));
      //  ui->line_tel->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
        ui->line_adresse->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{20}")));
       // ui->line_mdp->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]")));
        ui->line_id_poste->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{8}")));
    //controle de saisie poste
        ui->ID_LINE->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{8}")));
      //  ui->line_nbheures->setValidator(new QRegExpValidator(QRegExp("[0-9]{4}")));
       // ui->linejourconges->setValidator(new QRegExpValidator(QRegExp("[0-9]{4}")));
        ui->line_salaire->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{8}")));
        ui->line_prime->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{20}")));


        ui->ID_LINE->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{8}")));
        ui->PAS_LINE->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{20}")));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::login()
{
    if (cn.loginconnection(ui->ID_LINE->text(), ui->PAS_LINE->text()))
    {
        ui->stackedWidget->setCurrentIndex(1);
    } else
    {
        qDebug()<< "non";
    }
}

void MainWindow::on_login_button_clicked()
{
    bool test=false;

        if(ui->ID_LINE->text().isEmpty())
        {ui->ID_LINE->setStyleSheet("border: 1px solid red");

        }
        else {
        ui->ID_LINE->setStyleSheet("border: 1px solid blue");
        }

        if(ui->PAS_LINE->text().isEmpty())
        {ui->PAS_LINE->setStyleSheet("border: 1px solid red");

        }
        else {
        ui->PAS_LINE->setStyleSheet("border: 1px solid blue");
        }

        if(ui->ID_LINE->text().isEmpty()||ui->ID_LINE->text().isEmpty())
        { test=true;
           QMessageBox::warning(this,"we deliver","Veuillez remplir les champs obligatoires marqués en rouge");
        }
        if(test==false)
        {QString id=ui->ID_LINE->text();
        QString mdp=ui->PAS_LINE->text();
    if(id=="yb18" && mdp=="18")
        ui->stackedWidget->setCurrentIndex(1); // thezek l page num n
    else
       { QMessageBox::warning(this,"we deliver","Veuillez vérifier votre mot de passe ou votre identifiant");}
        }

 //   ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_ajouter_button_clicked()
{
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

}



void MainWindow::on_SUPPRIMER8BUTTON_clicked()
{
    int idEmploye = ui->lineEdit_2->text().toInt();
     bool test = tempemploye.supprimer(idEmploye);
     if (test)
      {
         ui->tableemploye->setModel(tempemploye.afficher());
       QMessageBox::information(nullptr, QObject::tr(" suppression employe "),
                              QObject::tr("employe supprimé :"), QMessageBox::Cancel);
      }
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
}

void MainWindow::on_pushButton_recherche_clicked()
{
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
{
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

void MainWindow::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_ajouter_button_2_clicked()
{
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
}

void MainWindow::on_pushButton_4_clicked()
{
    close();
}

void MainWindow::on_modifier_button_2_clicked()
{
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
{
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
{
    int id_poste = ui->line_id_supp->text().toInt();
     bool test = tempposte.supprimer(id_poste);
     if (test)
      {
         ui->tablepostee->setModel(tempposte.afficher());
       QMessageBox::information(nullptr, QObject::tr(" suppression poste "),
                              QObject::tr("poste supprimé :"), QMessageBox::Cancel);
      }
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
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_retour_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}






void MainWindow::on_pushButton_5_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_exporter_button_clicked()
{
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

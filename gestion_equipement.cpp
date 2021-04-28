#include "gestion_equipement.h"
#include "ui_gestion_equipement.h"
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

gestion_equipement::gestion_equipement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gestion_equipement)
{
    ui->setupUi(this);
    this->setWindowTitle("GESTION DES EQUIPEMENTS");
        ui->le_ide->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
        ui->le_nome->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->le_quantitee->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
        ui->le_etate->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->ide_mod->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
        ui->nom_mod_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->quantite_mod_2->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
        ui->etate_mod->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));


}

gestion_equipement::~gestion_equipement()
{
    delete ui;
}

void gestion_equipement::on_pushButton_clicked()
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

void gestion_equipement::on_tabWidget_2_currentChanged(int index)
{
       ui->tab_equipement->setModel(crudEquipement->affichere());
}

void gestion_equipement::on_pb_modifierequipement_clicked()
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

void gestion_equipement::on_pb_suppeq_clicked()
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

void gestion_equipement::on_pushButton_2_clicked()
{
    QPdfWriter pdf("C:/Users/ASUS/Desktop/solo/semestre 2/projet c++/cuisine/Equipements.pdf");

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

void gestion_equipement::on_pushButton_3_clicked()
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

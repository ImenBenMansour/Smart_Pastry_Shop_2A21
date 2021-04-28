#include "gestion_menu.h"
#include "ui_gestion_menu.h"
#include "crud_menu.h"
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
gestion_menu::gestion_menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_menu)
{
    ui->setupUi(this);
    this->setWindowTitle("GESTION DES MENUS");
    ui->le_id->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
        ui->le_nom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->la_categorie->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
        ui->text_delete->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
        ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->lineEdit_3->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->le_prix->setValidator(new QRegExpValidator(QRegExp("^[0-9]*(\.[0-9]+)?$")));
}

gestion_menu::~gestion_menu()
{
    delete ui;
}void gestion_menu::on_pb_ajouter_clicked()
{

    int id = ui->le_id->text().toInt();
    QString nom = ui->le_nom->text();
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





void gestion_menu::on_pb_supprimer_clicked()
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

void gestion_menu::on_tabWidget_currentChanged(int index)// ki t7ot index = 1 ya3ni action tsir kif temchi teckliki ala colonne el indice mt3o 1 sinon mat7ot chy kol mat7el ay colone ysir execution mt3 méthode
{
    //  setmodel heya la partie blanche ta3 widget tableview
    ui->tableView->setModel(crudMenu->afficher_menu());

}



void gestion_menu::on_pb_modifier_clicked()
{
    int id = ui->lineEdit->text().toInt();
    QString nom = ui->lineEdit_2->text();
    QString categorie = ui->lineEdit_3->text();
    double prix = ui->lineEdit_4->text().toDouble();
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




void gestion_menu::on_check_box_id_clicked()
{


    ui->tableView->setModel(crudMenu->afficher_menu());

    if(ui->check_box_id->isChecked() == true)
         ui->tableView->setModel(crudMenu->trie_id());
   else
        ui->tableView->setModel(crudMenu->afficher_menu());

}




void gestion_menu::on_pushButton_clicked()
{
    ui->tableView->setModel(crudMenu->afficher_menu());

    QString text_a_rechercher = ui->searchtxt->text();

    ui->tableView->setModel(crudMenu->recherche_menu_selon_nom(text_a_rechercher));

}



void gestion_menu::on_check_box_nom_clicked()
{
    ui->tableView->setModel(crudMenu->afficher_menu());

    if(ui->check_box_nom->isChecked() == true)
         ui->tableView->setModel(crudMenu->trie_nom());
   else
        ui->tableView->setModel(crudMenu->afficher_menu());

}

void gestion_menu::on_check_box_categorie_clicked()
{
    ui->tableView->setModel(crudMenu->afficher_menu());

    if(ui->check_box_categorie->isChecked() == true)
         ui->tableView->setModel(crudMenu->trie_categorie());
   else
        ui->tableView->setModel(crudMenu->afficher_menu());
}

void gestion_menu::on_pushButton_2_clicked()
{ ui->tableView->setModel(crudMenu->afficher_menu());

    QString text_a_rechercher = ui->searchtxt_2->text();

    ui->tableView->setModel(crudMenu->recherche_menu_selon_categorie(text_a_rechercher));


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

void gestion_menu::on_pushButton_3_clicked()
{
    ui->tableView->setModel(crudMenu->afficher_menu());

        int text_a_rechercher = ui->searchtxt_3->text().toInt();

        ui->tableView->setModel(crudMenu->recherche_menu_selon_id(text_a_rechercher));
}


void gestion_menu::on_pb_imprimer_menu_clicked()
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

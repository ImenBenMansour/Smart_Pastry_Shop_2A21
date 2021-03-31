#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseurs.h"
#include "produits.h"
#include <QSqlQuery>
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "connexion.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_modifier_clicked();

    void on_pb_ajouter_prod_clicked();
    void on_pb_supprimer_prod_clicked();
    void on_pb_modifier_prod_clicked();

    void on_radioB_tri_id_clicked();
    void on_radioB_tri_nom_clicked();
    void on_radioB_tri_prix_clicked();

    void on_pb_rechercher_clicked();

private:
    Ui::MainWindow *ui;
    fournisseurs tmpfournisseur;
    produits tmpProd;
};
#endif // MAINWINDOW_H

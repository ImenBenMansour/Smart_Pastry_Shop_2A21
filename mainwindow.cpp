#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crud_menu.h"
#include <QMessageBox>
#include "gestion_menu.h"
#include "gestion_recette.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    this->setWindowTitle("CUISINE");



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    gestion_menu *g = new gestion_menu(this);
    g->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    gestion_recette *g1 = new gestion_recette(this);
    g1->show();
}

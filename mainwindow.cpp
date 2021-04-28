#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crud_menu.h"
#include <QMessageBox>
#include "gestion_menu.h"
#include "gestion_recette.h"
#include "gestion_equipement.h"
#include"video_play.h"
#include<QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    this->setWindowTitle("CUISINE");
    //arduino
                int ret = A.connect_arduino();
                     switch(ret){
                     case(0): qDebug() << "arduino is available and connected to :" << A.getarduino_port_name();
                         break;
                     case(1): qDebug() << "arduino is available and not connected to :" << A.getarduino_port_name();
                         break;
                     case(-1): qDebug() << "arduino is not available" ;
                     }

                     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));



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



void MainWindow::on_pushButton_3_clicked()
{
    gestion_equipement *g2 = new gestion_equipement(this);
    g2->show();
}

void MainWindow::on_pushButton_4_clicked()
{

    Video_Play *g3 = new Video_Play(this);
    g3->show();
}

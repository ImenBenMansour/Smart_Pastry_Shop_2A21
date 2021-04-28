#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "crud_menu.h"
#include "crud_recette.h"
#include"arduino.h"



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


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    // lorsque on parle d'une interface on fait une déclaration au tant que pointeur
    Arduino A;
    Ui::MainWindow *ui;
    Crud_Menu *crudMenu;
    Crud_Recette *crudRecette;
};
#endif // MAINWINDOW_H

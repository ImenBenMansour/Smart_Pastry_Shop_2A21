#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reclamation.h"
#include <QMainWindow>
#include<QApplication>
#include"promotion.h"

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

    void on_pushButton_clicked();

    void on_pb_retour_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb2_ajouter_clicked();

    void on_pushButton_2_clicked();



    void on_pb_retour3_clicked();

    void on_pb_retour2_clicked();

    void on_pb2_supprimer_clicked();

    void on_pushButton_3_clicked();

    void on_pb_retour4_clicked();

    //void on_radioButton1_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_clicked();



    void on_pdf_clicked();

private:
    Ui::MainWindow *ui;
    reclamation R;
    promotion P;
};
#endif // MAINWINDOW_H

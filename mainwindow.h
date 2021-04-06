#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include"cartefid.h"
#include "clientfid.h"
#include<QPropertyAnimation>
#include <QApplication>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
   // void statistique_med();
    void on_pushButton_clicked();

    void on_pb_ajouter_clicked();

    void on_td_supp_clicked();

    void on_pb_modifier_clicked();

    void on_pushButton_3_clicked();

    void on_a_clicked();

    void on_bb_clicked();

    void on_pushButton_2_clicked();



    void on_ajouterclie_clicked();

    void on_supp_clicked();

    void on_modifierclient_clicked();

    void on_pushButton_4_clicked();



    void on_pushButton_mail_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_c_supp_textChanged(const QString &arg1);

    void on_le_cin_supp_textChanged(const QString &arg1);

    void on_le_cin_modifier_textChanged(const QString &arg1);

    void on_c_cin_modifier_textChanged(const QString &arg1);

private:

    Cartefid E;
    Clientfid C;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

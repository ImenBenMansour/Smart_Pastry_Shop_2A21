#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reclamation.h"
#include <QMainWindow>
#include<QApplication>
#include"promotion.h"
#include"notification.h"
#include"clientfid.h"
#include"cartefid.h"
#include "commande.h"
#include "reservation.h"

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

    void on_le_id_supp2_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_id_modii2_textChanged(const QString &arg1);

    //void on_le_id_rec_textChanged(const QString &arg1);

    void on_le_id_supp_textChanged(const QString &arg1);

    void on_le_id_modi_textChanged(const QString &arg1);

    void on_recherche_textChanged(const QString &arg1);

    void on_rech_id_clicked();

    void on_rech_mail_clicked();

    void on_rech_des_clicked();

    void on_pushButton_8_clicked();
    void on_pushButton_2clicked();

    void on_pb_ajouter_2clicked();

    void on_td_supp_clicked();

    void on_pb_modifier_2clicked();

    void on_pushButton_3_2clicked();

    void on_a_clicked();

    void on_bb_clicked();

    void on_pushButton_2_2clicked();



    void on_ajouterclie_clicked();

    void on_supp_clicked();

    void on_modifierclient_clicked();

    void on_pushButton_4_2clicked();



    void on_pushButton_mail_3_clicked();

    void on_pushButton_5_2clicked();

    void on_pushButton_7_2clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_8_2clicked();

    void on_pushButton_9_clicked();

    void on_c_supp_textChanged(const QString &arg1);

    void on_le_cin_supp_textChanged(const QString &arg1);

    void on_le_cin_modifier_textChanged(const QString &arg1);

    void on_c_cin_modifier_textChanged(const QString &arg1);

    void on_satta_clicked();

    void on_sat_client_clicked();

    void on_pushButton_10_clicked();

    void on_tri_clicked();


    void on_pushButton_19_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_modifier_2_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_5_2_clicked();

    void on_pushButton_7_2_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_21_clicked();

    //malek
    void on_ajouter1_clicked();

    void on_retour1_clicked();

    void on_modifier1_clicked();

    void on_retour2_clicked();

    void on_pushButton0_clicked();

    void on_supprimer1_clicked();

    void on_ajouter2_clicked();

    void on_retour3_clicked();

    void on_pushButton_22_clicked();

    void on_supprimer2_clicked();

    void on_modifier2_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_id_r3_textChanged(const QString &arg1);

    void on_id_r2_textChanged(const QString &arg1);

    void on_code2_textChanged(const QString &arg1);

    void on_code3_textChanged(const QString &arg1);

    void on_rechercher_code_clicked();

    void on_rechercher_nom_clicked();

    void on_rechercher_qt_clicked();

    void on_stat_clicked();

    void on_pb_pdf_clicked();






    void on_code2_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
    reclamation R;
    promotion P;
    Notification N;
    Cartefid E;
    Clientfid C;
    reservation RE;
    commande CO;

};
#endif // MAINWINDOW_H

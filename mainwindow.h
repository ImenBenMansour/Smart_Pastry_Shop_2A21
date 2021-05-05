#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reclamation.h"
#include <QMainWindow>
#include<QApplication>
#include"promotion.h"
#include"notification.h"
#include "arduino.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QRegularExpression>
#include <QTableWidgetItem>
#include <QItemSelectionModel>
#include <QDebug>
#include <QSqlTableModel>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <qtextbrowser.h>

#include <QPropertyAnimation>
#include"offres.h"
#include <QInputDialog>

#include <QTranslator>


#include "arduino.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
//camera

class QCamera ;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;


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

    void on_pb_comptage_clicked();



   void on_chat_clicked();

   void on_Camera_clicked();




   void on_pb_offres_clicked();

   void on_pb_ajouter_2_clicked();

   void on_pb_retour_2_clicked();

   void on_pb_supprimer_2_clicked();

   void on_pb_modifier_2_clicked();

   void on_rech_id_2_clicked();

   void on_rech_nom_clicked();

   void on_rech_date_clicked();

   void on_trie_id_clicked();

   void on_trie_nom_clicked();

   void on_trie_prix_clicked();

   void on_pb_reset_clicked();

   void on_off_supp_textChanged(const QString &arg1);

   void on_id_modi1_textChanged(const QString &arg1);

   void on_pb_retour2_2_clicked();

private:
    Ui::MainWindow *ui;
    reclamation R;
    promotion P;
    Notification N;
    arduino A;
    //camera
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mOptionMenu;
    QAction *mAllumerAction;
    QAction *mEteindreAction;
    QAction *mCapturerAction;
    offres O;






};
#endif // MAINWINDOW_H

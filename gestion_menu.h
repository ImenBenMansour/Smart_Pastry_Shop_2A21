#ifndef GESTION_MENU_H
#define GESTION_MENU_H
#include "crud_menu.h"
#include <QWidget>
#include <QDialog>

namespace Ui {
class gestion_menu;
}

class gestion_menu : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_menu(QWidget *parent = nullptr);

    ~gestion_menu();


private slots:
    void on_pb_ajouter_clicked();


    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_check_box_id_clicked();

    void on_pushButton_clicked();

    void on_check_box_nom_clicked();

    void on_check_box_categorie_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_text_delete_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

private:
    Ui::gestion_menu *ui;
    Crud_Menu *crudMenu;

};

#endif // GESTION_MENU_H

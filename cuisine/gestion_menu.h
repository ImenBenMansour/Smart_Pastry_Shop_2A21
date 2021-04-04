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

private:
    Ui::gestion_menu *ui;
    Crud_Menu *crudMenu;

};

#endif // GESTION_MENU_H

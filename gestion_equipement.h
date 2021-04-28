#ifndef GESTION_EQUIPEMENT_H
#define GESTION_EQUIPEMENT_H

#include <QWidget>
#include "crud_equipement.h"

namespace Ui {
class gestion_equipement;
}

class gestion_equipement : public QWidget
{
    Q_OBJECT

public:
    explicit gestion_equipement(QWidget *parent = nullptr);
    ~gestion_equipement();

private slots:
    void on_pushButton_clicked();

    void on_tabWidget_2_currentChanged(int index);

    void on_pb_modifierequipement_clicked();

    void on_pb_suppeq_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::gestion_equipement *ui;
    crud_equipement * crudEquipement;
};

#endif // GESTION_EQUIPEMENT_H

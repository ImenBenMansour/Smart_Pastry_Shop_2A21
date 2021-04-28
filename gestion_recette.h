#ifndef GESTION_RECETTE_H
#define GESTION_RECETTE_H

#include <QDialog>
#include "crud_recette.h"

namespace Ui {
class gestion_recette;
}

class gestion_recette : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_recette(QWidget *parent = nullptr);
    ~gestion_recette();

private slots:
    void on_pb_ajouter1_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pb_supprimer1_clicked();

    void on_pb_modifier1_clicked();

    void on_lineEdit1_textChanged(const QString &arg1);

    void on_text_delete1_textChanged(const QString &arg1);

    void on_pb_pdf_clicked();

    void on_pushButton_4_clicked();

    void on_pb_imprimer_recette_clicked();

private:
    Ui::gestion_recette *ui;
    Crud_Recette *crudRecette;
};

#endif // GESTION_RECETTE_H

#include "statistics.h"
#include "ui_statistics.h"
#include "crud_recette.h"
#include "crud_menu.h"

statistics::statistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistics)
{
    {
        ui->setupUi(this);
        this->setWindowTitle("STATISTIQUES");
        QPieSeries *series = new QPieSeries();

        Crud_Recette c ;
        Crud_Menu m;
        int  total = c.total_recette()+m.total_menu()/c.total_recette();

        series->append("Recettes",c.total_recette());
        series->append("Total des Menus par rapport au Recettes ",total);
        series->append("Menus",m.total_menu());
        series->setHoleSize(0.2);
        QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();

        QPieSlice *slice1 = series->slices().at(1);
        slice1->setExploded();
        slice1->setLabelVisible();

        QPieSlice *slice2 = series->slices().at(2);
        slice2->setLabelVisible();

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle(" Total des Menu / Recettes :");
        chart->legend()->hide();
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QChartView *chartview = new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        chartview->setParent(ui->horizontalFrame);
    }
}
statistics::~statistics()
{


    delete ui;

}

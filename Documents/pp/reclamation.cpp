#include "reclamation.h"
#include  <QSqlQuery>
#include <QtDebug>
#include<QObject>

int reclamation::getid_rec(){return id_rec;}
QString reclamation::getdes_rec(){return des_rec;}
QString  reclamation::getmail_rec(){return mail_rec;}
QDate reclamation::getdat(){return dat;}
void reclamation::setid_rec(int id_rec){this->id_rec=id_rec;}
void reclamation::setdes_rec(QString des_rec){this->des_rec=des_rec;}
void reclamation::setmail_rec(QString mail_rec){this->mail_rec=mail_rec;}
void reclamation::setdat(QDate dat){this->dat=dat;}
reclamation::reclamation()
{}

reclamation::reclamation(int id_rec,QString des_rec,QString mail_rec,QDate dat)
{
   this->id_rec=id_rec;
 this->des_rec=des_rec;
 this->mail_rec=mail_rec;
   this->dat=dat;


}
bool reclamation::ajouter()
{
    QSqlQuery query;

         query.prepare("INSERT INTO Reclamation (ID_REC, DES_REC, MAIL_REC,DAT) "
                       "VALUES (:id_rec, :des_rec, :mail_rec, :dat)");
         query.bindValue(":id_rec", id_rec);
         query.bindValue(":des_rec", des_rec);
         query.bindValue(":mail_rec", mail_rec);
         query.bindValue(":dat",dat);


    return query.exec();
}
bool reclamation::supprimer(int id_rec)
{
     QSqlQuery query;
    query.prepare("Delete from reclamation where id_rec=:id_rec");
    query.bindValue(":id_rec", id_rec);

   return query.exec();
}
QSqlQueryModel* reclamation::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM reclamation");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_rec"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("des_rec"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("mail_rec"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("dat"));



    return model;
}

bool reclamation::modifier(int id_rec,QString des_rec,QString mail_rec,QDate dat)
{

    QSqlQuery query;
    query.prepare("UPDATE reclamation set id_rec=:id_rec, des_rec=:des_rec, mail_rec=:mail_rec ,dat=:dat  WHERE id_rec=:id_rec");
    query.bindValue(":id_rec",id_rec);
    query.bindValue(":des_rec",des_rec);
    query.bindValue(":mail_rec",mail_rec);
    query.bindValue(":dat",dat);

    return query.exec();
}

bool reclamation::testmail(QString mail_rec){
    int test=0;
    for(int i = 0; i < mail_rec.size(); i++) {
if(mail_rec[i]=="@")
{test++;

}}
    for(int i = 0; i < mail_rec.size(); i++) {
if((test==1)&&(mail_rec[i]=="."))
{if(mail_rec.size()>i+1)
    return true;
}}
return false;}
void reclamation::exporter(QTableView *table)
{

    QString filters("CSV files (.csv);;All files (.*)");
    QString defaultFilter("CSV files (*.csv)");
    QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                                    filters, &defaultFilter);
    QFile file(fileName);
    QAbstractItemModel *model =  table->model();
    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream data(&file);
        QStringList strList;
        for (int i = 0; i < model->columnCount(); i++)
        {
            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
            else
                strList.append("");
        }
        data << strList.join(";") << "\n";
        for (int i = 0; i < model->rowCount(); i++)
        {
            strList.clear();
            for (int j = 0; j < model->columnCount(); j++)
            {

                if (model->data(model->index(i, j)).toString().length() > 0)
                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") + "\n";
        }
        file.close();
    }
}

QSqlQueryModel* reclamation::afficher_id_rec(QString id_rec)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM RECLAMATION WHERE ID_REC=:id_rec ");
    query.bindValue(":id_rec", id_rec);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_REC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DES_REC"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL_REC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DAT"));
    return model;
}

bool reclamation::search_id_rec(QString id_rec)
{
    QSqlQuery query;
    query.prepare("SELECT ID FROM RECLAMATION WHERE ID_REC=:id_rec");
    query.bindValue(":id_rec", id_rec);
    query.exec();

    if(query.size()!=id_rec){return false;}
    else return true;
}

QSqlQueryModel* reclamation::afficher_mail_rec(QString mail_rec)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM RECLAMATION WHERE MAIL_REC=:mail_rec ");
    query.bindValue(":mail_rec", mail_rec);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_REC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DES_REC"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL_REC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DAT"));
    return model;
}

bool reclamation::search_mail_rec(QString mail_rec)
{
    QSqlQuery query;
    query.prepare("SELECT NOM FROM RECLAMATION WHERE MAIL_REC=:mail_rec");
    query.bindValue(":mail_rec", mail_rec);
    query.exec();

    if(query.size()!=mail_rec){return false;}
    else return true;
}
QSqlQueryModel* reclamation::afficher_des_rec(QString des_rec)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM RECLAMATION WHERE DES_REC=:des_rec ");
    query.bindValue(":des_rec", des_rec);
    QSqlQueryModel* model= new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_REC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DES_REC"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL_REC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DAT"));
    return model;
}
QSqlQueryModel * reclamation::reset(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from RECLAMATION  ");

    return  model;
}

bool reclamation::search_des_rec(QString des_rec)
{
    QSqlQuery query;
    query.prepare("SELECT NOM FROM RECLAMATION WHERE DES_REC=:des_rec");
    query.bindValue(":des_rec", des_rec);
    query.exec();

    if(query.size()!=des_rec){return false;}
    else return true;
}

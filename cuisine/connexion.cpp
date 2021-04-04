#include "connexion.h"
#include <QDebug>
Connexion::Connexion()
{

}



bool Connexion::create_connexion() {
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");//initialisation de la connexion avec la base de donnée grace au  pilote odbc bch tnjm torbt app qt bel base donnée
    db.setDatabaseName("projet2A");
    db.setUserName("molka");
    db.setPassword("user");


    qDebug()<<db.lastError();
    if(db.open()) {
        test = true;
    }

    return test;

}

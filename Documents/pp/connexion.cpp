#include "connexion.h"
#include "QSqlDatabase"
connexion::connexion()
{

}
bool connexion::createconnexion(){
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet_2A");
    db.setUserName("noura");
    db.setPassword("noura");


    if(db.open())
        test=true;
    return(test);
}

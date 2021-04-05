#include "connexion.h"
#include "QSqlDatabase"
connexion::connexion()
{

}
bool connexion::createConnection(){
    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet_2A");
    db.setUserName("dhia");
    db.setPassword("3442");
    if(db.open())
    test=true;
return test;

}

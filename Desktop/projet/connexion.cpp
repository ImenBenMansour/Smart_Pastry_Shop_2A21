#include "connexion.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("base");
db.setUserName("riadh");
db.setPassword("SYSTEM");

if (db.open())
test=true;





    return  test;
}

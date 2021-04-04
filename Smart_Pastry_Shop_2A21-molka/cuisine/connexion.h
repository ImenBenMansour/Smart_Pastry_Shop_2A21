#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


class Connexion
{
public:
    Connexion();
   bool create_connexion();
};

#endif // CONNEXION_H

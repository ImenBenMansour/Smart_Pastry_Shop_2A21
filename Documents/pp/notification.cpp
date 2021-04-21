#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
Notification::Notification()
{

}

void Notification::notification_ajoutReclamation()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestionnaire service à la clientèle "," Reclamation ajoutée ",QSystemTrayIcon::Information,15000);
}
void Notification::notification_ajoutPromotion()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestionnaire service à la clientèle ","Promotion ajoutée ",QSystemTrayIcon::Information,15000);
}
void Notification::notification_supprimerReclamation(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestionnaire service à la clientèle ","reclamation Supprimé",QSystemTrayIcon::Information,15000);
}
void Notification::notification_supprimerPromotion(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestionnaire service à la clientèle ","promotion supprimé",QSystemTrayIcon::Information,15000);

}
void Notification::notification_modifierReclamation(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestionnaire service à la clientèle "," reclamation modifié",QSystemTrayIcon::Information,15000);

}
void Notification::notification_modifierPromotion(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestionnaire service à la clientèle  ","promotion modifié",QSystemTrayIcon::Information,15000);

}

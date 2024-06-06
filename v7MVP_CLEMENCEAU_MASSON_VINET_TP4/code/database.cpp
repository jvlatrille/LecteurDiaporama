#include "database.h"
#include "QSqlError"

database::database() {
    // Essayer d'ouvrir la base de données
    if(ouvrirBD()) {
        qDebug() << "Ouverture réussie"; // Si ça marche, on le dit
    }
    else {
        qDebug() << "Ouverture ratée"; // Sinon, on le dit aussi
    }
}

database::~database()
{
    fermerBD(); // Fermer la base de données quand on détruit
}

bool database::ouvrirBD()
{
    maBD = QSqlDatabase::addDatabase(CONNECT_TYPE); // Configurer le type de connexion
    maBD.setDatabaseName(DATABASE_NAME); // Donner le nom de la base de données
    if (!maBD.open()) {
        qDebug() << "Problème de connexion à la base de données : " << maBD.lastError().text(); // En cas de problème, on affiche l'erreur
        return false; // Retourner false si ça marche pas
    }
    qDebug() << "Connexion à la BD réussie";
    return true; // Retourner true si ça marche
}

bool database::fermerBD()
{
    if (maBD.isOpen()) {
        maBD.close(); // Fermer la base de données si elle est ouverte
        return true; // Retourner true si ça marche
    }
    return false; // Retourner false si elle n'était pas ouverte
}

QSqlDatabase database::getDatabase() const
{
    return maBD;
}

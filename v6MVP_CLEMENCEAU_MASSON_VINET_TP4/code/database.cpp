#include "database.h"


database::database() {
    // Essayer d'ouvrir
    if(ouvrirBD()) {
        qDebug() << "Ouverture réussie";
    }
    else {
        qDebug() << "Ouveture ratée";
    }
}

database::~database()
{
    fermerBD();
}

bool database::ouvrirBD()
{
    maBD = QSqlDatabase::addDatabase(CONNECT_TYPE);
    maBD.setDatabaseName(DATABASE_NAME);
    if (!maBD.open()) {
        qDebug() << "Problème de connexion à la base de donnée" ;
        return false;
   }
   qDebug() << "Connexion à la bd réussie";
   return true;
}


bool database::fermerBD()
{
    if (maBD.isOpen()) {
        maBD.close();
        return true;
    }
    return false;
}


/*
void database::chargerDiaposBD()
{
    QSqlQuery query;
    QString requete;
    requete = "SELECT * FROM Diapos ";
    query.prepare(requete);

    Diaporama diaporamasInfos;

        if (!query.exec()) {
            qDebug() << "Erreur lors de l'exécution de la requête :";
        }

        while (query.next()) {
            InfosDiaporama infosDiapoCourant;
            infosDiapoCourant.id = query.value(0).toUInt();
            infosDiapoCourant.titre = query.value(1).toString().toStdString();
            infosDiapoCourant.vitesseDefilement = query.value(2).toUInt();

            diaporamas.push_back(infosDiapoCourant);
        }
}
*/

#ifndef DATABASE_H
#define DATABASE_H

#include "user.h"
#include "bronzeuser.h"
#include "silveruser.h"
#include "admin.h"
#include "container.h"

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>
#include <QFile>

using namespace std;    // DA TOGLIERE
#include <iostream>     // DA TOGLIERE
#include "mainwindow.h"  // DA TOGLIERE
#include <QMessageBox>  // DA TOGLIERE


class DataBase {
private:
    QFile* file;

    Container<BronzeUser> userB;
    Container<SilverUser> userS;
    Container<Admin> admin;

public:
    DataBase();

    bool loadAdmin (); // Carico gli amministratori nel contenitore

    bool verifyAllUsername (const string&) const; // Ritorna true se l'username passato esiste già (tra bronze e silver)

    Admin getAdmin (const string&) const;   // Ritorna l'oggetto Admin con username uguale a quello passato

    bool verifyLoginAdmin (const string&, const int&) const;    // Verifica i dati che i dati di accesso dell'amministratore siano corretti


    bool loadBronze(); // Carico gli utenti bronze nel contenitore

    BronzeUser getBronze (const string&) const; // Ritorna l'oggetto BronzeUser con username uguale a quello passato

    bool verifyLoginBronze (const string&, const int&) const;    // Verifica i dati che i dati di accesso dell'utente bronze siano corretti

    bool verifyNumberBronze (const int&) const;  // Verifica se il numero di conto passato appartiene ad un utente bronze

    BronzeUser getBronzeByCount (const int&) const; // Ritorna l'oggetto BronzeUser con numero di conto uguale a quello passato

    bool verifyStillBronze (const BronzeUser&); // Verifica se l'oggetto BronzeUser soddisfa i requisiti oppure passa a Silver

    bool writeBronze (); // Scrive nel DB relativo agli utenti Bronze la lista di utenti Bronze passata


    bool loadSilver(); // Carico gli utenti silver nel contenitore

    SilverUser getSilver (const string&) const; // Ritorna l'oggetto SilverUser con username uguale a quello passato

    bool verifyLoginSilver (const string&, const int&) const;    // Verifica i dati che i dati di accesso dell'utente silver siano corretti

    bool verifyNumberSilver (const int&) const;  // Verifica se il numero di conto appartiene ad un utente silver

    SilverUser getSilverByCount (const int&) const; // Ritorna l'oggetto SilverUser con numero di conto uguale a quello passato

    bool verifyStillSilver (const SilverUser&); // Verifica se l'oggetto SilverUser soddisfa i requisiti oppure scende a Bronze

    bool writeSilver (); // Scrive nel DB relativo agli utenti Silver la lista di utenti Silver passata
};
#endif // DATABASE_H

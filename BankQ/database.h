#ifndef DATABASE_H
#define DATABASE_H

#include "user.h"
#include "basicuser.h"
#include "prouser.h"
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

#include "userinfo.h"


class DataBase {
private:
    QFile* file;

    Container<User> user;

public:
    DataBase();

    bool load (); // Carico gli amministratori nel contenitore

    bool verifyAdmin (const string&) const; // Ritorna true se l'username passato appartiene ad un amministratore

    bool verifyExistingUsername (const string&) const; // Ritorna true se l'username passato esiste già (tra Basic e Pro)

    bool verifyExistingCountNumber (const int&) const; // Ritorna true se il #conto passato passato esiste già

    //Admin getAdmin (const string&) const;   // Ritorna l'oggetto Admin con username uguale a quello passato

    bool verifyLogin (const string&, const int&) const;    // Verifica i dati che i dati di accesso dell'amministratore siano corretti

    bool addUser (const BasicUser&);    // Inserisce un nuovo utente nel DB

    //bool loadBasic(); // Carico gli utenti Basic nel contenitore

    //bool verifyBasic (const string&) const; // Ritorna true se l'username passato appartiene ad un utente Basic

    User* getUser (const string&) const; // Ritorna l'oggetto User con username uguale a quello passato

    //bool verifyLoginBasic (const string&, const int&) const;    // Verifica i dati che i dati di accesso dell'utente Basic siano corretti

    //bool verifyNumberBasic (const int&) const;  // Verifica se il numero di conto passato appartiene ad un utente Basic

    User* getUserByCountNumber (const int&) const; // Ritorna l'oggetto User con numero di conto uguale a quello passato

    bool verifyStillSame (const BasicUser&); // Verifica se l'utente cambia tipo di account o meno

    //bool fromBasicToPro (const BasicUser&); // "Passa" un utente Basic in utente Pro

    bool remove (const User&); // Rimuove dal DB l'utente passato

    bool write (); // Scrive nel DB relativo agli utenti Basic la lista di utenti Basic passata


    bool charge (const string&, const int&, const int&);    // Ricarica il conto del destinatario e riduce quello del mittente

    //bool loadPro(); // Carico gli utenti Pro nel contenitore

   // bool verifyPro (const string&) const; // Ritorna true se l'username passato appartiene ad un utente Pro

    //ProUser getPro (const string&) const; // Ritorna l'oggetto ProUser con username uguale a quello passato

    //bool verifyLoginPro (const string&, const int&) const;    // Verifica i dati che i dati di accesso dell'utente Pro siano corretti

    /*?????*/bool verifyNumberPro (const int&) const;  // Verifica se il numero di conto appartiene ad un utente Pro

    //ProUser getProByCount (const int&) const; // Ritorna l'oggetto ProUser con numero di conto uguale a quello passato

    //bool verifyStillPro (const ProUser&); // Verifica se l'oggetto ProUser soddisfa i requisiti oppure scende a Basic

    //bool removePro (const ProUser&); // Rimuove dal DB l'utente passato

    //bool writePro (); // Scrive nel DB relativo agli utenti Pro la lista di utenti Pro passata

    Container<BasicUser> getUserNoAdmin (); // Ritorna una lista con gli utenti nel DB ad eccezione degli amministraotri

    Container<ProUser> getUserNoRequest ();    // Ritorna una lista di utenti Pro senza richieste di bonus anticipato

    bool giveBonus (const User&);    // Assegna il bonus all'utente passato

    bool giveBonusToAll (); // Assegna il bonus agli utenti che non lo hanno ancora ricevuto
};
#endif // DATABASE_H

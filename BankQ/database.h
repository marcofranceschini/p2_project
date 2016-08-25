#ifndef DATABASE_H
#define DATABASE_H

#include "admin.h"
#include "prouser.h"
#include "userinfo.h"   // Per visualizzare i messaggi pop-up
#include "container.h"
#include "messagesdatabase.h"


#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>

class DataBase {
private:
    QFile* file;

    Container<User> user;

public:
    DataBase();

    bool load ();                                               // Carica gli utenti nel contenitore

    bool verifyAdmin (const string&) const;                     // Ritorna true se l'username passato appartiene ad un amministratore

    bool verifyExistingUsername (const string&) const;          // Ritorna true se l'username passato esiste già (tra Basic e Pro)

    bool verifyExistingUsernameException (const string&, const string&) const; // Ritorna true se l'username passato esiste già (tra Basic e Pro) tranne se è uguale a quello passato

    bool verifyExistingCountNumber (const int&) const;          // Ritorna true se il #conto passato passato esiste già

    bool verifyExistingCountNumberException (const int&, const int&) const;    // Ritorna true se il #conto passato passato esiste già (se è diverso da quello "vecchio")

    bool verifyLogin (const string&, const string&) const;      // Verifica i dati che i dati di accesso dell'amministratore siano corretti

    bool addUser (const BasicUser&);                            // Inserisce un nuovo utente nel DB

    User* getUser (const string&) const;                        // Ritorna l'oggetto User con username uguale a quello passato

    User* getUserByCountNumber (const int&) const;              // Ritorna l'oggetto User con numero di conto uguale a quello passato

    bool verifyStillSame (const BasicUser&);                    // Verifica se l'utente cambia tipo di account o meno

    bool remove (const User&);                                  // Rimuove dal DB l'utente passato

    bool write ();                                              // Scrive nel DB gli utenti presenti nel contenitore

    bool charge (const string&, const int&, const int&);        // Ricarica il conto del destinatario e riduce quello del mittente

    Container<BasicUser> getUserNoAdmin () const;               // Ritorna una lista con gli utenti nel DB ad eccezione degli amministraotri

    Container<ProUser> getUserNoRequest () const;               // Ritorna una lista di utenti Pro senza richieste di bonus anticipato

    bool giveBonus (const User&);                               // Assegna il bonus all'utente pro passato

    void giveBonusToAll ();                                     // Assegna il bonus agli utenti pro che non lo hanno ancora ricevuto

    void unlockAll ();                                          // "Sblocca" gli utenti (mette request "false" a tutti i pro)

    bool replace (const User&, const User&);                    // Rimpiazza nella lista il primo utente (username) con il secondo
};

#endif // DATABASE_H

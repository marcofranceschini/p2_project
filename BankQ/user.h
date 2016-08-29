#ifndef USER_H
#define USER_H

using namespace std;
#include <string>

class User {

protected:
    string name;        // Nome
    string surname;     // Cognome
    string address;     // Indirizzo
    string telephone;   // Numero di telefono (string perchè quando un numero inizia per 0 se è intero viene tolto)
    string code;        // Codice fiscale
    string username;    // Username (univoco)
    string pin;         // PIN intero di 5 cifre (string - vedi telefono)

public:

    User (string, string, string, string, string, string, string);

    User ();

    virtual ~User ();

    virtual User* clone () const;

    // Metodi get
    string getName () const;

    string getSurname () const;

    string getAddress () const;

    string getTelephone () const;

    string getCode () const;

    string getUsername () const;

    string getPin () const;


    // Metodi set
    void setName (const string&);

    void setSurname (const string&);

    void setAddress (const string&);

    void setTelephone (const string&);

    void setCode (const string&);

    void setUsername (const string&);

    void setPin (const string&);
};

#endif // USER_H

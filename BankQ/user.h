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
    int pin;            // PIN intero di 5 cifre

public:

    User (string, string, string, string, string, string, int);

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

    int getPin () const;


    // Metodi set
    void setName (const string&);

    void setSurname (const string&);

    void setAddress (const string&);

    void setTelephone (const string&);

    void setCode (const string&);

    void setUsername (const string&);

    void setPin (const int&);

    /*bool verifyLogin (string usr, int pass) const {
        return (username == usr && pin == pass);
        if(username == usr && pin == pass)
            //return true; // Dati del login verificati
            //if(dynamic_cast<Admin*>(utenti[it])) // Verifico che l'utente sia un amministratore
              //  admin = true;
            return true;
        else
            return false;


        string vet = new string[2];
        bool flag = false;
        for (int i=0; utenti.size() && !flag; ++i) {
            if(utenti[i].getUsername() == usr && utenti[i].getUsername() == pass) {
                flag = true;
                vet[0] = usr;
                if(dynamic_cast<Admin>(utenti[i])) // Verifico se l'utente è un amministratore
                    vet[1] = "1";
                else
                    vet[1] = "0";
            }
        }
        return vet;

    }*/
};

#endif // USER_H

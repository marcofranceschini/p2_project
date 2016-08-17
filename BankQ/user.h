#ifndef USER_H
#define USER_H

using namespace std;
#include <string>
#include "container.h"
//#include <QDate>
//#include <ctime> // Usato per birth


class User {
//private:
protected:
    string name;
    string surname;
    //Qdate birth;
    string address;
    int telephone;
    string code; // Codice fiscale - univoco
    //string username;
    //int pin;
   // bool admin; // 0 se non è amministratore, 1 altrimenti --> NO USO IL DYANMIC CAST

    string username;
    int pin;
public:

    /*User(string n, string s, string a, int t, string c) {
        name=n;
        surname=s;
        address=a;
        telephone=t;
        code=c;
    }*/
    User (string, string, string, int, string, string, int);

    User ();

    //User (User const&);

    virtual ~User ();

    virtual User* clone () const;


    // Metodi get
    string getName () const;

    string getSurname () const;

    string getAddress () const;

    int getTelephone () const;

    string getCode () const;

    string getUsername () const;

    int getPin () const;


    // Metodi set
    void setName (const string&);

    void setSurname (const string&);

    void setAddress (const string&);

    void setTelephone (const int&);

    void setCode (const string&);

    void setUsername (const string&);

    void setPin (const int&);



    //virtual bool verifyLogin (const int&) const;

    /*void setAdmin (int a) {
        admin=a;
    }*/

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

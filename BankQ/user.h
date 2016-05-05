#ifndef USER_H
#define USER_H

using namespace std;
#include <string>
#include "container.h"
//#include <QDate>
//#include <ctime> // Usato per birth


class User {
    private:
        string name;
        string surname;
        //Qdate birth;
        string address;
        int telephone;
        string code; // Codice fiscale - univoco
        string username;
        int pin;
       // bool admin; // 0 se non è amministratore, 1 altrimenti --> NO USO IL DYANMIC CAST

    public:

        /*User(string n, string s, string a, int t, string c) {
            name=n;
            surname=s;
            address=a;
            telephone=t;
            code=c;
        }*/
        /*User(string n, string s, string a, int t, string c, string u, int p, bool ad):
            name(n), surname(s), address(a), telephone(t), code(c), username(u), pin(p), admin(ad) {}*/
        User();

        virtual ~User() {}


        // Metodi get
        string getName () const {
            return name;
        }

        string getSurname () const {
            return surname;
        }

        string getAddress () const {
            return address;
        }

        int getTelephone () const {
            return telephone;
        }

        string getCode () const {
            return code;
        }

        string getUsername () const {
            return username;
        }

        int getPin () const {
            return pin;
        }

        /*int getAdmin () const {
            return admin;
        }*/

        // Metodi set
        void setName (string n) {
            name=n;
        }

        void setSurname (string s) {
            surname=s;
        }

        void setAddress (string a) {
            address=a;
        }

        void setTelephone (int t) {
            telephone=t;
        }

        void setCode (string c) {
            code=c;
        }

        void setUsername (string u) {
            username=u;
        }

        void setPin (int p) {
            pin=p;
        }

        /*void setAdmin (int a) {
            admin=a;
        }*/

        bool verifyLogin(string usr, int pass) const {
            if(username == usr && pin == pass)
                //return true; // Dati del login verificati
                //if(dynamic_cast<Admin*>(utenti[it])) // Verifico che l'utente sia un amministratore
                  //  admin = true;
                return true;
            else
                return false;

            /*string vet = new string[2];
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
            return vet;*/

        }
};
#endif // USER_H

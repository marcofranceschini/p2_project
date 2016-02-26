#ifndef USER_H
#define USER_H

using namespace std;
#include <string>
//#include <QDate>
//#include <ctime> // Usato per birth


class User {
    private:
        string name;
        string surname;
        //Qdate birth;
        string address;
        int telephone;
        string code; // Codice fiscale è univoco
        string username;
        int pin;
        bool admin; // 0 se non è amministratore, 1 altrimenti
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

        ~User();

        string getName () {
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

        void closeAccount (const string usr) {

        }
};
#endif // USER_H

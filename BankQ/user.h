#ifndef USER_H
#define USER_H

//using namespace std::string;
//#include <QDate>
#include <ctime> // Usato per birth
#include <QString>

class User {
    private:
        QString name;
        QString surname;
        //Qdate birth;
        QString address;
        int telephone;
        QString code; // Codice fiscale è univoco
        QString username;
        int pin;
    public:
        /*User(string n, string s, string a, int t, string c) {
            name=n;
            surname=s;
            address=a;
            telephone=t;
            code=c;
        }*/
        User();

        ~User();

        QString getName () {
            return name;
        }

        QString getSurname () const {
            return surname;
        }

        QString getAddress () const {
            return address;
        }

        int getTelephone () const {
            return telephone;
        }

        QString getCode () const {
            return code;
        }

        QString getUsername () const {
            return username;
        }

        int getPin () {
            return pin;
        }
};
#endif // USER_H

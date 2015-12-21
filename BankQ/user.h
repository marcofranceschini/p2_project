#ifndef USER_H
#define USER_H

using namespace std;
//using namespace std::string;
//#include <QDate>
#include <ctime> // Usato per birth
#include <string>

class User {
    private:
        string name;
        string surname;
        //Qdate birth;
        string address;
        int telephone;
        string code; // Codice fiscale è univoco
    public:
        User();


    string getName () {
        return name;
    }

    string getSurname () {
        return surname;
    }

    string getAddress () {
        return address;
    }

    int getTelephone () {
        return telephone;
    }

    string getCode () {
        return code;
    }
};
#endif // USER_H

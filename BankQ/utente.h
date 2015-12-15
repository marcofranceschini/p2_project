#ifndef UTENTE_H
#define UTENTE_H

using namespace std;
//using namespace std::string;
//#include <QDate>
#include <ctime> // Usato per birth
#include <string>

class Utente {
    private:
        string name;
        string surname;
        //Qdate birth;
        string address;
        int telephone;
        string code; // Codice fiscale è univoco
};

#endif // UTENTE_H

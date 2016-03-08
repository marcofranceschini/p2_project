#ifndef DATABASE_H
#define DATABASE_H

using namespace std;
#include <QFile>

template <class T>
class DataBase {
    private:
        QFile* file;
        T* utenti;  // Array di utenti
    public:
        DataBase();
        bool loadDB(); // Funzione per caricare gli utenti del DB nel contenitore
        string* verifyLogin(QString, QString) const; // Sse i dati di login sono corretti ritorna i dati dell'utente, altrimenti è vuoto
};

#endif // DATABASE_H

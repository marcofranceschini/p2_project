#ifndef DATABASE_H
#define DATABASE_H

using namespace std;
#include <QFile>

template <class T>
class DataBase {
    private:
        QFile* file;
        //T* utenti;  // Array di utenti - spostato tutto nella classe container
    public:
        DataBase();

        bool loadDB(T & ); // Funzione per caricare gli utenti del DB nel contenitore (vector)

        string* verifyLogin(string, string) const; // Sse i dati di login sono corretti ritorna i dati dell'utente, altrimenti è vuoto
};

#endif // DATABASE_H

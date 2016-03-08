#ifndef DATABASE_H
#define DATABASE_H

#include <QFile>

template <class T>
class DataBase {
    private:
        QFile* file;
        T* utenti;  // Array di utenti
    public:
        DataBase();
        bool loadDB(); // Funzione per caricare un nuovo utente nel DB
};

#endif // DATABASE_H

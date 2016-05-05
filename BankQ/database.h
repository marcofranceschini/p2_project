#ifndef DATABASE_H
#define DATABASE_H

using namespace std;
#include "container.h"
#include <QFile>

class DataBase {
    private:
        QFile* file;
        //T* utenti;  // Array di utenti - spostato tutto nella classe container
    public:
        DataBase();

        template <class T>
        bool loadDB(Container <T> & ); // Funzione per caricare gli utenti del DB nel contenitore (vector)
};

#endif // DATABASE_H

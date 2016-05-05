#ifndef DATABASE_H
#define DATABASE_H

using namespace std;
#include "container.h"
#include <QFile>

class DataBase {
    private:
        QFile* file;

    public:
        DataBase();

        template <class T>
        bool loadDB(Container <T> & ); // Funzione per caricare gli utenti del DB nel contenitore (lista)
};

#endif // DATABASE_H

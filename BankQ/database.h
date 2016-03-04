#ifndef DATABASE_H
#define DATABASE_H

#include <QFile>

template <class T>
class DataBase {
    private:
        QFile* file;
        T* array;
    public:
        DataBase();
};

#endif // DATABASE_H

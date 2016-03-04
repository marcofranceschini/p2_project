#include "database.h"

template <class T>
DataBase::DataBase() {
    database::file = new QFile("/home/marco/Documents/p2_project/Database/db.xml");
}


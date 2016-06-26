#include "database.h"

DataBase::DataBase() {
    DataBase::file = new QFile("db.xml");
    //loadDB();
}

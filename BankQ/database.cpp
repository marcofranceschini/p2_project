#include "database.h"

DataBase::DataBase() {
    DataBase::file = new QFile("Database/db.xml");
    //loadDB();
}

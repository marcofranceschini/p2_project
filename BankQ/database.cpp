#include "database.h"

DataBase::DataBase() {
    DataBase::file = new QFile("/home/marco/Documents/p2_project/Database/db.xml");
    //loadDB();
}

using namespace std;

#include "database.h"
#include "user.h"
#include "admin.h"

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>

//template <class T>
DataBase/*<T>*/::DataBase() {
    DataBase::file = new QFile("/home/marco/Documents/p2_project/Database/db.xml");
    //loadDB();
}

template <class T>
bool DataBase::loadDB(Container <T>& utenti) { // Carico il DB nel contenitore
    if (DataBase::file->exists()) {

        DataBase::file->open(QIODevice::ReadOnly);
        QXmlStreamReader xmlReader(DataBase::file);

        while (!xmlReader.atEnd()) {
            xmlReader.readNext();
            if (xmlReader.isStartElement()) {
                if (xmlReader.name().toString() == "user") {
                    xmlReader.readNext();
                    //User utente;
                    QXmlStreamReader app = xmlReader;
                    bool flag; // true se ho un utente normale

                    while (app.name().toString() != "user" && !flag) {
                        if (xmlReader.name().toString() == "salary")
                            flag = true;
                    }

                    if(flag) {  // Amministratore
                        Admin utente;
                        while (xmlReader.name().toString() != "user") {
                            if (xmlReader.name().toString() == "nome")
                                utente.setName(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "cognome")
                                utente.setSurname(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "codiceFiscale")
                                utente.setCode(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "indirizzo")
                                utente.setAddress(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "telefono")
                                utente.setTelephone(xmlReader.readElementText().toInt(false, 10)); // INT
                            if (xmlReader.name().toString() == "username")
                                utente.setUsername(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "pin")
                                utente.setPin(xmlReader.readElementText().toInt(false, 10)); // INT
                            xmlReader.readNext();
                        }
                        utenti = utente;
                    }else{  // Utente con conto - VERIFICARE CHE UTENTE È (bronze, silver, gold) [dynamic cast]
                        User utente;
                        while (xmlReader.name().toString() != "user") {
                            if (xmlReader.name().toString() == "nome")
                                utente.setName(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "cognome")
                                utente.setSurname(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "codiceFiscale")
                                utente.setCode(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "indirizzo")
                                utente.setAddress(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "telefono")
                                utente.setTelephone(xmlReader.readElementText().toInt(false, 10)); // INT
                            if (xmlReader.name().toString() == "username")
                                utente.setUsername(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "pin")
                                utente.setPin(xmlReader.readElementText().toInt(false, 10)); // INT
                            xmlReader.readNext();
                        }
                        utenti = utente;
                    }
                }
            }
        }

        DataBase::file->close();

        if (xmlReader.hasError()) return false;
    }
    return true;
}



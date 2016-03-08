#include "database.h"
#include "user.h"
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>

template <class T>
DataBase<T>::DataBase() {
    DataBase::file = new QFile("/home/marco/Documents/p2_project/Database/db.xml");
}

template <class T>
bool DataBase<T>::loadDB() { // Aggiungo un nuovo utente
    if (DataBase::file->exists()) {
        DataBase::file->open(QIODevice::ReadOnly);

        QXmlStreamReader xmlReader(DataBase::file);
        while (!xmlReader.atEnd()) {
            xmlReader.readNext();
            if (xmlReader.isStartElement()) {
                if (xmlReader.name().toString() == "user") {
                    xmlReader.readNext();
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
                            utente.setTelephone(xmlReader.readElementText()); // INT
                        if (xmlReader.name().toString() == "username")
                            utente.setUsername(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "pin")
                            utente.setPin(xmlReader.readElementText()); // INT
                        if (xmlReader.name().toString() == "admin")
                            utente.setAdmin(xmlReader.readElementText()); // BOOL
                        xmlReader.readNext();
                    }
                    DataBase::utenti.push_back(utente);
                }
            }
        }
        DataBase::file->close();
        if (xmlReader.hasError()) return false;
    }
    return true;
}

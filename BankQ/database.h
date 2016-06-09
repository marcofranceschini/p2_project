#ifndef DATABASE_H
#define DATABASE_H

#include "user.h"
#include "bronzeuser.h"
#include "silveruser.h"
#include "admin.h"
#include "container.h"

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>
#include <QFile>

#include "mainwindow.h"

class DataBase {
    private:
        QFile* file;

    public:
        DataBase();

    template <class T>
    bool loadDB(Container<T>& utenti) { // Carico il DB nel contenitore
        if (file->exists()) {
                file->open(QIODevice::ReadOnly);
                QXmlStreamReader xmlReader(file);

                while (!xmlReader.atEnd()) {
                    xmlReader.readNext();
                    if (xmlReader.isStartElement()) {
                        if (xmlReader.name().toString() == "admin") {
                            Admin admin;
                            xmlReader.readNext();
                            while (xmlReader.name().toString() != "admin") {
                                if (xmlReader.name().toString() == "nome")
                                    admin.setName(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "cognome")
                                    admin.setSurname(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "codiceFiscale")
                                    admin.setCode(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "indirizzo")
                                    admin.setAddress(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "telefono")
                                    admin.setTelephone(xmlReader.readElementText().toInt()); // INT
                                if (xmlReader.name().toString() == "username")
                                    admin.setUsername(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "pin")
                                    admin.setPin(xmlReader.readElementText().toInt()); // INT
                                xmlReader.readNext();
                            }
                            utenti.push_back(&admin);
                        } else if (xmlReader.name().toString() == "silver") {
                            SilverUser uSilver;
                            xmlReader.readNext();
                            while (xmlReader.name().toString() != "silver") {
                                if (xmlReader.name().toString() == "nome")
                                    uSilver.setName(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "cognome")
                                    uSilver.setSurname(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "codiceFiscale")
                                    uSilver.setCode(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "indirizzo")
                                    uSilver.setAddress(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "telefono")
                                    uSilver.setTelephone(xmlReader.readElementText().toInt()); // INT
                                if (xmlReader.name().toString() == "username")
                                    uSilver.setUsername(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "pin")
                                    uSilver.setPin(xmlReader.readElementText().toInt()); // INT
                                if(xmlReader.name().toString() == "count")
                                    uSilver.setCount(xmlReader.readElementText().toDouble());    // DOUBLE
                                xmlReader.readNext();
                            }
                            utenti.push_back(&uSilver);
                        } else if (xmlReader.name().toString() == "bronze") {
                            BronzeUser uBronze;
                            xmlReader.readNext();
                            while (xmlReader.name().toString() != "silver") {
                                if (xmlReader.name().toString() == "nome")
                                    uBronze.setName(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "cognome")
                                    uBronze.setSurname(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "codiceFiscale")
                                    uBronze.setCode(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "indirizzo")
                                    uBronze.setAddress(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "telefono")
                                    uBronze.setTelephone(xmlReader.readElementText().toInt()); // INT
                                if (xmlReader.name().toString() == "username")
                                    uBronze.setUsername(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "pin")
                                    uBronze.setPin(xmlReader.readElementText().toInt()); // INT
                                if(xmlReader.name().toString() == "count")
                                    uBronze.setCount(xmlReader.readElementText().toDouble());    // DOUBLE
                                xmlReader.readNext();
                            }
                            utenti.push_back(&uBronze);
                        }
                    }
                }
                file->close();
                if (xmlReader.hasError()) return false;
            }
            return true;
        }

};
#endif // DATABASE_H


/*#ifndef DATABASE_H
#define DATABASE_H

#include "user.h"
#include "bronzeuser.h"
#include "silveruser.h"
#include "admin.h"
#include "container.h"

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>
#include <QFile>

#include "mainwindow.h"

class DataBase {
    private:
        QFile* file;

    public:
        DataBase();

    template <class T>
    bool loadDB(Container<T>& utenti) { // Carico il DB nel contenitore
        if (file->exists()) {

            file->open(QIODevice::ReadOnly);
            QXmlStreamReader xmlReader(file);
            QXmlStreamReader copy(file);

            while (!xmlReader.atEnd()) {
                xmlReader.readNext();
                copy.readNext();

                if (copy.isStartElement()) {
                    if (copy.name().toString() == "user") {    // user o username???????????????
                        copy.readNext();
                        //User utente;
                        bool flag = false; // true se ho un amministratore
                        bool pro = false; // true se ho un utente AAA

                        while (copy.name().toString() != "user" && !flag && !pro) {    // user o username???????????????
                            if (copy.name().toString() == "salary")
                                flag = true;
                            else {
                                if(copy.name().toString() == "extra")
                                    pro = true;
                            }
                            copy.readNext();
                        }

                        if(flag) {  // Amministratore
                            Admin utente;
                            while (xmlReader.name().toString() != "user") {    // user o username???????????????
                                if (xmlReader.name().toString() == "nome")
                                    utente.setName(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "cognome")
                                    utente.setSurname(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "codiceFiscale")
                                    utente.setCode(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "indirizzo")
                                    utente.setAddress(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "telefono")
                                    utente.setTelephone(xmlReader.readElementText().toInt()); // INT
                                if (xmlReader.name().toString() == "username")
                                    utente.setUsername(xmlReader.readElementText().toStdString());
                                if (xmlReader.name().toString() == "pin")
                                    utente.setPin(xmlReader.readElementText().toInt()); // INT
                                xmlReader.readNext();
                            }
                            utenti.push_back(&utente);
                        }else{  // Utente con conto - VERIFICARE CHE UTENTE È (bronze, silver, gold) [dynamic cast]
                            if (pro) {
                                SilverUser utente;

                                while (xmlReader.name().toString() != "user") {    // user o username???????????????
                                    if (xmlReader.name().toString() == "nome")
                                        utente.setName(xmlReader.readElementText().toStdString());
                                    if (xmlReader.name().toString() == "cognome")
                                        utente.setSurname(xmlReader.readElementText().toStdString());
                                    if (xmlReader.name().toString() == "codiceFiscale")
                                        utente.setCode(xmlReader.readElementText().toStdString());
                                    if (xmlReader.name().toString() == "indirizzo")
                                        utente.setAddress(xmlReader.readElementText().toStdString());
                                    if (xmlReader.name().toString() == "telefono")
                                        utente.setTelephone(xmlReader.readElementText().toInt()); // INT
                                    if (xmlReader.name().toString() == "username")
                                        utente.setUsername(xmlReader.readElementText().toStdString());
                                    if (xmlReader.name().toString() == "pin")
                                        utente.setPin(xmlReader.readElementText().toInt()); // INT
                                    if(xmlReader.name().toString() == "count")
                                        utente.setCount(xmlReader.readElementText().toDouble());    // DOUBLE

                                    xmlReader.readNext();
                                }
                                utenti.push_back(&utente);
                            }else{
                                BronzeUser utente;

                                while (xmlReader.name().toString() != "user") {    // user o username???????????????
                                    if (xmlReader.name().toString() == "nome")
                                        utente.setName(xmlReader.readElementText().toStdString());
                                    if (xmlReader.name().toString() == "cognome")
                                        utente.setSurname(xmlReader.readElementText().toStdString());
                                    if (xmlReader.name().toString() == "codiceFiscale")
                                        utente.setCode(xmlReader.readElementText().toStdString());
                                    if (xmlReader.name().toString() == "indirizzo")
                                        utente.setAddress(xmlReader.readElementText().toStdString());
                                    if (xmlReader.name().toString() == "telefono")
                                        utente.setTelephone(xmlReader.readElementText().toInt()); // INT
                                    if (xmlReader.name().toString() == "username")
                                        utente.setUsername(xmlReader.readElementText().toStdString());
                                    if (xmlReader.name().toString() == "pin")
                                        utente.setPin(xmlReader.readElementText().toInt()); // INT
                                    if(xmlReader.name().toString() == "count")
                                        utente.setCount(xmlReader.readElementText().toDouble());    // DOUBLE
                                    xmlReader.readNext();
                                }
                                utenti.push_back(&utente);
                            }


                        }
                    }
                }
            }

            file->close();

            if (xmlReader.hasError()) return false;
        }
        return true;
    }

};

#endif // DATABASE_H*/

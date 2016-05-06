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

class DataBase {
    private:
        QFile* file;

    public:
        DataBase();

        template <class T>
        bool loadDB(Container<T>& utenti) { // Carico il DB nel contenitore
            if (DataBase::file->exists()) {

                DataBase::file->open(QIODevice::ReadOnly);
                QXmlStreamReader xmlReader(DataBase::file);

                while (!xmlReader.atEnd()) {
                    xmlReader.readNext();
                    if (xmlReader.isStartElement()) {
                        if (xmlReader.name().toString() == "user") {
                            xmlReader.readNext();
                            //User utente;
                            bool flag; // true se ho un utente normale
                            bool pro; // true se ho un utente AAA

                            while (xmlReader.name().toString() != "user" && !flag) {
                                if (xmlReader.name().toString() == "salary")
                                    flag = true;
                                else
                                    if(xmlReader.name().toString() == "extra")
                                        pro = true;

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
                                        utente.setTelephone(xmlReader.readElementText().toInt()); // INT
                                    if (xmlReader.name().toString() == "username")
                                        utente.setUsername(xmlReader.readElementText().toStdString());
                                    if (xmlReader.name().toString() == "pin")
                                        utente.setPin(xmlReader.readElementText().toInt()); // INT
                                    xmlReader.readNext();
                                }
                                //TODO L'immortacci ai template
                                utenti.push_back(utente);
                            }else{  // Utente con conto - VERIFICARE CHE UTENTE È (bronze, silver, gold) [dynamic cast]
                                if (pro) {
                                    SilverUser utente;

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
                                            utente.setTelephone(xmlReader.readElementText().toInt()); // INT
                                        if (xmlReader.name().toString() == "username")
                                            utente.setUsername(xmlReader.readElementText().toStdString());
                                        if (xmlReader.name().toString() == "pin")
                                            utente.setPin(xmlReader.readElementText().toInt()); // INT
                                        if(xmlReader.name().toString() == "count")
                                            utente.setCount(xmlReader.readElementText().toDouble());    // DOUBLE

                                        xmlReader.readNext();
                                    }
                                    utenti.push_back(utente);
                                }else{
                                    BronzeUser utente;

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
                                            utente.setTelephone(xmlReader.readElementText().toInt()); // INT
                                        if (xmlReader.name().toString() == "username")
                                            utente.setUsername(xmlReader.readElementText().toStdString());
                                        if (xmlReader.name().toString() == "pin")
                                            utente.setPin(xmlReader.readElementText().toInt()); // INT
                                        if(xmlReader.name().toString() == "count")
                                            utente.setCount(xmlReader.readElementText().toDouble());    // DOUBLE
                                        xmlReader.readNext();
                                    }
                                    utenti.push_back(utente);
                                }


                            }
                        }
                    }
                }

                DataBase::file->close();

                if (xmlReader.hasError()) return false;
            }
            return true;
        }

};

#endif // DATABASE_H

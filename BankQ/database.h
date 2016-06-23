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

using namespace std;
#include <iostream>
#include "mainwindow.h"
#include <QMessageBox>


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
                MainWindow u;

                while (!xmlReader.atEnd()) {
                    xmlReader.readNext();
                    if (xmlReader.isStartElement()) {
                            string a = (xmlReader.name().toString()).toUtf8().constData();
                            cout<<a;
                        if (xmlReader.name().toString() == "admin") {
                            Admin admin;
                            xmlReader.readNext();
                            u.boom();
                            /*while (xmlReader.name().toString() != "admin") {
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
                            }*/
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

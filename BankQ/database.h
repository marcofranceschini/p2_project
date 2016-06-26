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

        Container<BronzeUser> userB;
        Container<SilverUser> userS;
        Container<Admin> admin;

    public:
        DataBase();

        bool loadBronze() { // Carico gli utenti bronze nel contenitore
            if (file->exists()) {
                    file->open(QIODevice::ReadOnly);
                    QXmlStreamReader xmlReader(file);

                    while (!xmlReader.atEnd()) {
                        xmlReader.readNext();
                        if (xmlReader.isStartElement()) {
                            // string a = (xmlReader.name().toString()).toUtf8().constData();
                            // cout<<a;
                            if (xmlReader.name().toString() == "bronze") {
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
                                userB.push_back(&uBronze);
                            }
                        }
                    }
                    file->close();
                    if (xmlReader.hasError()) return false;
                }
                return true;
        }

        BronzeUser getBronze (const string& usr) const {
            for (Container<BronzeUser>::Iteratore it = userB.begin(); it != userB.end(); ++it) {
                if (userB[it]->getUsername() == usr)
                    return *userB[it];
            }
        }

        bool loadAdmin() { // Carico gli amministratori nel contenitore
            if (file->exists()) {
                    file->open(QIODevice::ReadOnly);
                    QXmlStreamReader xmlReader(file);
                    MainWindow u;

                    while (!xmlReader.atEnd()) {
                        xmlReader.readNext();
                        if (xmlReader.isStartElement()) {
                               // string a = (xmlReader.name().toString()).toUtf8().constData();
                               // cout<<a;
                            if (xmlReader.name().toString() == "admin") {
                                Admin ad;
                                xmlReader.readNext();
                                u.boom();
                                while (xmlReader.name().toString() != "admin") {
                                    if (xmlReader.name().toString() == "nome")
                                        ad.setName(xmlReader.readElementText().toStdString());
                                    if (xmlReader.name().toString() == "cognome")
                                        ad.setSurname(xmlReader.readElementText().toStdString());
                                    if (xmlReader.name().toString() == "codiceFiscale")
                                        ad.setCode(xmlReader.readElementText().toStdString());
                                    if (xmlReader.name().toString() == "indirizzo")
                                        ad.setAddress(xmlReader.readElementText().toStdString());
                                    if (xmlReader.name().toString() == "telefono")
                                        ad.setTelephone(xmlReader.readElementText().toInt()); // INT
                                    if (xmlReader.name().toString() == "username")
                                        ad.setUsername(xmlReader.readElementText().toStdString());
                                    if (xmlReader.name().toString() == "pin")
                                        ad.setPin(xmlReader.readElementText().toInt()); // INT
                                    xmlReader.readNext();
                                }
                                admin.push_back(&ad);
                            }
                        }
                    }
                    file->close();
                    if (xmlReader.hasError()) return false;
                }
                return true;
        }

        Admin getAdmin (const string& usr) const {
            for (Container<Admin>::Iteratore it = admin.begin(); it != admin.end(); ++it) {
                if (admin[it]->getUsername() == usr)
                    return *admin[it];
            }
        }

        bool loadSilver() { // Carico gli utenti silver nel contenitore
            if (file->exists()) {
                    file->open(QIODevice::ReadOnly);
                    QXmlStreamReader xmlReader(file);
                    MainWindow u;

                    while (!xmlReader.atEnd()) {
                        xmlReader.readNext();
                        if (xmlReader.isStartElement()) {
                            // string a = (xmlReader.name().toString()).toUtf8().constData();
                            // cout<<a;
                            if (xmlReader.name().toString() == "silver") {
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
                                userS.push_back(&uSilver);
                            }
                        }
                    }
                    file->close();
                    if (xmlReader.hasError()) return false;
                }
                return true;
        }

        SilverUser getSilver (const string& usr) const {
            for (Container<SilverUser>::Iteratore it = userS.begin(); it != userS.end(); ++it) {
                if (userS[it]->getUsername() == usr)
                    return *userS[it];
            }
        }

};
#endif // DATABASE_H

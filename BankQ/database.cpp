#include "database.h"

#include "QDebug"   // DA RIMUOVERE
#include "qstring.h"   // DA RIMUOVERE

DataBase::DataBase() {
    //file = new QFile("db.xml");
    //loadDB();
}

bool DataBase::loadAdmin () { // Carico gli amministratori nel contenitore
    file = new QFile("/home/marco/Documents/p2_project/BankQ/admin.xml");
    QString s =file->fileName();   // DA RIMUOVERE
    qDebug("AAA-" + s.toLatin1() + "-AAA");   // DA RIMUOVERE
    if (file->exists()) {
        file->open(QIODevice::ReadOnly);
        QXmlStreamReader xmlReader(file);
        while (!xmlReader.atEnd()) {
            xmlReader.readNext();
            if (xmlReader.isStartElement()) {
                   // string a = (xmlReader.name().toString()).toUtf8().constData();
                   // cout<<a;
                if (xmlReader.name().toString() == "admin") {
                    Admin ad;
                    xmlReader.readNext();
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
                    admin.push_back(new Admin(ad));
                }
            }
        }
        file->close();
        if (xmlReader.hasError()) return false;
        return true;
    }
    return false;
}

bool DataBase::verifyAllUsername (const string& usr) const {

}

Admin DataBase::getAdmin (const string& usr) const {
    for (Container<Admin>::Iteratore it = admin.begin(); it != admin.end(); ++it) {
        if (admin[it]->getUsername() == usr)
            return *admin[it];
    }
}

bool DataBase::verifyLoginAdmin (const string& usr, const int& pin) const {
    // NON SERVE
    MainWindow u;
    for (Container<Admin>::Iteratore it = admin.begin(); it != admin.end(); ++it) {
        //cout<<"AAAA"<<admin[it]->getUsername();
        u.boom();
        if (admin[it]->getUsername() == usr && admin[it]->getPin() == pin)
            return true;
        else
            return false;
    }
    return false;
}

bool DataBase::loadBronze () { // Carico gli utenti bronze nel contenitore
    file = new QFile("/home/marco/Documents/p2_project/BankQ/bronze.xml");
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
                        userB.push_back(new BronzeUser(uBronze));
                        cout<<"AAAAA"<<uBronze.getUsername();
                    }
                }
            }
            file->close();
            if (xmlReader.hasError()) return false;
            return true;
        }
        return false;
}

BronzeUser DataBase::getBronze (const string& usr) const {
    for (Container<BronzeUser>::Iteratore it = userB.begin(); it != userB.end(); ++it) {
        if (userB[it]->getUsername() == usr)
            return *userB[it];
    }
}

bool DataBase::verifyLoginBronze (const string& usr, const int& pin) const {
    for (Container<BronzeUser>::Iteratore it = userB.begin(); it != userB.end(); ++it) {
        cout<<"AAAA"<<userB[it]->getUsername();
        if (userB[it]->getUsername() == usr && userB[it]->getPin() == pin)
            return true;
         else
            return false;
    }
    return false;
}

bool DataBase::loadSilver () { // Carico gli utenti silver nel contenitore
    file = new QFile("/home/marco/Documents/p2_project/BankQ/silver.xml");
    if (file->exists()) {
            file->open(QIODevice::ReadOnly);
            QXmlStreamReader xmlReader(file);
            MainWindow u;// NON SERVE

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
                        userS.push_back(new SilverUser(uSilver));
                    }
                }
            }
            file->close();
            if (xmlReader.hasError()) return false;
            return true;
        }
        return false;
}

SilverUser DataBase::getSilver (const string& usr) const {
    for (Container<SilverUser>::Iteratore it = userS.begin(); it != userS.end(); ++it) {
        if (userS[it]->getUsername() == usr)
            return *userS[it];
    }
}

bool DataBase::verifyLoginSilver (const string& usr, const int& pin) const {
    for (Container<SilverUser>::Iteratore it = userS.begin(); it != userS.end(); ++it) {
        cout<<"AAAA"<<userS[it]->getUsername();
        if (userS[it]->getUsername() == usr && userS[it]->getPin() == pin)
            return true;
        else
            return false;
    }
    return false;
}

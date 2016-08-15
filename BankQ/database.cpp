#include "database.h"

#include "QDebug"   // DA RIMUOVERE
#include "qstring.h"   // DA RIMUOVERE

DataBase::DataBase() {
    //file = new QFile("db.xml");
    //loadDB();
}

bool DataBase::loadAdmin () { // Carico gli amministratori nel contenitore
    file = new QFile("/home/mrc/Documents/p2_project/BankQ/admin.xml");

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
                        if (xmlReader.name().toString() == "name")
                            ad.setName(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "surname")
                            ad.setSurname(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "address")
                            ad.setAddress(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "telephone")
                            ad.setTelephone(xmlReader.readElementText().toInt()); // INT
                        if (xmlReader.name().toString() == "code")
                            ad.setCode(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "username")
                            ad.setUsername(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "pin")
                            ad.setPin(xmlReader.readElementText().toInt()); // INT
                        if (xmlReader.name().toString() == "salary")
                            ad.setSalary(xmlReader.readElementText().toDouble()); // DOUBLE
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
    MainWindow u;   // NON SERVE
    for (Container<Admin>::Iteratore it = admin.begin(); it != admin.end(); ++it) {
        //cout<<"AAAA"<<admin[it]->getUsername();
        //u.boom();
        if (admin[it]->getUsername() == usr && admin[it]->getPin() == pin)
            return true;
        else
            return false;
    }
    return false;
}

bool DataBase::loadBronze () { // Carico gli utenti bronze nel contenitore
    file = new QFile("/home/mrc/Documents/p2_project/BankQ/bronze.xml");
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
                        while (xmlReader.name().toString() != "bronze") {
                            if (xmlReader.name().toString() == "name")
                                uBronze.setName(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "surname")
                                uBronze.setSurname(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "address")
                                uBronze.setAddress(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "telephone")
                                uBronze.setTelephone(xmlReader.readElementText().toInt());  // INT
                            if (xmlReader.name().toString() == "code")
                                uBronze.setCode(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "username")
                                uBronze.setUsername(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "pin")
                                uBronze.setPin(xmlReader.readElementText().toInt());    // INT
                            if(xmlReader.name().toString() == "count")
                                uBronze.setCount(xmlReader.readElementText().toDouble());   // DOUBLE
                            if(xmlReader.name().toString() == "countNumber")
                                uBronze.setCountNumber(xmlReader.readElementText().toInt());
                            xmlReader.readNext();
                        }
                        userB.push_back(new BronzeUser(uBronze));
                    }
                }
            }
            file->close();
            for (Container<BronzeUser>::Iteratore it = userB.begin(); it != userB.end(); ++it) {
                QString st =QString::fromStdString(userB[it]->getUsername());   // DA RIMUOVERE
                qDebug("AAA-" + st.toLatin1() + "-AAA");   // DA RIMUOVERE
            }
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

        QString st =QString::fromStdString(userB[it]->getUsername());   // DA RIMUOVERE
        qDebug("AAA-" + st.toLatin1() + "-AAA");   // DA RIMUOVERE
        MainWindow u;
        u.boom();
        if (userB[it]->getUsername() == usr) {
            if (userB[it]->getPin() == pin)
                return true;
             else
                return false;
        }
    }
    return false;
}

bool DataBase::verifyNumberBronze (const int& number) const {
    for (Container<BronzeUser>::Iteratore it = userB.begin(); it != userB.end(); ++it) {
        if (userB[it]->getCountNumber() == number)
            return true;
    }
    return false;
}

BronzeUser DataBase::getBronzeByCount (const int& conto) const {
    for (Container<BronzeUser>::Iteratore it = userB.begin(); it != userB.end(); ++it) {
        if (userB[it]->getCountNumber() == conto)
            return *userB[it];
    }
}

bool DataBase::verifyStillBronze (const BronzeUser& b) {
    if (100000 <= b.getCount()) {   // L'utente passa a silver
        //SilverUser s = new SilverUser (b.getName(), b.getSurname(), b.getAddress(), b.getTelephone(), b.getUsername(), b.getCode(), b.getPin(), b.getCountNumber(), b.getCount());
        SilverUser *s = new SilverUser (b);

        QString st =QString::fromStdString(s->getUsername());   // DA RIMUOVERE
        qDebug("AAA-" + st.toLatin1() + "-AAA");   // DA RIMUOVERE

        int cont = 0;
        for (Container<BronzeUser>::Iteratore it = userB.begin(); it != userB.end(); ++it) {
            if (userB[it]->getUsername() != b.getUsername())
                cont ++;
            else
                break;
        }
        userB.remove(cont); // Rimuove il "vecchio" utente bronze dalla lista degli utenti bronze
        userS.push_back(s); // Inserisce il "nuovo" utente silver nella lista di appartenenza
        if (this->writeBronze() && this->writeSilver())
            return false;
        else
            return true;
    } else {
        int cont = 0;
        for (Container<BronzeUser>::Iteratore it = userB.begin(); it != userB.end(); ++it) {
            if (userB[it]->getUsername() != b.getUsername())
                cont ++;
            else
                break;
        }
        userB.remove(cont); // Rimuove il "vecchio" utente bronze dalla lista degli utenti bronze
        BronzeUser app = static_cast<BronzeUser>(b);
        userB.push_back(&app); // Inserisce il "nuovo" utente bronze (con conto aggiornato) nella lista di appartenenza
        this->writeBronze();
        return true;
    }
}

bool DataBase::writeBronze () {
    file = new QFile("/home/mrc/Documents/p2_project/BankQ/bronze.xml");
    file->open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(file);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("bronzes");

    for (Container<BronzeUser>::Iteratore it = userB.begin(); it != userB.end(); ++it) {
        xmlWriter.writeStartElement("bronze");
        xmlWriter.writeTextElement("name", QString::fromStdString(userB[it]->getName()));
        xmlWriter.writeTextElement("surname", QString::fromStdString(userB[it]->getSurname()));
        xmlWriter.writeTextElement("address", QString::fromStdString(userB[it]->getAddress()));
        xmlWriter.writeTextElement("telephone", QString::number(userB[it]->getTelephone()));
        xmlWriter.writeTextElement("code", QString::fromStdString(userB[it]->getCode()));
        xmlWriter.writeTextElement("username", QString::fromStdString(userB[it]->getUsername()));
        xmlWriter.writeTextElement("pin", QString::number(userB[it]->getPin()));
        xmlWriter.writeTextElement("count", QString::number(userB[it]->getCount()));
        xmlWriter.writeTextElement("countNumber", QString::number(userB[it]->getCountNumber()));
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    file->close();
    if (xmlWriter.hasError()) return false;
    return true;
}


bool DataBase::loadSilver () { // Carico gli utenti silver nel contenitore
    file = new QFile("/home/mrc/Documents/p2_project/BankQ/silver.xml");
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
                            if (xmlReader.name().toString() == "name")
                                uSilver.setName(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "surname")
                                uSilver.setSurname(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "address")
                                uSilver.setAddress(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "telephone")
                                uSilver.setTelephone(xmlReader.readElementText().toInt()); // INT
                            if (xmlReader.name().toString() == "code")
                                uSilver.setCode(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "username")
                                uSilver.setUsername(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "pin")
                                uSilver.setPin(xmlReader.readElementText().toInt()); // INT
                            if(xmlReader.name().toString() == "count")
                                uSilver.setCount(xmlReader.readElementText().toDouble());    // DOUBLEE
                            if(xmlReader.name().toString() == "countNumber")
                                uSilver.setCountNumber(xmlReader.readElementText().toInt());
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
        if (userS[it]->getUsername() == usr && userS[it]->getPin() == pin)
            return true;
        else
            return false;
    }
    return false;
}

bool DataBase::verifyNumberSilver (const int& number) const {
    for (Container<SilverUser>::Iteratore it = userS.begin(); it != userS.end(); ++it) {
        if (userS[it]->getCountNumber() == number)
            return true;
    }
    return false;
}

SilverUser DataBase::getSilverByCount (const int& conto) const {
    for (Container<SilverUser>::Iteratore it = userS.begin(); it != userS.end(); ++it) {
        if (userS[it]->getCountNumber() == conto)
            return *userS[it];
    }
}

bool DataBase::verifyStillSilver (const SilverUser& s) {
    if (s.getCount() < 100000) {   // L'utente passa a bronze
        //SilverUser s = new SilverUser (b.getName(), b.getSurname(), b.getAddress(), b.getTelephone(), b.getUsername(), b.getCode(), b.getPin(), b.getCountNumber(), b.getCount());
        BronzeUser *b = new BronzeUser (s);

        int cont = 0;
        for (Container<SilverUser>::Iteratore it = userS.begin(); it != userS.end(); ++it) {
            if (userS[it]->getUsername() != s.getUsername())
                cont ++;
            else
                break;
        }
        userS.remove(cont); // Rimuove il "vecchio" utente silver dalla lista degli utenti silver

        userB.push_back(b); // Inserisce il "nuovo" utente bronze nella lista di appartenenza

        if (this->writeBronze() && this->writeSilver())
            return false;
        else
            return true;
    } else {
        int cont = 0;
        for (Container<SilverUser>::Iteratore it = userS.begin(); it != userS.end(); ++it) {
            if (userS[it]->getUsername() != s.getUsername())
                cont ++;
            else
                break;
        }
        userS.remove(cont); // Rimuove il "vecchio" utente bronze dalla lista degli utenti bronze
        SilverUser app = static_cast<SilverUser>(s);
        userS.push_back(&app); // Inserisce il "nuovo" utente bronze (con conto aggiornato) nella lista di appartenenza
        this->writeSilver();
        return true;
    }
}

bool DataBase::writeSilver () {
    file = new QFile("/home/mrc/Documents/p2_project/BankQ/silver.xml");
    file->open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(file);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("silvers");
    for (Container<SilverUser>::Iteratore it = userS.begin(); it != userS.end(); ++it) {
        xmlWriter.writeStartElement("silver");
        xmlWriter.writeTextElement("name", QString::fromStdString(userS[it]->getName()));
        xmlWriter.writeTextElement("surname", QString::fromStdString(userS[it]->getSurname()));
        xmlWriter.writeTextElement("address", QString::fromStdString(userS[it]->getAddress()));
        xmlWriter.writeTextElement("telephone", QString::number(userS[it]->getTelephone()));
        xmlWriter.writeTextElement("code", QString::fromStdString(userS[it]->getCode()));
        xmlWriter.writeTextElement("username", QString::fromStdString(userS[it]->getUsername()));
        xmlWriter.writeTextElement("pin", QString::number(userS[it]->getPin()));
        xmlWriter.writeTextElement("count", QString::number(userS[it]->getCount()));
        xmlWriter.writeTextElement("countNumber", QString::number(userS[it]->getCountNumber()));
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    file->close();
    if (xmlWriter.hasError()) return false;
    return true;
}

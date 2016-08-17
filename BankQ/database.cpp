#include "database.h"

#include "QDebug"       // DA RIMUOVERE
#include "qstring.h"    // DA RIMUOVERE
#include "mainwindow.h" // DA RIMUOVERE

DataBase::DataBase() {
    //file = new QFile("db.xml");
    //loadDB();
}

bool DataBase::load () { // Carico gli amministratori nel contenitore
    file = new QFile("/home/mrc/Documents/p2_project/BankQ/users.xml");

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
                qDebug("Pre admin");   // DA RIMUOVERE
                QString st = xmlReader.name().toString();   // DA RIMUOVERE
                qDebug("NN-" + st.toLatin1() + "-NN");
                if (xmlReader.name().toString() == "admin") {
                    qDebug("Dentro admin");   // DA RIMUOVERE
                    MainWindow u;   // DA RIMUOVERE
                    u.boom();       // DA RIMUOVERE
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
                    user.push_back(new Admin(ad));
                        QString st =QString::fromStdString(ad.getName());   // DA RIMUOVERE
                        qDebug("CCC-" + st.toLatin1() + "-CCC");
                } else if (xmlReader.name().toString() == "bronze") {
                    qDebug("Dentro bronze");   // DA RIMUOVERE
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
                    user.push_back(new BronzeUser(uBronze));
                    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
                        QString st =QString::fromStdString(user[it]->getName());   // DA RIMUOVERE
                        qDebug("CCC-" + st.toLatin1() + "-CCC");
                    }
                } else {
                    qDebug("Dentro silver");   // DA RIMUOVERE
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
                    user.push_back(new SilverUser(uSilver));
                }
            }
        }
        file->close();

        if (xmlReader.hasError()) return false;
        return true;
    }
    return false;
}

bool DataBase::verifyAdmin (const string& u) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        Admin* a = dynamic_cast<Admin*> (user[it]);
        if (a && a->getUsername() == u)
                return true;
            else
                return false;
    }
    return false;
}


bool DataBase::verifyAllUsername (const string& usr) const {

}

/*Admin DataBase::getAdmin (const string& usr) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        Admin* a = dynamic_cast<Admin*> (user[it]);
        if (a && a->getUsername() == usr)
            return *a;
    }
}*/

bool DataBase::verifyLogin (const string& usr, const int& pin) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        if (user[it]->getUsername() == usr){
            if (user[it]->getPin() == pin)
                return true;
            else
                return false;
        }
    }
    return false;
}

/*bool DataBase::loadBronze () { // Carico gli utenti bronze nel contenitore
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
                        user.push_back(new BronzeUser(uBronze));
                    }
                }
            }
            file->close();
            if (xmlReader.hasError()) return false;
            return true;
        }
        return false;
}*/

User DataBase::getUser (const string& usr) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        if (user[it]->getUsername() == usr)
            return *user[it];
    }
}

/*bool DataBase::verifyLoginBronze (const string& usr, const int& pin) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        BronzeUser* b = dynamic_cast<BronzeUser*> (user[it]);
        if (b && b->getUsername() == usr) {
            if (b->getPin() == pin)
                return true;
             else
                return false;
        }
    }
    return false;
}*/

/*bool DataBase::verifyNumberBronze (const int& number) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        BronzeUser* b = dynamic_cast<BronzeUser*> (user[it]);
        if (b && b->getCountNumber() == number)
            return true;
    }
    return false;
}*/

User DataBase::getUserByCountNumber (const int& conto) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        BronzeUser* b = dynamic_cast<BronzeUser*> (user[it]);
        if (b && b->getCountNumber() == conto)
            return *user[it];
    }
}

bool DataBase::verifyStillBronze (const BronzeUser& bronze) {
    if (100000 <= bronze.getCount()) {   // L'utente passa a silver
        //SilverUser s = new SilverUser (b.getName(), b.getSurname(), b.getAddress(), b.getTelephone(), b.getUsername(), b.getCode(), b.getPin(), b.getCountNumber(), b.getCount());
        SilverUser *s = new SilverUser (bronze);

        int cont = 0;
        for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
            BronzeUser* b = dynamic_cast<BronzeUser*> (user[it]);
            if (b && b->getUsername() != bronze.getUsername())
                cont ++;
            else
                break;
        }
        user.remove(cont); // Rimuove il "vecchio" utente bronze dalla lista degli utenti bronze
        user.push_back(s); // Inserisce il "nuovo" utente silver nella lista di appartenenza
        if (this->write() && this->write())
            return false;
        else
            return true;
    } else {
        int cont = 0;
        for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
            BronzeUser* b = dynamic_cast<BronzeUser*> (user[it]);
            if (b && b->getUsername() != bronze.getUsername())
                cont ++;
            else
                break;
        }
        user.remove(cont); // Rimuove il "vecchio" utente bronze dalla lista degli utenti bronze
        BronzeUser app = bronze;
        user.push_back(&app); // Inserisce il "nuovo" utente bronze (con conto aggiornato) nella lista di appartenenza
        this->write();
        return true;
    }
}

bool DataBase::remove (const User& u) {
    int cont = 0;
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        if (user[it]->getUsername() == u.getUsername()) break;
        cont++;
    }
    user.remove(cont);
    this->write();
}

bool DataBase::write () {
    file = new QFile("/home/mrc/Documents/p2_project/BankQ/user.xml");
    file->open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(file);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("users");

    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        BronzeUser* b = dynamic_cast<BronzeUser*> (user[it]);
        if (b) {
            xmlWriter.writeStartElement("bronze");
            xmlWriter.writeTextElement("name", QString::fromStdString(b->getName()));
            xmlWriter.writeTextElement("surname", QString::fromStdString(b->getSurname()));
            xmlWriter.writeTextElement("address", QString::fromStdString(b->getAddress()));
            xmlWriter.writeTextElement("telephone", QString::number(b->getTelephone()));
            xmlWriter.writeTextElement("code", QString::fromStdString(b->getCode()));
            xmlWriter.writeTextElement("username", QString::fromStdString(b->getUsername()));
            xmlWriter.writeTextElement("pin", QString::number(b->getPin()));
            xmlWriter.writeTextElement("count", QString::number(b->getCount()));
            xmlWriter.writeTextElement("countNumber", QString::number(b->getCountNumber()));
        } else {
            SilverUser* s = dynamic_cast<SilverUser*> (user[it]);
            if (s) {
                xmlWriter.writeStartElement("silver");
                xmlWriter.writeTextElement("name", QString::fromStdString(s->getName()));
                xmlWriter.writeTextElement("surname", QString::fromStdString(s->getSurname()));
                xmlWriter.writeTextElement("address", QString::fromStdString(s->getAddress()));
                xmlWriter.writeTextElement("telephone", QString::number(s->getTelephone()));
                xmlWriter.writeTextElement("code", QString::fromStdString(s->getCode()));
                xmlWriter.writeTextElement("username", QString::fromStdString(s->getUsername()));
                xmlWriter.writeTextElement("pin", QString::number(s->getPin()));
                xmlWriter.writeTextElement("count", QString::number(s->getCount()));
                xmlWriter.writeTextElement("countNumber", QString::number(s->getCountNumber()));
            } else {
                Admin* a = dynamic_cast<Admin*> (user[it]);
                xmlWriter.writeStartElement("admin");
                xmlWriter.writeTextElement("name", QString::fromStdString(a->getName()));
                xmlWriter.writeTextElement("surname", QString::fromStdString(a->getSurname()));
                xmlWriter.writeTextElement("address", QString::fromStdString(a->getAddress()));
                xmlWriter.writeTextElement("telephone", QString::number(a->getTelephone()));
                xmlWriter.writeTextElement("code", QString::fromStdString(a->getCode()));
                xmlWriter.writeTextElement("username", QString::fromStdString(a->getUsername()));
                xmlWriter.writeTextElement("pin", QString::number(a->getPin()));
                xmlWriter.writeTextElement("salary", QString::number(a->getSalary()));
            }
        }
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    file->close();
    if (xmlWriter.hasError()) return false;
    return true;
}


/*bool DataBase::loadSilver () { // Carico gli utenti silver nel contenitore
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
                        user.push_back(new SilverUser(uSilver));
                    }
                }
            }
            file->close();
            if (xmlReader.hasError()) return false;
            return true;
        }
        return false;
}*/

/*SilverUser DataBase::getSilver (const string& usr) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        SilverUser* s = dynamic_cast<SilverUser*> (user[it]);
        if (s && s->getUsername() == usr)
            return *s;
    }
}*/

/*bool DataBase::verifyLoginSilver (const string& usr, const int& pin) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        SilverUser* s = dynamic_cast<SilverUser*> (user[it]);
        if (s && s->getUsername() == usr && s->getPin() == pin)
            return true;
        else
            return false;
    }
    return false;
}*/

bool DataBase::verifyNumberSilver (const int& number) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        SilverUser* s = dynamic_cast<SilverUser*> (user[it]);
        if (s && s->getCountNumber() == number)
            return true;
    }
    return false;
}

/*SilverUser DataBase::getSilverByCount (const int& conto) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        SilverUser* s = dynamic_cast<SilverUser*> (user[it]);
        if (s && s->getCountNumber() == conto)
            return *s;
    }
}*/

bool DataBase::verifyStillSilver (const SilverUser& silver) {
    if (silver.getCount() < 100000) {   // L'utente passa a bronze
        //SilverUser s = new SilverUser (b.getName(), b.getSurname(), b.getAddress(), b.getTelephone(), b.getUsername(), b.getCode(), b.getPin(), b.getCountNumber(), b.getCount());
        BronzeUser *b = new BronzeUser (silver);

        int cont = 0;
        for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
            SilverUser* s = dynamic_cast<SilverUser*> (user[it]);
            if (s && s->getUsername() != silver.getUsername())
                cont ++;
            else
                break;
        }
        user.remove(cont); // Rimuove il "vecchio" utente silver dalla lista degli utenti silver

        user.push_back(b); // Inserisce il "nuovo" utente bronze nella lista di appartenenza

        if (this->write() && this->write())
            return false;
        else
            return true;
    } else {
        int cont = 0;
        for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
            SilverUser* s = dynamic_cast<SilverUser*> (user[it]);
            if (s && s->getUsername() != silver.getUsername())
                cont ++;
            else
                break;
        }
        user.remove(cont); // Rimuove il "vecchio" utente bronze dalla lista degli utenti bronze
        SilverUser app = static_cast<SilverUser>(silver);
        user.push_back(&app); // Inserisce il "nuovo" utente bronze (con conto aggiornato) nella lista di appartenenza
        this->write();
        return true;
    }
}

/*bool DataBase::removeSilver (const SilverUser& silver) {
    int cont = 0;
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        SilverUser* s = dynamic_cast<SilverUser*> (user[it]);
        if (s && s->getUsername() == silver.getUsername()) break;
        cont++;
    }
    user.remove(cont);
}*/

/*bool DataBase::writeSilver () {
    file = new QFile("/home/mrc/Documents/p2_project/BankQ/silver.xml");
    file->open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(file);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("silvers");
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        SilverUser* s = dynamic_cast<SilverUser*> (user[it]);
        if (s) {
            xmlWriter.writeStartElement("silver");
            xmlWriter.writeTextElement("name", QString::fromStdString(s->getName()));
            xmlWriter.writeTextElement("surname", QString::fromStdString(s->getSurname()));
            xmlWriter.writeTextElement("address", QString::fromStdString(s->getAddress()));
            xmlWriter.writeTextElement("telephone", QString::number(s->getTelephone()));
            xmlWriter.writeTextElement("code", QString::fromStdString(s->getCode()));
            xmlWriter.writeTextElement("username", QString::fromStdString(s->getUsername()));
            xmlWriter.writeTextElement("pin", QString::number(s->getPin()));
            xmlWriter.writeTextElement("count", QString::number(s->getCount()));
            xmlWriter.writeTextElement("countNumber", QString::number(s->getCountNumber()));
            xmlWriter.writeEndElement();
        }
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    file->close();
    if (xmlWriter.hasError()) return false;
    return true;
}*/

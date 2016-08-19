#include "database.h"

#include "QDebug"       // DA RIMUOVERE
#include "qstring.h"    // DA RIMUOVERE
#include "mainwindow.h" // DA RIMUOVERE

#include "messagesdatabase.h"

DataBase::DataBase() {
    //file = new QFile("db.xml");
    //loadDB();
}

bool DataBase::load () { // Carico gli amministratori nel contenitore
    file = new QFile("/home/mrc/Documents/p2_project/BankQ/users.xml");

    //QString s =file->fileName();   // DA RIMUOVERE
    //qDebug("AAA-" + s.toLatin1() + "-AAA");   // DA RIMUOVERE

    if (file->exists()) {
        file->open(QIODevice::ReadOnly);
        QXmlStreamReader xmlReader(file);
        while (!xmlReader.atEnd()) {
            xmlReader.readNext();
            if (xmlReader.isStartElement()) {
                   // string a = (xmlReader.name().toString()).toUtf8().constData();
                   // cout<<a;
                if (xmlReader.name().toString() == "admin") {
                    //MainWindow u;   // DA RIMUOVERE
                    //u.boom();       // DA RIMUOVERE
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
                } else if (xmlReader.name().toString() == "basic") {
                    BasicUser uBasic;
                    xmlReader.readNext();
                    while (xmlReader.name().toString() != "basic") {
                        if (xmlReader.name().toString() == "name")
                            uBasic.setName(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "surname")
                            uBasic.setSurname(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "address")
                            uBasic.setAddress(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "telephone")
                            uBasic.setTelephone(xmlReader.readElementText().toInt());  // INT
                        if (xmlReader.name().toString() == "code")
                            uBasic.setCode(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "username")
                            uBasic.setUsername(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "pin")
                            uBasic.setPin(xmlReader.readElementText().toInt());    // INT
                        if(xmlReader.name().toString() == "count")
                            uBasic.setCount(xmlReader.readElementText().toDouble());   // DOUBLE
                        if(xmlReader.name().toString() == "countNumber")
                            uBasic.setCountNumber(xmlReader.readElementText().toInt());
                        xmlReader.readNext();
                    }
                    user.push_back(new BasicUser(uBasic));
                } else if (xmlReader.name().toString() == "pro") {
                    ProUser uPro;
                    xmlReader.readNext();
                    while (xmlReader.name().toString() != "pro") {
                        if (xmlReader.name().toString() == "name")
                            uPro.setName(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "surname")
                            uPro.setSurname(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "address")
                            uPro.setAddress(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "telephone")
                            uPro.setTelephone(xmlReader.readElementText().toInt()); // INT
                        if (xmlReader.name().toString() == "code")
                            uPro.setCode(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "username")
                            uPro.setUsername(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "pin")
                            uPro.setPin(xmlReader.readElementText().toInt()); // INT
                        if(xmlReader.name().toString() == "count")
                            uPro.setCount(xmlReader.readElementText().toDouble());    // DOUBLEE
                        if(xmlReader.name().toString() == "countNumber")
                            uPro.setCountNumber(xmlReader.readElementText().toInt());
                        if(xmlReader.name().toString() == "request")
                            uPro.setRequest(xmlReader.readElementText().toInt());

                        xmlReader.readNext();
                    }
                    user.push_back(new ProUser(uPro));
                }
            }
        }
        /*for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
            QString st =QString::fromStdString(user[it]->getName());    // DA RIMUOVERE
            qDebug("CCC-" + st.toLatin1() + "-CCC");                    // DA RIMUOVERE
        }*/
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


bool DataBase::verifyExistingUsername (const string& u) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        BasicUser* b = dynamic_cast<BasicUser*> (user[it]);
        if (b && b->getUsername() == u)
                return true;
    }
    return false;
}

bool DataBase::verifyExistingCountNumber (const int& c) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        BasicUser* b = dynamic_cast<BasicUser*> (user[it]);
        if (b && b->getCountNumber() == c)
                return true;
    }
    return false;

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
        if (user[it]->getUsername() == usr && user[it]->getPin() == pin)
                return true;
    }
    return false;
}

bool DataBase::addUser (const BasicUser& u) {
    BasicUser* ncu = const_cast <BasicUser*> (&u);
    if (u.getCount() < 100000) {
        user.push_back(ncu);
    } else {
        user.push_back(new ProUser(*ncu));
    }
    this->write();
}

/*bool DataBase::loadBasic () { // Carico gli utenti Basic nel contenitore
    file = new QFile("/home/mrc/Documents/p2_project/BankQ/Basic.xml");
    if (file->exists()) {
            file->open(QIODevice::ReadOnly);
            QXmlStreamReader xmlReader(file);

            while (!xmlReader.atEnd()) {
                xmlReader.readNext();
                if (xmlReader.isStartElement()) {
                    // string a = (xmlReader.name().toString()).toUtf8().constData();
                    // cout<<a;
                    if (xmlReader.name().toString() == "Basic") {
                        BasicUser uBasic;
                        xmlReader.readNext();
                        while (xmlReader.name().toString() != "Basic") {
                            if (xmlReader.name().toString() == "name")
                                uBasic.setName(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "surname")
                                uBasic.setSurname(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "address")
                                uBasic.setAddress(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "telephone")
                                uBasic.setTelephone(xmlReader.readElementText().toInt());  // INT
                            if (xmlReader.name().toString() == "code")
                                uBasic.setCode(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "username")
                                uBasic.setUsername(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "pin")
                                uBasic.setPin(xmlReader.readElementText().toInt());    // INT
                            if(xmlReader.name().toString() == "count")
                                uBasic.setCount(xmlReader.readElementText().toDouble());   // DOUBLE
                            if(xmlReader.name().toString() == "countNumber")
                                uBasic.setCountNumber(xmlReader.readElementText().toInt());
                            xmlReader.readNext();
                        }
                        user.push_back(new BasicUser(uBasic));
                    }
                }
            }
            file->close();
            if (xmlReader.hasError()) return false;
            return true;
        }
        return false;
}*/

bool DataBase::verifyStillSame (const BasicUser& usr) {
    int cont = 0;   // Per sapere in quale posizione del Container l'oggetto si trova
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        BasicUser* b = dynamic_cast<BasicUser*> (user[it]);
        if (!b || (b && b->getUsername() != usr.getUsername()))
            cont ++;
        else
            break;
    }
    user.remove(cont); // Rimuove il "vecchio" utente dalla lista
    BasicUser* u = const_cast<BasicUser*> (&usr);

    if (100000 <= u->getCount() && !dynamic_cast<ProUser*> (u)) {
        // L'utente è Basic e deve diventare Pro
        ProUser *s = new ProUser (*u);

        user.push_back(s->clone()); // Inserisce il "nuovo" utente Pro nella lista

    } else if (u->getCount() < 100000 && dynamic_cast<ProUser*> (u)) {
        // L'utente è Pro e deve diventare Basic
        ProUser* s = dynamic_cast<ProUser*> (u);
        BasicUser* b = new BasicUser (*s);
        user.push_back(b->clone());
    } else {
        // L'utente non ha cambiato "tipo", ma va comunque aggiornato il DB
        /*int cont = 0;
        for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
            BasicUser* b = dynamic_cast<BasicUser*> (user[it]);
            if (b && b->getUsername() != Basic.getUsername())
                cont ++;
            else
                break;
        }*/
        //user.remove(cont); // Rimuove il "vecchio" utente Basic dalla lista degli utenti Basic
        if (dynamic_cast<ProUser*> (u)) { // È un utente Pro
            ProUser* s = dynamic_cast<ProUser*> (u);
            user.push_back(s->clone()); // Inserisce il "nuovo" utente Basic (con conto aggiornato) nella lista di appartenenza
        } else { // È un utente Basic
            user.push_back(u->clone());  // Inserisco il "nuovo" utente Basic (con conto aggiornato) nella lista di appartenenza
        }
        //delete u; // ATTENZIONE
        this->write();
        return true;
    }
    this->write();
    return false;
}

User* DataBase::getUser (const string& usr) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        if (user[it]->getUsername() == usr)
            return user[it]->clone();
    }
}

/*bool DataBase::verifyLoginBasic (const string& usr, const int& pin) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        BasicUser* b = dynamic_cast<BasicUser*> (user[it]);
        if (b && b->getUsername() == usr) {
            if (b->getPin() == pin)
                return true;
             else
                return false;
        }
    }
    return false;
}*/

/*bool DataBase::verifyNumberBasic (const int& number) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        BasicUser* b = dynamic_cast<BasicUser*> (user[it]);
        if (b && b->getCountNumber() == number)
            return true;
    }
    return false;
}*/

User* DataBase::getUserByCountNumber (const int& conto) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        BasicUser* b = dynamic_cast<BasicUser*> (user[it]);
        if (b && b->getCountNumber() == conto)
            return user[it]->clone();
    }
}

/*bool DataBase::fromBasicToPro (const BasicUser& Basic) {  // L'utente passa da Basic a Pro
        //ProUser s = new ProUser (b.getName(), b.getSurname(), b.getAddress(), b.getTelephone(), b.getUsername(), b.getCode(), b.getPin(), b.getCountNumber(), b.getCount());
        ProUser *s = new ProUser (Basic);

        int cont = 0;
        for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
            BasicUser* b = dynamic_cast<BasicUser*> (user[it]);
            if (b && b->getUsername() != Basic.getUsername())
                cont ++;
            else
                break;
        }
        user.remove(cont); // Rimuove il "vecchio" utente Basic dalla lista degli utenti Basic
        user.push_back(s); // Inserisce il "nuovo" utente Pro nella lista di appartenenza
        if (this->write() && this->write())
            return false;
        else
            return true;
}*/

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
    file = new QFile("/home/mrc/Documents/p2_project/BankQ/users.xml");
    file->open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(file);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("users");

    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        ProUser* s = dynamic_cast<ProUser*> (user[it]);
        if (s) {
            xmlWriter.writeStartElement("pro");
            xmlWriter.writeTextElement("name", QString::fromStdString(s->getName()));
            xmlWriter.writeTextElement("surname", QString::fromStdString(s->getSurname()));
            xmlWriter.writeTextElement("address", QString::fromStdString(s->getAddress()));
            xmlWriter.writeTextElement("telephone", QString::number(s->getTelephone()));
            xmlWriter.writeTextElement("code", QString::fromStdString(s->getCode()));
            xmlWriter.writeTextElement("username", QString::fromStdString(s->getUsername()));
            xmlWriter.writeTextElement("pin", QString::number(s->getPin()));
            xmlWriter.writeTextElement("count", QString::number(s->getCount()));
            xmlWriter.writeTextElement("countNumber", QString::number(s->getCountNumber()));
            xmlWriter.writeTextElement("request", QString::number(s->getRequest()));
        } else {
            BasicUser* b = dynamic_cast<BasicUser*> (user[it]);
            if (b) {
                xmlWriter.writeStartElement("basic");
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


/*bool DataBase::loadPro () { // Carico gli utenti Pro nel contenitore
    file = new QFile("/home/mrc/Documents/p2_project/BankQ/Pro.xml");
    if (file->exists()) {
            file->open(QIODevice::ReadOnly);
            QXmlStreamReader xmlReader(file);
            MainWindow u;// NON SERVE

            while (!xmlReader.atEnd()) {
                xmlReader.readNext();
                if (xmlReader.isStartElement()) {
                    // string a = (xmlReader.name().toString()).toUtf8().constData();
                    // cout<<a;
                    if (xmlReader.name().toString() == "Pro") {
                        ProUser uPro;
                        xmlReader.readNext();
                        while (xmlReader.name().toString() != "Pro") {
                            if (xmlReader.name().toString() == "name")
                                uPro.setName(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "surname")
                                uPro.setSurname(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "address")
                                uPro.setAddress(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "telephone")
                                uPro.setTelephone(xmlReader.readElementText().toInt()); // INT
                            if (xmlReader.name().toString() == "code")
                                uPro.setCode(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "username")
                                uPro.setUsername(xmlReader.readElementText().toStdString());
                            if (xmlReader.name().toString() == "pin")
                                uPro.setPin(xmlReader.readElementText().toInt()); // INT
                            if(xmlReader.name().toString() == "count")
                                uPro.setCount(xmlReader.readElementText().toDouble());    // DOUBLEE
                            if(xmlReader.name().toString() == "countNumber")
                                uPro.setCountNumber(xmlReader.readElementText().toInt());
                            xmlReader.readNext();
                        }
                        user.push_back(new ProUser(uPro));
                    }
                }
            }
            file->close();
            if (xmlReader.hasError()) return false;
            return true;
        }
        return false;
}*/

/*ProUser DataBase::getPro (const string& usr) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        ProUser* s = dynamic_cast<ProUser*> (user[it]);
        if (s && s->getUsername() == usr)
            return *s;
    }
}*/

/*bool DataBase::verifyLoginPro (const string& usr, const int& pin) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        ProUser* s = dynamic_cast<ProUser*> (user[it]);
        if (s && s->getUsername() == usr && s->getPin() == pin)
            return true;
        else
            return false;
    }
    return false;
}*/

bool DataBase::verifyNumberPro (const int& number) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        ProUser* s = dynamic_cast<ProUser*> (user[it]);
        if (s && s->getCountNumber() == number)
            return true;
    }
    return false;
}

/*ProUser DataBase::getProByCount (const int& conto) const {
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        ProUser* s = dynamic_cast<ProUser*> (user[it]);
        if (s && s->getCountNumber() == conto)
            return *s;
    }
}*/

/*bool DataBase::verifyStillPro (const ProUser& Pro) {
    if (Pro.getCount() < 100000) {   // L'utente passa a Basic
        //ProUser s = new ProUser (b.getName(), b.getSurname(), b.getAddress(), b.getTelephone(), b.getUsername(), b.getCode(), b.getPin(), b.getCountNumber(), b.getCount());
        BasicUser *b = new BasicUser (Pro);

        int cont = 0;
        for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
            ProUser* s = dynamic_cast<ProUser*> (user[it]);
            if (s && s->getUsername() != Pro.getUsername())
                cont ++;
            else
                break;
        }
        user.remove(cont); // Rimuove il "vecchio" utente Pro dalla lista degli utenti Pro

        user.push_back(b); // Inserisce il "nuovo" utente Basic nella lista di appartenenza

        if (this->write() && this->write())
            return false;
        else
            return true;
    } else {
        int cont = 0;
        for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
            ProUser* s = dynamic_cast<ProUser*> (user[it]);
            if (s && s->getUsername() != Pro.getUsername())
                cont ++;
            else
                break;
        }
        user.remove(cont); // Rimuove il "vecchio" utente Basic dalla lista degli utenti Basic
        ProUser app = static_cast<ProUser>(Pro);
        user.push_back(&app); // Inserisce il "nuovo" utente Basic (con conto aggiornato) nella lista di appartenenza
        this->write();
        return true;
    }
}*/

/*bool DataBase::removePro (const ProUser& Pro) {
    int cont = 0;
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        ProUser* s = dynamic_cast<ProUser*> (user[it]);
        if (s && s->getUsername() == Pro.getUsername()) break;
        cont++;
    }
    user.remove(cont);
}*/

/*bool DataBase::writePro () {
    file = new QFile("/home/mrc/Documents/p2_project/BankQ/Pro.xml");
    file->open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(file);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("Pros");
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        ProUser* s = dynamic_cast<ProUser*> (user[it]);
        if (s) {
            xmlWriter.writeStartElement("Pro");
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

Container<BasicUser> DataBase::getUserNoAdmin () {
    Container<BasicUser> u;
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        if (dynamic_cast<BasicUser*> (user[it]))
            u.push_back(dynamic_cast<BasicUser*> (user[it])->clone());
    }
    return u;
}

Container<ProUser> DataBase::getUserNoRequest() {
    Container<ProUser> u;
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        ProUser* p = dynamic_cast<ProUser*> (user[it]);
        if (p && !p->getRequest())
            u.push_back(p->clone());
    }
    return u;
}

bool DataBase::giveBonus(const User& cu) {
    User* ncu = const_cast<User*> (&cu);
    ProUser* u = dynamic_cast<ProUser*> (ncu);
    double c = u->getCount() + ((u->getCount())/100)*(u->getBonus() - u->getTax());
    u->setCount(c);
    u->setRequest(true);
    if (this->verifyStillSame(*u)) {    // verifyStillSame in questo caso riscrive soltanto l'utente nel DB
        MessagesDataBase m;
        if (m.loadMessages())
            m.addMessage(*new Message (cu.getUsername(), "BankQ", "Bonus ricevuto"));
        else
            qDebug("Errore nel caricamento del DB dei messaggi");
    }
}

bool DataBase::giveBonusToAll () {
    Container<ProUser> l = this->getUserNoRequest();
    for (Container<ProUser>::Iteratore it = l.begin(); it != l.end(); ++it) {
        this->giveBonus(*l[it]);
    }
}

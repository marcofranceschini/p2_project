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


bool DataBase::charge (const string& username, const int& cifra, const int& conto) {
    User* m_app = this->getUser(username);
    BasicUser* mittente = dynamic_cast<BasicUser*> (m_app); // Username dell'utente loggato
    QWidget* p = new QWidget(); // Per visualizzare i messaggi

    if (mittente->getCountNumber() != conto) {      // Verifico che il conto da ricarica e quello dell'utente loggato siano diversi
        if (0 <= mittente->getCount() - cifra) {    // Verifico che il conto abbia sufficiente credito

            User* r_app = this->getUserByCountNumber(conto);  // Username del "ricevente"
            BasicUser* ricevente = dynamic_cast<BasicUser*> (r_app);

            // Aggiunto l'importo al conto dell'utente "ricevente"
            ricevente->setCount(ricevente->getCount() + cifra);

            QString qstr = "Ricevuta una ricarica di € " + QString::number(cifra);
            string str = qstr.toUtf8().constData();
            MessagesDataBase m;

            if (m.loadMessages())   {
                // Messaggio per la ricarica ricevuta
                m.addMessage(*new Message(ricevente->getUsername(), mittente->getUsername(), str));

                // Messaggio per un'eventuale passaggio da Basic a Pro
                if (!this->verifyStillSame(*ricevente))   // Se l'utente è Basic allora può diventare Pro, altrimenti non accade "nulla"
                    // Se l'utente passa a Pro invio un messaggio
                    m.addMessage(*new Message(ricevente->getUsername(),"BankQ", "Grazie alla ricarica ricevuta il proprio conto è ora di tipo Pro"));
            } else {
                QMessageBox::warning(
                    p,
                    QString::fromStdString("BankQ - Errore"),
                    QString::fromStdString("Errore di caricamento (messaggi)")
                );
            }

            // Tolgo l'importo dal conto dell'utente loggato
            mittente->setCount(mittente->getCount() - cifra);

            if (!this->verifyStillSame(*mittente)) {   // Se l'utente è Pro allora può diventare Basic, altrimenti non accade "nulla"
                /*BasicUser* app = new BasicUser(*s);
                user = app;
                delete app;*/
                //delete &userS;    // CAUSA CRASH

                QMessageBox::information(
                    p,
                    QString::fromStdString("BankQ - Avviso"),
                    QString::fromStdString("Con l'ultimo ricarica il tipo di conto è diventanto Basic")
                );
            }
        } else {
            QMessageBox::warning(
                p,
                QString::fromStdString("BankQ - Ricarica"),
                QString::fromStdString("Credito insufficiente")
            );
        }
    } else {
        QMessageBox::warning(
            p,
            QString::fromStdString("BankQ - Ricarica"),
            QString::fromStdString("Non è possibile inserire il proprio conto")
        );
    }
}


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
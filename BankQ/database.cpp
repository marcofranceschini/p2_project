#include "database.h"

DataBase::DataBase() {}

bool DataBase::load () {    // Carica gli utenti nel contenitore
    file = new QFile("/home/mrc/Documents/p2_project/BankQ/users.xml");

    if (file->exists()) {
        file->open(QIODevice::ReadOnly);
        QXmlStreamReader xmlReader(file);

        while (!xmlReader.atEnd()) {
            xmlReader.readNext();
            if (xmlReader.isStartElement()) {
                if (xmlReader.name().toString() == "admin") {
                    Admin ad;
                    xmlReader.readNext();
                    while (xmlReader.name().toString() != "admin") {    // Creo un amministratore
                        if (xmlReader.name().toString() == "name")
                            ad.setName(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "surname")
                            ad.setSurname(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "address")
                            ad.setAddress(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "telephone")
                            ad.setTelephone(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "code")
                            ad.setCode(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "username")
                            ad.setUsername(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "pin")
                            ad.setPin(xmlReader.readElementText().toInt());
                        if (xmlReader.name().toString() == "salary")
                            ad.setSalary(xmlReader.readElementText().toDouble());
                        xmlReader.readNext();
                    }
                    user.push_back(new Admin(ad));

                } else if (xmlReader.name().toString() == "basic") {    // Creo un utente basic
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
                            uBasic.setTelephone(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "code")
                            uBasic.setCode(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "username")
                            uBasic.setUsername(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "pin")
                            uBasic.setPin(xmlReader.readElementText().toInt());
                        if(xmlReader.name().toString() == "count")
                            uBasic.setCount(xmlReader.readElementText().toDouble());
                        if(xmlReader.name().toString() == "countNumber")
                            uBasic.setCountNumber(xmlReader.readElementText().toInt());
                        xmlReader.readNext();
                    }
                    user.push_back(new BasicUser(uBasic));

                } else if (xmlReader.name().toString() == "pro") {  // Creo un utente pro
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
                            uPro.setTelephone(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "code")
                            uPro.setCode(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "username")
                            uPro.setUsername(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "pin")
                            uPro.setPin(xmlReader.readElementText().toInt());
                        if(xmlReader.name().toString() == "count")
                            uPro.setCount(xmlReader.readElementText().toDouble());
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
        file->close();

        if (xmlReader.hasError()) return false;
        return true;
    }
    return false;
}

bool DataBase::verifyAdmin (const string& u) const {    // Ritorna true se l'username passato appartiene ad un amministratore
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        Admin* a = dynamic_cast<Admin*> (user[it]);
        if (a && a->getUsername() == u)
                return true;
            else
                return false;
    }
    return false;
}


bool DataBase::verifyExistingUsername (const string& u) const {     // Ritorna true se l'username passato esiste già (tra Basic e Pro)
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        BasicUser* b = dynamic_cast<BasicUser*> (user[it]);
        if (b && b->getUsername() == u)
                return true;
    }
    return false;
}

bool DataBase::verifyExistingCountNumber (const int& c) const {     // Ritorna true se il #conto passato passato esiste già
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        BasicUser* b = dynamic_cast<BasicUser*> (user[it]);
        if (b && b->getCountNumber() == c)
                return true;
    }
    return false;

}

bool DataBase::verifyLogin (const string& usr, const int& pin) const {      // Verifica i dati che i dati di accesso dell'amministratore siano corretti
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        if (user[it]->getUsername() == usr && user[it]->getPin() == pin)
                return true;
    }
    return false;
}

bool DataBase::addUser (const BasicUser& u) {   // Inserisce un nuovo utente nel DB
    BasicUser* ncu = const_cast <BasicUser*> (&u);
    if (u.getCount() < 100000) {
        user.push_back(ncu);
    } else {
        user.push_back(new ProUser(*ncu));
    }
    if (this->write())
        return true;
    return false;
}

User* DataBase::getUser (const string& usr) const {     // Ritorna l'oggetto User con username uguale a quello passato
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        if (user[it]->getUsername() == usr)
            return user[it]->clone();
    }
    return new User();  // RIMUOVERE?
}

User* DataBase::getUserByCountNumber (const int& conto) const {     // Ritorna l'oggetto User con numero di conto uguale a quello passato
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        BasicUser* b = dynamic_cast<BasicUser*> (user[it]);
        if (b && b->getCountNumber() == conto)
            return user[it]->clone();
    }
    return new User();  // RIMUOVERE?
}

bool DataBase::verifyStillSame (const BasicUser& usr) {     // Verifica se l'utente cambia tipo di account o meno
    int cont = 0;                                           // Per sapere in quale posizione del Container l'oggetto si trova
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        BasicUser* b = dynamic_cast<BasicUser*> (user[it]);
        if (!b || (b && b->getUsername() != usr.getUsername()))
            cont ++;
        else
            break;
    }
    BasicUser* u = const_cast<BasicUser*> (&usr);

    if (100000 <= u->getCount() && !dynamic_cast<ProUser*> (u)) {       // L'utente è Basic e deve diventare Pro

        ProUser *s = new ProUser (*u);
        user.replace(cont, s->clone());     // Inserisce il "nuovo" utente Pro al posto di quello vecchio

    } else if (u->getCount() < 100000 && dynamic_cast<ProUser*> (u)) {  // L'utente è Pro e deve diventare Basic

        BasicUser* b = new BasicUser (*u);
        user.replace(cont, b->clone());     // Inserisce il "nuovo" utente Basic al posto di quello vecchio

    } else {    // L'utente non ha cambiato "tipo", ma vanno comunque aggiornati DB e Container

        if (dynamic_cast<ProUser*> (u)) {   // È un utente Pro

            ProUser* s = dynamic_cast<ProUser*> (u);
            user.replace(cont, s->clone()); // Inserisce il "nuovo" utente Basic (con conto aggiornato) nella lista di appartenenza

        } else {                            // È un utente Basic

            user.replace(cont, u->clone()); // Inserisco il "nuovo" utente Basic (con conto aggiornato) nella lista di appartenenza
        }
        //delete u; // ATTENZIONE
        this->write();
        return true;
    }
    this->write();
    return false;
}

bool DataBase::remove (const User& u) {     // Rimuove dal DB l'utente passato
    int cont = 0;
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        if (user[it]->getUsername() == u.getUsername()) break;
        cont++;
    }
    user.remove(cont);
    if (this->write())
        return true;
    return false;
}

bool DataBase::write () {       // Scrive nel DB gli utenti presenti nel contenitore
    file = new QFile("/home/mrc/Documents/p2_project/BankQ/users.xml");

    file->open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(file);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("users");

    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        ProUser* s = dynamic_cast<ProUser*> (user[it]);
        if (s) {    // È un utente pro
            xmlWriter.writeStartElement("pro");
            xmlWriter.writeTextElement("name", QString::fromStdString(s->getName()));
            xmlWriter.writeTextElement("surname", QString::fromStdString(s->getSurname()));
            xmlWriter.writeTextElement("address", QString::fromStdString(s->getAddress()));
            xmlWriter.writeTextElement("telephone", QString::fromStdString(s->getTelephone()));
            xmlWriter.writeTextElement("code", QString::fromStdString(s->getCode()));
            xmlWriter.writeTextElement("username", QString::fromStdString(s->getUsername()));
            xmlWriter.writeTextElement("pin", QString::number(s->getPin()));
            xmlWriter.writeTextElement("count", QString::number(s->getCount()));
            xmlWriter.writeTextElement("countNumber", QString::number(s->getCountNumber()));
            xmlWriter.writeTextElement("request", QString::number(s->getRequest()));
        } else {
            BasicUser* b = dynamic_cast<BasicUser*> (user[it]);
            if (b) {    // È un utente basic
                xmlWriter.writeStartElement("basic");
                xmlWriter.writeTextElement("name", QString::fromStdString(b->getName()));
                xmlWriter.writeTextElement("surname", QString::fromStdString(b->getSurname()));
                xmlWriter.writeTextElement("address", QString::fromStdString(b->getAddress()));
                xmlWriter.writeTextElement("telephone", QString::fromStdString(b->getTelephone()));
                xmlWriter.writeTextElement("code", QString::fromStdString(b->getCode()));
                xmlWriter.writeTextElement("username", QString::fromStdString(b->getUsername()));
                xmlWriter.writeTextElement("pin", QString::number(b->getPin()));
                xmlWriter.writeTextElement("count", QString::number(b->getCount()));
                xmlWriter.writeTextElement("countNumber", QString::number(b->getCountNumber()));
            } else {    // È un amministratore
                Admin* a = dynamic_cast<Admin*> (user[it]);
                xmlWriter.writeStartElement("admin");
                xmlWriter.writeTextElement("name", QString::fromStdString(a->getName()));
                xmlWriter.writeTextElement("surname", QString::fromStdString(a->getSurname()));
                xmlWriter.writeTextElement("address", QString::fromStdString(a->getAddress()));
                xmlWriter.writeTextElement("telephone", QString::fromStdString(a->getTelephone()));
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


bool DataBase::charge (const string& username, const int& cifra, const int& conto) {    // Ricarica il conto del destinatario e riduce quello del mittente
    User* m_app = this->getUser(username);
    BasicUser* mittente = dynamic_cast<BasicUser*> (m_app);     // Username dell'utente loggato
    QWidget* p = new QWidget();                                 // Per visualizzare i messaggi

    if (mittente->getCountNumber() != conto) {                  // Verifico che il conto da ricarica e quello dell'utente loggato siano diversi
        if (0 <= mittente->getCount() - cifra) {                // Verifico che il conto abbia sufficiente credito

            User* r_app = this->getUserByCountNumber(conto);    // Username del "ricevente"
            BasicUser* ricevente = dynamic_cast<BasicUser*> (r_app);


            ricevente->setCount(ricevente->getCount() + cifra); // Aggiunto l'importo al conto dell'utente "ricevente"

            QString qstr = "Ricevuta una ricarica di € " + QString::number(cifra);
            string str = qstr.toUtf8().constData();
            MessagesDataBase m;

            if (m.loadMessages())   {                           // Messaggio per la ricarica ricevuta

                m.addMessage(*new Message(ricevente->getUsername(), mittente->getUsername(), str));

                if (!this->verifyStillSame(*ricevente))         // Se l'utente è Basic allora può diventare Pro, altrimenti non accade "nulla"

                    m.addMessage(*new Message(ricevente->getUsername(),"BankQ", "Grazie alla ricarica ricevuta il proprio conto è ora di tipo Pro"));   // L'utente passa a Pro e lo segnalo
            } else {
                QMessageBox::warning(
                    p,
                    QString::fromStdString("BankQ - Errore"),
                    QString::fromStdString("Errore di caricamento del messaggi")
                );
                return false;
            }

            mittente->setCount(mittente->getCount() - cifra);   // Tolgo l'importo dal conto dell'utente loggato

            if (!this->verifyStillSame(*mittente)) {            // Se l'utente è Pro allora può diventare Basic, altrimenti non accade "nulla"
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
            return true;
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
    return false;
}

Container<BasicUser> DataBase::getUserNoAdmin () const {    // Ritorna una lista con gli utenti nel DB ad eccezione degli amministraotri
    Container<BasicUser> u;
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        if (dynamic_cast<BasicUser*> (user[it]))
            u.push_back(dynamic_cast<BasicUser*> (user[it])->clone());
    }
    return u;
}

Container<ProUser> DataBase::getUserNoRequest() const {     // Ritorna una lista di utenti Pro senza richieste di bonus anticipato
    Container<ProUser> u;
    for (Container<User>::Iteratore it = user.begin(); it != user.end(); ++it) {
        ProUser* p = dynamic_cast<ProUser*> (user[it]);
        if (p && !p->getRequest())
            u.push_back(p->clone());
    }
    return u;
}

bool DataBase::giveBonus(const User& cu) {      // Assegna il bonus all'utente pro passato

    User* ncu = const_cast<User*> (&cu);
    ProUser* u = dynamic_cast<ProUser*> (ncu);
    double c = u->getCount() + ((u->getCount())/100)*(u->getBonus() - u->getTax()); // Calcolo il nuovo saldo
    u->setCount(c);
    u->setRequest(true);
    if (this->verifyStillSame(*u)) {    // verifyStillSame in questo caso riscrive soltanto l'utente nel DB
        MessagesDataBase m;
        if (m.loadMessages()) {
            m.addMessage(*new Message (cu.getUsername(), "BankQ", "Bonus ricevuto"));
            return true;
        } else
            qDebug("Errore nel caricamento del DB dei messaggi");
    }
    return false;
}

void DataBase::giveBonusToAll () {      // Assegna il bonus agli utenti pro che non lo hanno ancora ricevuto
    Container<ProUser> l = this->getUserNoRequest();
    for (Container<ProUser>::Iteratore it = l.begin(); it != l.end(); ++it) {
        this->giveBonus(*l[it]);
    }
}

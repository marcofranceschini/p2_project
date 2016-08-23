#include "messagesdatabase.h"

MessagesDataBase::MessagesDataBase() {}

bool MessagesDataBase::loadMessages () {    // Carico i messaggi nel contenitore

    file = new QFile("/home/mrc/Documents/p2_project/BankQ/messages.xml");

    if (file->exists()) {
        file->open(QIODevice::ReadOnly);
        QXmlStreamReader xmlReader(file);
        while (!xmlReader.atEnd()) {
            xmlReader.readNext();
            if (xmlReader.isStartElement()) {
                if (xmlReader.name().toString() == "message") {
                    Message m;
                    xmlReader.readNext();
                    while (xmlReader.name().toString() != "message") {
                        if (xmlReader.name().toString() == "recipient")
                            m.setRecipient(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "sender")
                            m.setSender(xmlReader.readElementText().toStdString());
                        if (xmlReader.name().toString() == "text")
                            m.setText(xmlReader.readElementText().toStdString());
                        xmlReader.readNext();
                    }
                    messages.push_back(new Message(m));
                }
            }
        }
        file->close();
        if (xmlReader.hasError()) return false;
        return true;
    }
    return false;
}

int MessagesDataBase::countMessage (const string& u) const {    // Ritorna il numero di messaggi per un utente
    int cont = 0;
    for (Container<Message>::Iteratore it = messages.begin(); it != messages.end(); ++it) {
        if (messages[it]->getRecipient() == u)
            cont++;
    }
    return cont;
}

Container<Message> MessagesDataBase::getMessageByUser (const string& user) const {  // Ritorna i messaggi per l'utente passato
    Container<Message> app;
    for (Container<Message>::Iteratore it = messages.begin(); it != messages.end(); ++it) {
        if (messages[it]->getRecipient() == user)
            app.push_back(messages[it]);
    }
    return app;
}

bool MessagesDataBase::deleteMessages (const string& user) {    // Elimina i messaggi per l'utente passato

    if (0 < this->countMessage(user)) {
        vector<int> vet(this->countMessage(user));
        for (unsigned int i = 0; i < vet.size(); ++i) {
            vet[i] = 0;
        }
        int i = 0;
        for (Container<Message>::Iteratore it = messages.begin(); it != messages.end(); ++it) {
            if (messages[it]->getRecipient() != user)
                vet[i]++;
            else
                ++i;
        }

        for (unsigned int i = 0; i < vet.size(); ++i) {
            messages.remove(vet[i]);
        }
        return this->writeMessages();
    }
    return false;
}

bool MessagesDataBase::addMessage (const Message& m) {  // Inserisce un nuovo messaggio nel Container di messaggi
    messages.push_back(const_cast<Message*>(&m));
    return this->writeMessages();
}

bool MessagesDataBase::writeMessages () {   // Scrive i messaggi nel DB

    file = new QFile("/home/mrc/Documents/p2_project/BankQ/messages.xml");
    file->open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(file);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("messages");
    for (Container<Message>::Iteratore it = messages.begin(); it != messages.end(); ++it) {
        xmlWriter.writeStartElement("message");
        xmlWriter.writeTextElement("recipient", QString::fromStdString(messages[it]->getRecipient()));
        xmlWriter.writeTextElement("sender", QString::fromStdString(messages[it]->getSender()));
        xmlWriter.writeTextElement("text", QString::fromStdString(messages[it]->getText()));
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    file->close();
    if (xmlWriter.hasError()) return false;
    return true;
}

bool MessagesDataBase::deleteOneMessage (const Message& m) {    // Elimina un messaggio passato
    int cont = 0;
    for (Container<Message>::Iteratore it = messages.begin(); it != messages.end(); ++it) {
        if (*messages[it] == m) {

            messages.remove(cont);
            this->writeMessages();
            return true;
        }

        cont++;
    }
    return false;
}

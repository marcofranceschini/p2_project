#include "messagesdatabase.h"
#include "database.h"

#include "mainwindow.h" // DA RIMUOVERE

MessagesDataBase::MessagesDataBase() {}

bool MessagesDataBase::loadMessages () {
    file = new QFile("/home/mrc/Documents/p2_project/BankQ/messages.xml");

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

int MessagesDataBase::countMessage (const string& u) {
    int cont = 0;
    for (Container<Message>::Iteratore it = messages.begin(); it != messages.end(); ++it) {
        if (messages[it]->getRecipient() == u)
            cont++;
            /*QString st =QString::fromStdString(messages[it]->getRecipient());   // DA RIMUOVERE
            qDebug("QQQ-" + st.toLatin1() + "-QQQ");   // DA RIMUOVERE
            */
    }
    return cont;
}

Container<Message> MessagesDataBase::getMessageByUser (const string& user) {
    Container<Message> app;
    for (Container<Message>::Iteratore it = messages.begin(); it != messages.end(); ++it) {
        if (messages[it]->getRecipient() == user)
            app.push_back(messages[it]);
    }
    return app;
}

bool MessagesDataBase::deleteMessages (const string& user) {

    if (0 < this->countMessage(user)) {
        vector<int> vet(this->countMessage(user));
        for (int i = 0; i < vet.size(); ++i) {
            vet[i] = 0;
        }
        int i = 0;
        for (Container<Message>::Iteratore it = messages.begin(); it != messages.end(); ++it) {
            if (messages[it]->getRecipient() != user)
                vet[i]++;
            else
                ++i;
        }

        for (int i = 0; i < vet.size(); ++i) {
            messages.remove(vet[i]);
        }
        QString st =QString::number(this->countMessage(user));   // DA RIMUOVERE
        qDebug("QQQ-" + st.toLatin1() + "-QQQ");                 // DA RIMUOVERE
        return this->writeMessages();
    }
    return false;
}

bool MessagesDataBase::addMessage (Message m) {
    messages.push_back(&m);
    return this->writeMessages();
}

bool MessagesDataBase::writeMessages () {
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

/*bool MessagesDataBase::addBonus (const string& u) {
    DataBase d;
    if (d.load()) {
        User* user = d.getUser(u);
        ProUser* pro = dynamic_cast<ProUser*>(user);
    }
}*/

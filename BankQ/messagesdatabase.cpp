#include "messagesdatabase.h"

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
        if (messages[it]->getRecipient() == u) {
            cont++;
            QString st =QString::fromStdString(messages[it]->getRecipient());   // DA RIMUOVERE
            qDebug("QQQ-" + st.toLatin1() + "-QQQ");   // DA RIMUOVERE
        }
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
    file = new QFile("/home/mrc/Documents/p2_project/BankQ/messages.xml");
    file->open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(file);
    xmlWriter.setAutoFormatting(true);

    vector<int> vet(this->countMessage(user));
    for (int i = 0; i < vet.size(); ++i) {
        vet[i] = 0;
    }
    int i = 0;
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("messages");
    for (Container<Message>::Iteratore it = messages.begin(); it != messages.end(); ++it) {
        if (messages[it]->getRecipient() != user) {
            xmlWriter.writeStartElement("message");
            xmlWriter.writeTextElement("recipient", QString::fromStdString(messages[it]->getRecipient()));
            xmlWriter.writeTextElement("sender", QString::fromStdString(messages[it]->getSender()));
            xmlWriter.writeTextElement("text", QString::fromStdString(messages[it]->getText()));
            xmlWriter.writeEndElement();
            vet[i]++;
        } else
            ++i;
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    for (int i = 0; i < vet.size(); ++i) {
        messages.remove(vet[i]);
    }

    file->close();
    if (xmlWriter.hasError()) return false;
    return true;
}

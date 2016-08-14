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
        if (messages[it]->getRecipient() == u)
            cont++;
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

#ifndef MESSAGESDATABASE_H
#define MESSAGESDATABASE_H

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>
#include <QFile>

#include "container.h"
#include "message.h"

class MessagesDataBase {
private:
    QFile* file;

    Container<Message> messages;

public:
    MessagesDataBase ();

    bool loadMessages (); // Carico i messaggi nel contenitore

    int countMessage (const string&); // Conta quanti messaggi ha un utente

    Container<Message> getMessageByUser (const string&); // Ritorna i messaggi per l'utente passato

    bool deleteMessages (const string&); // Elimina i messaggi dell'utente passato

    bool addMessage (const Message&); // Inserisce un nuovo messaggio nel Container di messaggi

    bool writeMessages (); // Scrive i messaggi nel DB

    bool deleteOneMessage (const Message&); // Elimina un messaggio passato

    //bool addBonus (const string&); // Crea un messaggio per la richiesta del bonus anticipato
};

#endif // MESSAGESDATABASE_H

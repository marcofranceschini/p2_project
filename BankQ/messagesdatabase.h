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

    bool loadMessages ();                                       // Carico i messaggi nel contenitore

    int countMessage (const string&) const;                     // Ritorna il numero di messaggi per un utente

    Container<Message> getMessageByUser (const string&) const;  // Ritorna i messaggi per l'utente passato

    bool deleteMessages (const string&);                        // Elimina i messaggi per l'utente passato

    bool addMessage (const Message&);                           // Inserisce un nuovo messaggio nel Container di messaggi

    bool writeMessages ();                                      // Scrive i messaggi nel DB

    bool deleteOneMessage (const Message&);                     // Elimina un messaggio passato

    bool replace (const string&, const string&);                // Aggiorna i messaggi con il nuovo username (in caso di modifica)
};

#endif // MESSAGESDATABASE_H

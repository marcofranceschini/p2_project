#include "message.h"

Message::Message (string r, string s, string t): recipient(r), sender(s), text(t) {}

Message::Message () {}


void Message::setRecipient (const string& r) {
    recipient = r;
}

string Message::getRecipient () const {
    return recipient;
}

void Message::setSender (const string& s) {
    sender = s;
}

string Message::getSender () const {
    return sender;
}

void Message::setText (const string& t) {
    text = t;
}

string Message::getText () const {
    return text;
}

bool Message::operator== (const Message& m) const {    // Confronta due messaggi
    if (m.getRecipient() == recipient && m.getSender() == sender && m.getText() == text)
        return true;
    return false;
}

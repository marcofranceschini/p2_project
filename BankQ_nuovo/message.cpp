#include "message.h"

Message::Message (string r, string s, string t/*, bool re*/): recipient(r), sender(s), text(t)/*, read(re)*/ {}

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

/*void Message::setRead (const bool& r) {
    read = r;
}

bool Message::getRead () const {
    return read;
}*/

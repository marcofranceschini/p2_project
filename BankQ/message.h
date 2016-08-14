#ifndef MESSAGE_H
#define MESSAGE_H

using namespace std;
#include <string>

class Message {
private:
    string recipient;
    string sender;
    string text;
public:
    Message (string, string, string);

    Message ();

    void setRecipient (const string&);

    string getRecipient () const;

    void setSender (const string&);

    string getSender () const;

    void setText (const string&);

    string getText () const;
};

#endif // MESSAGE_H

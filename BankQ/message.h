#ifndef MESSAGE_H
#define MESSAGE_H

using namespace std;
#include <string>

class Message {
private:
    string recipient;
    string sender;
    string text;
    bool read; // 0 = no, 1 = si
public:
    Message (string, string, string, bool);

    Message ();

    void setRecipient (const string&);

    string getRecipient () const;

    void setSender (const string&);

    string getSender () const;

    void setText (const string&);

    string getText () const;

    void setRead (const bool&);

    bool getRead () const;
};

#endif // MESSAGE_H

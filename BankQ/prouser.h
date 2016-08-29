#ifndef PROUSER_H
#define PROUSER_H

#include "basicuser.h"

class ProUser: public BasicUser {
private:
    static int bonus;    // Bonus annuo in percentuale

    static int proTax;   // Tasse, ridotta, per gli utenti pro

    bool request;        // true = non ha ricevuto il bonus, false altrimenti

public:
    ProUser (string, string, string, string, string, string, string, int, int, bool);

    ProUser ();

    ~ProUser ();

    virtual ProUser* clone () const;

    ProUser (const ProUser&);

    ProUser (const BasicUser&);

    int getBonus () const;

    int getTax () const;

    bool verifyLogin (const int&) const;

    bool getRequest () const;

    void setRequest (bool r);
};

#endif // PROUSER_H

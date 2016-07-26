#ifndef BRONZEUSER_H
#define BRONZEUSER_H

#include "user.h"

class BronzeUser: public User {
protected:
    static double tax;     // Tasse
    static double bonus;   // Bonus

private:
    double count;   // Conto corrente

public:
    /*BronzeUser(string n, string s, string a, int t, string cod, string u, int p, bool ad):
        User(n, s, a, t, cod, u, p, ad) {}*/
     // float surcharge; L'utente bronzo non ha tasse aggiuntive da pagare a differenza degli altri tipi di utente
    BronzeUser (string, string, string, int, string, string, int);

    BronzeUser ();

    BronzeUser (const BronzeUser&);

    virtual double getTotalTax () const;

    virtual double getTotalBonus () const;

    double getCount () const;

    void setCount (double);

    virtual bool verifyLogin (const int&) const;
};



#endif // BRONZEUSER_H

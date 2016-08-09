#ifndef BRONZEUSER_H
#define BRONZEUSER_H

#include "user.h"

class BronzeUser: public User {
protected:
    static double tax;     // Tasse

    static double bonus;   // Bonus

    int countNumber; // Numero di conto

    double count;   // Conto corrente

public:
    /*BronzeUser(string n, string s, string a, int t, string cod, string u, int p, bool ad):
        User(n, s, a, t, cod, u, p, ad) {}*/
     // float surcharge; L'utente bronzo non ha tasse aggiuntive da pagare a differenza degli altri tipi di utente
    BronzeUser (string, string, string, int, string, string, int, int, double);

    BronzeUser ();

    BronzeUser (const BronzeUser&);

    virtual double getTotalTax () const;

    virtual double getTotalBonus () const;

    virtual double getCount () const;

    virtual void setCount (double);

    virtual void decreaseCount (double);

    virtual void increaseCount (double);

    virtual int getCountNumber () const;

    virtual void setCountNumber (int);

    virtual bool verifyLogin (const int&) const;
};



#endif // BRONZEUSER_H

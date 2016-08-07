#ifndef BRONZEUSER_H
#define BRONZEUSER_H

#include "user.h"

class BronzeUser: public User {
protected:
    static double tax;     // Tasse
    static double bonus;   // Bonus
    string countNumber; // Numero di conto

private:
    double count;   // Conto corrente

public:
    /*BronzeUser(string n, string s, string a, int t, string cod, string u, int p, bool ad):
        User(n, s, a, t, cod, u, p, ad) {}*/
     // float surcharge; L'utente bronzo non ha tasse aggiuntive da pagare a differenza degli altri tipi di utente
    BronzeUser (string, string, string, int, string, string, int, string);

    BronzeUser ();

    BronzeUser (const BronzeUser&);

    virtual double getTotalTax () const;

    virtual double getTotalBonus () const;

    double getCount () const;

    void setCount (double);

    virtual string getCountNumber () const;

    virtual void setCountNumber (string);

    virtual bool verifyLogin (const int&) const;
};



#endif // BRONZEUSER_H

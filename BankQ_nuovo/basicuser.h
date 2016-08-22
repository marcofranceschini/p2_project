#ifndef BASICUSER_H
#define BASICUSER_H

#include "user.h"

class BasicUser: public User {
protected:
    static double tax;  // Tasse

    //static double bonus;   // Bonus

    int countNumber;    // Numero di conto

    double count;       // Conto corrente

public:
    /*BasicUser(string n, string s, string a, int t, string cod, string u, int p, bool ad):
        User(n, s, a, t, cod, u, p, ad) {}*/
     // float surcharge; L'utente bronzo non ha tasse aggiuntive da pagare a differenza degli altri tipi di utente
    BasicUser (string, string, string, int, string, string, int, int, double);

    BasicUser ();

    ~BasicUser ();

    virtual BasicUser* clone () const;

    BasicUser (const BasicUser&);

    virtual double getTax () const;

    //virtual double getTotalBonus () const;

    virtual double getCount () const;

    virtual void setCount (double);

    /*virtual void decreaseCount (double);

    virtual void increaseCount (double);*/

    virtual int getCountNumber () const;

    virtual void setCountNumber (int);

    virtual bool verifyLogin (const int&) const;

    //BasicUser* operator= (const BasicUser&);
};

#endif // BASICUSER_H

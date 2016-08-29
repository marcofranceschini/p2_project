#ifndef BASICUSER_H
#define BASICUSER_H

#include "user.h"

class BasicUser: public User {
protected:
    static double tax;  // Tasse

    int countNumber;    // Numero di conto

    double count;       // Conto corrente

public:
    BasicUser (string, string, string, string, string, string, string, int, double);

    BasicUser ();

    ~BasicUser ();

    virtual BasicUser* clone () const;

    BasicUser (const BasicUser&);

    virtual double getTax () const;

    virtual double getCount () const;

    virtual void setCount (double);

    virtual int getCountNumber () const;

    virtual void setCountNumber (int);
};

#endif // BASICUSER_H

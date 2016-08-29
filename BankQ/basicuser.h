#ifndef BASICUSER_H
#define BASICUSER_H

#include "user.h"

class BasicUser: public User {
protected:
    static int tax;  // Tasse

    int countNumber;    // Numero di conto

    int count;          // Conto corrente

public:
    BasicUser (string, string, string, string, string, string, string, int, int);

    BasicUser ();

    ~BasicUser ();

    virtual BasicUser* clone () const;

    BasicUser (const BasicUser&);

    virtual int getTax () const;

    virtual int getCount () const;

    virtual void setCount (int);

    virtual int getCountNumber () const;

    virtual void setCountNumber (int);
};

#endif // BASICUSER_H

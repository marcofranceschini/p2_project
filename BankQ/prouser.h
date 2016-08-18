#ifndef PROUSER_H
#define PROUSER_H

#include "basicuser.h"

class ProUser: public BasicUser {
private:
    static double extraBonus;   // Bonus aggiuntivo rispetto all'utente Bronze

public:
    ProUser (string, string, string, int, string, string, int, int, double);

    ProUser ();

    ~ProUser ();

    virtual ProUser* clone () const;

    ProUser (const ProUser&);

    ProUser (const BasicUser&);


    /*virtual float getTotalTax() const {
        return ProUser::getTotalTax();
    }L'utente silver non tasse aggiuntive, serve quinid il get?? */

    double getTotalBonus () const;

    bool verifyLogin (const int&) const;

    /*double getCount () const {
        return count;
    }*/
};

//double ProUser::extraBonus = 1.5;

#endif // PROUSER_H

#ifndef PROUSER_H
#define PROUSER_H

#include "basicuser.h"

class ProUser: public BasicUser {
private:
    static double bonus;   // Bonus annuo in percentuale

    static double proTax;

    bool request; // 0 = non ha ricevuto il bonus, 1 altrimenti

public:
    ProUser (string, string, string, int, string, string, int, int, double, bool);

    ProUser ();

    ~ProUser ();

    virtual ProUser* clone () const;

    ProUser (const ProUser&);

    ProUser (const BasicUser&);


    /*virtual float getTotalTax() const {
        return ProUser::getTotalTax();
    }L'utente silver non tasse aggiuntive, serve quinid il get?? */

    double getBonus () const;

    double getTax () const;

    bool verifyLogin (const int&) const;

    bool getRequest () const;

    void setRequest (bool r);

    /*double getCount () const {
        return count;
    }*/
};

//double ProUser::extraBonus = 1.5;

#endif // PROUSER_H

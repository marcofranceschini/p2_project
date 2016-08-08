#ifndef SILVERUSER_H
#define SILVERUSER_H

#include "bronzeuser.h"

class SilverUser: public BronzeUser {
private:
    static double extraBonus;   // Bonus aggiuntivo rispetto all'utente Bronze

public:
    SilverUser (string, string, string, int, string, string, int, string, double);

    SilverUser();

    SilverUser (const SilverUser&);


    /*virtual float getTotalTax() const {
        return SilverUser::getTotalTax();
    }L'utente silver non tasse aggiuntive, serve quinid il get?? */

    double getTotalBonus () const;

    bool verifyLogin (const int&) const;

    /*double getCount () const {
        return count;
    }*/
};

//double SilverUser::extraBonus = 1.5;

#endif // SILVERUSER_H

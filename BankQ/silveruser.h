#ifndef SILVERUSER_H
#define SILVERUSER_H

#include "bronzeuser.h"

class SilverUser: public BronzeUser {
    private:
        /*static float bonusS; */// L'utente silver ha un bonus aggiuntivo rispetto a quello standard
        static double extraBonus;
    public:
        SilverUser();

        /*virtual float getTotalTax() const {
            return SilverUser::getTotalTax();
        }L'utente silver non tasse aggiuntive, serve quinid il get?? */

        double getTotalBonus () const {
            return extraBonus + BronzeUser::getTotalBonus();
        }

        /*double getCount () const {
            return count;
        }*/
};

//double SilverUser::extraBonus = 1.5;

#endif // SILVERUSER_H

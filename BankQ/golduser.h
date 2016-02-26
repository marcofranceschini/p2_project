#ifndef GOLDUSER_H
#define GOLDUSER_H
#include "silveruser.h"

class GoldUser: public SilverUser {
    private:
        float bonusGold;
        int surcharge; //  L'utente gold ha tasse aggiuntive da pagare
        // Tassa int e normalmente (bronze e silver) è float per usare Template
    public:
        GoldUser();
        ~GoldUser();

        float getTotalTax() const {
             return surcharge + BronzeUser::getTotalTax();
        } // Le tasse tra silver e bronze sono ugali, se devo farle ritornare uso il getTax di BronzeUser

        float getTotalBonus() const {
            return bonusGold + SilverUser::getTotalBonus();
        }

        /*virtual float getTotalTax() const {
            return this->SilverUser::getTotalTax() + surcharge;
        }*/

        /* virtual float getTotalBonus() const {
             return this->SilverUser::getTotalBonus() + bonusG;
         }*/
};

/*float GoldUser::bonusGold = 1.5;
int GoldUser::surcharge = 1.3;*/

#endif // GOLDUSER_H

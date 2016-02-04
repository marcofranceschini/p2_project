#ifndef SILVERUSER_H
#define SILVERUSER_H
#include "bronzeuser.h"

class SilverUser: public BronzeUser {
    private:
        static float bonusS; // L'utente silver ha un bonus aggiuntivo rispetto a quello standard
    public:
        SilverUser();

        float getBonusS () {
            return bonusS;
        }

       /* virtual float getTotalTax() const {
            getTax();
        }*/ // Le tasse tra silver e bronze sono ugali, se devo farle ritornare uso il getTax di BronzeUser
        virtual float getTotalTax() const {
            return this->BronzeUser::getTotalTax();
        }


        virtual float getTotalBonus() const {
            return this->BronzeUser::getTotalBonus() + bonusS;
        }
};

float SilverUser::bonusS = 1;

#endif // SILVERUSER_H

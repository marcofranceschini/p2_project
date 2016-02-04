#ifndef BRONZEUSER_H
#define BRONZEUSER_H
#include "user.h"

class BronzeUser: public User {
    private:
        static float tax;
        static float bonusB;
    public:
        /*BronzeUser(string n, string s, string a, int t, string cod, string u, int p, bool ad):
            User(n, s, a, t, cod, u, p, ad) {}*/
         // float surcharge; L'utente bronzo non ha tasse aggiuntive da pagare a differenza degli altri tipi di utente
        BronzeUser();

        virtual float getTotalTax() const {
            return tax;
        }

        virtual float getTotalBonus() const {
            return bonusB;
        }
};
float BronzeUser::tax = 1;
float BronzeUser::bonusB = 1.5;

#endif // BRONZEUSER_H

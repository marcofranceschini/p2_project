#ifndef BRONZEUSER_H
#define BRONZEUSER_H

#include "user.h"

class BronzeUser: public User {
    protected:
        /*static*/ double tax;     // Tasse
        /*static*/ double bonus;   // Bonus

    private:
        double count;   // Conto corrente

    public:
        /*BronzeUser(string n, string s, string a, int t, string cod, string u, int p, bool ad):
            User(n, s, a, t, cod, u, p, ad) {}*/
         // float surcharge; L'utente bronzo non ha tasse aggiuntive da pagare a differenza degli altri tipi di utente
        BronzeUser();

        virtual double getTotalTax () const {
            return tax;
        }

        virtual double getTotalBonus () const {
            return bonus;
        }

        double getCount () const {
            return count;
        }

        void setCount (double c) {
            count = c;
        }

        virtual bool verifyLogin (const int& pass) const {
            return (pin == pass);
        }
};

//double BronzeUser::tax = 1;
//double BronzeUser::bonus = 1.5;

#endif // BRONZEUSER_H

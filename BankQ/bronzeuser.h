#ifndef BRONZEUSER_H
#define BRONZEUSER_H
#include "user.h"

class BronzeUser: public User {
    private:
        float tax;
        float cheking;
    public:
        BronzeUser();
         // float surcharge; L'utente bronzo non ha tasse aggiuntive da pagare a differenza degli altri tipi di utente
        float getTax () const {
            return tax;
        }

        float getCheking () const {
            return cheking;
        }

        void setCheking (float c) {
            cheking=cheking+c;
        }
};

#endif // BRONZEUSER_H

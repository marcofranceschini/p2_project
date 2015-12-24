#ifndef BRONZEUSER_H
#define BRONZEUSER_H
#include "user.h"

class BronzeUser: public User {
    private:
        float tax;
    public:
        BronzeUser();
         // float surcharge; L'utente bronzo non ha tasse aggiuntive da pagare a differenza degli altri tipi di utente
        float getTax () {
            return tax;
        }

};

#endif // BRONZEUSER_H

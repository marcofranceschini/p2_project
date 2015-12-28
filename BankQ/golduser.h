#ifndef GOLDUSER_H
#define GOLDUSER_H
#include "user.h"

class GoldUser: public User {
    private:
        float bonusExtra;
        int surcharge; //  L'utente gold ha tasse aggiuntive da pagare
        // Tassa int e normalmente (bronze e silver) è float per usare Template
    public:
        GoldUser();
        ~GoldUser();

        float getBonusExtra () {
            return bonusExtra;
        }
};

#endif // GOLDUSER_H

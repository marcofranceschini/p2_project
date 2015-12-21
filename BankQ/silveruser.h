#ifndef SILVERUSER_H
#define SILVERUSER_H

class SilverUser {
    private:
        float bonus; // L'utente silver ha un bonus aggiuntivo rispetto a quello standard
    public:
        SilverUser();

        float getBonus () {
            return bonus;
        }
};

#endif // SILVERUSER_H

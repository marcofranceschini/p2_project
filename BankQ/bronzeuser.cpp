#include "bronzeuser.h"

BronzeUser::BronzeUser(string n, string s, string a, int t, string c, string u, int p):User(n, s, a, t, c, u, p) {}

BronzeUser::BronzeUser() {}

double BronzeUser::getTotalTax () const {
    return tax;
}

double BronzeUser::getTotalBonus () const {
    return bonus;
}

double BronzeUser::getCount () const {
    return count;
}

void BronzeUser::setCount (double c) {
    count = c;
}

bool BronzeUser::verifyLogin (const int& pass) const {
    int p = const_cast<int&> (pass);
    if (pin==p) return true;
    return false;
}

double BronzeUser::tax = 1;

double BronzeUser::bonus = 1.5;

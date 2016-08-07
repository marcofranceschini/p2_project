#include "silveruser.h"

SilverUser::SilverUser(string n, string s, string a, int t, string c, string u, int p, string num):BronzeUser(n, s, a, t, c, u, p, num) {}

SilverUser::SilverUser() {}

SilverUser::SilverUser (const SilverUser& s) {
    name = s.getName();
    surname = s.getSurname();
    address = s.getAddress();
    telephone = s.getTelephone();
    code = s.getCode();
    username = s.getUsername();
    pin = s.getPin();
    countNumber = s.getCountNumber();
}

double SilverUser::getTotalBonus () const {
    return extraBonus + tax;
}

bool SilverUser::verifyLogin (const int& pass) const {
    int p = const_cast<int&> (pass);
    if (pin==p) return true;
    return false;
}

double SilverUser::extraBonus = 1.5;

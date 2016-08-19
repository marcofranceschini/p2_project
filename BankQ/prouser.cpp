#include "prouser.h"

ProUser::ProUser (string n, string s, string a, int t, string c, string u, int p, int nu, double co):BasicUser(n, s, a, t, c, u, p, nu, co) {}

ProUser::ProUser () {}

ProUser::~ProUser () {}

ProUser* ProUser::clone () const {
    return new ProUser (name, surname, address, telephone, code, username, pin, countNumber, count);
}

ProUser::ProUser (const ProUser& s) {
    name = s.getName();
    surname = s.getSurname();
    address = s.getAddress();
    telephone = s.getTelephone();
    code = s.getCode();
    username = s.getUsername();
    pin = s.getPin();
    countNumber = s.getCountNumber();
    count = s.getCount();
}

ProUser::ProUser (const BasicUser& b) {
    name = b.getName();
    surname = b.getSurname();
    address = b.getAddress();
    telephone = b.getTelephone();
    code = b.getCode();
    username = b.getUsername();
    pin = b.getPin();
    countNumber = b.getCountNumber();
    count = b.getCount();
}

double ProUser::getBonus () const {
    return bonus;
}

double ProUser::getTax () const {
    return proTax;
}

bool ProUser::verifyLogin (const int& pass) const {
    int p = const_cast<int&> (pass);
    if (pin==p) return true;
    return false;
}

double ProUser::bonus = 1.5;
double ProUser::proTax = 0.5;

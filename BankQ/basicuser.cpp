#include "basicuser.h"

BasicUser::BasicUser (string n, string s, string a, string t, string c, string u, int p, int nu, double co): User(n, s, a, t, c, u, p), countNumber(nu), count(co) {}

BasicUser::BasicUser () {}

BasicUser::~BasicUser () {}

BasicUser* BasicUser::clone () const {
    return new BasicUser (name, surname, address, telephone, code, username, pin, countNumber, count);
}

BasicUser::BasicUser (const BasicUser& u): User(u.getName(), u.getSurname(), u.getAddress(), u.getTelephone(), u.getCode(), u.getUsername(), u.getPin()), countNumber(u.getCountNumber()), count(u.getCount()) {
    /*name = u.getName();
    surname = u.getSurname();
    address = u.getAddress();
    telephone = u.getTelephone();
    code = u.getCode();
    username = u.getUsername();
    pin = u.getPin();
    countNumber = u.getCountNumber();
    count = u.getCount();*/
}

double BasicUser::getTax () const {
    return tax;
}

double BasicUser::getCount () const {
    return count;
}

void BasicUser::setCount (double c) {
    count = c;
}

int BasicUser::getCountNumber () const {
    return countNumber;
}

void BasicUser::setCountNumber (int c) {
    countNumber = c;
}

bool BasicUser::verifyLogin (const int& pass) const {
    int p = const_cast<int&> (pass);
    if (pin==p) return true;
    return false;
}

double BasicUser::tax = 1.0;

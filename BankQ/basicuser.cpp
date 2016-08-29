#include "basicuser.h"

BasicUser::BasicUser (string n, string s, string a, string t, string c, string u, string p, int nu, double co): User(n, s, a, t, c, u, p), countNumber(nu), count(co) {}

BasicUser::BasicUser () {}

BasicUser::~BasicUser () {}

BasicUser* BasicUser::clone () const {
    return new BasicUser (name, surname, address, telephone, code, username, pin, countNumber, count);
}

BasicUser::BasicUser (const BasicUser& u): User(u.getName(), u.getSurname(), u.getAddress(), u.getTelephone(), u.getCode(), u.getUsername(), u.getPin()), countNumber(u.getCountNumber()), count(u.getCount()) {}

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

double BasicUser::tax = 1.0;

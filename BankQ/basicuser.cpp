#include "basicuser.h"

BasicUser::BasicUser (string n, string s, string a, string t, string c, string u, string p, int nu, int co): User(n, s, a, t, c, u, p), countNumber(nu), count(co) {}

BasicUser::BasicUser () {}

BasicUser::~BasicUser () {}

BasicUser* BasicUser::clone () const {
    return new BasicUser (name, surname, address, telephone, code, username, pin, countNumber, count);
}

BasicUser::BasicUser (const BasicUser& u): User(u.getName(), u.getSurname(), u.getAddress(), u.getTelephone(), u.getCode(), u.getUsername(), u.getPin()), countNumber(u.getCountNumber()), count(u.getCount()) {}

int BasicUser::getTax () const {
    return tax;
}

int BasicUser::getCount () const {
    return count;
}

void BasicUser::setCount (int c) {
    count = c;
}

int BasicUser::getCountNumber () const {
    return countNumber;
}

void BasicUser::setCountNumber (int c) {
    countNumber = c;
}

int BasicUser::tax = 2;

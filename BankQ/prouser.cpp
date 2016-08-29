#include "prouser.h"

ProUser::ProUser (string n, string s, string a, string t, string c, string u, string p, int nu, int co, bool r): BasicUser(n, s, a, t, c, u, p, nu, co), request(r) {}

ProUser::ProUser () {}

ProUser::~ProUser () {}

ProUser* ProUser::clone () const {
    return new ProUser (name, surname, address, telephone, code, username, pin, countNumber, count, request);
}

ProUser::ProUser (const ProUser& s): BasicUser(s.getName(), s.getSurname(), s.getAddress(), s.getTelephone(), s.getCode(), s.getUsername(), s.getPin(), s.getCountNumber(), s.getCount()), request(s.getRequest()) {}

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
    request = false;
}

int ProUser::getBonus () const {
    return bonus;
}

int ProUser::getTax () const {
    return proTax;
}

bool ProUser::getRequest () const {
    return request;
}

void ProUser::setRequest (bool r) {
    request = r;
}

int ProUser::bonus = 2;

int ProUser::proTax = 1;

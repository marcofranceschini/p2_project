#include "user.h"

User::User(string n, string s, string a, string t, string c, string u, int p): name(n), surname(s), address(a), telephone(t), code(c), username(u), pin(p) {}

User::User () {}

User::~User() {}

User* User::clone () const {
    return new User (name, surname, address, telephone, code, username, pin);
}


// Metodi get
string User::getName () const {
    return name;
}

string User::getSurname () const {
    return surname;
}

string User::getAddress () const {
    return address;
}

string User::getTelephone () const {
    return telephone;
}

string User::getCode () const {
    return code;
}

string User::getUsername () const {
    return username;
}

int User::getPin () const {
    return pin;
}


// Metodi set
void User::setName (const string& n) {
    name=n;
}

void User::setSurname (const string& s) {
    surname=s;
}

void User::setAddress (const string& a) {
    address=a;
}

void User::setTelephone (const string& t) {
    telephone=t;
}

void User::setCode (const string& c) {
    code=c;
}

void User::setUsername (const string& u) {
    username=u;
}

void User::setPin (const int& p) {
    pin=p;
}

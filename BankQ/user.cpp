#include "user.h"

User::User(string n, string s, string a, int t, string c, string u, int p): name(n), surname(s), address(a), telephone(t), code(c), username(u), pin(p) {

   // User::User (string n, string s, string a, int t, string c, string u, int p): name(n), surname(s), address(a), telephone(t), code(c), username(u), pin(p) {}
}

User::User () {}

User::~User() {}

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

int User::getTelephone () const {
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

/*int getAdmin () const {
    return admin;
}*/

// Metodi set
void User::setName (string n) {
    name=n;
}

void User::setSurname (string s) {
    surname=s;
}

void User::setAddress (string a) {
    address=a;
}

void User::setTelephone (int t) {
    telephone=t;
}

void User::setCode (string c) {
    code=c;
}

void User::setUsername (string u) {
    username=u;
}

void User::setPin (int p) {
    pin=p;
}

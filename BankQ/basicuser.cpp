#include "basicuser.h"

BasicUser::BasicUser (string n, string s, string a, int t, string c, string u, int p, int nu, double co):User(n, s, a, t, c, u, p), countNumber(nu), count(co) {}

BasicUser::BasicUser () {}

BasicUser::~BasicUser () {}

BasicUser* BasicUser::clone () const {
    return new BasicUser (name, surname, address, telephone, code, username, pin, countNumber, count);
}

BasicUser::BasicUser (const BasicUser& u) {
    name = u.getName();
    surname = u.getSurname();
    address = u.getAddress();
    telephone = u.getTelephone();
    code = u.getCode();
    username = u.getUsername();
    pin = u.getPin();
    countNumber = u.getCountNumber();
    count = u.getCount();
}

double BasicUser::getTotalTax () const {
    return tax;
}

double BasicUser::getTotalBonus () const {
    return bonus;
}

double BasicUser::getCount () const {
    return count;
}

void BasicUser::setCount (double c) {
    count = c;
}

/*void BasicUser::decreaseCount (double c) {

    // Verifico se l'utente scende a bronze
    if (count - c < 100000) {

    } else
        count = count - c;
    // Fare una seconda funzione, quella corrente torna true o false se scendo di grado o meno
    // l'altra funzione (non va inserita in brozeUser) crea un nuovo utente ed elimina l'utente silver con conseguente
    // riscrittura sul db
}

void BasicUser::increaseCount (double c) {

    // Verifico se l'utente sale a silver
    if (100000 <= count + c) {

    } else
        count = count + c;
}*/

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

/*BasicUser* BasicUser::operator= (const BasicUser& u) {
    delete this;
    name = u.getName();
    surname = u.getSurname();
    address = u.getAddress();
    telephone = u.getTelephone();
    code = u.getCode();
    username = u.getUsername();
    pin = u.getPin();
    countNumber = u.getCountNumber();
    count = u.getCount();
}*/


double BasicUser::tax = 1;

double BasicUser::bonus = 1.5;

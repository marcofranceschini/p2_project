#include "bronzeuser.h"

BronzeUser::BronzeUser (string n, string s, string a, int t, string c, string u, int p, int nu, double co):User(n, s, a, t, c, u, p), countNumber(nu), count(co) {}

BronzeUser::BronzeUser () {}

BronzeUser::~BronzeUser () {}

BronzeUser::BronzeUser (const BronzeUser& u) {
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

/*void BronzeUser::decreaseCount (double c) {

    // Verifico se l'utente scende a bronze
    if (count - c < 100000) {

    } else
        count = count - c;
    // Fare una seconda funzione, quella corrente torna true o false se scendo di grado o meno
    // l'altra funzione (non va inserita in brozeUser) crea un nuovo utente ed elimina l'utente silver con conseguente
    // riscrittura sul db
}

void BronzeUser::increaseCount (double c) {

    // Verifico se l'utente sale a silver
    if (100000 <= count + c) {

    } else
        count = count + c;
}*/

int BronzeUser::getCountNumber () const {
    return countNumber;
}

void BronzeUser::setCountNumber (int c) {
    countNumber = c;
}

bool BronzeUser::verifyLogin (const int& pass) const {
    int p = const_cast<int&> (pass);
    if (pin==p) return true;
    return false;
}

/*BronzeUser* BronzeUser::operator= (const BronzeUser& u) {
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


double BronzeUser::tax = 1;

double BronzeUser::bonus = 1.5;

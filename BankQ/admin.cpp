#include "admin.h"

Admin::Admin(string n, string s, string a, string t, string c, string u, string p, double sal):User(n, s, a, t, c, u, p), salary(sal) {}

Admin::Admin () {}

Admin::Admin (const Admin& a): User(a.getName(), a.getSurname(), a.getAddress(), a.getTelephone(), a.getCode(), a.getUsername(), a.getPin()), salary(a.getSalary()) {
    /*name = a.getName();
    surname = a.getSurname();
    address = a.getAddress();
    telephone = a.getTelephone();
    code = a.getCode();
    username = a.getUsername();
    pin = a.getPin();
    salary = a.getSalary();*/
}

Admin::~Admin() {}

double Admin::getSalary () const {
    return salary;
}

void Admin::setSalary (double s) {
    salary = s;
}

Admin* Admin::clone () const {
    return new Admin (name, surname, address, telephone, code, username, pin, salary);
}

/*bool Admin::verifyLogin (const int& pass) const {
    int p = const_cast<int&> (pass);
    if (pin==p) return true;
    return false;
}*/

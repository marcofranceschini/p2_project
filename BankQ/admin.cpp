#include "admin.h"

Admin::Admin(string n, string s, string a, string t, string c, string u, string p, double sal):User(n, s, a, t, c, u, p), salary(sal) {}

Admin::Admin () {}

Admin::Admin (const Admin& a): User(a.getName(), a.getSurname(), a.getAddress(), a.getTelephone(), a.getCode(), a.getUsername(), a.getPin()), salary(a.getSalary()) {}

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

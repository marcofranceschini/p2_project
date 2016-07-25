#include "admin.h"

Admin::Admin(string n, string s, string a, int t, string c, string u, int p, double sal):User(n, s, a, t, c, u, p), salary(sal) {}

Admin::Admin () {}

double Admin::getSalary () const {
    return salary;
}

Admin* Admin::clone () const {
    return new Admin (name, surname, address, telephone, code, username, pin, salary);
}

/*bool Admin::verifyLogin (const int& pass) const {
    int p = const_cast<int&> (pass);
    if (pin==p) return true;
    return false;
}*/

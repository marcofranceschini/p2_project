#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"

class Admin: public User {
private:
    double salary;
public:
    Admin (string, string, string, int, string, string, int, double);

    Admin ();

    Admin (const Admin&);

    ~Admin ();


    double getSalary () const;

    Admin* clone () const;

    bool verifyLogin (const int& pass) const {
        int p = const_cast<int&> (pass);
        if (pin==p) return true;
        return false;
    }
};

#endif // ADMIN_H

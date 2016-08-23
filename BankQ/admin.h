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

    /*Admin* operator= (const Admin& a) {
        return new Admin(a);
    }*/


    double getSalary () const;

    void setSalary (double);

    Admin* clone () const;

    //bool verifyLogin (const int&) const;
};

#endif // ADMIN_H

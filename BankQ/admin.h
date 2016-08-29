#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

class Admin: public User {
private:
    double salary;
public:
    Admin (string, string, string, string, string, string, string, double);

    Admin ();

    Admin (const Admin&);

    ~Admin ();

    double getSalary () const;

    void setSalary (double);

    Admin* clone () const;
};

#endif // ADMIN_H

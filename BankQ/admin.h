#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"

class Admin: public User {
    private:
        double salary;
    public:
        Admin();

        double getSalary () const {
            return salary;
        }

        bool verifyLogin (const int& pass) const {
            return (pin == pass);
        }
};

#endif // ADMIN_H

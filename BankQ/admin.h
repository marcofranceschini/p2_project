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
            //int p = const_cast<int&> (pass);
            //if (pin==p) return true;
            //return false;
            return false;
        }
};

#endif // ADMIN_H

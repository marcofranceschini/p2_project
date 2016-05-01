#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"

class Admin: public User {
    private:
        double salary;
    public:
        Admin();
        ~Admin();

        double getSalary () const {
            return salary;
        }

        void closeAccount();
};

#endif // ADMIN_H

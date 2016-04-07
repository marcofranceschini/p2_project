#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"

class Admin: public User {
    private:
        double salary;
    public:
        Admin();
        //virtual ~Admin();

        double getSalary () const {
            return salary;
        }

        virtual void closeAccount();
};

#endif // ADMIN_H

#ifndef ADDUSER_H
#define ADDUSER_H

#include "database.h"
#include "basicuser.h"

class AddUser {
private:
    BasicUser user;
public:
    AddUser(BasicUser);

    bool addUser () const;
};

#endif // ADDUSER_H

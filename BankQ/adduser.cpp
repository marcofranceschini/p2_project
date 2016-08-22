#include "adduser.h"

AddUser::AddUser(BasicUser u): user(u) {

}

bool AddUser::addUser () const {
    DataBase d;
    return d.addUser(user);
}

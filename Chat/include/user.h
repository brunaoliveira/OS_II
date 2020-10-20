#ifndef USER_H
#define USER_H

#include <list>
#include <string>
#include "group.h"

class Group;

class User {
    public:
    std::list<User> activeUsers;

    // atributos
    std::string userId;
    int userConections;

    // construtor
    User(std::string userId);
    // ~User();

    // métodos
    void addUser(User user);
    void deleteUser(User user);
    void showUsers();
    int joinGroup(Group group);

};


#endif
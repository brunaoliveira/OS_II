#ifndef GROUP_H
#define GROUP_H

#include "user.h"
#include <string>
#include <list>

class User;

class Group {

public:
    std::string name;      //group name
    std::list<User> users; //connected users TODO: reference to user class

    Group(std::string name);    //Constructor
    ~Group();                   //Destructor
    void joinUser(User user);   //New user join to the group
    void leftUser(User user);   //User left the group
    std::list<User> getUsers(); //Get connected users
};

#endif

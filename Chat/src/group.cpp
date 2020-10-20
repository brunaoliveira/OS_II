#include "../include/group.h"
#include "../include/user.h"

Group::Group(std::string name)
{
    this->name = name;
}

void Group::joinUser(User user)
{
    this->users.push_back(user);
}

void Group::leftUser(User user)
{
    this->users.remove(user);
}

std::list<User> Group::getUsers()
{
    return this->users;
}

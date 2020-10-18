#ifndef USER_H
#define USER_H


class User {
    // construtor
    User(std::string userId);
    void addUser(User* user);
    void deleteUser(User* user);
    void showUsers();

};


#endif
#ifndef USER_H
#define USER_H


class User {
    // atributos
    std::string userId;

    // construtor
    User(std::string userId);

    // métodos
    void addUser(User* user);
    void deleteUser(User* user);
    void showUsers();

};


#endif
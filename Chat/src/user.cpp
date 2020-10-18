#include "user.h"
#include "constants.h"
#include <string>


User::User(std::string userId) {
    this->userId = userId;
}

void User::addUser(User* user) {

}

void User::deleteUser(User* user) {
    // TODO
    // solicita permissão de escrita
    // deleta o usuário
    // libera permissão de escrita 
}

int User::joinGroup(Group* group) {
    // checar o numero de conexões para esse usuário
    if (thisUser.conections < MAX_USER_CONECTIONS) {
        // adiciona ao grupo
        // tem que ver se ja estava no grupo
        // e o quais consequencias

    }
    // não conectou pq já tem 2 conexões 
    return 0;
}

void User::showUsers() {

}
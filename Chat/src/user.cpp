#include "../include/user.h"
#include "../include/constants.h"
#include "../include/group.h"
#include "../include/server.h"



std::list<std::string> activeUsers;

User::User(std::string userId) {
    this->userId = userId;
    this->userConections = 0;
}

void addUser(User user) {
    // adiciona ao grupo?
    activeUsers.push_back(user.userId); // adiciona à lista de usuários ativos
}

void User::deleteUser(User user) {
    // TODO
    // solicita permissão de escrita
    // deleta o usuário
    // activeUsers.remove(user.userId); // remove da lista de usuários ativos
    // libera permissão de escrita 
}

int User::joinGroup(Group group) {
    // checar o numero de conexões para esse usuário
    if (this->userConections < MAX_USER_CONECTIONS) {
        // adiciona ao grupo
        
        ++this->userConections; // incrementa conexões do usuario
        // tem que ver se ja estava no grupo
        // e quais consequencias

    }
    // não conectou pq já tem 2 conexões 
    return 0;
}

void showUsers() {
    // for (std::list<std::string>::iterator it = activeUsers.begin(); it!=activeUsers.end(); it++)
    //     std::cout << "User ID: "  << std::endl;
    std::cout << "Active users:" << std::endl;
    
    for (std::string val : activeUsers)
        std::cout << val << std::endl;
    std::cout << '\n';
}

//testing
int main() {
    User user1 = User("A");
    User user2 = User("B");
    User user3 = User("C");
    addUser(user1);
    addUser(user2);
    addUser(user3);
    showUsers();

    return 1;
}
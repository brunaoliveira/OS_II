#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <iostream> // pra reconhecer o uint16_t

// conforme a definição do trabalho: packet é enviado entre servidor e cliente
typedef struct __packet {
    uint16_t type; //Tipo do pacote (p.ex. DATA | CMD)
    uint16_t seqn; //Número de sequência
    uint16_t length; //Comprimento do payload
    uint16_t timestamp; //Timestamp do dado
    const char* _payload; //Dados da mensagem
} packet; 

// TODO: criar estrutura para as mensagens que serão trocadas entre os usuários

#endif
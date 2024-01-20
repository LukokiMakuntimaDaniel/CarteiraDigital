#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include "estruturas.h"


struct NOLDL* criarNoUser(struct DadosUser dadosUser) {
    struct NOLDL* novoNo = (struct NOLDL*)malloc(sizeof(struct NOLDL));
    if (novoNo == NULL) {
        return 0;
    }

    novoNo->dadosUser = dadosUser;
    novoNo->prev = NULL;
    novoNo->next = NULL;
    return novoNo;
}

struct NOLDL* criarNoCarteira(struct DadosUser dadosUser) {
    struct NOLDL* novoNo = (struct NOLDL*)malloc(sizeof(struct NOLDL));
    if (novoNo == NULL) {
        return 0;
    }

    novoNo->dadosUser = dadosUser;
    novoNo->prev = NULL;
    novoNo->next = NULL;
    return novoNo;
}

void CadastrarUtilizador(struct NOLDL** cabeca, struct DadosUser dadosUser) {
    struct NOLDL* novoNo = criarNoUser(dadosUser);

    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        struct NOLDL* temp = *cabeca;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novoNo;
        novoNo->prev = temp;
    }
}



#endif // FUNCOES_H_INCLUDED

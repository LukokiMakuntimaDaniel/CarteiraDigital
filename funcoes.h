#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include "estruturas.h"


struct NOLDLU* criarNoUser(struct DadosUser dadosUser) {
    struct NOLDLU* novoNo = (struct NOLDLU*)malloc(sizeof(struct NOLDLU));
    if (novoNo == NULL) {
        return 0;
    }

    novoNo->dadosUser = dadosUser;
    novoNo->prev = NULL;
    novoNo->next = NULL;
    return novoNo;
}

struct NOLDLHT* criarNoHT(struct dadosHistoricoTrasacao dadosTrasacao) {

    struct NOLDLHT* novoNo = (struct NOLDLHT*)malloc(sizeof(struct NOLDLHT));
    if (novoNo == NULL) {
        return 0;
    }

    novoNo->dadosHT = dadosTrasacao;
    novoNo->prev = NULL;
    novoNo->next = NULL;
    return novoNo;
}

void CadastrarUtilizador(struct NOLDLU** cabeca, struct DadosUser dadosUser) {
    struct NOLDLU* novoNo = criarNoUser(dadosUser);

    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        struct NOLDLU* temp = *cabeca;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novoNo;
        novoNo->prev = temp;
    }
}

void cadastrarCarteira(struct NOLDLHT** cabeca, struct dadosHistoricoTrasacao dados) {
    struct NOLDLHT* novoNo = criarNoHT(dados);

    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        struct NOLDLHT* temp = *cabeca;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novoNo;
        novoNo->prev = temp;
    }
}


void cadastrarCarteira(struct CarteiraDigital* carteira, double saldo, const char* codigoCarteira, int numeroEstudante) {
    if (carteira->qtd < MAX_CARTEIRA) {
        carteira->dadosCarteira[carteira->qtd].saldo = saldo;
        snprintf(carteira->dadosCarteira[carteira->qtd].codigoCarteira, sizeof(carteira->dadosCarteira[carteira->qtd].codigoCarteira), "%s", codigoCarteira);
        carteira->dadosCarteira[carteira->qtd].numeroEstudante = numeroEstudante;
        carteira->qtd++;
        return 1;
    } else {
        return 0;
    }
}

#endif // FUNCOES_H_INCLUDED

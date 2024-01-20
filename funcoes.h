#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


struct NOLDLC* criarNOC(struct dadosConta dados) {

    struct NOLDLC* novoNo = (struct NOLDLC*)malloc(sizeof(struct NOLDLC));
    if (novoNo == NULL) {
        return 0;
    }

    novoNo->dados = dados;
    novoNo->prev = NULL;
    novoNo->next = NULL;
    return novoNo;
}


void cadastratConta(struct NOLDLC** cabeca, struct dadosConta dados) {
    struct NOLDLC* novoNo = criarNOC(dados);

    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        struct NOLDLC* temp = *cabeca;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novoNo;
        novoNo->prev = temp;
    }
}



int CadastrarUtilizador(struct NOLDLU** cabeca, struct DadosUser dadosUser) {
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
    if(cadastrarUsuarioEGravarArquivo(dadosUser)){
        return 1;
    }else{
        return 0;
    }
}


void cadastrarTrasacao(struct NOLDLHT** cabeca, struct dadosHistoricoTrasacao dados) {
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


int cadastrarCarteira(struct CarteiraDigital* carteira, double saldo, const char* codigoCarteira, int numeroEstudante) {
    if (carteira->qtd < MAX_CARTEIRA) {
        carteira->dadosCarteira[carteira->qtd].saldo = saldo;
        snprintf(carteira->dadosCarteira[carteira->qtd].codigoCarteira, sizeof(carteira->dadosCarteira[carteira->qtd].codigoCarteira), "%s", codigoCarteira);
        carteira->dadosCarteira[carteira->qtd].numeroEstudante = numeroEstudante;
        carteira->qtd++;
    } else {
        return 0;
    }

    if(cadastrarCarteiraEGravarArquivo(double saldo, const char* codigoCarteira, int numeroEstudante)){
        return 1;
    }else{
        return 0;
    }
}

int cadastrarUsuarioEGravarArquivo(struct DadosUser dadosUser) {
    FILE *arquivoUsuario = fopen("usuarios.txt", "a");

    if (arquivoUsuario != NULL) {
        fprintf(arquivoUsuario, "%s,%d,%d,%s,%d,%d,%s,%s\n",dadosUser->nome, dadosUser->numeroEstudante, dadosUser->sala,dadosUser->curso, dadosUser->idade, dadosUser->ano,dadosUser->senha, dadosUser->numeroTelefone);
        fclose(arquivoUsuario);
        return 1;
    } else {
        return 0;
    }
}

int cadastrarCarteiraEGravarArquivo(double saldo, const char* codigoCarteira, int numeroEstudante) {
    FILE *arquivoCarteira = fopen("carteira.txt", "a");
    if (arquivoCarteira != NULL) {
        fprintf(arquivoCarteira, "%.2f,%s,%d\n",saldo,codigoCarteira,numeroEstudante);
        fclose(arquivoCarteira);
        return 1;
    } else {
        return 0;
    }
}
#endif

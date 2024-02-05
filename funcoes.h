#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"


struct NOLDLU * criarNoUser(struct DadosUser dadosUser) {
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


int cadastratConta(struct NOLDLC* cabeca, struct dadosConta dados) {
    struct NOLDLC* novoNo = criarNOC(dados);
    if (cabeca == NULL) {
        cabeca = novoNo;
    } else {
        struct NOLDLC* temp = cabeca;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novoNo;
        novoNo->prev = temp;
    }

    if(cadastrarContaEGravarArquivo(dados)){
        return 1;
    }else{
        return 0;
    }
}



int CadastrarUtilizador(struct NOLDLU* cabeca, struct DadosUser dadosUser) {
    struct NOLDLU* novoNo = criarNoUser(dadosUser);


    if (cabeca == NULL) {
        cabeca = novoNo;
    } else {
        struct NOLDLU* temp = cabeca;
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


int cadastrarTrasacao(struct NOLDLHT* cabeca, struct dadosHistoricoTrasacao dados) {
    struct NOLDLHT* novoNo = criarNoHT(dados);

    if (cabeca == NULL) {
        cabeca = novoNo;
    } else {
        struct NOLDLHT* temp = cabeca;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novoNo;
        novoNo->prev = temp;
    }

    if(cadastrarTransacaoEGravarArquivo(dados)){
            return 1;
    }else{
        return 0;
    }
}


int cadastrarCarteira(struct CarteiraDigital* carteira, struct DadosCarteira dados ) {
    if (carteira->qtd < MAX_CARTEIRA) {
        carteira->dadosCarteira[carteira->qtd].saldo = dados.saldo;
        snprintf(carteira->dadosCarteira[carteira->qtd].codigoCarteira, sizeof(carteira->dadosCarteira[carteira->qtd].codigoCarteira), "%s", dados.codigoCarteira);
        carteira->dadosCarteira[carteira->qtd].numeroEstudante = dados.numeroEstudante;
        carteira->qtd++;
    } else {
        return 0;
    }

    if(cadastrarCarteiraEGravarArquivo(dados.saldo, dados.codigoCarteira,dados.numeroEstudante)){
        return 1;
    }else{
        return 0;
    }
}

int cadastrarUsuarioEGravarArquivo(struct DadosUser dadosUser) {
    FILE *arquivoUsuario = fopen("usuarios.txt", "a");

    if (arquivoUsuario != NULL) {
        fprintf(arquivoUsuario, "%s,%d,%d,%s,%d,%d,%s,%s\n",dadosUser.nome, dadosUser.numeroEstudante, dadosUser.sala,dadosUser.curso, dadosUser.idade, dadosUser.ano,dadosUser.senha, dadosUser.numeroTelefone);
        fclose(arquivoUsuario);
        return 1;
    } else {
        return 0;
    }
}


void removerNovaLinha(char *str) {
    size_t comprimento = strcspn(str, "\n");
    if (comprimento < strlen(str)) {
        str[comprimento] = '\0';
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

int cadastrarContaEGravarArquivo(struct dadosConta dadosConta) {
    FILE *arquivoConta = fopen("contas.txt", "a");
    if (arquivoConta != NULL) {
        fprintf(arquivoConta, "%s,%s\n", dadosConta.codigoCarteira, dadosConta.tipoDeConta);
        fclose(arquivoConta);
        return 1;
    } else {
        return 0;
    }
}

int cadastrarTransacaoEGravarArquivo(struct dadosHistoricoTrasacao dadosTransacao) {
    FILE *arquivoTransacao = fopen("transacoes.txt", "a");
    if (arquivoTransacao != NULL) {
        fprintf(arquivoTransacao, "%d,%d,%d,%d,%d,%d,%s\n",dadosTransacao.ano, dadosTransacao.dia, dadosTransacao.mes,dadosTransacao.ano, dadosTransacao.tipoTrazacao,dadosTransacao.saldo, dadosTransacao.codigoCarteira);
        fclose(arquivoTransacao);
        return 1;
    } else {
        return 0;
    }
}

char * login(struct NOLDLU * lista , int numero , char *senha){
    while (lista != NULL) {
            if (lista->dadosUser.numeroEstudante == numero && strcmp(lista->dadosUser.senha, senha) == 0) {
                return lista->dadosUser.numeroTelefone;
            }
            lista = lista->next;
        }
        return NULL;
}

char* pegarMeuNome(struct NOLDLU* head, char* numeroTelefone) {
    struct NOLDLU* current = head;
    while (current != NULL) {
        if (strcmp(current->dadosUser.numeroTelefone, numeroTelefone) == 0) {
            return current->dadosUser.nome;
        }
        current = current->next;
    }
    return NULL;
}


int depositar(struct CarteiraDigital *carteira, int numeroEstudante, double saldoAdicional) {
    int i;
    for (i = 0; i < carteira->qtd; i++) {
        if (carteira->dadosCarteira[i].numeroEstudante == numeroEstudante) {
            carteira->dadosCarteira[i].saldo += saldoAdicional;
            return 1;
        }
    }
    return 0;
}

int levantamneto(struct CarteiraDigital *carteira, int numeroEstudante, double saldoAdicional) {
    int i;
    for (i = 0; i < carteira->qtd; i++) {
        if (carteira->dadosCarteira[i].numeroEstudante == numeroEstudante) {
            carteira->dadosCarteira[i].saldo -= saldoAdicional;
            return 1;
        }
    }
    return 0;
}

int contarDadosDeConta(struct NOLDLC* inicio) {
    int contador = -1;
    struct NOLDLC* atual = inicio;

    while (atual != NULL) {
        contador++;
        atual = atual->next;
    }
    return contador;
}


int listarDadosPorNumeroEstudante(struct NOLDLU* inicio, int numeroEstudante) {
    struct NOLDLU* atual = inicio;

    while (atual != NULL) {
        if (atual->dadosUser.numeroEstudante == numeroEstudante) {
            printf("Nome: %s\n", atual->dadosUser.nome);
            printf("Número do Estudante: %d\n", atual->dadosUser.numeroEstudante);
            printf("Sala: %d\n", atual->dadosUser.sala);
            printf("Curso: %s\n", atual->dadosUser.curso);
            printf("Idade: %d\n", atual->dadosUser.idade);
            printf("Ano: %d\n", atual->dadosUser.ano);
            printf("Senha: %s\n", atual->dadosUser.senha);
            printf("Número de Telefone: %s\n", atual->dadosUser.numeroTelefone);
            return 1;
        }
        atual = atual->next;
    }
    return 0;
}



void visualizarCarteiras(struct CarteiraDigital carteiraDigital) {
    printf("Carteiras Digitais:\n");
    for (int i = 0; i < carteiraDigital.qtd; i++) {
        printf("Carteira %d:\n", i + 1);
        printf("Saldo: %.2f\n", carteiraDigital.dadosCarteira[i].saldo);
        printf("Código: %s\n", carteiraDigital.dadosCarteira[i].codigoCarteira);
        printf("Número de Estudante: %d\n", carteiraDigital.dadosCarteira[i].numeroEstudante);
        printf("\n");
    }
}
#endif

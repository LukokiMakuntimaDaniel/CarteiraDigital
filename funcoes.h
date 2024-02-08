#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"


//criar no do user recebendo todos os dados do user
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


//criar no da transacao recebendo os dados da tranzacao
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
        struct NOLDLU * temp = cabeca;
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
        fprintf(arquivoTransacao, "%d,%d,%d,%d,%d,%d,%s\n",dadosTransacao.ano, dadosTransacao.dia, dadosTransacao.mes,dadosTransacao.ano, dadosTransacao.tipoTrazacao,dadosTransacao.saldo, dadosTransacao.codigoCarteiraOrigem,dadosTransacao.codigoCarteiraDestino);
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


int transferirSaldo(struct CarteiraDigital *carteira, int origem, int destino, double valor, struct NOLDLHT* cabeca) {
    int i, indiceOrigem = -1, indiceDestino = -1;

    for (i = 0; i < carteira->qtd; i++) {
        if (carteira->dadosCarteira[i].numeroEstudante == origem){
            printf("\n%f\n",carteira->dadosCarteira[i].saldo);
            indiceOrigem = i;
        }else if (carteira->dadosCarteira[i].numeroEstudante == destino){
            indiceDestino = i;
        }
    }

    if (indiceOrigem != -1 && indiceDestino != -1) {
        if (carteira->dadosCarteira[indiceOrigem].saldo >= valor) {
            carteira->dadosCarteira[indiceOrigem].saldo -= valor;
            carteira->dadosCarteira[indiceDestino].saldo += valor;

            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            struct dadosHistoricoTrasacao dadosTransacao;
            dadosTransacao.ano = tm.tm_year + 1900;
            dadosTransacao.dia = tm.tm_mday;
            dadosTransacao.mes = tm.tm_mon + 1;
            dadosTransacao.tipoTrazacao = 1;
            dadosTransacao.saldo = valor;
            strcpy(dadosTransacao.codigoCarteiraOrigem, carteira->dadosCarteira[indiceOrigem].codigoCarteira);
            strcpy(dadosTransacao.codigoCarteiraDestino, carteira->dadosCarteira[indiceDestino].codigoCarteira);
            cadastrarTransacaoEGravarArquivo(dadosTransacao);
            cadastrarTrasacao(cabeca, dadosTransacao);

        } else {
            printf("Saldo insuficiente na carteira %d.\n", origem);
            return 0;
        }
    } else {
        printf("Carteira de origem ou destino nao encontrada.\n");
        return 0;
    }
    return 1;
}


int levantamentoSaldo(struct CarteiraDigital *carteira, double saldo, int numeroEstudante, struct NOLDLHT** cabeca) {
    int i;
    // Procura a carteira com o número do estudante fornecido
    for (i = 0; i < carteira->qtd; i++) {
        if (carteira->dadosCarteira[i].numeroEstudante == numeroEstudante) {
            // Verifica se o saldo a ser retirado não excede o saldo disponível na carteira
            if (carteira->dadosCarteira[i].saldo <= saldo) {
                carteira->dadosCarteira[i].saldo -= saldo; // Reduz o saldo da carteira após o levantamento
                break; // Sai do loop após encontrar a carteira
            }else{
                return 0;
            }
        }
    }
        // Obter a data atual do sistema
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        // Criar e cadastrar a transação de levantamento de saldo com o código da carteira como origem e destino
        struct dadosHistoricoTrasacao dadosTransacao;
        dadosTransacao.ano = tm.tm_year + 1900; // Adiciona 1900 ao ano
        dadosTransacao.dia = tm.tm_mday; // Dia do mês
        dadosTransacao.mes = tm.tm_mon + 1; // Mês (0-11), por isso é necessário adicionar 1
        dadosTransacao.tipoTrazacao = 2; // Tipo de transação para levantamento de saldo
        dadosTransacao.saldo = saldo;
        strcpy(dadosTransacao.codigoCarteiraOrigem, carteira->dadosCarteira[i].codigoCarteira); // Código da carteira como origem
        strcpy(dadosTransacao.codigoCarteiraDestino, carteira->dadosCarteira[i].codigoCarteira); // Código da carteira como destino
        cadastrarTransacaoEGravarArquivo(dadosTransacao);
        cadastrarTrasacao(cabeca, dadosTransacao); // Chama a função para cadastrar a transação
        return 1;
}


double obterSaldo(struct CarteiraDigital *carteira, int numeroEstudante) {
    double saldo = 0.0;
    int i;

    // Procura a carteira com o número do estudante fornecido
    for (i = 0; i < carteira->qtd; i++) {
        if (carteira->dadosCarteira[i].numeroEstudante == numeroEstudante) {
            saldo = carteira->dadosCarteira[i].saldo;
            break; // Sai do loop após encontrar a carteira
        }
    }

    return saldo;
}


char* obterCodigoCarteiraPorEstudante(struct CarteiraDigital *carteira, int numeroEstudante) {
    char* codigoCarteira = NULL;
    int i;

    // Procura a carteira com o número do estudante fornecido
    for (i = 0; i < carteira->qtd; i++) {
        if (carteira->dadosCarteira[i].numeroEstudante == numeroEstudante) {
            codigoCarteira = carteira->dadosCarteira[i].codigoCarteira;
            break; // Sai do loop após encontrar a carteira
        }
    }

    return codigoCarteira;
}


void mostrarTransacoesPorCarteiraOrigem(struct NOLDLHT *cabecaTransacoes, char *codigoCarteiraOrigem) {
    struct NOLDLHT *atual = cabecaTransacoes;
    int saber=0;

    printf("Transações da carteira de origem %s:\n", codigoCarteiraOrigem);

    // Percorre a lista de transações
    while (atual != NULL) {
        // Verifica se a transação corresponde ao código da carteira de origem fornecido
        if (strcmp(atual->dadosHT.codigoCarteiraOrigem, codigoCarteiraOrigem) == 0) {
            // Imprime os detalhes da transação
            printf("Ano: %d\n", atual->dadosHT.ano);
            printf("Mês: %d\n", atual->dadosHT.mes);
            printf("Dia: %d\n", atual->dadosHT.dia);
            printf("Tipo de transação: %d\n", atual->dadosHT.tipoTransacao);
            printf("Saldo: %d\n", atual->dadosHT.saldo);
            printf("Código da carteira de origem: %s\n", atual->dadosHT.codigoCarteiraOrigem);
            printf("Código da carteira de destino: %s\n", atual->dadosHT.codigoCarteiraDestino);
            // Aqui você pode imprimir outras informações da transação, se disponível
            printf("\n");
            saber++;
        }
        // Avança para o próximo nó na lista
        atual = atual->next;
    }
    return saber;
}
#endif

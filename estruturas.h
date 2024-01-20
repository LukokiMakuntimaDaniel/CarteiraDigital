#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

struct DadosUser {
    char nome[50];
    int numeroEstudante;
    int sala;
    char curso[50];
    int idade;
    int ano;
};

struct carteira{
    double saldo;
    int numeroEstudante;
};


struct NOLDL {
    struct DadosUser dadosUser;
    struct NOLDL* prev;
    struct NOLDL* next;
};


#endif // FUNCOES_H_INCLUDED

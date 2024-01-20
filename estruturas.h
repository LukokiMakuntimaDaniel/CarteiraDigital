#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#define MAX_CARTEIRA 2500

struct DadosUser {
    char nome[50];
    int numeroEstudante;
    int sala;
    char curso[50];
    int idade;
    int ano;
    char senha[50];
    char  numeroTelefone[50];
};




struct NOLDLU {
    struct DadosUser dadosUser;
    struct NOLDL* prev;
    struct NOLDL* next;
};




struct DadosCarteira{
    double saldo;
    char codigoCarteira[50];
    int numeroEstudante;
};

struct dadosConta{
    char codigoCarteira[50];
    char tipoDeConta[50];
};

struct CarteiraDigital {
    struct DadosCarteira dadosCarteira[MAX_CARTEIRA];
    int qtd;
};

struct dadosHistoricoTrasacao{
    int ano;
    int dia;
    int mes;
    int ano;
    int tipoTrazacao;
    int saldo;
    char codigoCarteira[50];
};


struct NOLDLC {
    struct dadosConta dados;
    struct NOLDL* prev;
    struct NOLDL* next;
};


struct NOLDLHT {
    struct dadosHistoricoTrasacao dadosHT;
    struct NOLDL* prev;
    struct NOLDL* next;
};

#endif // FUNCOES_H_INCLUDED

#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED
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

struct NOLDLU* criarNoUser(struct DadosUser dadosUser);
struct NOLDLHT* criarNoHT(struct dadosHistoricoTrasacao dadosTrasacao);
struct NOLDLC* criarNOC(struct dadosConta dados);
int cadastrarConta(struct NOLDLC* cabeca, struct dadosConta dados);
int CadastrarUtilizador(struct NOLDLU* cabeca, struct DadosUser dadosUser);
int cadastrarTrasacao(struct NOLDLHT* cabeca, struct dadosHistoricoTrasacao dados);
int cadastrarCarteira(struct CarteiraDigital* carteira, struct DadosCarteira dados);
int cadastrarUsuarioEGravarArquivo(struct DadosUser dadosUser);
int cadastrarCarteiraEGravarArquivo(double saldo, const char* codigoCarteira, int numeroEstudante);
int cadastrarContaEGravarArquivo(struct dadosConta dadosConta);
int cadastrarTransacaoEGravarArquivo(struct dadosHistoricoTrasacao dadosTransacao);
char * login(struct NOLDLU * lista , int numero, char* senha);
char* pegarMeuNome(struct NOLDLU* head, char* numeroTelefone);
void removerNovaLinha(char *str);
int contarDadosDeConta(struct NOLDLC* inicio);
int listarDadosPorNumeroEstudante(struct NOLDLU* inicio, int numeroEstudante);
void visualizarCarteiras(struct CarteiraDigital carteiraDigital);
#endif // ESTRUTURAS_H_INCLUDED

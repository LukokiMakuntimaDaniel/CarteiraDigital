#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "funcoes.h"
#include <stdlib.h>

struct NOLDLU *utilizador = NULL;
int opcao,opcao1,opcao2,numero;
char numeroTelefone[50],senha[50];
struct DadosUser novoUsuario;

int main()
{

    do{
        printf("----------------------------------------------------\n");
        printf("1- SISTEMA \n");
        printf("2- CARTEIRA DIGITAL \n");
        printf("0- SAIR \n");
        printf("----------------------------------------------------\n");
        printf("escolha uma opção: \n");
        scanf("%d",&opcao);
        system("cls");

        switch (opcao){
            case 1:
                //Login
                do{
                    printf("----------------------------------------------------\n");
                    printf("1: Entrar como Utilizador\n");
                    printf("2: Entrar como Gestor\n");
                    printf("3: Cadastrar Usuario\n");
                    printf("0- SAIR \n");
                    printf("----------------------------------------------------\n");
                    printf("escolha uma opção: \n");
                    scanf("%d",&opcao1);
                    system("cls");
                    switch (opcao1){
                        case 2:
                            break;
                        case 1:
                            printf("Digite O Numero de Estudante");
                            scanf("%d",&numero);
                            getchar();
                            printf("Digite a senha")
                            scanf("%s",&senha);
                            printf("processando.....");
                            numeroTelefone=login(&NOLDLU,numero,senha)
                            if(numeroTelefone){
                                    system("cls");
                                    printf("Usuario: %s ",(pegarMeuNome(&NOLDLU,numeroTelefone)))
                                    printf("----------------------------------------------------\n");
                                    printf("1: Efectuar a Transferencia\n");
                                    printf("2: Consultar o Saldo \n");
                                    printf("2: Levantamento do Saldo \n");
                                    printf("2: Efectuar o Pagamento \n");
                                    printf("2: Visualizar o Historico \n");
                                    printf("escolha uma opção: \n");
                                    printf("0- SAIR \n");
                                    printf("----------------------------------------------------\n");
                                    scanf("%d",&opcao1);
                                    system("cls");
                            }else{
                                system("cls");
                                printf("senha incorreta");

                            }
                            break;
                        case 3:
                            printf("Cadastrando Usuario");
                            printf("Digite o nome do usuário: ");
                            fgets(novoUsuario.nome, sizeof(novoUsuario.nome), stdin);
                            printf("Digite o número de estudante: ");
                            scanf("%d", &novoUsuario.numeroEstudante);
                            printf("Digite a sala: ");
                            scanf("%d", &novoUsuario.sala);
                            getchar(); // Limpar o buffer de entrada
                            printf("Digite o curso: ");
                            fgets(novoUsuario.curso, sizeof(novoUsuario.curso), stdin);
                            printf("Digite a idade: ");
                            scanf("%d", &novoUsuario.idade);
                            printf("Digite o ano: ");
                            scanf("%d", &novoUsuario.ano);
                            getchar(); // Limpar o buffer de entrada
                            printf("Digite a senha: ");
                            fgets(novoUsuario.senha, sizeof(novoUsuario.senha), stdin);
                            printf("Digite o número de telefone: ");
                            fgets(novoUsuario.numeroTelefone, sizeof(novoUsuario.numeroTelefone), stdin);
                            if(CadastrarUtilizador(&numero,novoUsuario)){
                                    printf("cadastrado com sucesso");
                            }

                            break;
                    }
                }while(opcao1!=0)



                break;
           case 2:
                //Login
                do{
                    printf("----------------------------------------------------\n");
                    printf("1: Entrar como Utilizador\n");
                    printf("2: Entrar como Gestor\n");
                    printf("escolha uma opção: \n");
                    printf("0- SAIR \n");
                    printf("----------------------------------------------------\n");
                    scanf("%d",opcao2);
                    system("cls");
                    switch (opcao2){
                        case 1:

                            break;

                        case 2:
                            break;
                    }
                }while(opcao1!=0)
                break;
        }
    }while(opcao!=0);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "funcoes.h"
#include "estruturas.h"

struct NOLDLU *utilizadores = NULL;
struct NOLDLC * contas = NULL;
struct CarteiraDigital carteiras;



int opcao,opcao1,opcao2,numero,opcao3,opcao4;
char *numeroTelefone,senha[50],telefone[50],codigoCarteira[50]="LW";
double saldo=10000;
struct DadosUser novoUsuario;
struct dadosConta novaConta;
struct DadosCarteira novaCarteira;

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
                do{
                    printf("----------------------------------------------------\n");
                    printf("1: LOGAR NO LombongoPay COMO GESTOR\n");
                    printf("2: CADASTRAR O UTILIZADOR DA CARTEIRA DIGITAL ESTUDANTE\n");
                    printf("0- SAIR \n");
                    printf("----------------------------------------------------\n");
                    printf("escolha uma opção: \n");
                    scanf("%d",&opcao1);
                    system("cls");
                    switch (opcao1){
                        case 1:
                            printf("Digite O Numero DE ACESSO: ");
                            scanf("%d",&numero);
                            getchar();
                            printf("Digite a senha");
                            scanf("%s",&senha);
                            printf("processando.....");
                            if(numero==2024 && strcmp(senha,"UAN")==0){
                                do{
                                    printf("\nBEM VINDO GESTOR\n");
                                    printf("----------------------------------------------------\n");
                                    printf("1: Depositar saldo\n");
                                    printf("2: Levantar Saldo\n");
                                    printf("3: Consultar a Quantidade de Contas\n");
                                    printf("4: Criar Conta\n");
                                    printf("5: Visualizar Utilizadores\n");
                                    printf("6: Visualizar Todas as Carteiras\n");
                                    printf("0- SAIR \n");
                                    printf("----------------------------------------------------\n");
                                    printf("escolha uma opção: \n");
                                    scanf("%d",&opcao4);
                                    system("cls");
                                    switch (opcao4){
                                        case 1:
                                            break;
                                        case 2:
                                            break;
                                        case 3:
                                            break;
                                        case 4:
                                            getchar();
                                            printf("CRIAÇÃO DE CONTA\n");
                                            printf("Digite o numero de telefone do Estudante\n");
                                            fgets(telefone, sizeof(telefone), stdin);
                                            removerNovaLinha(telefone);
                                            printf("Digite o numero do Estudante\n");
                                            scanf("%d",&numero);
                                            strcat(codigoCarteira,telefone);
                                            strcpy(novaCarteira.codigoCarteira,codigoCarteira);
                                            novaCarteira.saldo=saldo;
                                            novaCarteira.numeroEstudante=numero;
                                            strcpy(novaConta.codigoCarteira,codigoCarteira);
                                            strcpy(novaConta.tipoDeConta,"Poupanca");
                                            if(cadastrarCarteira(&carteiras,novaCarteira) && cadastratConta(&contas,novaConta)){
                                                printf("\nCarteira e conta criada\n");
                                                printf("\nPressione Enter para continuar...\n");
                                                getchar();
                                            }else{
                                                printf("\nLimite da carteira estourou\n");
                                                printf("\nPressione Enter para continuar...\n");
                                                getchar();
                                            }


                                            break;
                                         case 5:
                                            break;
                                         case 6:
                                            break;
                                    }

                                }while(opcao4!=0);
                            }else{
                                printf("senha Incorreta");
                            }
                            break;
                        case 2:
                            getchar();
                            printf("Cadastrando Usuario\n");
                            printf("\nDigite o nome do Usuario: \n");
                            fgets(novoUsuario.nome, sizeof(novoUsuario.nome), stdin);
                            removerNovaLinha(novoUsuario.nome);
                            printf("Digite o número de estudante: \n");
                            scanf("%d", &novoUsuario.numeroEstudante);
                            printf("Digite a sala: \n");
                            scanf("%d", &novoUsuario.sala);
                            getchar(); // Limpar o buffer de entrada
                            printf("Digite o curso: \n");
                            fgets(novoUsuario.curso, sizeof(novoUsuario.curso), stdin);
                            removerNovaLinha(novoUsuario.curso);
                            printf("Digite a idade: ");
                            scanf("%d", &novoUsuario.idade);
                            printf("Digite o ano: \n");
                            scanf("%d", &novoUsuario.ano);
                            getchar(); // Limpar o buffer de entrada
                            printf("Digite a senha: \n");
                            fgets(novoUsuario.senha, sizeof(novoUsuario.senha), stdin);
                            removerNovaLinha(novoUsuario.senha);
                            printf("Digite o número de telefone: \n");
                            fgets(novoUsuario.numeroTelefone, sizeof(novoUsuario.numeroTelefone), stdin);
                            removerNovaLinha(novoUsuario.numeroTelefone);
                            if(CadastrarUtilizador(&utilizadores,novoUsuario)){
                                printf("\ncadastrado com sucesso\n");
                                printf("\nPressione Enter para continuar...\n");
                                getchar();
                            }else{
                                printf("\nCadastre de Novo\n");
                                 printf("\nPressione Enter para continuar...\n");
                                 getchar();
                                system("cls");
                            }
                            break;
                    }
                }while(opcao1!=0);



                break;
           case 2:
                //Login
                printf("FAÇA O LOGIN NO LombongoPay COMO ESTUDANTE\n ");
                printf("Digite O Numero de Estudante");
                scanf("%d",&numero);
                getchar();
                printf("Digite a senha");
                scanf("%s",&senha);
                printf("processando.....");
                numeroTelefone = login(&utilizadores,numero,senha);
                if(numeroTelefone){
                        system("cls");
                    do{
                        printf("Usuario: %s ",(pegarMeuNome(&utilizadores,numeroTelefone)));
                        printf("----------------------------------------------------\n");
                        printf("1: Efectuar a Transferencia\n");
                        printf("2: Consultar o Saldo \n");
                        printf("3: Levantamento do Saldo \n");
                        printf("4: Efectuar o Pagamento \n");
                        printf("5: Visualizar o Historico \n");
                        printf("0- SAIR \n");
                        printf("----------------------------------------------------\n");
                        printf("escolha uma opção: \n");
                        scanf("%d",&opcao3);
                        system("cls");
                        switch (opcao3){
                            case 1:
                                break;

                            case 2:
                                break;

                            case 3:
                                break;

                            case 4:
                                break;

                            case 5:
                                break;
                        }
                    }while(opcao3!=0);
                }else{
                    system("cls");
                    printf("senha incorreta");

                }
                break;
        }
    }while(opcao!=0);
    return 0;
}

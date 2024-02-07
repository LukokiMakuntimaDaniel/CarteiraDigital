#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "estruturas.h"

struct NOLDLU *utilizadores = NULL;
struct NOLDLC * contas = NULL;
struct CarteiraDigital carteiras;
struct NOLDLHT *transacao=NULL;



int opcao,opcao1,opcao2,numero,opcao3,opcao4,numeroDestino;
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
                                        case 2:
                                            printf("\nDigite o numero do estudante\n");
                                            scanf("%d",&numero);
                                            printf("Digite o saldo a depositar\n");
                                            scanf("%lf",&saldo);
                                            if(levantamneto(&carteiras,numero,saldo)){
                                                printf("O valor vou depositado com sucesso\n");
                                                printf("\nPressione Enter para continuar...\n");
                                                getchar();
                                            }else{
                                                printf("\Nhouve algum erro ou estudante não encontrado\n");
                                                printf("\nPressione Enter para continuar...\n");
                                                getchar();
                                            }
                                            break;
                                        case 1:
                                            printf("\nDigite o numero do estudante\n");
                                            scanf("%d",&numero);
                                            printf("Digite o numero do estudante\n");
                                            scanf("%lf",&saldo);
                                            if(depositar(&carteiras,numero,saldo)){
                                                printf("Operacao de levantamento feito com sucesso\n");
                                                printf("\nPressione Enter para continuar...\n");
                                                getchar();
                                            }else{
                                                printf("houve algum erro ou estudante não encontrado\n");
                                                printf("\nPressione Enter para continuar...\n");
                                                getchar();
                                            }
                                            break;
                                        case 3:
                                            printf("\nQuantidade de Contas\n");
                                            printf("-------------------------------------------------------------");
                                            printf("\n Na Nossa base de dados existe %d "+contarDadosDeConta(&contas));
                                            printf("-------------------------------------------------------------");
                                            printf("\nPressione Enter para continuar...\n");
                                            getchar();
                                            break;
                                        case 4:
                                            getchar();
                                            saldo=10000;
                                            printf("\nCRIAÇÃO DE CONTA\n");
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
                                             printf("\nDigite o numero do estudante: ");
                                             scanf("%d",&numero);
                                             if(listarDadosPorNumeroEstudante(&utilizadores,numero)){
                                                printf("\nPressione Enter para continuar...\n");
                                                getchar();
                                             }else{
                                                printf("\nUtilizador nao encontrado\n");
                                                printf("\nPressione Enter para continuar...\n");
                                                getchar();
                                             }
                                            break;
                                         case 6:
                                             printf("\nVisualizar todas as carteiras\n");
                                             visualizarCarteiras(carteiras);
                                             printf("\nPressione Enter para continuar...\n");
                                             getchar();
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
                        printf("1: Efectuar a Transferencia de valores\n");
                        printf("2: Consultar o Saldo \n");
                        printf("3: Levantamento do Saldo \n");
                        printf("5: Visualizar o Historico \n");
                        printf("0- SAIR \n");
                        printf("----------------------------------------------------\n");
                        printf("escolha uma opção: \n");
                        scanf("%d",&opcao3);
                        system("cls");
                        switch (opcao3){
                            case 1:
                                printf("\nTransferencia de valores\n");
                                printf("Digite o numero de Destino do Estudante\n");
                                scanf("%d",&numeroDestino);
                                printf("Digite o valor a transferir\n");
                                scanf("%lf",&saldo);
                                if(transferirSaldo(&carteiras,numero,numeroDestino,saldo,&transacao)){
                                     printf("\nTransferencia de %.2f realizada com sucesso da carteira %d para %d.\n", saldo, numero, numeroDestino);
                                     printf("\nPressione Enter para continuar...\n");
                                     getchar();
                                }else{
                                    printf("\nPressione Enter para continuar...\n");
                                    getchar();
                                }
                                break;
                            case 2:
                                 printf("Digite o valor a transferir\n");
                                 scanf("%lf",&saldo);
                                if(levantamentoSaldo(&carteiras,saldo,numero,&transacao){

                                }else{
                                    printf("\nocorreu um erro valor insuficiente\n");
                                    printf("\nPressione Enter para continuar...\n");
                                    getchar();
                                }

                                break;

                            case 3:
                                break;

                            case 4:
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

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "funcoes.h"
#include "estruturas.h"

struct NOLDLU *utilizadores = NULL;
int opcao,opcao1,opcao2,numero;
char *numeroTelefone,senha[50];
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
                            printf("Digite O Numero de Estudante");
                            scanf("%d",&numero);
                            getchar();
                            printf("Digite a senha");
                            scanf("%s",&senha);
                            printf("processando.....");
                            if(numero==2024 && strcmp(senha,"UAN")==0){

                            }else{
                                printf("senha Incorreta");
                            }
                            break;
                        case 1:
                            printf("Digite O Numero de Estudante");
                            scanf("%d",&numero);
                            getchar();
                            printf("Digite a senha");
                            scanf("%s",&senha);
                            printf("processando.....");
                            numeroTelefone = login(&utilizadores,numero,senha);
                            if(numeroTelefone){
                                    system("cls");
                                    printf("Usuario: %s ",(pegarMeuNome(&utilizadores,numeroTelefone)));
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
                            }else{

                            }

                            break;
                    }
                }while(opcao1!=0);



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
                }while(opcao1!=0);
                break;
        }
    }while(opcao!=0);
    return 0;
}

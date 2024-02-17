#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

void  menuprincipal(){
        printf("----------------------------------------------------\n");
        printf("1- SISTEMA \n");
        printf("2- CARTEIRA DIGITAL \n");
        printf("0- SAIR \n");
        printf("----------------------------------------------------\n");
        printf("escolha uma opção: \n");
}

void  menusistema(){
    printf("----------------------------------------------------\n");
    printf("1: LOGAR NO LombongoPay COMO GESTOR\n");
    printf("2: CADASTRAR O UTILIZADOR DA CARTEIRA DIGITAL ESTUDANTE\n");
    printf("0- SAIR \n");
}

void  menuGestor(){
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
}

void menuEstudante(){
     printf("----------------------------------------------------\n");
    printf("1: Efectuar a Transferencia de valores\n");
    printf("2: Consultar o Saldo \n");
    printf("3: Levantamento do Saldo \n");
    printf("5: Visualizar o Historico \n");
    printf("0- SAIR \n");
    printf("----------------------------------------------------\n");
    printf("escolha uma opção: \n");
}


#endif // MENU_H_INCLUDED

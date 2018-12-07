#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


// Argumento do sistema para limpar a tela
void limpatela(void){
    system("cls");
}

int menuRU(){
    int opcao;

    limpatela();

    printf("Lotacao atual: xyx pessoas as xy:xy\n");
    printf("Lotacao media: xyx\n");
    printf("   11:00 - 11:30: 050 pessoas\n");
    printf("   11:30 - 12:00: 100 pessoas\n");
    printf("   12:00 - 12:30: 150 pessoas\n");
    printf("   12:30 - 13:00: 200 pessoas\n");
    printf("   13:00 - 13:30: 200 pessoas\n");
    printf("   13:30 - 14:00: 150 pessoas\n");

    printf("=====/ MENU RU /=====\n");
    printf("1 - Novo Usuario\n");
    printf("2 - Creditos\n");
    printf("3 - Entrar no RU\n");
    printf("0 - Sair do Programa\n");
    printf("=====================\n");

    printf("Digite a opcao desejada: ");

    scanf("%d", &opcao);

    return opcao;
}

int menuCredito(){
    int opcao;
    
    limpatela();

    printf("=====/ MENU CREDITO /=====\n");
    printf("1 - Consultar Credito\n");
    printf("2 - Comprar Credito\n");
    printf("0 - Voltar ao MENU RU\n");
    printf("==========================\n");

    printf("Digite a opcao desejada: ");

    scanf("%d", &opcao);

    return opcao;
}

int menuConsulta(){
    int opcao;

    limpatela();

    printf("=====/ MENU CONSULTA /=====\n");
    printf("1 - Consultar outro Id\n");
    printf("0 - Voltar ao MENU CREDITO\n");
    printf("===========================\n");

    printf("Digite a opcao desejada: ");

    scanf("%d", &opcao);

    return opcao;
}

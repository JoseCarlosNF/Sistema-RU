#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "menu.h"


// Argumento do sistema para limpar a tela
void limpatela(void){
    system("cls");
}

int menuRU(int lotacao, int hora, int minuto){
    int opcao;

    limpatela();

    lotacaoMedia(lotacao, hora, minuto);

    printf("=====/ MENU RU /=====\n");
    printf("1 - Novo Usuario\n");
    printf("2 - Creditos\n");
    printf("3 - Entrar no RU\n");
    printf("4 - Lista de Usuarios\n");
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

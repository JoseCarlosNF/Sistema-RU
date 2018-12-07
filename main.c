#include "menu.c"
#include <stdio.h>

void main(void){
    FILE *file;
    int opcao;

    file = fopen("sistema-ru.db", "r+");

    if (file == NULL)
        printf("Erro ao abrir SISTEMA-RU.DB.\n");
    else{
        while(1){
            opcao = menuRU();

            // Menu RU - Opcao 1
            if (opcao == 1)
                printf("Novo usuario.\n");

            // Menu RU - Opcao 2
            else if (opcao == 2){
                while(1){
                    opcao = menuCredito();

                    // Menu Credito - Opcao 1
                    if (opcao == 1)
                        printf("Consultar Credito.\n");

                    // Menu Credito - Opcao 2
                    else if (opcao == 2)
                        printf("Comprar Credito.\n");

                    // Menu Credito - Opcao 0
                    else if (opcao == 0)
                        break;
                        
                    // Menu Credito - Opcao invalida
                    else
                        printf("OPCAO INVALIDA.\n");
                }            
            }

            // Menu RU - Opcao 3
            else if (opcao == 3)
                printf("Entrar no RU.\n");

            // Menu RU - Opcao 0
            else if (opcao == 0)
                break;

            // Menu RU - Opcao invalida
            else
                printf("OPCAO INVALIDA.\n");
        }        
    }
}
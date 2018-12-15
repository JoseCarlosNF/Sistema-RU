#include "menu.c"
#include "funcoes.c"
#include <stdio.h>

#define lotacaoMax 10

int main(void){
    int opcao;
    int retorno;
    int lotacao;
    int hora;
    int minuto;

    lotacao = 0;
    minuto = 0;
    hora = 11;

    while(1){
        opcao = menuRU(lotacao, hora, minuto);

        // Menu RU - Opcao 1
        if (opcao == 1)
            novoUsuario();

        // Menu RU - Opcao 2
        else if (opcao == 2){
            while(1){
                opcao = menuCredito();

                // Menu Credito - Opcao 1
                if (opcao == 1)
                    consultarCredito();

                // Menu Credito - Opcao 2
                else if (opcao == 2)
                    comprarCredito();

                // Menu Credito - Opcao 0
                else if (opcao == 0)
                    break;
                    
                // Menu Credito - Opcao invalida
                else
                    printf("OPCAO INVALIDA.\n");
            }            
        }

        // Menu RU - Opcao 3
        else if (opcao == 3){
            if ((hora >= 11 && hora < 14) && (lotacao < lotacaoMax)){
                retorno = entrarRU();
                if (retorno == 1){
                    lotacao++;
                    minuto += 10;
                    if (minuto == 60){
                        hora ++;
                        minuto = 0;
                    }
                }
            }
            else if (11 > hora || hora > 14){
                printf("Fora do Horario.\n");
                system("pause");
            }
            else if (lotacao >= lotacaoMax)
                printf("Lotacao Maxima. Aguarde um momento.\n");
                system("pause");
        }

        // Menu RU - Opcao 4
        else if (opcao == 4){
            arquivoTexto();
            system("pause");
        }
        
        // Menu RU - Opcao 0
        else if (opcao == 0)
            break;

        // Menu RU - Opcao invalida
        else
            printf("OPCAO INVALIDA.\n");
    }
}
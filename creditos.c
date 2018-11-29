#include<stdio.h>
#include<stdlib.h>

void creditos(){
    int operacao;

    /* Menu Creditos*/
    system("cls");
    printf("=====/ CREDITOS /=====\n");
    printf("1 - Consulta\n");
    printf("2 - Compra\n");
    printf("0 - Voltar\n");
    printf("======================\n");
    scanf("%d", &operacao);

    while (operacao != 0){
        switch (operacao){
            case 1:consulta();break;
            case 2:printf("compra()\n");break;
            case 0:printf("menu()\n"); break;
            default:printf("OPERACAO INVALIDA\n");break;
        }
    }

}

void consulta(){
    FILE *f;
    int id, idBuscar;
    char nome[15], sobrenome[15];
    float credito;

    f = fopen("dados.db", "r");

    if (f == NULL)
        perror("Nao foi possivel abrir o arquivo.");
    else{
        printf("Digite o ID para buscar: ");
        scanf("%d", &idBuscar);
    }

    fscanf(f,"%d %s %s %f", &id, &nome, &sobrenome, &credito);

    while(!feof(f)){
        if (id == idBuscar){
            printf("%d %s %s %.2f\n", id, nome, sobrenome, credito);
            break;
        }
        fscanf(f,"%d %s %s %f", &id, &nome, &sobrenome, &credito);
    }
    if (feof(f))
        printf("NAO ENCONTRADO\n");
}
void compra(){
    /* Comprar Creditos */
}
int main(){
    creditos();
    return 0;
}

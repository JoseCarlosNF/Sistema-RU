#include<stdio.h>
void consulta(){
    FILE *f;
    int idBuscar, id;
    char nome[15], sobrenome[15];
    double credito;

    f = fopen("dados.db", "r");

    if (f == NULL)
        perror("Nao foi possivel abrir o arquivo.");
    else{
        printf("Digite o ID para busca: ");
        scanf("%d", &idBuscar);
    }

    fscanf(f,"%d %s %s %.2f", &id, &nome, &sobrenome, &credito);
    
    while(!feof(f)){
        if (id == idBuscar)
            printf("%d %s %s %.2lf\n", id, nome, sobrenome, credito);
        fscanf(f,"%d %s %s %.2lf", &id, &nome, &sobrenome, &credito);
        break;
    }
}

int main(){
    consulta();
    return 0;
}

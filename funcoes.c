#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

// Estrutura de dados - Usuario
struct dadosUsuario{
    int id;
    float credito;
    char *nome;
    char *sobrenome;
};

// Adicionar um novo usuario ao sistema
void inserirUsuario(FILE *arq){
    struct dadosUsuario User;

    User.id = 1;
    User.nome = "Jose";
    User.sobrenome = "Carlos";
    User.credito = 150.55;
    printf("%-5s %-10s %-15s %s\n", "ID", "NOME", "SOBRENOME", "CREDITO");
    printf("%-5d %-10s %-15s %.2f\n", User.id, User.nome, User.sobrenome, User.credito);
}

int main(){
    inserirUsuario();
    return 0;
}



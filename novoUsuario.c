#include<stdio.h>

void novoUsuario(){
    FILE *f;
    char nome[30], sobrenome[30];
    float credito;
    int id;

    f = fopen("dados.db", "a"); // Abrir arquivo

    if (f == NULL)
        perror("Nao foi possivel abrir o arquivo.\n");  // Não ceseguiu abrir o arquivo
    else
        printf("Arquivo aberto\n"); // Sinal de arquivo aberto (só pra teste)


    printf("Nome:");                /* Inserção dos dados */
    scanf("%s", &nome);             // Nome: xxxxxxxxxxxxxxx
    printf("Sobrenome:");           // Sobrenome: xxxxxxxxxxxxxxx
    scanf("%s", &sobrenome);        // Credito: xxxx.xx
    printf("Credito:");
    scanf("%f", &credito);  

    fprintf(f, "id %s %s %.2f\n", nome, sobrenome, credito); // Inserir no arquivo

    fclose(f);  // Fechar o arquivo
}

int main(){
    novoUsuario();
    return 0;
}

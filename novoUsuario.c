#include<stdio.h>

int ultimoId(){
    FILE *f;
    int id;
    char nome[15], sobrenome[15];
    float credito;

    f = fopen("dados.db", "r");

    while(!feof(f)){
        fscanf(f,"%d %s %s %f", &id, &nome, &sobrenome, &credito);
    }
    printf("%d\n", id);
    return id;
}

void novoUsuario(){
    FILE *f;
    int id;
    char nome[15], sobrenome[15];
    float credito;

    f = fopen("dados.db", "a"); // Abrir arquivo

    if (f == NULL)
        perror("Nao foi possivel abrir o arquivo.\n");  // Não ceseguiu abrir o arquivo
    else
        printf("Arquivo aberto\n"); // Sinal de arquivo aberto (só pra teste)


    id = ultimoId() + 1;
    printf("Nome:");                /* Inserção dos dados */
    scanf("%s", &nome);             // Nome: xxxxxxxxxxxxxxx
    printf("Sobrenome:");           // Sobrenome: xxxxxxxxxxxxxxx
    scanf("%s", &sobrenome);        // Credito: xxxx.xx
    printf("Credito:");
    scanf("%f", &credito);  

    fprintf(f, "%d %s %s %.2f\n", id, nome, sobrenome, credito); // Inserir no arquivo

    fclose(f);  // Fechar o arquivo
}

int main(){
    novoUsuario();
    return 0;
}

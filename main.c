#include<stdio.h>
#include<stdlib.h>

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
void menu(){
    int operacao;
    operacao = 1;
    while(operacao != 0){
        system("cls");

        printf("Lotacao atual: <lotacaoAtual> pessoas as <horaAtual>\n");
        printf("Lotacao media:\n");
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

        scanf("%d", &operacao);
        
        switch (operacao){
            case 1:novoUsuario();break;
            case 2:creditos();break;
            case 3:printf("entrarRU\n");break;
            case 0:printf("SAINDO...\n"); break;
            default:printf("OPCAO INVALIDA\n");break;
        }
    }
}
int main(){
    menu();
    return 0;
}

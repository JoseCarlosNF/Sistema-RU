#include<stdio.h>
#include<stdlib.h>
#include"funcoes.h"

struct dadosCadastro{
    int id;
    char nome[15];
    char sobrenome[15];
    float credito;
};

int ultimoID(){
    FILE *f;
    struct dadosCadastro aluno;

    f = fopen("cadastro.txt", "r");

    if(f == NULL)
        printf("Nao possivel abrir CADASTRO.TXT\n");
    else{
        while(!feof(f)){
            fscanf(f, "%d %s %s %f", &aluno.id, aluno.nome, aluno.sobrenome, &aluno.credito);
            if(feof(f))
                break;
        }
    }
    return aluno.id;
}

void novoUsuario(void){
    FILE *f;
    struct dadosCadastro aluno;

    f = fopen("cadastro.txt", "a");

    if (f == NULL)
        printf("Nao foi possivel abrir CADASTRO.TXT.\n");
    else{
        printf("Digite Nome e Sobrenome <separedos por espaco>: ");
        scanf("%s %s", &aluno.nome, &aluno.sobrenome);
        fprintf(f, "%-5d %-15s %-15s %.2f\n", ultimoID()+1, aluno.nome, aluno.sobrenome, 0.00);    

        fclose(f);
        printf("Cadastro efetudao.\n");
        printf("Aperter ENTER para continuar...\n");
        getchar();
    }
}

void consultarCredito(void){
    FILE *f;
    int idBusca;
    struct dadosCadastro aluno;

    f = fopen("cadastro.txt", "r");

    if (f == NULL)
        printf("Nao foi possivel abrir CADASTRO.TXT.\n");
    else{
        printf("Digite o ID para busca: ");
        scanf("%d", &idBusca);
        
        while(!feof(f)){
            fscanf(f, "%d %s %s %f", &aluno.id, aluno.nome, aluno.sobrenome, &aluno.credito);
            if (aluno.id == idBusca){
                limpatela();
                printf("%-5s %-15s %-15s %s\n", "ID", "NOME", "SOBRENOME", "CREDITO");
                printf("%-5d %-15s %-15s %.2f\n", aluno.id, aluno.nome, aluno.sobrenome, aluno.credito);
                break;
            }
            else if (feof(f))
                printf("ID nao encontrado.\n");
        }
        printf("Aperter ENTER para continuar...\n");
        getchar();
    }
}

void copiaTempToCadastro(){
    FILE *aux;
    FILE *f;
    struct dadosCadastro aluno;

    f = fopen("cadastro.txt", "w");
    aux = fopen("temp.txt", "r");

    while(!feof(aux)){
        fscanf(aux, "%d %s %s %f", &aluno.id, aluno.nome, aluno.sobrenome, &aluno.credito);
        if (feof(aux))
            break;
        fprintf(f, "%-5d %-15s %-15s %.2f\n", aluno.id, aluno.nome, aluno.sobrenome, aluno.credito);
    }
    fclose(f);
    fclose(aux);
}

void comprarCredito(){
    FILE *f;
    FILE *aux;
    struct dadosCadastro aluno;
    float compra;
    int idBusca;

    f = fopen("cadastro.txt", "r");
    aux = fopen("temp.txt", "w");

    if (f == NULL)
        printf("Nao foi possivel abrir CADASTRO.TXT\n");
    else if (aux == NULL)
        printf("Nao foi possivel abrir AUX.TXT\n");
    else{
        printf("Digite o ID do usuario: ");
        scanf("%d", &idBusca);
        
        while(!feof(f)){
            fscanf(f, "%d %s %s %f", &aluno.id, aluno.nome, aluno.sobrenome, &aluno.credito);
            if (feof(f)){
                break;
            }
            else if (aluno.id == idBusca){
                printf("Digite o valor da compra ou desconto: ");
                scanf("%f", &compra);
                compra = aluno.credito + compra;
                fprintf(aux, "%-5d %-15s %-15s %.2f\n", aluno.id, aluno.nome, aluno.sobrenome, compra);

                printf("Compra efetudada.\n");
                printf("Aperter ENTER para continuar...\n");
                getchar();
            }
            else
                fprintf(aux, "%-5d %-15s %-15s %.2f\n",aluno.id, aluno.nome, aluno.sobrenome, aluno.credito);                        
        }
        fclose(f);
        fclose(aux);
        copiaTempToCadastro();
    }
}

int entrarRU(){
    FILE *f;
    FILE *aux;
    struct dadosCadastro aluno;
    float compra;
    int idBusca;
    int retorno;

    f = fopen("cadastro.txt", "r");
    aux = fopen("temp.txt", "w");

    if (f == NULL)
        printf("Nao foi possivel abrir CADASTRO.TXT\n");
    else if (aux == NULL)
        printf("Nao foi possivel abrir AUX.TXT\n");
    else{
        printf("Digite o ID do usuario: ");
        scanf("%d", &idBusca);
        
        while(!feof(f)){
            fscanf(f, "%d %s %s %f", &aluno.id, aluno.nome, aluno.sobrenome, &aluno.credito);
            if (feof(f)){
                break;                
            }
            else if (aluno.id == idBusca){
                if(aluno.credito >= 1){
                    compra = aluno.credito - 1;
                    fprintf(aux, "%-5d %-15s %-15s %.2f\n", aluno.id, aluno.nome, aluno.sobrenome, compra);                    
                    retorno = 1;
                    printf("Entrada Autorizada.\n");
                    printf("Aperter ENTER para continuar...\n");
                    getchar();                    
                }
                else{
                    fprintf(aux, "%-5d %-15s %-15s %.2f\n",aluno.id, aluno.nome, aluno.sobrenome, aluno.credito);                
                    retorno = 0;
                    printf("Saldo insuficiente.\n");
                    printf("Aperter ENTER para continuar...\n");
                    getchar();
                }                    
            }
            else
                fprintf(aux, "%-5d %-15s %-15s %.2f\n",aluno.id, aluno.nome, aluno.sobrenome, aluno.credito);                        
        }
        fclose(f);
        fclose(aux);
        copiaTempToCadastro();
    }
    return retorno;
}

void arquivoTexto(){
    FILE *f;
    struct dadosCadastro aluno;

    f = fopen("cadastro.txt", "r");

    if (f == NULL)
        printf("Nao foi possivel abrir CADASTRO.TXT.\n");
    else{
        printf("%-5s %-15s %-15s %s\n", "ID", "NOME", "SOBRENOME", "CREDITO");
        while(!feof(f)){
            fscanf(f, "%d %s %s %f", &aluno.id, aluno.nome, aluno.sobrenome, &aluno.credito);
            if (feof(f))
                break;
            printf("%-5d %-15s %-15s %.2f\n", aluno.id, aluno.nome, aluno.sobrenome, aluno.credito);
        }
    }
    printf("Aperter ENTER para continuar...\n");
    getchar();
}

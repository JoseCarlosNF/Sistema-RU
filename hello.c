#include <stdio.h>
#include <string.h>

int cadastro(){
	FILE *arquivo;
	char nome[30], sobrenome[30], c;
	int id;
	float credito;

	arquivo = fopen("arquivo.txt", "w");

	if (arquivo == NULL)
		perror("Nao possivel abrir.\n");
	else
		printf("Arquivo aberto\n");
		
	printf("Insercao de Dados:\n");
	printf("Digite ID, Nome, Credito\n");
	scanf("%d %s %s %f", &id, nome, sobrenome, &credito);

	while (strcmp(nome, "sair") != 0){
		fprintf(arquivo, "%d %s %s %.2f\n", id, nome, sobrenome, credito);
		printf("?");
		scanf("%d %s %s %f", &id, nome, sobrenome, &credito);
	}
	fclose(arquivo);

	/*
	fopen("arquivo.txt", "r");

	printf("Exibindo:\n\n");
	while (fscanf(arquivo, "%c", &c) != EOF)
		printf("%c", c);
		printf("\n\n");
	fclose(arquivo);
	*/
	return 0;
}

int main(){
	cadastro();

	getchar();
	return 0;
}
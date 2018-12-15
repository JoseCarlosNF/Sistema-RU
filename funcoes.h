#ifndef FUNCOES_H
#define FUNCOES_H

int ultimoID(); // Retorna o ultimo id da lista de usuarios

void novoUsuario(); // Cadastro do um novo usuario

void consultarCredito(); // Consultar credito a partir do id

void comprarCredito(); // Atualiza o registro do usuario (comprando ou descontando credito)

void copiaTempToCadastro(); // Copia o conteudo do arquivo auxiliar para o arquivo cadastro

int entrarRU(); // Verifica se o credito do usuario é maior que 0 e Atualiza o registro do usuario (desconta a taxa do ru -1)

void arquivoTexto(); // Imprime o banco de dados dos usuário

void apagaArquivoTemp(); // Apaga arquivo temporario (mudar de acordo com sistema opercional Windows: del; Linux: rm)

int lotacaoMedia(); // retorna a lotação media

#endif
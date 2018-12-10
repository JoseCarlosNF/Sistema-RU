#ifndef FUNCOES_H
#define FUNCOES_H

int ultimoID(); // Retorna o ultimo id da lista de usuarios

void novoUsuario(); // Cadastro do um novo usuario

void consultarCredito(); // Consultar credito a partir do id

void comprarCredito(); // Atualiza o registro do usuario (comprando credito)

void copiaTempToCadastro(); // Copia o conteudo do arquivo auxiliar para o arquivo cadastro

int entrarRU(); // Atualiza o registro do usuario (descontado dos creditos a taxa do ru)

void arquivoTexto(); // Imprime os dados do banco em um aruivo de texto

void apagaArquivoTemp(); // Apaga arquivo temporario

#endif
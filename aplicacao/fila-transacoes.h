#ifndef FILA_TRANSACOES_H
#define FILA_TRANSACOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif


/**
 * @brief Estrutura que representa uma operação financeira.
 * 
 * Contém o nome do cliente, o tipo da operação,
 * a prioridade de execução e um ID.
 */
typedef struct{
    
    char operacao[100];
    int prioridade;
    int id;                                                                                                                            

} Operacao;

/**
 * @brief Nó da lista de operações financeiras.
 * 
 * Cada nó armazena uma operação e aponta para o próximo elemento da lista.
 */
typedef struct Elemento{
    
    Operacao dados;
    struct Elemento *prox;

} Elemento;

typedef Elemento *Lista;

/**
 * @brief Cria uma nova lista de transações financeiras.
 * 
 * A função aloca dinamicamente uma nova lista e a inicializa como vazia.
 * 
 * @return Lista * Ponteiro para a nova lista criada. Retorna NULL em caso de falha de alocação.
 */
Lista *criarLista();

/**
 * @brief Insere uma nova operação na lista, respeitando a prioridade.
 * 
 * A inserção é feita de forma ordenada, garantindo que operações com prioridade mais alta
 * fiquem no início da fila.
 * 
 * @param li Ponteiro para a lista.
 * @param nova_op Estrutura contendo os dados da operação a ser inserida.
 * @return int Retorna 1 se a inserção foi bem-sucedida, ou 0 em caso de erro.
 */
int insercaoOrdenada(Lista *li, Operacao nova_op);


/**
 * @brief Remove a operação com maior prioridade.
 * 
 * Após a remoção, o espaço de memória é liberado.
 * 
 * @param li Ponteiro para a lista de operações.
 * @return int Retorna 1 se a operação foi removida com sucesso, ou 0 se a lista estiver vazia.
 */
int imprimirFila(Lista *li);

/**
 * @brief Imprime todas as operações da lista.
 * 
 * Exibe o ID, a operação e a prioridade de cada item.
 * 
 * @param li Ponteiro para a fila.
 * @return int Retorna 1 se as operação foram impressas com sucesso, ou 0 se a lista não existir.
 */
int processarFila(Lista *li);

/**
 * @brief Libera toda a memória utilizada pela lista.
 * 
 * Percorre toda a lista de elementos e libera cada nó alocado dinamicamente.
 * 
 * @param li Ponteiro para a lista.
 */
void liberarLista(Lista *li);

void limpar_buffer();

void menu();

#endif
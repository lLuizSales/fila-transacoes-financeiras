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

#define STATUS_PENDENTE "PENDENTE"
#define STATUS_PROCESSADA "PROCESSADA"
#define STATUS_ERRO "ERRO"

/**
 * @brief Estrutura que representa uma operação financeira.
 * 
 * Contém o nome do cliente, o tipo da operação,
 * a prioridade de execução e um ID.
 */
typedef struct{
    
    char operacao[100];
    char status[20];
    int prioridade;
    int id;                                                                                                                            

} Operacao;

typedef struct NoPilha{
    
    Operacao dados;
    struct NoPilha *proximo;

} NoPilha;

typedef struct Pilha{
    
    NoPilha *topo;

} Pilha;

/**
 * @brief Nó da lista de operações financeiras.
 * 
 * Cada nó armazena uma operação e aponta para o próximo elemento da lista.
 */
typedef struct{
    
    Operacao *dados;
    int tamanho, capacidade;

} Heap;

/**
 * @brief Cria uma nova lista de transações financeiras.
 * 
 * A função aloca dinamicamente uma nova lista e a inicializa como vazia.
 * 
 * @return Lista * Ponteiro para a nova lista criada. Retorna NULL em caso de falha de alocação.
 */

Heap *criarHeap(int n);

/**
 * @brief Cria uma nova pilha (utilizado para a função de edesfazer).
 * 
 * @return Pilha * Ponteiro para a nova pilha ou NULL em caso de falha.
 */
Pilha *criarPilha();

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
int inserirFila(Heap *h, Operacao nova_op);

/**
 * @brief Adiciona uma operação processada no topo da pilha.
 * 
 * @param p Ponteiro para a Pilha.
 * @param op Operação a ser empilhada.
 * @return int Retorna 1 se o empilhamento foi bem-sucedido, ou 0 em caso de erro.
 */
int empilhar(Pilha *p, Operacao op);

/**
 * @brief Remove e retorna a operação do topo da pilha.
 * 
 * @param p Ponteiro para a Pilha.
 * @return Operacao A operação removida, ou uma operação vazia em caso da pilha estar vazia.
 */
Operacao desempilhar(Pilha *p);

/**
 * @brief Remove a operação com maior prioridade.
 * 
 * Após a remoção, o espaço de memória é liberado.
 * 
 * @param li Ponteiro para a lista de operações.
 * @return int Retorna 1 se a operação foi removida com sucesso, ou 0 se a lista estiver vazia.
 */
void imprimirFila(Heap *h);

Operacao processarFilaRetorno(Heap *h);

/**
 * @brief Imprime todas as operações da lista.
 * 
 * Exibe o ID, a operação e a prioridade de cada item.
 * 
 * @param li Ponteiro para a fila.
 * @param op_processada Ponteiro onde será armazenada a operação processada.
 * @return int Retorna 1 se as operação foram impressas com sucesso, ou 0 se a lista não existir.
 */
int processarFila(Heap *h, Operacao *op_processada);

/**
 * @brief Libera toda a memória utilizada pela lista.
 * 
 * Percorre toda a lista de elementos e libera cada nó alocado dinamicamente.
 * 
 * @param li Ponteiro para a lista.
 */
void liberarHeap(Heap *h);

/**
 * @brief Libera toda a memória utilizada pela pilha.
 * 
 *  @param p Ponteiro para a Pilha.
 */
void liberarPilha(Pilha *p);

/**
 * @brief Remove uma operação de qualquer posição com base no seu ID.
 *  
 * @param id ID da operação a ser removida.
 * @return int Retorna 1 se a remoção foi bem-sucedida, ou 0 se o ID não foi encontrado ou a fila é inválida.
 */
int removerID(Heap *h, int id);

void heapUp(Heap *h, int id);
void heapDown(Heap *h, int id);
void troca(Operacao *a, Operacao *b);

void limpar_buffer();

void menu();

#endif
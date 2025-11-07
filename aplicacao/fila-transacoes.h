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

typedef struct{
    
    char operacao[100];
    int prioridade;
    int id;                                                                                                                            

} Operacao;

typedef struct Elemento{
    
    Operacao dados;
    struct Elemento *prox;

} Elemento;

typedef Elemento *Lista;

Lista *criarLista();

int insercaoOrdenada(Lista *li, Operacao nova_op);

int imprimirFila(Lista *li);

int processarFila(Lista *li);

void limpar_buffer();

void menu();

#endif
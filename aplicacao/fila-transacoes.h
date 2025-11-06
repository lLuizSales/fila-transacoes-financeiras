#ifndef FILA_TRANSACOES_H
#define FILA_TRANSACOES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    
    char nome[100];
    int prioridade;                                                                                                                             
    float valor;

}  Operacao;

typedef struct Elemento{
    
    Operacao dados;
    struct Elemento *prox;

} Elemento;

typedef Elemento *Lista;

Lista *criarLista();

int insercaoOrdenada(Lista *li, Operacao nova_op);

int imprimirFila(Lista *li);

int exclusaoOrdenada(Lista *li);

void limpar_buffer();

#endif
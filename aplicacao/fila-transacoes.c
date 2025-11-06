#include "fila-transacoes.h"

Lista *criarLista(){
    
    Lista *li = (Lista *)malloc(sizeof(Lista));

    if(li != NULL){

        (*li) = NULL;

    }

    return li;

}

int insercaoOrdenada(Lista *li, Transacao nova_tran){

    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));

    novo->dados = nova_tran;
    novo->prox = NULL;

    if(li == NULL) return 0;

    if((*li) == NULL){

        *li = novo;

        return 1;
    }

    Elemento *atual = *li;

    while(novo->dados.prioridade < atual->dados.prioridade){

        atual = atual->prox;

    }

    if(atual->prox == NULL){

        atual->prox = novo;

        return 1;

    } else if (atual->prox != NULL){

        novo->prox = atual->prox;
        atual->prox = novo;
        
        return 1;

    }

}

int exclusaoOrdenada(Lista *li){

}

int imprimirFila(Lista *li){

}
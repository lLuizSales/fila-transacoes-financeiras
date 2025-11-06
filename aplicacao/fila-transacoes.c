#include "fila-transacoes.h"

void limpar_buffer(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

Lista *criarLista(){
    
    Lista *li = (Lista *)malloc(sizeof(Lista));

    if(li != NULL){

        (*li) = NULL;

    }

    return li;

}

int insercaoOrdenada(Lista *li, Operacao nova_op){

    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));

    novo->dados = nova_op;
    novo->prox = NULL;

    if(li == NULL) return 0;

    if((*li) == NULL){

        *li = novo;

        return 1;
    }

    Elemento *anterior = NULL;
    Elemento *atual = *li;

    while(atual != NULL && novo->dados.prioridade < atual->dados.prioridade){

        anterior = atual;
        atual = atual->prox;

    }

    if(anterior == NULL){

        novo->prox = *li;
        *li = novo;       

        return 1;

    } else {

        novo->prox = atual;
        anterior->prox = novo;
        
        return 1;

    }

}

int exclusaoOrdenada(Lista *li){

}

int imprimirFila(Lista *li){
    
    if(li == NULL) return 0;

    if((*li) == NULL){
        
        printf("Nenhuma operação feita!\n");

        return 1;

    }

    Elemento *atual = *li;
    
    while(atual != NULL){

        printf("Cliente: %s\n", atual->dados.nome);
        printf("%.2f\n", atual->dados.valor);
        printf("%d\n", atual->dados.prioridade);

        atual = atual->prox;

    }
    
    return 1;

}insercaoOrdenada(li, nova_tran);
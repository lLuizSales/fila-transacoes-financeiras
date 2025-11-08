#include "fila-transacoes.h"

void limpar_buffer(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Cria uma nova lista de transações financeiras.
 * 
 * A função aloca dinamicamente uma nova lista
 * e a inicializa como vazia.
 * 
 * @return Lista * Ponteiro para a fila criada, ou NULL em caso de falha.
 */
Lista *criarLista(){
    
    Lista *li = (Lista *)malloc(sizeof(Lista));

    if(li != NULL){

        (*li) = NULL;

    }

    return li;

}

void menu(){

    printf("-----Operações Financeiras-----\n");
    printf("1. Transferências\n");
    printf("2. Consulta\n");
    printf("3. Extrato do mês anterior\n");
    printf("4. Imprimir fila\n");
    printf("5. Processar Fila\n");
    printf("6. Sair\n");

}

/**
 * @brief Insere uma nova operação na lista respeitando sua prioridade.
 * 
 * A inserção é feita de forma ordenada, de modo que as operações de maior prioridade
 * fiquem no início da fila.
 * 
 * @param li Ponteiro para a lista.
 * @param nova_op Estrutura com os dados da operação.
 * @return int Retorna 1 em caso de sucesso e 0 em caso de erro.
 */
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

    while(atual != NULL && novo->dados.prioridade <= atual->dados.prioridade){

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

/**
 * @brief Remove a operação com maior prioridade.
 * 
 * Libera o nó removido da memória.
 * 
 * @param li Ponteiro para a lista.
 * @return int Retorna 1 se a remoção foi bem-sucedida, 0 se a fila estiver vazia ou for inválida.
 */
int processarFila(Lista *li){

    if(*li == NULL){

        system(LIMPAR_TELA);

        printf("Nenhuma operação a ser processada!\n");

        printf("\nPressione <ENTER> para voltar ao menu de operações.");
        getchar();

        return 1;
    } 

    Elemento *anterior = *li;

    system(LIMPAR_TELA);

    printf("--------Operação a ser processada--------\n");
    printf("ID: %d | Operação: %s | Prioridade: %d |\n", anterior->dados.id, anterior->dados.operacao, anterior->dados.prioridade);

    printf("\nPressione <ENTER> para voltar ao menu de operações.");
    getchar();

    *li = anterior->prox;

    free(anterior);


}

/**
 * @brief Imprime todas as operações da lista.
 * 
 * Exibe na tela cada operação em ordem de prioridade, sem alterar a lista.
 * 
 * @param li Ponteiro para a lista.
 */
int imprimirFila(Lista *li){
    
    if(li == NULL) return 0;

    if((*li) == NULL){
        
        system(LIMPAR_TELA);

        printf("Nenhuma operação requisitada!\n");

        printf("\nPressione <ENTER> para voltar ao menu de operações.");
        getchar();

        return 1;

    }

    Elemento *atual = *li;

    system(LIMPAR_TELA);
    printf("--------Operações--------\n\n");

    while(atual != NULL){

        printf("ID: %d | Operação: %s | Prioridade: %d |\n", atual->dados.id, atual->dados.operacao, atual->dados.prioridade);

        atual = atual->prox;

    }

    printf("\nPressione <ENTER> para voltar ao menu de operações.");
    getchar();
    
    return 1;

}


/**
 * @brief Libera toda a memória alocada pela lista.
 * 
 * Percorre todos os nós da lista e libera cada um deles.
 * 
 * @param li Ponteiro para a lista a ser desalocada.
 */
void liberarLista(Lista *li) {

    if (li != NULL) {

        Elemento *atual = *li;
        Elemento *prox;

        while (atual != NULL) {

            prox = atual->prox;  
            free(atual);         
            atual = prox;

        }

        free(li);
    }
}
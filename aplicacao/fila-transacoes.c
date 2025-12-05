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
Heap *criarHeap(int n){
    
    Heap* h = (Heap *)malloc(sizeof(Heap));

    if (h == NULL) return NULL;
    
    h->capacidade = (n > 0) ? n : 10;
    h->tamanho = 0;
    h->dados = (Operacao *)malloc(h->capacidade * sizeof(Operacao));

    if (h->dados == NULL) {

        free(h);

        return NULL;

    }

    return h;

}

/**
 * @brief Cria uma nova pilha para a funcionalidade de "desfazer".
 * 
 * @return Pilha * Ponteiro para a nova pilha ou NULL em caso de falha.
 */
Pilha *criarPilha() {
    
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));

    if (p == NULL) return NULL;
    
    p->topo = NULL;
    
    return p;

}

void menu(){

    printf("-----Operações Financeiras-----\n");
    printf("1. Transferências\n");
    printf("2. Consulta\n");
    printf("3. Extrato do mês anterior\n");
    printf("4. Imprimir fila\n");
    printf("5. Processar Fila\n");
    printf("6. Remover Operação por ID\n");
    printf("7. Buscar por ID\n");
    printf("8. Desfazer Última Operação Processada (Undo)\n");
    printf("9. Sair\n");

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
int inserirFila(Heap *h, Operacao nova_op){

    if (h == NULL) return 0;

    strcpy(nova_op.status, STATUS_PENDENTE);
    
    if (h->tamanho == h->capacidade) {
        
        h->capacidade *= 2;
        
        h->dados = (Operacao*)realloc(h->dados, h->capacidade * sizeof(Operacao));
        
        if (h->dados == NULL) return 0;
    
    }

    h->dados[h->tamanho] = nova_op;
    
    heapUp(h, h->tamanho);
    
    h->tamanho++;
    return 1;

}

/**
 * @brief Adiciona uma operação processada ao topo da pilha.
 */
int empilhar(Pilha *p, Operacao op) {
    
    if (p == NULL) return 0;
    
    NoPilha *novoNo = (NoPilha *)malloc(sizeof(NoPilha));

    if (novoNo == NULL) return 0;
    
    novoNo->dados = op;
    novoNo->proximo = p->topo;
    p->topo = novoNo;
    
    return 1;

}

/**
 * @brief Remove e retorna a operação do topo da pilha.
 */
Operacao desempilhar(Pilha *p) {

    Operacao operacao_vazia = {"N/A", "", -1, -1};
    strcpy(operacao_vazia.status, STATUS_ERRO);

    if (p == NULL || p->topo == NULL) return operacao_vazia;
    
    NoPilha *noRemover = p->topo;
    Operacao op = noRemover->dados;

    p->topo = p->topo->proximo;
    free(noRemover);

    return op;

}

/**
 * @brief Função que retorna a operação de maior prioridade sem removê-la.
 */
Operacao processarFilaRetorno(Heap *h) {

    Operacao operacao_vazia = {"N/A", "", -1, -1};
    strcpy(operacao_vazia.status, STATUS_ERRO);

    if (h == NULL || h->tamanho == 0) return operacao_vazia;
    
    return h->dados[0];

}

/**
 * @brief Remove a operação com maior prioridade.
 * 
 * Libera o nó removido da memória.
 * 
 * @param li Ponteiro para a lista.
 * @return int Retorna 1 se a remoção foi bem-sucedida, 0 se a fila estiver vazia ou for inválida.
 */
int processarFila(Heap *h, Operacao *op_processada){
    
    if (h == NULL || h->tamanho == 0) return 0;

    *op_processada = h->dados[0];

    strcpy(op_processada->status, STATUS_PROCESSADA);

    h->dados[0] = h->dados[h->tamanho - 1];
    h->tamanho--;

    heapDown(h, 0);

    return 1;

}

/**
 * @brief Imprime todas as operações da lista.
 * 
 * Exibe na tela cada operação em ordem de prioridade, sem alterar a lista.
 * 
 * @param li Ponteiro para a lista.
 */
void imprimirFila(Heap *h){
    
    if(h == NULL || h->tamanho == 0){
        
        printf("Nenhuma operacao requisitada!");

        printf("\nPressione <ENTER> para voltar ao menu de operações.");
        getchar();

        return;

    }

    system(LIMPAR_TELA);
    printf("--------Operações--------\n\n");

    for (int i = 0; i < h->tamanho; i++) {
        printf("Index %d | ID: %d | Operação: %s | Prioridade: %d | Status: %s |\n", i, 
               h->dados[i].id, h->dados[i].operacao, h->dados[i].prioridade, h->dados[i].status);
    }
    printf("---------------------------\n");

    printf("\nPressione <ENTER> para voltar ao menu de operações.");
    getchar();

}


/**
 * @brief Libera toda a memória alocada pela lista.
 * 
 * Percorre todos os nós da lista e libera cada um deles.
 * 
 * @param li Ponteiro para a lista a ser desalocada.
 */
void liberarHeap(Heap *h) {

    if(h != NULL){

        free(h->dados);
        free(h);

    }
}

/**
 * @brief Libera a memória usada pela pilha.
 *
 * @param p Ponteiro para a Pilha.
 */
void liberarPilha(Pilha *p) {

    if (p != NULL) {
        
        NoPilha *atual = p->topo;
        NoPilha *proximo;

        while (atual != NULL) {
            
            proximo = atual->proximo;
            free(atual);
            atual = proximo;

        }
        
        free(p);
    
    }
}

void troca(Operacao *a, Operacao *b) {
    
    Operacao temp = *a;
    *a = *b;
    *b = temp;

}

void heapUp(Heap* h, int id) {

    int pai = (id - 1) / 2;

    if (id > 0 && h->dados[id].prioridade > h->dados[pai].prioridade) {
        
        troca(&h->dados[id], &h->dados[pai]);
        
        heapUp(h, pai);
    
    }

}

void heapDown(Heap* h, int id) {
    
    int maior = id;
    int esquerda = 2 * id + 1;
    int direita = 2 * id + 2;

    if (esquerda < h->tamanho && h->dados[esquerda].prioridade > h->dados[maior].prioridade) {
        
        maior = esquerda;
    
    }

    if (direita < h->tamanho && h->dados[direita].prioridade > h->dados[maior].prioridade) {
        
        maior = direita;
    
    }

    if (maior != id) {
        
        troca(&h->dados[id], &h->dados[maior]);
        
        heapDown(h, maior);
    
    }

}

Operacao buscaId(Heap *h, int id) {

    Operacao operacao_vazia = {"ID não encontrado", "", -1, -1};
    strcpy(operacao_vazia.status, STATUS_ERRO);

    if (h == NULL || h->tamanho == 0) {
        
        return operacao_vazia;
    
    }

    for (int i = 0; i < h->tamanho; i++) {
        
        if (h->dados[i].id == id) {
            
            return h->dados[i]; 
        
        }
    
    }


    return operacao_vazia;
}

int removerID(Heap *h, int id) {
    
    if (h == NULL || h->tamanho == 0) {
        return 0;
    }

    int chaveRemover = -1;

    for (int i = 0; i < h->tamanho; i++) {
        
        if (h->dados[i].id == id) {
            
            chaveRemover = i;
            break;
        
        }
    
    }

    if (chaveRemover == -1) {
        return 0;
    }

    troca(&h->dados[chaveRemover], &h->dados[h->tamanho - 1]);
    
    h->tamanho--;

    heapUp(h, chaveRemover);
    heapDown(h, chaveRemover);

    return 1;

}
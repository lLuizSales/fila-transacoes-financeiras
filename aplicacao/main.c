#include "fila-transacoes.c"

int main(){

    Heap *h = criarHeap(10);

    Pilha *p = criarPilha();

    if (h == NULL || p == NULL) {
        printf("Erro ao inicializar a Heap ou a Pilha.\n");
        return 0;
    }

    Operacao nova_op;

    int opcao = 0;

    nova_op.id = 0;

    do {

        system(LIMPAR_TELA);
        
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limpar_buffer();

        if(opcao == 1){

            int t_opcao = 0;

            system(LIMPAR_TELA);
            printf("-----Transferências disponíveis-----\n");
            printf("1. Transferência imediata\n");
            printf("2. Transferência agendada\n");
            scanf("%d", &t_opcao);

            if(t_opcao == 1){

                strcpy(nova_op.operacao, "Transferência imediata");
                nova_op.prioridade = 4;
                nova_op.id++;
                inserirFila(h, nova_op);

            } else if(t_opcao == 2){

                strcpy(nova_op.operacao, "Transferência agendada");
                nova_op.prioridade = 3;
                nova_op.id++;
                inserirFila(h, nova_op);

            } else {

                system(LIMPAR_TELA);

                printf("Opção inexistente!\n");
                
                printf("\nPressione <ENTER> para voltar ao menu de operações.");
                getchar();

            }

        } else if(opcao == 2){
            
            strcpy(nova_op.operacao, "Consulta");
            nova_op.prioridade = 2;
            nova_op.id++;
            inserirFila(h, nova_op);

        } else if(opcao == 3){

            strcpy(nova_op.operacao, "Extrato do mês anterior");
            nova_op.prioridade = 1;
            nova_op.id++;
            inserirFila(h, nova_op);

        } else if(opcao == 4){
            
            imprimirFila(h);

        } else if(opcao == 5){

            Operacao op_a_processar = processarFilaRetorno(h);
            Operacao op_processada;
            int sucesso = 0;

            if (op_a_processar.id != -1) {
                
                sucesso = processarFila(h, &op_processada);

                if (sucesso) {
                    
                    empilhar(p, op_processada);
                    
                    system(LIMPAR_TELA);
                    printf("Sucesso! Operação processada:\n");
                    printf("   ID: %d | Tipo: %s | Prioridade: %d | Status: %s \n", 
                            op_processada.id, op_processada.operacao, op_processada.prioridade, op_processada.status);
                }
            }
            
            if (!sucesso) {
                system(LIMPAR_TELA);
                printf("A fila de operações está vazia. Não há nenhuma operação para processar.\n");
            }
            
            printf("\nPressione <ENTER> para voltar ao menu de operações.");
            getchar();

        } else if(opcao == 6){

            system(LIMPAR_TELA);

            int id_remover = 0;
            printf("Digite o ID da operação a ser removida: ");
            scanf("%d", &id_remover);
            limpar_buffer();

            if (removerID(h, id_remover)) {
                system(LIMPAR_TELA);
                printf("Operação com ID %d removida da fila.\n", id_remover);
            } else {
                system(LIMPAR_TELA);
                printf("Erro! Operação com ID %d não encontrada ou a fila está vazia.\n", id_remover);
            }

            printf("\nPressione <ENTER> para voltar ao menu de operações.");
            getchar();

        } else if(opcao == 7){
            
            system(LIMPAR_TELA);

            int id = 0;
            
            printf("Digite um ID para a busca: ");
            scanf("%d", &id);
            limpar_buffer();

            Operacao busca = buscaId(h, id);

            if(busca.id != -1){

                printf("--------Operação--------\n\n");
                printf("ID: %d | Operação: %s | Prioridade: %d |\n", 
                busca.id, busca.operacao, busca.prioridade);

            } else{

                printf("Operação não encontrada para o ID %d.\n", id);

            }

            printf("\nPressione <ENTER> para voltar ao menu de operações.");
            getchar();

        } else if(opcao == 8){

            Operacao op_desfeita = desempilhar(p);

            if (op_desfeita.id != -1) {
                
                if (inserirFila(h, op_desfeita)) {
                    system(LIMPAR_TELA);
                    printf("A operação '%s' (ID: %d) foi desfeita e retornou à fila com status PENDENTE.\n", 
                            op_desfeita.operacao, op_desfeita.id);
                } else {
                    system(LIMPAR_TELA);
                    printf("Erro ao reinserir a operação desfeita na fila.\n");
                }
            } else {
                system(LIMPAR_TELA);
                printf("A pilha de operações processadas está vazia. Não há nada para desfazer.\n");
            }
            
            printf("\nPressione <ENTER> para voltar ao menu de operações.");
            getchar();

        } else if(opcao != 9){

            system(LIMPAR_TELA);

            printf("Opção inexistente!\n");

            printf("\nPressione <ENTER> para voltar ao menu de operações.");
            getchar();


        }

    } while(opcao != 9);

    liberarHeap(h);    
    liberarPilha(p);
    
    system(LIMPAR_TELA);
    printf("\nSaindo do programa...\n");
    
    return 1;
}
#include "fila-transacoes.c"

int main(){

    Heap *h = criarHeap(10);

    Operacao nova_op;

    int opcao = 0;

    nova_op.id = 0;

    do {

        system(LIMPAR_TELA);
        
        menu();
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

            processarFila(h);

        } else if(opcao == 6){
            
            system(LIMPAR_TELA);

            int id = 0;
            
            printf("Digite um ID: ");
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

        } else if(opcao != 7){

            system(LIMPAR_TELA);

            printf("Opção inexistente!\n");

            printf("\nPressione <ENTER> para voltar ao menu de operações.");
            getchar();


        }

    } while(opcao != 7);

    liberarHeap(h);    
    
    system(LIMPAR_TELA);
    printf("\nSaindo do programa...\n");
    
    return 1;
}
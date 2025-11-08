#include "fila-transacoes.c"

int main(){

    Lista *li = criarLista();

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
                insercaoOrdenada(li, nova_op);

            } else if(t_opcao == 2){

                strcpy(nova_op.operacao, "Transferência agendada");
                nova_op.prioridade = 3;
                nova_op.id++;
                insercaoOrdenada(li, nova_op);

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
            insercaoOrdenada(li, nova_op);

        } else if(opcao == 3){

            strcpy(nova_op.operacao, "Extrato do mês anterior");
            nova_op.prioridade = 1;
            nova_op.id++;
            insercaoOrdenada(li, nova_op);

        } else if(opcao == 4){
            
            imprimirFila(li);

        } else if(opcao == 5){

            processarFila(li);

        } else if(opcao != 6){

            system(LIMPAR_TELA);

            printf("Opção inexistente!\n");

            printf("\nPressione <ENTER> para voltar ao menu de operações.");
            getchar();


        }

    } while(opcao != 6);

    liberarLista(li);    
    
    system(LIMPAR_TELA);
    printf("\nSaindo do programa...\n");
    
    return 1;
}
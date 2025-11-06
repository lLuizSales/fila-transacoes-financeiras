#include "fila-transacoes.c"

int main(){

    Lista *li = criarLista();

    Transacao nova_tran;

    int opcao = 0;

    do {

        printf("1. Adicionar nova operação\n");
        printf("2. Imprimir fila\n");
        printf("3. Sair\n");
        /*printf("-----Operações Financeiras-----\n");
        printf("1. Transferências\n");
        printf("2. Consulta\n");
        printf("3. Extrato do mês anterior\n");
        printf("4. Imprimir fila\n");
        printf("5. Sair\n");*/
        scanf("%d", &opcao);
        limpar_buffer();

        if(opcao == 1){

            printf("Nome: ");
            scanf("%[^\n]", nova_tran.nome);
            printf("Valor: ");
            scanf("%f", &nova_tran.valor);
            printf("Prioridade: ");
            scanf("%d", &nova_tran.prioridade);
            /*printf("--Transferências disponíveis--\n");
            printf("1. Transferência imediata\n");
            pritnf("2. Transferência com valor > 10.000");
            pritnf("3. Transferência agendada");*/

            insercaoOrdenada(li, nova_tran);

        } else if(opcao == 2) {

            imprimirFila(li);

        }



        
        

        

    } while(opcao != 3);
    
    return 1;
}
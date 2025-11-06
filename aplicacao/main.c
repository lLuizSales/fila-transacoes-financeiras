#include "fila-transacoes.c"

int main(){

    Lista *li = criarLista();

    Operacao nova_op;

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

            int t_opcao = 0;
            
            /*printf("--Transferências disponíveis--\n");
            printf("1. Transferência imediata\n");
            pritnf("2. Transferência com valor > 10.000");
            pritnf("3. Transferência agendada");*/

        } else if(opcao == 2){

            printf("Nome: ");
            scanf("%[^\n]", nova_op.nome);
                        


        } else if(opcao == 3){

        } else if(opcao == 4){

            imprimirFila(li);

        }



        
        

        

    } while(opcao != 3);
    
    return 1;
}
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


/* Implementação de Fila de Prioridade com lista encadeada não ordenada.
   Neste caso, a inserção acontece sempre no início da lista e a remoção é 
   responsável por encontrar o elemento de maior prioridade e, em seguida,
   executar a sua remoção (atualizando os ponteiros necessários).
   
   Exemplo: Incluir os elementos 3,6,1,8,4 na fila:
   inicio -> [3]
   inicio -> [6] -> [3]
   inicio -> [1] -> [6] -> [3]
   inicio -> [8] -> [1] -> [6] -> [3]
   inicio -> [4] -> [8] -> [1] -> [6] -> [3]
   
   Retirar da FP: encontrar o de maior prioridade e remover:
   inicio -> [4] -> [1] -> [6] -> [3]  
*/

int main() {
    FilaPrioridade* pq = criarFP();

    // Inserindo números com prioridades
    inserir(pq, 150, 1);
    inserir(pq, 220, 3);
    inserir(pq, 180, 1);
    inserir(pq, 370, 4);
    inserir(pq,  60, 2);
    inserir(pq, 500, 6);
    inserir(pq,  75, 7);
    inserir(pq,  25, 8);
    inserir(pq, 270, 1);
    inserir(pq, 320, 2);

    //imprime(pq);

    /*
    printf("Retirada completa na ordem de prioridade:\n");
    while (!vazia(pq)) {
        int number = retirar(pq);
        printf("%d ", number);
    }
    */
    elem(pq);


    // Liberar memória
    liberarFP(pq);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main() {
    Node *lnum; // lista de números com encadeamento de nós
    int val;
    lnum = createEmptyList();
    for(int i=0;i<10;i++){  //  inserir 10 elementos
        scanf("%d",&val);
        lnum = insertAtBeginning(lnum, val);
    }
    lnum = randomNumbers(lnum);

    int verify = isEmptyList(lnum);
    if (verify==1) {
        printf("Lista vazia\n");
    }else {
        printf("Lista Inicial: ");
        printList(lnum);
    }

    removeElement(lnum, 10);
    int biggest = biggestNumber(lnum);
    removeBiggestNumber(lnum, biggest);
    printf("Lista sem o 10 e sem o maior numero: ");
    printList(lnum);

    Node *listEvens = createEmptyList();
    listEvens = listOfEvens(lnum);
    printf("Lista de Pares: ");
    printList(listEvens);

    int n = numberOfElementsRecursive(listEvens);
    printf("Numero de Elementos: %d\n", n);

    const int *listVector = returnVector(listEvens, n);
    printf("Vetor: [");
    for (int i = 0; i < n; i++) {
        printf("%d, ", listVector[i]);
    }
    printf("]");
    printf("\n");
}
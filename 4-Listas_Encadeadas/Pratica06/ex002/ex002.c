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
        printList(lnum);
    }
    removeElement(lnum, 10);
    printList(lnum);
}
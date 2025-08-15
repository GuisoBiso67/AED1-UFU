#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

List* concat(List* liA, List* liB) {
    if (liA == NULL || liB == NULL) return 0;
    if ((*liB) == NULL) return liA; // se a lista B for vazia, retorno a lista A mesmo;
    //Elem *node = (Elem*)malloc(sizeof(Elem));
    //if (node == NULL) return 0; // erro de alocação
    


    /*
    Ship *node = (Ship*)malloc(sizeof(Ship));
    if (node == NULL) return 0;
    node->data = s; // copia os dados da nave;
    if ((*li) == NULL) { // se a lista estiver vazia;
        *li = node;
        node->next = node;
    }else {
        Ship *aux = *li;
        while (aux->next != (*li)) { // enquanto aux for diferente do início;
            aux = aux->next;
        }
        aux->next = node; // o ultimo aponta para o novo nó;
        node->next = *li; // o novo nó aponta para o "primeiro";
        *li = node; // novo início é o novo nó;
    }
    return 1;
    }
    */
}

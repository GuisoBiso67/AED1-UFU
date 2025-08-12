#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

Ships* createList() {
    Ships* li = (Ships*)malloc(sizeof(Ships));
    if (li != NULL) *li = NULL;
    return li;
}

void printList(Ships* li) {
    if (li == NULL) {
        printf("Lista vazia!");
        return;
    }
    Ship *aux = *li;
    int count = 0;
    do {
        printf("\n- Nave %d | Capacidade: %d | Combustivel: %d \n",count+1, aux->data.maxCapacity, aux->data.currentFuel);
        count++;
        aux = aux->next;
    } while (aux != (*li));
}

int cycle(Ships* li, int fuel, int quantShips) {
    if (li == NULL) return 0;
    Ship *aux = *li;
    int verify; // verifica se todas as naves já atingiram a capacidade máxima;
    do { // programa mais lento que esse impossível. Depois eu vejo um jeito de melhorar isso;
        verify = quantShips;
        do {
            if ((aux->data.currentFuel+fuel) <= aux->data.maxCapacity ) {
                aux->data.currentFuel += fuel;
                verify--;
            }
            if (aux->next == (*li) && verify == quantShips) {
                break;
            }
            aux = aux->next;
        }while (aux != (*li));
    }while (verify != quantShips); // será verdadeira quando não entrar no if nenhuma vez;
    return 1;
}

int insertAtBeginning(Ships* li, struct ship s) {
    if (li == NULL) return 0;
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

int insertAtEnd(Ships* li, struct ship s) {
    if (li == NULL) return 0;
    Ship *node = (Ship*)malloc(sizeof(Ship));
    if (node == NULL) return 0;
    node->data = s;
    if ((*li) == NULL) { // lista vazia;
        *li = node;
        node->next = node;
    }else {
        Ship *aux = *li;
        while (aux->next != (*li)) {
            aux = aux->next;
        }
        aux->next = node; // o ultimo aponta para o novo ultimo (node);
        node->next = *li; // novo ultimo aponta para o inicio;
    }
    return 1;
}

int insertNeatly(Ships* li, struct ship s) {
    if (li == NULL) return 0;
    Ship *node = (Ship*)malloc(sizeof(Ship));
    if (node == NULL) return 0;
    node->data = s;
    if ((*li) == NULL) {
        *li = node;
        node->next = node;
        return 1;
    }else {
        if ((*li)->data.maxCapacity > s.maxCapacity) { // insere inicio;
            Ship *current = *li;
            while (current->next != (*li)) { // procura último elemento;
                current = current->next;
                node->next = *li;
                current->next = node;
                *li = node;
                return 1;
            }
        }
        Ship *before = *li, *current = (*li)->next;
        // 1ª condição é para parar quando voltar no 1º elemento;
        // 2ª condição faz inserir entre o "before" e o "current";
        while (current != (*li) && current->data.maxCapacity < s.maxCapacity) {
            before = current;
            current = current->next;
        }
        before->next = node;
        node->next = current;
        return 1;
    }
}

int removeFromBeginning(Ships* li) {
    if (li == NULL) return 0;
    if ((*li) == NULL) return 0;
    if ((*li) == (*li)->next) { // lista com um único elemento;
        free(*li);
        *li = NULL;
        return 1;
    }
    Ship *current = *li;
    while (current->next != (*li)) {
        current = current->next;
    }
    Ship *node = *li;
    current->next = node->next;
    *li = node->next;
    free(node);
    return 1;
}

int removeFromEnd(Ships* li) {
    if (li == NULL) return 0;
    if ((*li) == NULL) return 0;
    if ((*li) == (*li)->next) { // lista com um único elemento;
        free(*li);
        *li = NULL;
        return 1;
    }
    Ship *before, *node = *li;
    while (node->next != (*li)) { // procura último nó;
        before = node;
        node = node->next;
    }
    before->next = node->next;
    free(node);
    return 1;
}

int removeElement(Ships* li, int maxCapacity) {
    if (li == NULL) return 0;
    if ((*li) == NULL) return 0;
    Ship *node = *li;
    if (node->data.maxCapacity == maxCapacity) {
        if (node == node->next) { // lista com um único elemento;
            free(node);
            *li = NULL;
            return 1;
        }else { // se não, busca o último elemento;
            Ship *last = *li;
            while (last->next != (*li)) {
                last = last->next;
            }
            last->next = (*li)->next;
            *li = (*li)->next;
            free(node);
            return 1;
        }
    }
    Ship *before = node;
    node = node->next;
    while (node != (*li) && node->data.maxCapacity != maxCapacity) {
        before = node;
        node = node->next;
    }
    if (node == *li) return 0;
    before->next = node->next;
    free(node);
    return 1;
}

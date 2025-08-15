#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

Ships* createList() {
    Ships* li = (Ships*)malloc(sizeof(Ships));
    if (li != NULL) *li = NULL;
    return li;
}
/*
void createListV2(Descriptor* d) {
    Ship *start = NULL;
    Ship *end = NULL;
    int quant = 0;
}

int addAtBeginningV2(Descriptor* li, struct ship s) {
    Ship *newShip = (Ship*)malloc(sizeof(Ship));
    newShip->data = s;
    newShip->next = li->start;
    if (li->start == NULL && li->end == NULL) {
        li->start = newShip;
        li->end = newShip;
        li->quant += 1;
    }else {
        if (li->quant == 1) li->end = li->start;
        li->start = newShip;
        li->quant += 1;
    }
    return 1;
}

int addAtEndV2(Descriptor* li, struct ship s) {
    Ship *newShip = (Ship*)malloc(sizeof(Ship));
    newShip->data = s;
    newShip->next = li->start; // ???
    if (li->start == NULL && li->end == NULL) {
        li->start = newShip;
        li->end = newShip;
        li->quant += 1;
    }else {
        li->end->next = newShip;
        li->end = newShip;
        newShip->next = li->start; // para ser lista circular;
        li->quant += 1;
    }
    return 1;
}
*/

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

int quantCycles(Ships* li, int fuel) {
    if (li == NULL) return 0;
    Ship *aux = *li;
    Ship *shipN = *li; // nave que mais precisa abastecer;
    int dif;
    do {
        dif = aux->data.maxCapacity - aux->data.currentFuel; // diferença entre combustivel atual e capacidade;
        if (dif > (shipN->data.maxCapacity - shipN->data.currentFuel)) {
            shipN = aux;
        }
        aux = aux->next;
    }while (aux!=(*li));
    const int cycles = (shipN->data.maxCapacity - shipN->data.currentFuel)/fuel;
    return cycles;
}

/* versão 1 da função cycle (horrível)
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
            if (aux->next == (*li) && verify == quantShips) { // se o programa for parar quando verificar o while e o "verify" nao for decrementado, então todas as naves estão cheias
                break;
            }
            aux = aux->next;
        }while (aux != (*li));
    }while (verify != quantShips); // será verdadeira quando não entrar no if nenhuma vez;
    return 1;
}
*/

int cycles(Ships* li, int fuel, int quantCycles) {
    if (li == NULL) return 0;
    Ship *aux = *li;
    int verify = quantCycles; // verificador recebe a quantidade de ciclos necessária para encher as naves
    do {
        if ((aux->data.currentFuel+fuel) <= aux->data.maxCapacity ) {
            aux->data.currentFuel += fuel;
        }
        if (aux->next == (*li)) { // decrementa 1 após cada ciclo;
            //if (verify == 0) break; // verifica se os ciclos acabaram;
            verify--;
        }
        aux = aux->next;
    }while (aux != (*li) || verify > 0);
    return 1;
}


// -------- FUNÇÕES EXTRAS -----------
int insertAtBeginning(Ships* li, struct ship s){
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

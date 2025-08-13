#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct ship{ // struct de cada nave;
    int maxCapacity;
    int currentFuel;
};
typedef struct elem* Ships; // Ships é a lista;

typedef struct elem { // elementos da lista;
    struct ship data;
    struct elem *next;
} Ship;

// função cria lista
Ships* createList();

// funções de inserção;
int insertAtBeginning(Ships* li, struct ship s); // função extra
int insertAtEnd(Ships* li, struct ship s); // função extra
int insertNeatly(Ships* li, struct ship s); // ordena pela capacidade maxima de forma crescente;

// funções de remoção;
int removeFromBeginning(Ships* li); // função extra
int removeFromEnd(Ships* li); // função extra
int removeElement(Ships* li, int maxCapacity); // função extra

// função para imprimir lista circular
void printList(Ships* li);

// função que calcula quantidade de ciclos necessários para encher todas as naves.
int quantCycles(Ships* li, int fuel);

// função para abastecer as naves
int cycles(Ships* li, int fuel, int quantCycles);

#endif //FUNCTIONS_H

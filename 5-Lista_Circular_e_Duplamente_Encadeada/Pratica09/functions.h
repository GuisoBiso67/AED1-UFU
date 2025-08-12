#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct ship{ // struct de cada nave
    int maxCapacity;
    int currentFuel;
};
typedef struct elem* Ships;

typedef struct elem { // elementos da lista
    struct ship data;
    struct elem *next;
} Ship;

// função cria lista
Ships* createList();

// funções de inserção;
int insertAtBeginning(Ships* li, struct ship s);
int insertAtEnd(Ships* li, struct ship s);
int insertNeatly(Ships* li, struct ship s); // ordena pela capacidade maxima de forma crescente;

// funções de remoção;
int removeFromBeginning(Ships* li);
int removeFromEnd(Ships* li);
int removeElement(Ships* li, int maxCapacity);

// função para imprimir lista circular
void printList(Ships* li);

// função para abastecer as naves
int cycle(Ships* li, int fuel, int quantShips);

#endif //FUNCTIONS_H

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct element{
    int data;
    struct element *before; // ponteiro antes
    struct element *next; // ponteiro próximo
};
typedef struct element Elem; // Nó
typedef struct element* List; // Lista

List* concat(List* liA, List* liB);

#endif //FUNCTIONS_H

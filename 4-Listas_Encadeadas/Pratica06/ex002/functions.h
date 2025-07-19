#ifndef FUNCTIONS_H
#define FUNCTIONS_H
// Definição da estrutura Nó para encadeamento de inteiros;
struct node {
    int item;
    struct node* next;
};
// Definição do tipo No;
typedef struct node Node;

Node* createEmptyList();
Node* insertAtBeginning(Node *l, int elem);

void printList(Node *l);

int isEmptyList(Node *l);
Node* randomNumbers(Node *l);
Node* removeElement(Node *l, int elem);
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "functions.h"

// Função para criar uma lista vazia
Node* createEmptyList(){
    return NULL;
}

// Função para inserir um elemento na lista
Node* insertAtBeginning(Node *l, int elem){
    Node* new;
    new = (Node*) malloc (sizeof(Node));
    if (new == NULL) return new;

    new->item= elem;
    new->next = l;
    return new;
}

void printList(Node *l) {
    if (l == NULL) return;
    Node *p = l;
    while (p != NULL) {
        printf("%d ", p->item);
        p = p->next;
    }
    printf("\n");
}

// a) função que verifica se lista eh vazia;
int isEmptyList(Node *l) {
    if (l == NULL) return 1;
    else return 0;
}

// b) inserir valores aleatórios entre (0 e 20) no início;
Node* randomNumbers(Node *l) {
    for (int i=0;i<20;i++) {
        int elem = rand() % 20; // gera numeros aleatorios;
        l = insertAtBeginning(l, elem);
    }
    return l;
}

// c) remover um determinado valor (remove apenas a primeira ocorrência deste valor);
Node* removeElement(Node *l, int elem) {
    if (l == NULL) return l;
    int found=0;
    Node *before = NULL;
    Node *current = l;
    while (current != NULL) {
        if (current->item == elem) { // elemento encontrado;
            found = 1;
            break;
        }
        else {
            before = current;
            current = current->next;
        }
    }
    if (found == 1) {
        if (current == l) {
            l = l->next; // primeiro elemento da lista;
        }else{
            before->next = current->next; // elemento em qualquer outra posição;
        }
        free(current);
    }
    else printf("Elemento nao encontrado\n");
    return l;
}

// d) remover o maior elemento da lista (faça a função que encontra o maior separadamente);
int biggestNumber(Node *l) {
    if (l == NULL) return 1;
    Node* aux = l;
    int biggest = l->item;
    while (aux != NULL) {
        if (aux->item > biggest) biggest = aux->item;
        aux = aux->next;
    }
    return biggest;
}

Node* removeBiggestNumber(Node *l, const int elem) {
    if (l == NULL) return l;
    removeElement(l, elem);
}

// e) retornar apenas os elementos pares em uma nova lista encadeada (a função par deve ser implementada separadamente);
int isEvenNumber(const int number) {
    if (number % 2 == 0) return 1;
    else return 0;
}

Node* listOfEvens(Node *l) {
    if (l == NULL) return l;
    Node *listOfEvens = createEmptyList();
    Node *p = l;
    while (p->next != NULL) {
        if (isEvenNumber(p->item)) {
            listOfEvens = insertAtBeginning(listOfEvens, p->item);
        }
        p = p->next;
    }
    return listOfEvens;
}

// f) contar o número de elementos da lista (criar duas soluções, uma iterativa e outra recursiva);
int numberOfElementsIterative(Node *l) {
    if (l == NULL) return 0;
    Node *p = l;
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

int numberOfElementsRecursive(Node *l) {
    Node *p = l;
    if (p == NULL) return 0;
    else return 1 + numberOfElementsRecursive(p->next);
}

/* g) retornar todos os elementos da lista em um vetor, criado dinâmicamente (usar uma das funções que conta os
elementos da lista para a alocação dinâmica de memória do vetor); */
int* returnVector(Node *l, int tam) {
    if (l == NULL) return 0;
    Node *p = l;

    int *vector = (int*) malloc (sizeof(int) * tam);
    if (vector == NULL) return 0; // erro de alocação de memoria;

    int *start = vector; // guarda inicio do vetor

    while (p != NULL) {
        *vector = p->item;
        vector++;
        p = p->next;
    }

    return start;
}
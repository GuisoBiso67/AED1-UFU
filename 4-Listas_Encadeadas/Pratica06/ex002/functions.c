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

// e) retornar apenas os elementos pares em uma nova lista encadeada (a função par deve ser implementada separadamente);

// f) contar o número de elementos da lista (criar duas soluções, uma iterativa e outra recursiva);

/* g) retornar todos os elementos da lista em um vetor, criado dinâmicamente (usar uma das funções que conta os
elementos da lista para a alocação dinâmica de memória do vetor); */
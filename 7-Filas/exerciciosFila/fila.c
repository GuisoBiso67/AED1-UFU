#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Função para criar uma nova fila de prioridade
FilaPrioridade* criarFP() {
    FilaPrioridade* pq = (FilaPrioridade*)malloc(sizeof(FilaPrioridade));
    pq->inicio = NULL;
    return pq;
}

// Função para verificar se a fila está vazia
int vazia(FilaPrioridade* pq) {
    return pq->inicio == NULL;
}

// Função para inserir um novo elemento na fila
void inserir(FilaPrioridade* pq, int valor, int priori) {
    No* novo = (No*) malloc (sizeof(No));
    novo->item = valor;
    novo->prioridade = priori;
    novo->prox = pq->inicio;
    pq->inicio = novo;
}

void imprime(FilaPrioridade* pq) {
    No* aux = pq->inicio;
    while (aux != NULL) {
        printf("%d ", aux->item);
        aux = aux->prox;
    }
    printf("\n");
}

void elem(FilaPrioridade* pq) {
    int contP=0, contI=0;
    while (!vazia(pq)) {
        int number = retirar(pq);
        if (number%2 == 0) {
            contP++;
        }else {
            contI++;
        }
    }
    printf("Elementos Pares: %d\n",contP);
    printf("Elementos Impares: %d\n",contI);
}

// Função para remover e retornar o elemento de maior prioridade
int retirar(FilaPrioridade* pq) {
    if (vazia(pq)) {
        printf("A fila está vazia!\n");
        return -1;
    }

    No* atual = pq->inicio;
    No* maxNo = atual;
    No* maxNoAnt = NULL;
    No* prev = NULL;

    // Percorre a lista para encontrar o nó com a maior prioridade
    while (atual != NULL) {
        if (atual->prioridade > maxNo->prioridade) {
            maxNo = atual;
            maxNoAnt = prev;
        }
        prev = atual;
        atual = atual->prox;
    }

    // Remove o nó com a maior prioridade
    if (maxNoAnt == NULL) {
        pq->inicio = maxNo->prox;       // O de maior prioridade é o primeiro
    } else {
        maxNoAnt->prox = maxNo->prox;
    }

    int val = maxNo->item;
    free(maxNo);
    return val;
}

// Função para liberar a memória da fila
void liberarFP(FilaPrioridade* pq) {
    No* atual = pq->inicio;
    No* proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(pq);
}

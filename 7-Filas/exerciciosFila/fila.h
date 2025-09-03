#ifndef FILA_H
#define FILA_H

// Definição da estrutura do nó
typedef struct no {
    int item;            // Dados a serem armazenados
    int prioridade;      // Prioridade do dado
    struct no* prox;     // Ponteiro para o próximo nó
} No;

// Definição da estrutura da fila de prioridade
typedef struct FilaPrioridade {
    No* inicio; // Ponteiro para o início da fila
} FilaPrioridade;

FilaPrioridade* criarFP();
int vazia(FilaPrioridade* pq);
void liberarFP(FilaPrioridade* pq);
void inserir(FilaPrioridade* pq, int valor, int priori);
int retirar(FilaPrioridade* pq);
void imprime(FilaPrioridade* pq);
void elem(FilaPrioridade* pq);

#endif //FILA_H

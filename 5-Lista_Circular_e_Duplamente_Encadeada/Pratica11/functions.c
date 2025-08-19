#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctype.h>
//#include <time.h>
#include "functions.h"

void createList(Descriptor *li) {
    li->start = NULL;
    li->end = NULL;
    li->quant = 0;
}

void printList(Descriptor *li) {
    Person *aux = li->start;
    do {
        printf("%s, ", aux->name);
        aux = aux->next;
    }while (aux != li->start);
    printf("\n");
    printf("Inicio: %s\n",li->start->name);
    printf("Fim: %s\n",li->end->name);
    printf("Quantidade: %d\n",li->quant);
}

int insertAtBeginning(Descriptor *li, char* name) {
    if (li == NULL) return 0; // lista não existe
    Person *newPerson = (Person*)malloc(sizeof(Person));
    strcpy(newPerson->name, name);

    if (li->start == NULL && li->end == NULL) { // lista vazia
        newPerson->next = newPerson;
        newPerson->prev = newPerson;
        li->start = newPerson;
        li->end = newPerson;
        li->quant += 1;
        return 1;
    }

    newPerson->next = li->start;
    newPerson->prev = li->end;
    li->end->next = newPerson;
    li->start->prev = newPerson;

    li->start = newPerson;
    li->quant += 1;
}

int removeNode(Descriptor *li, char* name) {
    if (li == NULL) return 0;
    if (li->start == NULL && li->end == NULL) return 0; // lista vazia
    if (li->start == li->end) { // lista com 1 elemento
        if (strcmp(li->start->name, name) == 0) { // nao sei se ta certo isso aqui embaixo
            free(li->start);
            li->start = NULL;
            free(li->end);
            li->end = NULL;
            li->quant -= 1;
        }
        else return 0;
    }

    Person *aux = li->start;
    do {
        if (strcmp(aux->name, name) == 0) break;
        aux=aux->next;
    }while (aux != li->start);

    if (aux == li->start) { // se o primeiro nó precisar ser removido
        li->start = li->start->next;
        li->start->prev = li->end;
        li->end->next = li->start;
        free(aux);
        li->quant -= 1;
        return 1;
    }
    if (aux == li->end) {
        li->end = li->end->prev;
        li->end->next = li->start;
        li->start->prev = li->end;
        free(aux);
        li->quant -= 1;
        return 1;
    }
    aux->next->prev = aux->prev;
    aux->prev->next = aux->next;
    li->quant -= 1;
    free(aux);
    return 1;
}

char* firstPersonWithBox(Descriptor *li, int a) {
    if (li == NULL) return NULL; // lista nao existe
    if (li->start == NULL && li->end == NULL) return NULL; // lista vazia
    if (li->start == li->end) {
        li->box = li->start;
        return li->box->name;
    }
    Person *aux = li->start;
    for (int i=0; i < a; i++) {
        aux = aux->next;
    }
    li->box = aux;
    return li->box->name;
}

// percurso a esquerda; passa caixa para pessoa a direita
char* goForward(Descriptor *li, int k) {
    Person *aux = li->box;
    for (int i=0;i<k-1;i++) {
        aux = aux->next;
    }
    li->box = aux->prev; // pessoa da direita fica com a caixa;
    return aux->name;
}

// percurso para direita; passa caixa para pessoa a esquerda
char* goBackward(Descriptor *li, int k) {
    Person *aux = li->box;
    for (int i=0;i<k-1;i++) {
        aux = aux->prev;
    }
    li->box = aux->next; // pessoa da esquerda fica com a caixa
    return aux->name;
}

char* chooseLeader(Descriptor *li, int k) {
    if (li == NULL) return NULL;
    if (li->start == NULL && li->end == NULL) return NULL;
    if (li->start == li->end) return li->box->name; // "circulo" com uma pessoa ela é o líder

    while (li->start != li->end) {
        char* eliminated = goBackward(li, k);
        removeNode(li, eliminated);
        if (li->start == li->end) break; // para o caso de ter apenas 1 após o goBackward;

        char* eliminated2 = goForward(li, k);
        removeNode(li, eliminated2);
    }
    return li->box->name;
}

// função extra, peguei a função e adaptei de um exercício da professora;
void carregar_nome_arquivo(Descriptor* li, const char* nomeArquivo) {
    //char* name;
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[200]; // Buffer para armazenar cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Remover o caractere de nova linha
        linha[strcspn(linha, "\n")] = '\0';
        insertAtBeginning(li, linha);// Inserir na lista
    }

    fclose(arquivo);
}

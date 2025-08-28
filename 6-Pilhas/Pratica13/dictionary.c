#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

//Definição do tipo lista
//void trim(char *str);

Descriptor* create_list() {
    Descriptor* d = (Descriptor*) malloc(sizeof(Descriptor));
    if(d == NULL) return NULL; // erro de alocação;
    d->start = NULL;
    d->end = NULL;
    d->quantity = 0;
    return d;
}

int insert_word(Descriptor* d, Entry e) {
    if (d == NULL) return 0;
    Node *newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL) return 0;

    newNode->data = e;
    newNode->next = NULL;
    if (d->start == NULL && d->end == NULL) { // primeira palavra
        d->start = newNode;
        d->end = newNode;
        d->quantity++;
        return 1;
    }

    Node *current = d->start;
    Node *previous = NULL;
    while (current != NULL && strcmp(current->data.word, newNode->data.word) < 0) { // encontra posição em que vai colocar a palavra
        previous = current;
        current = current->next;
    }

    if (current == NULL) { // insere no final;
        previous->next = newNode;
        d->end = newNode;
        d->quantity++;
        return 1;
    }
    if (previous == NULL) { // insere no inicio;
        newNode->next = d->start;
        d->start = newNode;
        d->quantity++;
        return 1;
    }
    // inserir no meio;
    newNode->next = current;
    previous->next = newNode;
    d->quantity++;
    return 1;
}

void show_dictionary(Descriptor* d) {
    if (d==NULL || d->start == NULL || d->end == NULL) {
        printf("Dicionario vazio!\n"); return;
    }
    Node *current = d->start;
    while (current != NULL) {
        printf("------------------------------------------------------------\n");
        printf("| %s (%s): ",current->data.word, current->data.classification);
        printf("%s\n", current->data.meaning);
        current = current->next;
    }
    printf("\n| Quantidade: %d\n", d->quantity);
}

void search_word(Descriptor* d, const char* word) {
    if (d==NULL || d->start == NULL || d->end == NULL) {
        printf("Dicionario vazio!\n"); return;
    }
    Node *current = d->start;
    while (current != NULL) {
        if (strcmp(current->data.word, word) == 0) {
            printf("| %s (%s): ",current->data.word, current->data.classification);
            printf("%s\n", current->data.meaning);
            return;
        }
        current = current->next;
    }
    printf("Palavra nao cadastrada!\n");
}

int load_words(Descriptor* d, const char* fileName) {
    Entry w;
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    char linha[200]; // Buffer para armazenar cada linha do arquivo
    while (fgets(linha, sizeof(linha), file)) {
        // Remover o caractere de nova linha
        linha[strcspn(linha, "\n")] = '\0';

        strcpy(w.word, strtok(linha, ";"));
        strcpy(w.classification, strtok(NULL, ";"));
        strcpy(w.meaning, strtok(NULL, ";"));
        trim(w.word);
        trim(w.classification);
        trim(w.meaning);
        insert_word(d, w); // Inserir na lista
    }
    fclose(file);
    return 1;
}

/*
void freeList(Descriptor* d) {
    if (d==NULL) return;
    Node *current = d->start;
    while (current != NULL) {
        free(current);
        current = current->next;
    }
}
*/

void trim(char *str) {
    char *start, *end;
    // Encontrar o primeiro caractere que não é espaço em branco
    start = str;
    while (*start && isspace((unsigned char)*start)) {
        start++;
    }
    // Se a string estiver vazia, retorna
    if (*start == 0) {
        *str = '\0';
        return;
    }
    // Encontrar o último caractere que não é espaço
    end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) {
        end--;
    }
    // Adiciona o caractere nulo após o último caractere que não é espaço
    *(end + 1) = '\0';
    // Mover a string para o início da posição de memória original
    if (start != str) {
        memmove(str, start, end - start + 2);
    }
}
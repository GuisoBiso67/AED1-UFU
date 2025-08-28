#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"
#include "battery.h"

DescriptorBattery* create_battery_list() {
    DescriptorBattery* d = malloc(sizeof(DescriptorBattery));
    if(d == NULL) return NULL; // erro de alocação;
    d->start = NULL;
    d->end = NULL;
    d->quantity = 0;
    return d;
}

void initBattery(Battery *b){
    b->top = NULL;
    b->size = -1;
}

int empty(Battery *b) {
    return (b->top == NULL);
}

int stack(Battery *b, const char* word){ // função empilhar;
    NodeB *aux = malloc(sizeof(NodeB));
    strcpy(aux->word, word);
    aux->next = b->top;
    b->top = aux;
    b->size++;
    return 1;
}

void unstack(Battery *b, char* word) {
    if (empty(b)) {
        printf("Lista Vazia!"); return;
    }
    NodeB *q;
    q = b->top; // q auxiliar armazena o top;
    b->top = q->next; // top agora é a camada de baixo;
    strcpy(word, q->word); // copia a palavra do q para um char auxiliar;
    free(q); // libera q;
    b->size--; // decrementa quantidade;
}


int insert_in_descriptor(DescriptorBattery* d, Battery* b) {
    if (d == NULL) return 0;
    if (d->end == NULL && d->start == NULL) { // primeira pilha
        d->start = b;
        d->end = b;
        d->quantity++;
        return 1;
    }
    d->end->next = b; // insere ao final da lista de pilhas;
    d->end = b;
    //d->end->next = NULL;
    d->quantity++;
    return 1;
}

int load_phrases(DescriptorBattery* db, const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    char word[20];
    char linha[200]; // Buffer para armazenar cada linha do arquivo
    char linhaTemp[200];
    while (fgets(linha, sizeof(linha), file)) {
        // Remover o caractere de nova linha
        linha[strcspn(linha, "\n")] = '\0';
        strcpy(linhaTemp, linha); // copia para uma linha temporária;
        Battery *aux = malloc(sizeof(Battery)); // ele acusa de vazar memoria aqui, mas se eu liberar o aux nessa função, o descritor não é preenchido, nao consegui resolver;
        initBattery(aux);

        char* token = strtok(linhaTemp, " ");
        while (token != NULL) { // sei la;
            strcpy(word, token);
            trim(word);
            stack(aux, word); // inserir palavra na bateria
            token = strtok(NULL, " ");
        }
        insert_in_descriptor(db, aux); // Inserir na lista de baterias;
        //free(aux);
    }
    fclose(file);
    return 1;
}

void show_battery(Battery* b, Descriptor* d) {
    if (b == NULL) printf("Pilha vazia!\n");
    char word[20];
    while (!empty(b)) {
        unstack(b, word);
        search_word(d, word);
        //printf("%s ",word);
    }
}

void show_all_batteries(DescriptorBattery* db, Descriptor* d) { // imprime ao contrario mesmo;
    if (db == NULL) {
        printf("DescriptorBatteries vazio!\n"); return;
    }
    if (db->start == NULL && db->end == NULL) {
        printf("DescriptorBatteries vazio!\n"); return;
    }
    Battery *aux = db->start;
    int i=0;
    printf("\n");
    while (aux != NULL) {
        printf("Frase %d:\n",i+1);
        show_battery(aux, d);
        printf("\n");
        //printf("Palavras:\n");

        aux = aux->next;
        i++;
    }
    free_descriptor(db);
}

void free_descriptor(DescriptorBattery* d) {
    if (d == NULL) return;
    Battery* current = d->start;
    while (current != NULL) {
        Battery* next = current->next;

        // libera cada nó da pilha
        NodeB* node = current->top;
        while (node != NULL) {
            NodeB* tmp = node;
            node = node->next;
            free(tmp);
        }

        // libera a bateria
        free(current);
        current = next;
    }
    d->start = NULL;
    d->end = NULL;
    d->quantity = 0;
}


/*
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
*/

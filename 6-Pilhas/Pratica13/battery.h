#ifndef BATTERY_H
#define BATTERY_H

/*
 * Iniciar a pilha ok
 * Verificar se a pilha esta vazia (empty) ok
 * Retornar o elemento que esta no topo da pilha (top) ?
 * Inserir um elemento no topo da pilha (push) ok
 * Retirar um elemento do topo da pilha (pop) ok
*/

struct nodeB { // "camada" da pilha
    char word[20];
    struct nodeB *next; // aponta para a camada de cima
};
typedef struct nodeB NodeB;

struct battery { // pilha completa
    struct battery *next; // aponta para a proxima pilha;
    NodeB *top;
    int size;
};
typedef struct battery Battery;

typedef struct {
    Battery *start;
    Battery *end;
    int quantity;
} DescriptorBattery;

DescriptorBattery* create_battery_list();
void initBattery(Battery *b);
int empty(Battery *b);
int stack(Battery *b, const char* word);
void unstack(Battery *b, char* word);
int load_phrases(DescriptorBattery* db, const char* fileName);
int insert_in_descriptor(DescriptorBattery* d, Battery* b);
void show_battery(Battery* b, Descriptor* d);
void show_all_batteries(DescriptorBattery* db, Descriptor* d);
void free_descriptor(DescriptorBattery* d);

#endif //BATTERY_H

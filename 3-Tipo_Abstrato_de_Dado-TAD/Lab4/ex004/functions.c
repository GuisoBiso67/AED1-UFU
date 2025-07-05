#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "functions.h"

struct element{
    struct products data; 
    struct element *next; // ponteiro que aponta para o proximo nó da lista;
};
typedef struct element Elem;

// criar lista
List* createList(){
    List* li = (List*) malloc(sizeof(List)); // guarda o endereço do primeiro nó da lista, ou seja, o inicio da lista;
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

// inserir elemento na lista;
int insertListAtEnd(List* li, struct products prod){
    if(li == NULL) return 0;
    Elem *node = (Elem*) malloc(sizeof(Elem));
    if(node == NULL) return 0; // retorna 0 pq é o final da lista;
    node->data = prod;
    node->next = NULL;
    if((*li) == NULL){ // caso a lista esteja vazia, insere no início;
        *li = node; // node é o primeiro elemento da lista
    }else{
        Elem *aux = *li; // usa um ponteiro auxiliar para não perder a referencia do primeiro elemento;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = node;
    }
    return 1;
}

// encontra produto com menor preço;
int searchCheapProduct(List* li, struct products *prod){
    if(li == NULL) return 0; // verifica se a lista existe;
    Elem *node = *li; // primeiro nó;
    Elem *node2 = node->next; // nó seguinte;
    Elem *cheaperNode; // nó com o menor preço;
    if(node2 == NULL){
        *prod = node->data; // se node2 é NULL, a lista tem apenas 1 elemento;
        return 1;
    }
    while(node2 != NULL){
        if(node->data.value >= node2->data.value){
            cheaperNode = node2;
        }else{
            cheaperNode = node;
        }
        node = node2;
        node2 = node->next;
    }
    *prod = cheaperNode->data;
    return 1;
}

// imprime a lista;
void printList(List *l){
    Elem *node = *l;
    int i=0;

    printf("\n---LISTA DE PRODUTOS---\n");
    while(node != NULL){
        printf("--- Produto %d ---\n",i+1);
        printf("Codigo: %d\n", node->data.codProd);
        printf("Nome: %s", node->data.nameProd); // sem \n pq o fgets ja tem;
        printf("Valor: R$%.2f\n", node->data.value);
        printf("Quantidade no Estoque: %d\n", node->data.quantStock);
        i++;
        node = node->next; // avança para o proximo produto;
    }
}

// imprime qual o produto de menor preço;
void printCheaperProduct(struct products *prod){
    printf("\n---Produto Mais Barato---\n");
    printf("Codigo: %d\n", prod->codProd);
    printf("Nome: %s\n", prod->nameProd);
    printf("Valor: R$%.2f\n", prod->value);
    printf("Quantidade no Estoque: %d\n", prod->quantStock);
}

// vende produto;
int sellProduct(List* li, char *nameProd, int quant){
    Elem *node = *li;
    while(node != NULL && strcmp(node->data.nameProd, nameProd) != 0){
        node = node->next;
    }
    if(node == NULL){
        printf("Produto nao encontrado :(\n");
    }
    if(node->data.quantStock >= quant){
        node->data.quantStock -= quant;
        printf("Venda Realizada!\n");
        printf("Produto: %s\n", nameProd);
        printf("Quantidade Comprada: %d\n", quant);
        printf("Quantidade do Estoque: %d\n", node->data.quantStock);
    }else{
        printf("Nao foi possivel fazer a compra. Estoque insuficiente!\n");
    }
}


// FUNÇÕES EXTRAS:
void freeList(List* li){
    if(li != NULL){
        Elem* node; // node = nó da lista;
        while((*li) != NULL){
            node = *li;
            *li = (*li)->next;
            free(node);
        }
        free(li); // libera a "cabeça" da lista;
    }
}

int sizeList(List* li){
    if(li == NULL) return 0;
    int count = 0;
    Elem* node = *li; // 'node' é um ponteiro auxiliar para não perder a cabeça da lista;
    while(node != NULL){
        count++;
        node = node->next;
    }
    return count;
}
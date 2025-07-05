#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

struct products{
    int codProd;        //código do produto
    char nameProd[10];  //nome do produto
    float value;        //valor do produto
    int quantStock;    //quantidade disponível em estoque
};
typedef struct element* List;

List* createList();
int insertListAtEnd(List* li, struct products prod);
void printList(List *l);
int searchCheapProduct(List* li, struct products *prod);
void printCheaperProduct(struct products *prod);
int sellProduct(List* li, char *nameProd, int quant);

// FUNÇÕES EXTRAS:
void freeList(List* li); // função para liberar memoria usada na lista;
int sizeList(List* li); // função que retorna o tamanho da lista;
#endif
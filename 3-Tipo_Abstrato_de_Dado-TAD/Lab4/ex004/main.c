#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "functions.h"

/*
    NÃO TENHO CERTEZA SE ERA EXATAMENTE DESSE JEITO QUE DEVERIA RESOLVER ESSE EXERCÍCIO. NÃO ESTAVA ENTENDENDO PELO MATERIAL DO MOODLE E SEGUI OS VÍDEOS DE LISTA DINÂMICA DO BACKES;

    Produtos para inserir de exemplo:

    1001
    Tomate
    2.99
    500
    
    1002
    Uva
    9.99
    200
    
    1003
    Arroz
    10.99
    100
    
    1004
    Suco
    4.99
    200
    
    1005
    Chocolate
    2.99
    50
    
*/

int main(){
    List *listOfProducts; // *lProducts é um ponteiro para um ponteiro que aponta para o struct Element;
    listOfProducts = createList();
    // freeList(vProducts);
    // int size = sizeList(vProducts);
    typedef struct products Product;
    Product productN;
    Product *cheaperProduct;
    
    int c;
    char choice='y';

    while(choice!='n'){
        printf("Codigo do Produto: ");
        scanf("%d", &productN.codProd);
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Nome do Produto: ");
        fgets(productN.nameProd, 10, stdin);
        printf("Valor do Produto: ");
        scanf("%f", &productN.value);
        printf("Quantidade em Estoque do Produto: ");
        scanf("%d", &productN.quantStock);
        while ((c = getchar()) != '\n' && c != EOF);
        int x = insertListAtEnd(listOfProducts, productN);

        printf("Inserir mais algum produto?(y/n): ");
        scanf("%c",&choice);
    }
    printList(listOfProducts);
    searchCheapProduct(listOfProducts, cheaperProduct);
    printCheaperProduct(cheaperProduct);

    char selling;
    int quant;

    while ((c = getchar()) != '\n' && c != EOF);
    printf("Quer comprar algum produto?(y/n): ");
    scanf("%c", &selling);
    while ((c = getchar()) != '\n' && c != EOF);
    while(selling!='n'){
        printf("Nome: ");
        fgets(productN.nameProd, 10, stdin);
        printf("Quantidade: ");
        scanf("%d", &quant);
        int s = sellProduct(listOfProducts, productN.nameProd, quant);

        printf("Quer comprar algum produto?(y/n): ");
        scanf("%c", &selling);
        while ((c = getchar()) != '\n' && c != EOF);
    }
}
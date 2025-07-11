#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "livros.h"

/*
void cleanBuffer(char c){
    while ((c = getchar()) != '\n' && c != EOF);
}
*/

Book *emptyList(int size){
    Book *l;
    l = (Book *) malloc(sizeof(Book));
    if (l != NULL){
        l = (Book *) malloc(size * sizeof(Book));
        return l;
    } else return NULL;
}

Book *insertNewBook(Book* li, struct book book, int pos, int *maxSize){
    int newSize;

    if(pos>=(*maxSize)){
        newSize = pos+1;
        li = (Book *) realloc(li, (newSize)*sizeof(Book));
    }
    strcpy(li[pos].title, book.title);
    strcpy(li[pos].author, book.author);
    li[pos].year = book.year;
    li[pos].price = book.price;

    *maxSize = newSize;
    return li;
}

// sei la
Book *removeBook(Book* li, char *nameBook, int *maxSize){
    int i=0;
    int newSize;
    while(strcmp(li[i].title, nameBook) != 0){
        i++;
        continue;
    }

    for(i;i<(*maxSize);i++){
        strcpy(li[i].title, li[i+1].title);
        strcpy(li[i].author, li[i+1].author);
        li[i].year = li[i+1].year;
        li[i].price = li[i+1].price;
    }
    newSize = (*maxSize)-1;
    li = (Book *) realloc(li, (newSize)*sizeof(Book));
    *maxSize = newSize;
    //free(li[(*maxSize)]);

    return li;
}


void printBooks(Book* li, int capacity){
    printf("\n------Lista de Livros------");
    for(int i=0;i<capacity;i++){
        printf("\n---Livro %d---", i+1);
        printf("\nTitulo: %s",li[i].title);
        printf("Autor: %s", li[i].author); // ja tem \n na string
        printf("Ano: %d", li[i].year); // ja tem \n na string
        printf("\nPreco: %.2f\n", li[i].price);
    }
    printf("\n---------------------------");
}
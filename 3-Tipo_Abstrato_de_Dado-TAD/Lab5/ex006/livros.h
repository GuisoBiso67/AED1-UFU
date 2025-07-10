#ifndef _LIVROS_H
#define _LIVROS_H

struct book{
    char title[30], author[30];
    int year;
    float price;
};
typedef struct book Book;

//void cleanBuffer(char c);
Book *emptyList(int size);
Book *insertNewBook(Book* li, struct book book, int position, int *maxSize);
Book *removeBook(Book* li, char *nameBook, int *maxSize);
void printBooks(Book* li, int capacity);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "livros.h"

int main(){
    Book *listBooks;
    int maxSize;
    printf("Tamanho Desejado para a Lista: ");
    scanf("%d", &maxSize);
    listBooks = emptyList(maxSize);

    //int vInt, vFloat; // variavel para verificar entradas;
    int c;
    int option;
    Book bookN; // struct de livro auxiliar;
    int quant=0;

    printf("\n-------OPCOES-------");
    printf("\n1-Inserir Novo Livro");
    printf("\n2-Remover Livro");
    printf("\n3-Listar Livros");
    printf("\n0-Sair");
    printf("\n--------------------\n");
    printf("Opcao: ");
    scanf("%d", &option);
    while ((c = getchar()) != '\n' && c != EOF);

    while(option!=0){
        switch (option){
            case 1:
                printf("Titulo: ");
                fgets(bookN.title, 30, stdin);

                printf("Autor: ");
                fgets(bookN.author, 30, stdin);

                printf("Ano: ");
                scanf("%d", &bookN.year);

                // nao consegui verificar as entradas;
                /*
                while(vInt != 1){ // verifica de eh inteiro;
                    printf("\nEntrada invalida. Insira um numero inteiro: ");
                    vInt = scanf("%d", &bookN.year);
                }
                */

                printf("Preco: ");
                scanf("%f", &bookN.price);

                // nao consegui verificar as entradas;
                /*
                while(fmod(vFloat, 1) == 0){ // verifica se eh float;
                    printf("\nEntrada invalida. Insira um valor float: ");
                    vFloat = scanf("%f", &bookN.price);
                }
                */

                listBooks = insertNewBook(listBooks, bookN, quant, &maxSize);
                quant++;
                break;
            case 2:
                printf("Titulo: ");
                fgets(bookN.title, 30, stdin);
                listBooks = removeBook(listBooks, bookN.title, &maxSize);
                break;
            case 3:
                printBooks(listBooks, maxSize);
                break;
            default:
                printf("Opcao Invalida. Selecione outra opcao\n");
        }

        printf("\n-------OPCOES-------");
        printf("\n1-Inserir Novo Livro");
        printf("\n2-Remover Livro");
        printf("\n3-Listar Livros");
        printf("\n0-Sair");
        printf("\n--------------------\n");
        printf("Opcao: ");
        scanf("%d", &option);
        while ((c = getchar()) != '\n' && c != EOF);
    }
}
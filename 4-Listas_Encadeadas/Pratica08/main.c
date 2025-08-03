#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    Descriptor list;
    initList(&list);

    // testando addAt
    addAtBeginning(&list, 1);
    addAtEnd(&list, 2);
    addAtBeginning(&list, 3);
    addAtEnd(&list, 4);
    addAtBeginning(&list, 5);
    addAtEnd(&list, 6);
    addAtBeginning(&list, 7);
    addAtEnd(&list, 8);
    addAtBeginning(&list, 9);
    addAtEnd(&list, 10);
    showList(&list);

    // testeando removeFrom
    printf("\n--------------------\n");
    removeFromBeginning(&list);
    removeFromEnd(&list);
    showList(&list);

    // testando as condições do removeElement
    printf("\n--------------------\n");
    removeElement(&list, 5);
    showList(&list);
    printf("\n--------------------\n");
    removeElement(&list, 7);
    showList(&list);
    printf("\n--------------------\n");
    removeElement(&list, 8);
    showList(&list);
}

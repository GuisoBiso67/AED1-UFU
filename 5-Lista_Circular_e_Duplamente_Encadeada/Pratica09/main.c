#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    Ships *li;
    li = createList();

    int ships;
    printf("Quantidade de Naves: ");
    scanf("%d", &ships);
    int *vetFuelCapacity, *vetCurrentFuel;
    vetFuelCapacity = (int*) malloc(ships * sizeof(int));
    vetCurrentFuel = (int*) malloc(ships * sizeof(int));

    printf("Capacidade de combustivel das naves: ");
    for (int i = 0; i < ships; i++) {
        scanf("%d", &vetFuelCapacity[i]);
    }
    printf("Combustivel inicial das naves: ");
    for (int i = 0; i < ships; i++) {
        scanf("%d", &vetCurrentFuel[i]);
    }

    printf("Quantidade de combustivel por ciclo: ");
    int fuel;
    scanf("%d", &fuel);

    for (int i = 0; i < ships; i++) {
        struct ship n;
        n.maxCapacity = vetFuelCapacity[i];
        n.currentFuel = vetCurrentFuel[i];
        insertNeatly(li,n);
    }

    // lembrando que ele imprime a lista em ordem crescente conforme a capacidade do combustível;
    printf("\n---LISTA INICIAL---\n");
    printList(li);

    printf("\n\n---LISTA APOS O CICLO---\n");
    cycle(li, fuel, ships);
    printList(li);

    free(vetCurrentFuel);
    free(vetFuelCapacity);
}

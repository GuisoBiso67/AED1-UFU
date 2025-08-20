#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "playlist.h"

int main(){
    int i=0;
    char mus[100];
    Lista* li = cria_lista();
    srand(time(NULL));

    carregar_musicas_arquivo(li, "musicas.txt");

    imprime_lista(li);
    printf("\nTamanho: %d\n",tamanho_lista(li));

    printf("\nInforme a musica a ser procurada: ");
    scanf("%[^\n]", mus);
    busca_ant_prox(li, mus);

    printf("\nAvancar 10 posicoes: ");
    avancar_posicoes(li, 10);

    libera_lista(li);
    system("pause");
    return 0;
}


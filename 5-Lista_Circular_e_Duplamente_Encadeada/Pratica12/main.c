#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "playlist.h"

int main(){
    int i=0, op;
    char mus[100];
    Musica m;
    Lista* li = cria_lista();
    srand(time(NULL));

    do {
        printf("\n\n----- MENU -----\n");
        printf("1 - Carregar playlist\n");
        printf("2 - Mostrar Playlist\n");
        printf("3 - Procurar Musica\n");
        // novas funções
        printf("4 - Inserir Nova Musica\n"); // colocar no txt ????
        printf("5 - Remover Musica\n");
        printf("6 - Procurar Compositor\n");
        printf("7 - Avancar N musicas\n");
        printf("8 - Retroceder N musicas\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 0:
                printf("Saindo...\n");
                break;
            case 1:
                const int loadingOK = carregar_musicas_arquivo(li, "musicas2.txt");
                if (loadingOK == 1) {
                    printf("Playlist carregada com sucesso!\n");
                }else {
                    printf("Nao foi possivel abrir a playlist!\n");
                }
                break;
            case 2:
                imprime_lista(li);
                printf("\nTamanho: %d\n",tamanho_lista(li));
                break;
            case 3:
                printf("\nInforme a musica a ser procurada: ");
                scanf("%[^\n]", mus);
                busca_ant_prox(li, mus);
                break;
            case 4:
                printf("Nome da Musica: ");
                scanf("%[^\n]", m.nome);
                getchar();
                printf("Artista: ");
                scanf("%[^\n]", m.artista);
                getchar();
                const int insertOK = inserir_musicaF(li, m);
                if (insertOK == 1) {
                    printf("Musica adicionada com sucesso!\n");
                }else {
                    printf("Nao foi possivel adicionar a musica!\n");
                }
                break;
            case 5:
                printf("Nome da Musica: ");
                scanf("%[^\n]", m.nome);
                getchar();
                printf("Artista: ");
                scanf("%[^\n]", m.artista);
                getchar();
                const int removeOK = remover_musica(li, m);
                if (removeOK == 1) {
                    printf("Musica removida!\n");
                }else if (removeOK == -1){
                    printf("Musica nao encontrada!\n");
                }else {
                    printf("Playlist Vazia!");
                }
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                printf("Opcao Invalida. Selecione outra acao");
                break;
        }
    }while (op !=0);

    libera_lista(li);
    system("pause");





    /*
    printf("\nAvancar 10 posicoes: ");
    avancar_posicoes(li, 10);

    libera_lista(li);
    system("pause");
    return 0;
    */
}


#ifndef PLAYLIST_H
#define PLAYLIST_H

struct musica{
    char nome[100];
    char composicao[100];
};
typedef struct musica Musica;

struct no{
    struct no *ant;
    Musica mpb;
    struct no *prox;
};
typedef struct no noMusica;
typedef struct no *Lista;

Lista* cria_lista();

void carregar_musicas_arquivo(Lista* li, const char* nomeArquivo);
void imprime_lista(Lista* li);
void avancar_posicoes(Lista* li, int qtd);
void busca_ant_prox(Lista* li, char *val);

int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
void libera_lista(Lista* li);

#endif //PLAYLIST_H

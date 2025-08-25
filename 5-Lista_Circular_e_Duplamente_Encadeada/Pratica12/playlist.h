#ifndef PLAYLIST_H
#define PLAYLIST_H

struct musica{
    char nome[100];
    char artista[100];
};
typedef struct musica Musica;

struct no{
    struct no *ant;
    Musica mpb;
    struct no *prox;
};
typedef struct no noMusica;
typedef struct no *Lista;

struct controle {
    struct no *playingNow;
};
typedef struct controle Controle;

Lista* cria_lista();

// funções originais
int carregar_musicas_arquivo(Lista* li, const char* nomeArquivo);
void imprime_lista(Lista* li);
void avancar_posicoes(Lista* li, int qtd);
void busca_ant_prox(Lista* li, char *val);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
void libera_lista(Lista* li);

// funções novas
int inserir_musicaF(Lista* li, Musica m); // insere musica no final da lista;
int remover_musica(Lista* li, Musica m); // remove musica da playlist;
int procurar_artista(Lista* li, char* artista);
int reproduzir_musica(Lista* li, Musica m, Controle *c);
void cria_lista_controle(Controle *c);

#endif //PLAYLIST_H

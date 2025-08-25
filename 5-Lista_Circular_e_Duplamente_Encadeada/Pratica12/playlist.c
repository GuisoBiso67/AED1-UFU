#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "playlist.h"

//Definição do tipo lista
void trim(char *str);
int insere_lista_inicio(Lista* li, Musica m1);

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));  // área para o "endereço do endereço" do início da lista
    if(li != NULL)
        *li = NULL;
    return li;
}

int carregar_musicas_arquivo(Lista* li, const char* nomeArquivo) {
    Musica mpbx;
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    char linha[200]; // Buffer para armazenar cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Remover o caracter de nova linha
        linha[strcspn(linha, "\n")] = '\0';

        // Separar nome da música e nome dos compositores
        strcpy(mpbx.artista, strtok(linha, "|"));
        strcpy(mpbx.nome, strtok(NULL, ";"));
        trim(mpbx.artista);
        trim(mpbx.nome);
        // inserir_musicaF(li, mpbx);
        inserir_musicaF(li, mpbx); // Inserir na lista duplamente encadeada
    }
    return 1;
    fclose(arquivo);
}

int insere_lista_inicio(Lista* li, Musica m1){
    if(li == NULL)
        return 0;
    noMusica* novo;
    novo = (noMusica*) malloc(sizeof(noMusica));
    if(novo == NULL)
        return 0;
    novo->mpb = m1;
    novo->prox = (*li);
    novo->ant = NULL;
    if(*li != NULL)   //lista não vazia: atualizar o ponteiro anterior do antigo primeiro!
        (*li)->ant = novo;
    *li = novo;
    return 1;
}

void avancar_posicoes(Lista* li, int qtd){
    int i=0;                   // contador para avançar posições
    noMusica* atual = *li;

    if(li == NULL) return;
    while(atual != NULL && i < qtd){  // controla a quantidade de passos
        atual = atual->prox;          // e o final da lista
        i++;
    }
    if (atual!=NULL){
        printf("\nDe: %s (%s) - ",(*li)->mpb.nome, (*li)->mpb.artista);
        printf("Para: %s (%s)\n",atual->mpb.nome, atual->mpb.artista);
        printf("-------------------------------\n");
    }
    else printf("\nFinal da Playlist!");
}


void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    noMusica* atual = *li;
    while(atual != NULL){
        printf("Nome: %s\n",atual->mpb.nome);
        printf("Composicao: %s\n",atual->mpb.artista);
        printf("-------------------------------\n");
        atual = atual->prox;
    }
}

void libera_lista(Lista* li){
    if(li != NULL){
        noMusica* atual;
        while((*li) != NULL){
            atual = *li;
            *li = (*li)->prox;
            free(atual);
        }
        free(li);
    }
}

void busca_ant_prox(Lista* li, char *val){
    int achou=0;
    if(li == NULL)    // lista não existe
        return;
    noMusica* atual = *li;
    while(atual != NULL){
        if (strcmp(atual->mpb.nome, val) == 0){
            achou = 1; break;
        }
        atual = atual->prox;
    }
    if (achou == 1){
        printf("<Anterior> ");
        if (atual->ant !=NULL)
            printf("Nome: %s\t Composicao: %s\n", atual->ant->mpb.nome, atual->ant->mpb.artista);
        else printf("NULO\n");
        printf("<Musica Encontrada> Nome: %s\t Composicao: %s\n",atual->mpb.nome, atual->mpb.artista);
        printf("<Proxima> ");
        if (atual->prox !=NULL)
            printf("Nome: %s\t Composicao: %s\n", atual->prox->mpb.nome, atual->prox->mpb.artista);
        else
            printf("NULO\n");
    }
    else printf("\nMusica nao encontrada!");
}


int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;   // inicia a contagem em zero
    noMusica* no = *li;
    while(no != NULL){
        cont++;     // para cada música, incrementa a contagem
        no = no->prox;
    }
    return cont;    // retorna a contagem final
}


int lista_vazia(Lista* li){
    if(li == NULL)   // não existe lista criada
        return 1;
    if(*li == NULL)  // lista vazia
        return 1;
    return 0;
}

void trim(char *str) {
    char *start, *end;

    // Encontrar o primeiro caractere que não é espaço em branco
    start = str;
    while (*start && isspace((unsigned char)*start)) {
        start++;
    }

    // Se a string estiver vazia, retorna
    if (*start == 0) {
        *str = '\0';
        return;
    }

    // Encontrar o último caractere que não é espaço
    end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) {
        end--;
    }

    // Adiciona o caractere nulo após o último caractere que não é espaço
    *(end + 1) = '\0';

    // Mover a string para o início da posição de memória original
    if (start != str) {
        memmove(str, start, end - start + 2);
    }
}



// --------- FUNÇÕES NOVAS ------------

int inserir_musicaF(Lista* li, Musica m) {
    if (li == NULL) return 0;
    noMusica *novo = (noMusica*)malloc(sizeof(noMusica));
    if(novo == NULL) return 0;

    if (*li == NULL) {
        novo->mpb = m;
        novo->ant = NULL;
        novo->prox = *li;
        *li = novo;
        return 1;
    }

    noMusica *aux = *li;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    novo->mpb = m;
    novo->ant = aux;
    novo->prox = NULL;
    aux->prox = novo;
    return 1;
}

int remover_musica(Lista* li, Musica m) {
    if (li == NULL || *li == NULL) return 0;
    noMusica *aux = *li;
    do {
        if ((strcmp(aux->mpb.nome, m.nome) == 0) && (strcmp(aux->mpb.artista, m.artista) == 0)) {
            break;
        }
        aux = aux->prox;
    }while (aux != NULL);

    if (aux == NULL) return -1;

    if (aux->ant == NULL) { // se for o primeiro elemento;
        *li = aux->prox;
        if (*li != NULL) { // se o elemento nao for o único;
            (*li)->ant = NULL;
        }
    } else if (aux->prox == NULL) { // remoção do último;
        aux->ant->prox = NULL;
    }else { // remoção padrão;
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }

    free(aux);
    return 1;
}

void cria_lista_controle(Controle *c) {
    c->playingNow = NULL;
}

int procurar_artista(Lista* li, char* artista) {
    if (li == NULL || *li == NULL) return 0;
    int cont = 0;
    noMusica *aux = *li;
    do {
        if (strcmp(aux->mpb.artista, artista) == 0) {
            printf("Nome: %s | Artista: %s\n", aux->ant->mpb.nome, aux->ant->mpb.artista);
            cont++;
        }
        aux = aux->prox;
    }while (aux != NULL);
    if (cont == 0) {
        printf("Nenhuma musica encontrada. Artista nao esta na playlist!");
        return 1;
    }
    printf("%d musicas encontradas do artista %s.\n",cont,artista);
    return 1;
}

int reproduzir_musica(Lista* li, Musica m, Controle *c) {
    if (li == NULL || *li == NULL) return 0;
    int achou = 0;
    noMusica *aux = *li;
    while (aux != NULL) {
        if ((strcmp(aux->mpb.nome, m.nome) == 0) && (strcmp(aux->mpb.artista, m.artista) == 0)) {
            achou = 1;
            break;
        }
        aux = aux->prox;
    }
    if (achou == 0) return 0;
    printf("<Tocando Agora> Musica: %s | Artista: %s\n", m.nome, m.artista);
    c->playingNow = aux;
    //printf("%s, %s\n", c->playingNow->mpb.artista, c->playingNow->mpb.nome);
    return 1;
}
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

void carregar_musicas_arquivo(Lista* li, const char* nomeArquivo) {
    Musica mpbx;
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[200]; // Buffer para armazenar cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Remover o caracter de nova linha
        linha[strcspn(linha, "\n")] = '\0';

        // Separar nome da música e nome dos compositores
        strcpy(mpbx.nome, strtok(linha, "-"));
        strcpy(mpbx.composicao, strtok(NULL, "-"));
        trim(mpbx.nome);
        trim(mpbx.composicao);
        insere_lista_inicio(li, mpbx); // Inserir na lista duplamente encadeada
    }
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
        printf("\nDe: %s (%s) - ",(*li)->mpb.nome, (*li)->mpb.composicao);
        printf("Para: %s (%s)\n",atual->mpb.nome, atual->mpb.composicao);
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
        printf("Composicao: %s\n",atual->mpb.composicao);
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
            printf("Nome: %s\t Composicao: %s\n", atual->ant->mpb.nome, atual->ant->mpb.composicao);
        else printf("NULO\n");
        printf("<Tocando Agora> Nome: %s\t Composicao: %s\n",atual->mpb.nome, atual->mpb.composicao);
        printf("<Proxima> ");
        if (atual->prox !=NULL)
            printf("Nome: %s\t Composicao: %s\n", atual->prox->mpb.nome, atual->prox->mpb.composicao);
        else
            printf("NULO\n");
    }
    else printf("\nMusica nao encontrada.");
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

    // Encontrar o primeiro caracter que não é espaço em branco
    start = str;
    while (*start && isspace((unsigned char)*start)) {
        start++;
    }

    // Se a string estiver vazia, retorna
    if (*start == 0) {
        *str = '\0';
        return;
    }

    // Encontrar o último caracter que não é espaço
    end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) {
        end--;
    }

    // Adiciona o caracter nulo após o último caracter que não é espaço
    *(end + 1) = '\0';

    // Mover a string para o início da posição de memória original
    if (start != str) {
        memmove(str, start, end - start + 2);
    }
}
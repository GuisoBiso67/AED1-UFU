#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct lista{ 
    int *dados; // define um ponteiro para um vetor 
    int quant; // mantém a quantidade 
};
typedef struct lista Lista;

Lista *criarListaVazia(int tam){
    Lista *l;
    l = (Lista *) malloc (sizeof(Lista));
    if (l != NULL){ 
        l->dados = (int *) malloc (tam * sizeof(int));
        l->quant=0;
        return l;
    } else return NULL; 
}

void inserirElemento(Lista *l, int elem, int tam){ 
    if (l->quant < tam){ 
        l->dados[l->quant] = elem;
        l->quant++;
    } else {
        printf("\nMemoria insuficiente.");
    }
} 
    
void imprimirLista (Lista *l){ 
    int p;
    for (p=0; p<l->quant; p++){
        printf("%d ", l->dados[p]);
    }
}

int main(void) { 
    Lista *lp;
    int tam;
    srand(time(NULL));
    printf("Informe o tamanho maximo desejado para a lista:");
    scanf("%d",&tam);
    lp = criarListaVazia(tam); // aloca memória e devolve o endereço 
    for(int i=0;i<tam;i++){
        inserirElemento(lp, rand()%100, tam);
    } 
    imprimirLista(lp); 
    return 0;
}
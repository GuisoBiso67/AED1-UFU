#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pesquisa_binaria(int* vetor, int tamanho, int chave){
    int meio, inicio=0, fim=tamanho-1;

    while(inicio<=fim){
        meio = (inicio+fim)/2;

        if(vetor[meio] == chave){
            return meio;
        }
        else if(vetor[meio] < chave){
            inicio = meio+1; // +1 pq nao precisa  incluir o meio q ja foi verificado;
        }
        else if(vetor[meio] > chave){
            fim = meio-1; // - 1 pq nao precisa  incluir o meio q ja foi verificado;
        }
    }    
    return -1;
}

int main(){
    int vet[] = {0,2,4,6,8,10,12,14,16,18,20};
    int tamanho = sizeof(vet)/sizeof(vet[0]); // retorna o numero certo de bytes;

    int *p;
    p = vet;
    
    int value=10;

    int answer = pesquisa_binaria(p, tamanho, value);
    printf("Position of %d: %d\n", value, answer);
}
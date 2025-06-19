#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#define TAM 3

int main(){
    int matriz[TAM][TAM] = {2, 7, 6, 9, 5, 1, 4, 3, 8};
    int transposta[TAM][TAM];
    printf("Soma matriz: %d\n", somaMatriz(&matriz[0][0], TAM));
    printf("Soma diag principal: %d\n", somaDiagP(&matriz[0][0], TAM));
    printf("Soma diag sec: %d\n", somaDiagS(&matriz[0][0], TAM));

    if(simetrica(&matriz[0][0], TAM) == 1){
        printf("Matriz eh simetrica\n");
    }else{
        printf("Matriz nao eh simetrica\n");
    }

    fazerTransposta(&matriz[0][0], &transposta[0][0], TAM);
    
    if(quadradoMagico(&matriz[0][0], &transposta[0][0], TAM) == 1){
        printf("Matriz eh quadrado perfeito\n");
    }else{
        printf("Matriz nao eh quadrado perfeito\n");
    }
}
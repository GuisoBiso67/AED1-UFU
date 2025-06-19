#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int somaMatriz(int* matriz, int n){ // soma dos elementos;
    int soma=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            soma += *(matriz+i * n+j);
        }
    }
    return soma;
}

int somaDiagP(int* matriz, int n){ // soma da diagonal principal;
    int somaP=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                somaP += *(matriz+i * n+j);
            }
        }
    }
    return somaP;
}

int somaDiagS(int* matriz, int n){ // soma da diagonal secundaria;
    int somaS=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i+j == n-1){
                somaS += *(matriz+i * n+j);
            }
        }
    }
    return somaS;
}

int simetrica(int* matriz, int n){ // verificar se eh simetrica;
    int transposta[n][n];
    int cont=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            transposta[i][j] = *(matriz+j * n+i);
            //printf("%d ",transposta[i][j]);
        }
        //printf("\n");
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(*(matriz+i * n+j) == transposta[i][j]){
                cont++;
            }
        }
    }

    if(cont==n*n){
        return 1;
    }else{
        return -1;
    }
}

int fazerTransposta(int* matriz, int* transposta, int n){ // fazer a transposta da matriz inserida;
    int cont=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            *(transposta+i * n+j) = *(matriz+j * n+i);
        }
    }
}


int quadradoMagico(int* matriz, int* transposta, int n){ 
    int linhas[n], contLinhas=0;
    int colunas[n], contColunas=0;
    int diagP, diagS;
    diagP = somaDiagP(matriz, n);
    diagS = somaDiagS(matriz, n);

    for(int i=0;i<n;i++){ // garantir a inicialização das somas em zero;
        linhas[i] = 0;
        colunas[i] = 0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            linhas[i]=linhas[i]+*(matriz+i * n+j); // verifica soma das linhas;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            colunas[i]=colunas[i]+*(transposta+i * n+j); // verifica soma das colunas (que sao as linhas da transposta);
        }
    }

    for(int i=1;i<n;i++){
        if(linhas[i] == linhas[i-1]){
            contLinhas++;
        }
        if(colunas[i] == colunas[i-1]){
            contColunas++;
        }
    }

    if(contLinhas==n-1 && contColunas==n-1){
        if(linhas[0] == colunas[0] && colunas[0] == diagP && diagP == diagS){
            return 1;
        }else{
            return -1;
        }
    }else{
        return -1;
    }
}
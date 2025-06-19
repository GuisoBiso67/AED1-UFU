#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

int main(){
    int quantAlunos=3;
    TipoAluno vAlunos[quantAlunos];
    double p1, p2, notaExtra;

    for(int i=0;i<quantAlunos;i++){
        printf("Nome aluno %d: ", i+1);
        scanf(" %50[^\n]%*c", vAlunos[i].nome);
        printf("Prova 1: ");
        scanf("%lf", &p1);
        printf("Prova 2: ");
        scanf("%lf", &p2);
        printf("Nota Extra: ");
        scanf("%lf", &notaExtra);
        vAlunos[i].media = notaFinal(p1,p2,notaExtra);
    }

    for(int i=0;i<quantAlunos;i++){
        printf("Aluno %d: %s\n", i+1, vAlunos[i].nome);
        printf("Nota Final: %.2lf\n", vAlunos[i].media);
    }
}
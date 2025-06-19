#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

double notaFinal(double p1, double p2, double notaExtra){
    double notaFinal;
    notaFinal=((p1+p2)/2)+notaExtra;
    if(notaFinal>10){
        return 10.00;
    }else{
        return notaFinal;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int raizes(float a, float b, float c, float* x1, float* x2, float* delta){
    *delta = (b*b)-(4*a*c);
    if(delta<0){
        return -1;
    }
    *x1 = ((-b)+(*delta))/(2*a);
    *x2 = ((-b)-(*delta))/(2*a);
    return 0;
}

int main(){
    float a=1, b=5, c=6;
    float x1, x2, delta;

    int p = raizes(a,b,c,&x1,&x2,&delta);

    if(p==-1){
        printf("Nao ha raizes reais. Delta eh menor que zero!\n");
    }else{
        printf("X' = %.2f\nX'' = %.2f\nDelta: %.2f\n",x1,x2,delta);
    }
}
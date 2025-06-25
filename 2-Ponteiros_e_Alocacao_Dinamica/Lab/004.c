#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int ord(int* a, int* b, int* c){
    int temp;

    for(int i=0;i<3;i++){
        if(*a>*b){
            temp=*b;
            *b=*a;
            *a=temp;
        }
        if(*b>*c){
            temp = *c;
            *c=*b;
            *b=temp;
        }
    }

    if(*a==*b && *b==*c){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int x, y, z;
    scanf("%d %d %d",&x, &y, &z);
    int v = ord(&x, &y, &z);
    printf("Ordenado: %d %d %d / Valores Diferentes?: %d\n", x, y, z, v);
}
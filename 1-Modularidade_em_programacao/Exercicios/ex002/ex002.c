#include <stdio.h>
#include <stdlib.h>
#include "media.h"

int main(){
    float a, b, c;
    scanf("%f %f %f",&a,&b,&c);
    printf("%.2f\n", media(a,b,c));
}
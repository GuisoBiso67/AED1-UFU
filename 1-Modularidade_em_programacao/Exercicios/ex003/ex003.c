#include <stdio.h>
#include <stdlib.h>
#include "mdc.h"

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("MDC: %d\n", mdc(a,b));
}
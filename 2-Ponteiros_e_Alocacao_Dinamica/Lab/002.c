#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    int a;
    char c;
    float f;
    
    int *p1 = &a;
    char *p2 = &c;
    float *p3 = &f;

    printf("Int before: %d\n", *p1);
    printf("Char before: %c\n", *p2);
    printf("Float before: %f\n", *p3);

    *p1 = 5;
    *p2 = 'c';
    *p3 = 7.0;

    printf("Int after: %d\n", *p1);
    printf("Char after: %c\n", *p2);
    printf("Float after: %f\n", *p3);
}
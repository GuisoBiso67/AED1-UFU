#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    float array[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float *p = array;

    for(int i=0;i<10;i++){
        printf("Pos %d: %p , %f %f \n",i, p+i, *(p+i), array[i]);
    }
}
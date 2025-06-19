#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mdc.h"

int mdc(int num1, int num2){
    if(num1%num2 == 0)
        return num2;
    else
        return mdc(num2, num1%num2);
}
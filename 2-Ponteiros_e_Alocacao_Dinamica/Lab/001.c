#include <stdio.h>

// retorna o valor em bytes das variaveis no struct, no caso 12. (4+4+4);
typedef struct {
    int dia, mes, ano; 
} data;

int main (void) {
   printf ("sizeof (data) = %d\n", sizeof (data));
   return 1;
}
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    double *p = malloc(sizeof(double));
    *p = 3.0;
    free(p); 

    double result = pow(*p, 2);  
    printf("Result: %.2f\n", result);

    return 0;
}
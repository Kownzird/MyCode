#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    printf("strtof: %f\n", strtof("0.123", NULL));
    printf("strtod: %lf\n", strtod("-1.1185", NULL));
    printf("strtold: %Lf\n", strtold("100.0123", NULL));
    
    exit(0);
}
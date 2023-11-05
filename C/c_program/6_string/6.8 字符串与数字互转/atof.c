#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    printf("atof: %lf\n", atof("0.123"));
    printf("atof: %lf\n", atof("-1.1185"));
    printf("atof: %lf\n", atof("100.0123"));

    exit(0);
}
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    fputc('A', stdout);
    fputc('B', stdout);
    fputc('C', stdout);
    fputc('D', stdout);
    fputc('\n', stdout);

    exit(0);
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;
int main(void)
{
    execle("/bin/ls", "ls", "-a", "-l", NULL, environ);
    perror("execle error");
    exit(-1);
}
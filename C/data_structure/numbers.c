#include <time.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <strings.h>
#include <pthread.h>
#include <semaphore.h>

#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	FILE *fp = fopen("numbers.txt", "w");

	srand(time(NULL));

	int i;
	for(i=0; i<1000*1000; i++)
	{
		fprintf(fp, "%u\n", rand()%((int)pow(10, rand()%8+5)));
	}

	fclose(fp);

	return 0;
}

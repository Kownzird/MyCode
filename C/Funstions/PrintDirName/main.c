#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
 
void printdir(char *dir, int depth)
{
	DIR		*dp;
	struct	dirent	*entry;
	struct	stat	statbuf;
	
	if ((dp = opendir(dir)) == NULL) {
		fprintf(stderr, "cannot open directory: %s\n", dir);
		return ;
	}
	chdir(dir);				//system call
	while ( (entry = readdir(dp)) != NULL ) {
		lstat( entry->d_name, &statbuf );
		if ( S_ISDIR(statbuf.st_mode) ) {
			if ( strcmp(".", entry->d_name) == 0 ||
				 strcmp("..", entry->d_name) == 0 ) {
				continue;
			}// end of if
			
			printf("%*s%s/\n", depth,"",entry->d_name);
			
			printdir(entry->d_name, depth + 4);
		}
		else
			printf("%*s%s\n", depth, "", entry->d_name);
		
	}
	chdir("..");
	closedir(dp);
}
 
 
int main()
{
	printf("Directory scan of /Users/lance:\n");
	printdir("/bin", 0);
	printf("done.\n");
	
	exit(0);
}

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
extern char **environ;
int main(int argc, char *argv[])
{
	char **e;
	printf("this is printed from new program with proc id %d\n", getpid());

	for(int i=0;i<argc;i++)
	{
		printf("argument %d %s  ",i,argv[i]);
	}
	printf("\n");
	for( e=environ;*e!=NULL;e++)
	{
		printf("enviroment %s  ",*e);
	}
	printf("\n");
	return 0;
}
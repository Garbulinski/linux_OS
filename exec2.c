#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("this is printed from new program with proc id %d\n", getpid());

	for(int i=0;i<argc;i++)
	{
		printf(" caca argument %d %s  ",i,argv[i]);
	}
	printf("\n");
	return 0;
}
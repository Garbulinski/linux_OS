#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int count=0;

	printf("the process has started \n");

	while(count < argc)
	{
		printf("string is %s\n", argv[count]);
		count++;
	}
	return 0;
}

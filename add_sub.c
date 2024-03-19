#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(strstr(argv[1],"add"))
	{
		printf("sum was called %d\n", atoi(argv[2])+atoi(argv[3]));
	}
	else if(strstr(argv[1],"sub"))
	{
		printf("substraction was called %d\n", atoi(argv[2])-atoi(argv[3]));
	}
	else{
		printf("wrong parameter was called\n");
	}
}
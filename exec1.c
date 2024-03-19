#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("This print is made from first program with proc id %d", getpid());
	execl("./exec2","arg1", "arg2", "argc3", NULL);

	printf("This part of the program will not be executed as this print\n");
	return 0;
}
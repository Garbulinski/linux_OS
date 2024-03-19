#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char *args[]={"arg1", "arg2","arg3",NULL};
	char *env[]={"ENV1=1","ENV2=2","ENV3=100",NULL};
	printf("This print is made from first program with proc id %d", getpid());
	execve(argv[1],args, env);

	printf("This part of the program will not be executed as this print\n");
	return 0;
}